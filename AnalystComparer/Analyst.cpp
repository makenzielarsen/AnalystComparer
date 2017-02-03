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

vector<Trade> **Analyst::getPurchases() const {
    return purchases;
}

const vector<string> &Analyst::getStockSymbolsInvestedIn() const {
    return stockSymbolsInvestedIn;
}

double Analyst::getTotalProfitLoss() const {
    return totalProfitLoss;
}

double Analyst::getProfitLossPerDay() const {
    return profitLossPerDay;
}
