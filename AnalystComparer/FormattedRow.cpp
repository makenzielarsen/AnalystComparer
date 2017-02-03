//
// Created by Stephen Clyde on 1/19/17.
//

#include <iostream>
#include <iomanip>
#include "FormattedRow.h"
#include "FormattedTable.h"

FormattedRow::FormattedRow(FormattedTable* table) :
    m_table(table)
{
    if (table != nullptr)
    {
        m_cells = new FormattedCell*[m_table->getColumnCount()];
    }
}

FormattedRow::~FormattedRow()
{
    for (int cellIndex = 0; cellIndex < m_cellCount; cellIndex++)
        delete m_cells[cellIndex];
    delete [] m_cells;
}


void FormattedRow::addCell(FormattedCell* cell)
{
    if (cell != nullptr)
    {
        if (m_cellCount >= m_table->getColumnCount())
        {
            std::cerr << "Cannot add row: too many rows" << std::endl;
        }
        else
        {
            cell->setColumnDefinition(m_table->getColumnDefinition(m_cellCount));
            m_cells[m_cellCount++] = cell;
        }
    }
}

void FormattedRow::write(std::ostream& outputStream)
{
    for (int m_cellIndex = 0; m_cellIndex < m_cellCount; m_cellIndex++)
    {
        m_cells[m_cellIndex]->write(outputStream);
        outputStream << "|";
    }
    outputStream << std::endl;
}

