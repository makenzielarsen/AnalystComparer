//
// Created by Makenzie Larsen on 2/2/17.
//

#include <string>
#include <vector>
#include "Analyst.h"

using namespace std;

const string &Analyst::getFullName() const {
    return fullName;
}

const string &Analyst::getInitials() const {
    return initials;
}

int Analyst::getSimulationDays() const {
    return simulationDays;
}

double Analyst::getSeedMoney() const {
    return seedMoney;
}

vector<Trade> Analyst::getTrades() const {
    return trades;
}

const set<string> & Analyst::getStockSymbolsInvestedIn() const {
    return stockSymbolsInvestedIn;
}

double Analyst::getProfitLossPerDay() const {
    return getTotalProfitLoss() / simulationDays;
}

double Analyst::getTotalProfitLoss() const {
    double profitLoss = 0;
    for (auto const &purchase : trades) {
        profitLoss += purchase.getProfitLoss();
    }
    return profitLoss;
}

int Analyst::load(ifstream &inputStream) {
    if (inputStream.is_open()) {
        string line;
        getline(inputStream, line);
        fullName = line;
        getline(inputStream, line);
        initials = line;
        getline(inputStream, line);
        simulationDays = stoi(line);
        getline(inputStream, line);
        seedMoney = stoi(line);
        getline(inputStream, line);
        int numberOfTrades = stoi(line);
        for (int i = 0; i < numberOfTrades; i++) {
            Trade purchase;
            if (purchase.load(inputStream) == 0) {
                trades.push_back(purchase);
                stockSymbolsInvestedIn.insert(purchase.getStockSymbol());
            } else {
                return 1;
            }
        }
        return 0;
    }
    return 1;
}

double Analyst::getStockPerformanceForSymbol(string symbol) const {

    double firstDay = 0;
    double lastDay = 0;
    double profitLoss = 0;

    for (int i = 0; i < trades.size(); i++) {
        auto purchase = trades[i];
        if(purchase.getStockSymbol().compare(symbol) == 0) {
            if (firstDay == 0) {
                firstDay = purchase.getPurchaseDateAndTime();
            }
            lastDay = purchase.getSaleDateAndTime();
            profitLoss += purchase.getProfitLoss();
        }
    }

    double stockInvestmentDays = (lastDay - firstDay) / (24 * 60);
    double profitLossPerDay = profitLoss / stockInvestmentDays;

    return profitLossPerDay;
}
