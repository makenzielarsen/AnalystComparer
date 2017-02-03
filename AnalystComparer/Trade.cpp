//
// Created by Makenzie Larsen on 2/2/17.
//

#include <fstream>
#include "Trade.h"

int Trade::load(std::ifstream &inputStream) {
    inputStream >> stockSymbol;
    inputStream >> quantity;
    inputStream >> purchaseDateAndTime;
    inputStream >> purchasePrice;
    inputStream >> purchaseTransactionFee;
    inputStream >> saleDateAndTime;
    inputStream >> salePrice;
    inputStream >> saleTransactionFee;
    return 0;
}
