//
// Created by Stephen Clyde on 1/19/17.
//

#ifndef FORMATTEDTABLE_COLUMNDEFINITION_H
#define FORMATTEDTABLE_COLUMNDEFINITION_H


#include <string>

class ColumnDefinition {
public:
    enum DataType { String, Integer, Money, FixedPrecision};
    enum Justification { Default, Left, Right, Center };

private:
    std::string     m_header;
    int             m_width = 0;
    DataType        m_dataType;
    Justification   m_justification;
    int             m_precision = 0;

public:
    ColumnDefinition(const std::string& header, int width, DataType dataType = String, Justification justification = Default, int precision = 0);

    const int getWidth() const { return m_width; }
    const DataType  getDataType() const { return m_dataType; }
    const Justification getJustification() const { return m_justification; }
    const int getPrecision() const { return m_precision; }

    void write(std::ostream& outputStream);
    void writeSeparator(std::ostream& outputStream);

private:
    void setupWidthAndJustification(std::ostream &outputStream);
};

#endif //FORMATTEDTABLE_COLUMNDEFINITION_H
