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

int Analyst::getPurchasesOrSales() const {
    return purchasesOrSales;
}

vector<Trade> Analyst::getPurchases() const {
    return purchases;
}

const set<string> & Analyst::getStockSymbolsInvestedIn() const {
    return stockSymbolsInvestedIn;
}

double Analyst::getProfitLossPerDay() const {
    return getTotalProfitLoss() / simulationDays;
}

double Analyst::getTotalProfitLoss() const {
    double profitLoss = 0;
    for (auto const &purchase : purchases) {
        profitLoss += purchase.getProfit();
    }
    return profitLoss;
}

//double Analyst::getStockProfitLossPerDay() const {
//    int symbolCount = 0;
//    std::string symbols[purchases.size()];
//    std::vector<Trade> stockAdditions;
//    for (int purchase = 0; purchase < purchasesOrSales; purchase++) {
//        std::vector<std::string> temporary(purchasesOrSales);
//        temporary[purchase] = purchases[purchase].getStockSymbol();
//
//        std::string *existingSymbol = std::find(std::begin(symbols), std::end(symbols), temporary[purchase]);
//        ptrdiff_t position = std::find(std::begin(stockAdditions[purchase].getStockSymbol()), std::end(stockAdditions[purchase].getStockSymbol()), temporary[purchase]) - std::begin(symbols);
//
//        if (existingSymbol == std::end(symbols)) {
//            symbols[symbolCount++] = temporary[purchase];
//            Trade symbolTemp = purchases[purchase];
//            stockAdditions.push_back(symbolTemp);
//        } else {
//
//        }
//    }
//}


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
        purchasesOrSales = stoi(line);
        for (int i = 0; i < purchasesOrSales; i++) {
            Trade purchase;
            if (purchase.load(inputStream) == 0) {
                purchases.push_back(purchase);
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

    for (int i = 0; i < purchasesOrSales; i++) {
        auto purchase = purchases[i];
        if(purchase.getStockSymbol().compare(symbol) == 0) {
            if (firstDay == 0) {
                firstDay = purchase.getPurchaseDateAndTime();
            }
            lastDay = purchase.getSaleDateAndTime();
            profitLoss += purchase.getProfit();
        }
    }

    double stockInvestmentDays = (lastDay - firstDay) / (24 * 60);
    double profitLossPerDay = profitLoss / stockInvestmentDays;

    return profitLossPerDay;
}
