//
// Created by Stephen Clyde on 1/19/17.
//

#ifndef FORMATTEDTABLE_FORMATTEDCELL_H
#define FORMATTEDTABLE_FORMATTEDCELL_H

#include <ostream>
#include <string>
#include "ColumnDefinition.h"

class FormattedCell {
private:
    enum allocatedDataType { Unknown, String, Integer, Float};
    allocatedDataType   m_dataType = allocatedDataType::Unknown;
    void*               m_value = nullptr;
    std::string         m_formattedValue;
    ColumnDefinition*   m_columnDefinition = nullptr;

public:
    FormattedCell(std::string value);
    FormattedCell(int value);
    FormattedCell(float value);
    ~FormattedCell();

    void setColumnDefinition(ColumnDefinition* columnDefinition);
    void write(std::ostream& outputStream);

private:
    void setupFormattedValue(std::ostream& outputStream);
    void setupWidthAndJustification(std::ostream &outputStream);
};


#endif //FORMATTEDTABLE_FORMATTEDCELL_H
