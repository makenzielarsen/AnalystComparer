//
// Created by Stephen Clyde on 1/19/17.
//

#ifndef FORMATTEDTABLE_FORMATTEDTABLE_H
#define FORMATTEDTABLE_FORMATTEDTABLE_H

#include <ostream>
#include "ColumnDefinition.h"
#include "FormattedRow.h"

class FormattedTable {
private:
    ColumnDefinition**  m_columns = nullptr;
    int                 m_maxColumns = 0;
    int                 m_columnCount = 0;
    FormattedRow**      m_rows = nullptr;
    int                 m_maxRows = 0;
    int                 m_rowCount = 0;

public:
    FormattedTable(int maxRows, int maxColumns);
    ~FormattedTable();

    void addColumn(ColumnDefinition* columnDefinition);
    void addRow(FormattedRow* row);

    ColumnDefinition* getColumnDefinition(int columnIndex) const;
    int getColumnCount() const { return m_columnCount; }

    void write(std::ostream& outputStream);

private:
    void writeHeaders(std::ostream& outputStream);
};


#endif //FORMATTEDTABLE_FORMATTEDTABLE_H
