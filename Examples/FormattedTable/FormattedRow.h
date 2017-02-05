//
// Created by Stephen Clyde on 1/19/17.
//

#ifndef FORMATTEDTABLE_FORMATTEDROW_H
#define FORMATTEDTABLE_FORMATTEDROW_H

#include <ostream>
#include "FormattedCell.h"

class FormattedTable;

class FormattedRow {

private:
    FormattedTable*     m_table = nullptr;
    FormattedCell**     m_cells = nullptr;
    int                 m_cellCount = 0;

public:
    FormattedRow(FormattedTable* table);
    ~FormattedRow();

    void addCell(FormattedCell* cell);

    int getCellCount() const { return m_cellCount; }
    void write(std::ostream& outputStream);
};


#endif //FORMATTEDTABLE_FORMATTEDROW_H
