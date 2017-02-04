cmake_minimum_required(VERSION 3.6)
project(AnalystComparer)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Utils.cpp Utils.h Comparer.cpp Comparer.h Constants.h Analyst.h Trade.h Trade.cpp Analyst.cpp ColumnDefinition.h ColumnDefinition.cpp FormattedCell.h FormattedCell.cpp FormattedRow.h FormattedRow.cpp FormattedTable.h FormattedTable.cpp)

add_executable(AnalystComparer ${SOURCE_FILES})