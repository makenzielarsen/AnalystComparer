//
// Created by Stephen Clyde on 1/16/17.
//

#ifndef ANALYSTCOMPARER_RANKER_H
#define ANALYSTCOMPARER_RANKER_H

#include <fstream>
#include "Constants.h"
#include "Analyst.h"


class Comparer {
private:
    std::string     m_outputFilename;
    vector<Analyst> m_analysts;
    set<string>     m_symbols;

public:
    int load(int argv, char* argc[]);
    int compare() const;

private:
    void loadSymbols();
    void outputInvestorNames(std::ofstream& outputStream) const;
    void outputOverallPerformance(std::ofstream& outputStream) const;
    void outputStockPerformance(std::ofstream& outputStream) const;
};

#endif //ANALYSTCOMPARER_RANKER_H
