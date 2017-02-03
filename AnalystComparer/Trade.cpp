//
// Created by Makenzie Larsen on 2/2/17.
//

#include <fstream>
#include <sstream>
#include "Trade.h"
#include "Utils.h"

using namespace std;

int Trade::load(std::ifstream &inputStream) {
    int numberOfFields = 8;
    string *fields = new string[numberOfFields];
    string line;
    getline(inputStream, line);
    split(line, ',', fields, numberOfFields);
    stockSymbol = fields[0];
    quantity = stoi(fields[1]);
    purchaseDateAndTime = stoi(fields[2]);
    purchasePrice = stoi(fields[3]);
    purchaseTransactionFee = stoi(fields[4]);
    saleDateAndTime = stoi(fields[5]);
    salePrice = stoi(fields[6]);
    saleTransactionFee = stoi(fields[7]);
    return 0;
}
