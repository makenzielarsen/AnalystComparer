//
// Created by Stephen Clyde on 1/16/17.
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include "Comparer.h"
#include "Utils.h"
#include "Analyst.h"
#include "FormattedTable.h"

int Comparer::load(int argc, char* argv[]) {
    if (argc<3)
    {
        std::cout << "Invalid parameters" << std::endl;
        std::cout << "usage: AnalystComparer <output file> <input file 1> <input file 2> ..." << std::endl;
        return -1;
    }

    m_outputFilename = argv[1];
    auto analystCount = argc - 2;

    int analystIndex = 0;
    for (; analystIndex < analystCount; analystIndex++)
    {
        std::ifstream inputStream;
        inputStream.open(argv[2 + analystIndex]);

        Analyst analyst;
        if (analyst.load(inputStream) != 0) {
            std::cout << "Failed to load " << argv[analystIndex] << std::endl;
        }
        m_analysts.push_back(analyst);

        inputStream.close();
    }

    loadSymbols();

    int result = 0;
    if (analystIndex < m_analysts.size()) {
        result = -1;
    }

    return result;
}

int Comparer::compare() const {
    if (m_analysts.size() < 2)
    {
        std::cout << "Cannot do comparison with " << m_analysts.size() << " analysts" << std::endl;
        return -1;
    }

    if (m_outputFilename == "")
    {
        std::cout << "Cannot do comparison because no output file is specified" << std::endl;
        return -1;
    }

    std::ofstream outputStream(m_outputFilename);
    outputInvestorNames(outputStream);
    outputOverallPerformance(outputStream);
    outputStockPerformance(outputStream);

    return 0;
}

void Comparer::loadSymbols() {
    for (auto const &analyst : m_analysts) {
        auto symbols = analyst.getStockSymbolsInvestedIn();
        m_symbols.insert(symbols.begin(), symbols.end());
    }
}


void Comparer::outputInvestorNames(std::ofstream& outputStream) const {
    outputStream << "Analyst Comparison" << endl;
    outputStream << endl;
    outputStream << "Investors" << endl;
    for (auto const &analyst : m_analysts) {
        outputStream << analyst.getInitials() << setw(4) << "" << analyst.getFullName() << endl;
    }
    outputStream << endl;
}

void Comparer::outputOverallPerformance(std::ofstream& outputStream) const {
    outputStream << "Overall Performance" << std::endl;

    outputStream << setw(16) << "";
    for (auto const &analyst : m_analysts) {
        outputStream << setw(16) << analyst.getInitials();
    }
    for (auto const &analyst : m_analysts) {
        outputStream << setw(16) << "D (days)";
        outputStream << setw(16) << analyst.getSimulationDays();
        outputStream << setw(16) << analyst.getSeedMoney();
        outputStream << setw(16) << analyst.getTotalProfitLoss();
        outputStream << setw(16) << analyst.getProfitLossPerDay();
        outputStream << endl;
    }
    outputStream << endl;

//    FormattedTable table(6, 3);
//
//    table.addColumn(new ColumnDefinition("", 10, ColumnDefinition::String));
//
//    for (int investor = 0; investor < m_analystCount; investor++) {
//        table.addColumn(new ColumnDefinition(m_analysts[investor].getInitials(), 10, ColumnDefinition::String));
//    }
//    for (int investor = 0; investor < m_analystCount; investor++) {
//        FormattedRow* row = new FormattedRow(&table);
//        row->addCell(new FormattedCell(m_analysts[investor].getSimulationDays()));
//        row->addCell(new FormattedCell(m_analysts[investor].getSeedMoney()));
//        row->addCell(new FormattedCell(m_analysts[investor].getTotalProfitLoss()));
//        row->addCell(new FormattedCell(m_analysts[investor].getProfitLossPerDay()));
//        table.addRow(row);
//    }
//
//    table.write(outputStream);
//    outputStream << endl;
};

void Comparer::outputStockPerformance(std::ofstream& outputStream) const {
    outputStream << "Stock Performance" << endl;


    outputStream << endl;
}
