//
// Created by Stephen Clyde on 1/19/17.
//

#include <iostream>
#include <sstream>
#include <iomanip>
#include "FormattedCell.h"

FormattedCell::FormattedCell(std::string value)
{
    m_dataType = allocatedDataType::String;
    m_value = new std::string(value);
}

FormattedCell::FormattedCell(int value)
{
    m_dataType = allocatedDataType::Integer;
    m_value = new int(value);
}

FormattedCell::FormattedCell(float value)
{
    m_dataType = allocatedDataType::Float;
    m_value = new float(value);
}

FormattedCell::~FormattedCell()
{
    if (m_value)
    {
        switch (m_dataType)
        {
            case allocatedDataType::String: {
                delete (std::string *) m_value;
                break;
            }
            case allocatedDataType::Integer: {
                delete (int *) m_value;
                break;

            }
            case allocatedDataType::Float: {
                delete (float *) m_value;
                break;
            }
            case allocatedDataType::Unknown: {
                std::cerr << "Cannot delete a cell value of an unknown data type" << std::endl;
                break;
            }
        }
    }
}

void FormattedCell::setColumnDefinition(ColumnDefinition* columnDefinition)
{
    m_columnDefinition = columnDefinition;
}

void FormattedCell::write(std::ostream& outputStream)
{
    setupFormattedValue(outputStream);
    setupWidthAndJustification(outputStream);
    outputStream << m_formattedValue;
}

void FormattedCell::setupFormattedValue(std::ostream& outputStream)
{

    if (m_columnDefinition->getDataType() == ColumnDefinition::String)
    {
        m_formattedValue = *(std::string *) m_value;
    }
    else
    {
        std::stringstream ss;
        switch (m_columnDefinition->getDataType()) {
            case ColumnDefinition::Integer:
                ss << *((int *) m_value);
                ss >> m_formattedValue;
                break;
            case ColumnDefinition::Money:
                ss << std::fixed << std::setprecision(2);
                ss << ((float) *((int *) m_value)) / 100.0;
                ss >> m_formattedValue;
                break;
            case ColumnDefinition::FixedPrecision:
                ss << std::fixed << std::setprecision(m_columnDefinition->getPrecision())
                   << *((float *) m_value);
                ss >> m_formattedValue;
                break;
            default:
                break;
        }
    }

}

void FormattedCell::setupWidthAndJustification(std::ostream &outputStream)
{
    switch (m_columnDefinition->getJustification()) {
        case ColumnDefinition::Left: {
            outputStream << std::left << std::setw(m_columnDefinition->getWidth());
            break;
        }
        case ColumnDefinition::Right: {
            outputStream << std::right << std::setw(m_columnDefinition->getWidth());
            break;
        }
        case ColumnDefinition::Center: {
            if (m_formattedValue.length() > m_columnDefinition->getWidth()) {
                m_formattedValue.erase((unsigned long) m_columnDefinition->getWidth());
            }

            int leftPad = (m_columnDefinition->getWidth() - (int) m_formattedValue.length()) / 2;
            int width = m_columnDefinition->getWidth() - leftPad;
            if (leftPad > 0) {
                outputStream << std::right << std::setw(leftPad) << ' ';
            }
            outputStream << std::left << std::setw(width);
            break;
        }
        case ColumnDefinition::Default: {
            outputStream << std::left << std::setw(m_columnDefinition->getWidth());
        }
    }

}
