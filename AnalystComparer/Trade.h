//
// Created by Makenzie Larsen on 2/2/17.
//

#ifndef ANALYSTCOMPARER_TRADE_H
#define ANALYSTCOMPARER_TRADE_H


#include <string>

class Trade {
private:
    std::string stockSymbol;
    double quantity;
    double purchaseDateAndTime;
    double purchasePrice;
    double purchaseTransactionFee;
    double saleDateAndTime;
    double salePrice;
    double saleTransactionFee;
    double moneyInvested = {quantity * purchasePrice + purchaseTransactionFee + saleTransactionFee};
    double profit = {quantity * salePrice - moneyInvested};
public:
    int load(std::ifstream& inputStream);
    std::string getStockSymbol() { return stockSymbol; }
    double getQuantity() { return quantity; }
    double getPurchasePrice() { return purchasePrice; }
    double getPurchaseDateAndTime() { return purchaseDateAndTime; }
    double getPurchaseTransactionFee() { return purchaseTransactionFee; }
    double getSaleDateAndTime() { return saleDateAndTime; }
    double getSalePrice() { return salePrice; }
    double getSaleTransactionFee() { return saleTransactionFee; }
    double getMoneyInvested() { return moneyInvested; }
    double getProfit() { return profit; }

};

#endif //ANALYSTCOMPARER_TRADE_H
