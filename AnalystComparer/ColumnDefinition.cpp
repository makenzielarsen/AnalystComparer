//
// Created by Stephen Clyde on 1/19/17.
//

#include <iostream>
#include <iomanip>
#include "ColumnDefinition.h"

ColumnDefinition::ColumnDefinition(const std::string& header,
                                   int width,
                                   DataType dataType,
                                   Justification justification,
                                   int precision) :
    m_header(header), m_width(width), m_dataType(dataType)
{
    if (dataType == Money)
    {
        m_justification = Right;
        m_precision = 2;
    } else
    {
        m_precision = precision;
        if (justification == Default)
        {
            if (dataType == FixedPrecision || dataType == Integer)
            {
                justification = Right;
            } else {
                justification = Left;
            }
        }
        m_justification = justification;
    }
}


void ColumnDefinition::write(std::ostream& outputStream)
{
    setupWidthAndJustification(outputStream);
    outputStream << m_header << "|";
}

void ColumnDefinition::writeSeparator(std::ostream& outputStream)
{
    std::string dashes = "";
    dashes.append((unsigned long) m_width, '-');
    outputStream << dashes << "|";
}

void ColumnDefinition::setupWidthAndJustification(std::ostream &outputStream)
{
    switch (m_justification)
    {
        case ColumnDefinition::Left: {
            outputStream << std::left << std::setw(m_width);
            break;
        }
        case ColumnDefinition::Right: {
            outputStream << std::right << std::setw(m_width);
            break;
        }
        case ColumnDefinition::Center: {
            if (m_header.length() > m_width) {
                m_header.erase((unsigned long) m_width);
            }

            int leftPad = (m_width - (int) m_header.length()) / 2;
            int width = m_width - leftPad;
            if (leftPad > 0) {
                outputStream << std::right << std::setw(leftPad) << ' ';
            }
            outputStream << std::left << std::setw(width);
            break;
        }
        case ColumnDefinition::Default: {
            outputStream << std::left << std::setw(m_width);
            break;
        }
    }

}
