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

const vector<string> &Analyst::getStockSymbolsInvestedIn() const {
    return stockSymbolsInvestedIn;
}

double Analyst::getTotalProfitLoss() {
    double totalProfitLoss = totalProfitLoss();
    return totalProfitLoss;
}

double Analyst::getProfitLossPerDay() {
    double totalProfitLossPerDay = profitLossPerDay(totalProfitLoss());
    return totalProfitLossPerDay;
}

double Analyst::totalProfitLoss(){
    double profitLoss;
    for (int i = 0; i < purchasesOrSales; i++) {
        profitLoss += purchases[i].getProfit();
    }
    return profitLoss;
}

double Analyst::profitLossPerDay(double totalProfitLoss){
    double totalProfitLossPerDay = totalProfitLoss / simulationDays;
    return totalProfitLossPerDay;
}

double Analyst::stockProfitLossPerDay() {
    int symbolCount = 0;
    std::string symbols[purchases.size()];
    for (int purchase = 0; purchase < purchasesOrSales; purchase++) {
        std::vector<std::string> temporary(purchasesOrSales);
        temporary[purchase] = purchases[purchase].getStockSymbol();

        std::string *existingSymbol = std::find(std::begin(symbols), std::end(symbols), temporary[purchase]);

        if (existingSymbol == std::end(symbols)) {
            symbols[symbolCount++] = temporary[purchase];
            Trade symbolCount = 
        }
    }
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
        purchasesOrSales = stoi(line);
        for (int i = 0; i < purchasesOrSales; i++) {
            Trade purchase;
            if (purchase.load(inputStream) == 0) {
                purchases.push_back(purchase);
                stockSymbolsInvestedIn.push_back(purchase.getStockSymbol());
            } else {
                return 1;
            }
        }
        return 0;
    }
    return 1;
}
