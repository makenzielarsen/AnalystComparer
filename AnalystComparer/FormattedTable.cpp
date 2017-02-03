//
// Created by Stephen Clyde on 1/19/17.
//

#include <iostream>
#include <iomanip>
#include "FormattedTable.h"

FormattedTable::FormattedTable(int maxRows, int maxColumns) :
    m_maxRows(maxRows), m_maxColumns(maxColumns)
{
    m_columns = new ColumnDefinition*[m_maxColumns];
    m_rows = new FormattedRow*[m_maxRows];
}

FormattedTable::~FormattedTable()
{
    for (int columnIndex = 0; columnIndex < m_columnCount; columnIndex++)
        delete m_columns[columnIndex];
    delete [] m_columns;

    for (int rowIndex = 0; rowIndex < m_rowCount; rowIndex++)
        delete m_rows[rowIndex];
    delete [] m_rows;
}


void FormattedTable::addColumn(ColumnDefinition* columnDefinition)
{
    if (columnDefinition != nullptr)
    {
        if (m_columnCount >= m_maxColumns)
        {
            std::cerr << "Cannot add column: too many columns" << std::endl;
        }
        else
        {
            m_columns[m_columnCount++] = columnDefinition;
        }
    }
}

void FormattedTable::addRow(FormattedRow* row)
{
    if (row != nullptr)
    {
        if (m_rowCount >= m_maxRows)
        {
            std::cerr << "Cannot add row: too many rows" << std::endl;
        }
        else if (row->getCellCount() != m_columnCount)
        {
            std::cerr << "Cannot add row: wrong number of cells in the row" << std::endl;
        }
        else
        {
            m_rows[m_rowCount++] = row;
        }
    }
}

ColumnDefinition* FormattedTable::getColumnDefinition(int columnIndex) const
{
    ColumnDefinition* columnDefinition = nullptr;

    if (columnIndex>=0 && columnIndex < m_columnCount)
    {
        columnDefinition = m_columns[columnIndex];
    }

    return columnDefinition;
}

void FormattedTable::write(std::ostream& outputStream)
{
    writeHeaders(outputStream);
    for (int rowIndex = 0; rowIndex < m_rowCount; rowIndex++)
    {
        m_rows[rowIndex]->write(outputStream);
    }
}

void FormattedTable::writeHeaders(std::ostream& outputStream)
{
    for (int columnIndex = 0; columnIndex < m_columnCount; columnIndex++)
    {
        m_columns[columnIndex]->write(outputStream);
    }
    outputStream << std::endl;

    for (int columnIndex = 0; columnIndex < m_columnCount; columnIndex++)
    {
        m_columns[columnIndex]->writeSeparator(outputStream);
    }
    outputStream << std::endl;

}


