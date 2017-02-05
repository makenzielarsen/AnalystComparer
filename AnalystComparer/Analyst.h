#ifndef ANALYSTCOMPARER_ANALYST_H
#define ANALYSTCOMPARER_ANALYST_H

#include <string>
#include <vector>
#include <set>
#include <fstream>
#include "Trade.h"

using namespace std;

class Analyst{
private:
    string fullName;
    string initials;
    int simulationDays;
    double seedMoney;
    int purchasesOrSales;

    vector<Trade> purchases;
    set<string> stockSymbolsInvestedIn;

public:
    int load(ifstream& inputStream);

    const string &getFullName() const;

    const string &getInitials() const;

    int getSimulationDays() const;

    double getSeedMoney() const;

    int getPurchasesOrSales() const;

    vector<Trade> getPurchases() const;

    const set<string> &getStockSymbolsInvestedIn() const;

    double getTotalProfitLoss() const;

    double getProfitLossPerDay() const;

    double getStockPerformanceForSymbol(string) const;
};
#endif //ANALYSTCOMPARER_ANALYST_H