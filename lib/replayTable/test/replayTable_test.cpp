#include <gtest/gtest.h>
#include "replayTable.hpp"


//Black Box test for addRow method of replayTable
TEST(replayTableTest, AddRow)
{
    replayTable table;
    attributeMap row;
    row["timestamp"] = 1;
    row["pos"] = 10;
    table.addRow(row);
// Check that the row was added correctly
    const auto& tableData = table.getTable();
    ASSERT_EQ(tableData.size(), 1);
    EXPECT_EQ(std::get<int>(tableData[0].at("timestamp")),1);
    EXPECT_DOUBLE_EQ(std::get<double>(tableData[0].at("pos")), 10.0);
}

// Black Box test for exportCSV
TEST(replayTableTest, ExportTableCSV)
{
    replayTable table;
    attributeMap row1;
    row1["timestamp"] = 1;
    row1["pos"] = 10.0;
    table.addRow(row1);

    attributeMap row2;
    row2["timestamp"] = 2;
    row2["pos"] = 20.0;
    table.addRow(row2);

    table.exportCSV("test.csv");

    std::ifstream file("test.csv");
    ASSERT_TRUE(file.is_open());
    
    std::string line;
    std::getline(file, line);
    EXPECT_EQ(line, "timestamp, pos"); // check header formatting

    std::getline(file, line);
    EXPECT_EQ(line, "1,10"); // check first row was inserted correctly

    std::getline(file, line);
    EXPECT_EQ(line, "2,20"); // check second row

    file.close();
}

// White Box test for addRow with different types
TEST(replayTableTest, AddMultipleTypes)
{
    replayTable table;
    attributeMap row1;
    row1["timestamp"] = 1;
    row1["pos"] = 10;
    table.addRow(row1);
    
    attributeMap row2;
    row2["timestamp"] = 2;
    row2["status"] = "moving";
    table.addRow(row2);
    
    const auto& tableData = table.getTable();
    ASSERT_EQ(tableData.size(), 2);
    
    EXPECT_EQ(std::get<int>(tableData[0].at("timestamp")), 1); // check timestamp
    EXPECT_EQ(std::get<int>(tableData[0].at("pos")),10); // check position
    
    EXPECT_EQ(std::get<int>(tableData[1].at("timestamp")), 2);
    EXPECT_EQ(std::get<std::string>(tableData[1].at("status")), "moving");
}

/*
// Integration test: Check that the updater can update the table
TEST(replayTableUpdaterTest, AddRowToTableOnUpdate)
{
    testObject obj(0.0, 1.0);
    replayTable table;
    std::vector<std::string> attributes = {"pos"};
    replayTableUpdater updater(&obj, &table, attributes, 1);

    updater.update();
    const auto& tableData = table.getTable();
    EXPECT_EQ(tableData.size(), 1); // check that 1 row was added

    // Check row was updated correctly
    const auto& row = tableData[0];
    EXPECT_EQ(std::get<int>(row.at("timestamp")), 1);
    EXPECT_DOUBLE_EQ(std::get<double>(row.at("pos")), 1.0);  // pos should be 1.0 after 1 update

    // Perform another update
    updater.update();
    const auto& tableData2 = table.getTable();
    EXPECT_EQ(tableData2.size(), 2);  // Table should now have 2 rows

    // Check the new row contains updated position
    const auto& row2 = tableData2[1];
    EXPECT_EQ(std::get<int>(row2.at("timestamp")), 2);  // Timestamp should be 2
    EXPECT_DOUBLE_EQ(std::get<double>(row2.at("pos")), 2.0);  // pos should be 2.0 after 2 updates
}

// Integration test: check reset works after updates
TEST(replayTableTest, ResetTableAfterUpdates) 
{
    testObject obj(0.0, 1.0);  // create the object
    replayTable table;
    std::vector<std::string> attributes = {"pos"};
    replayTableUpdater updater(&obj, &table, attributes, 1);  // Set update frequency to 1

    // Perform 3 updates
    updater.update();
    updater.update();
    updater.update();
    
    // Table should have 3 rows now
    EXPECT_EQ(table.getTable().size(), 3);

    // Reset the table
    table.reset();
    EXPECT_EQ(table.getTable().size(), 0);  // Table should be empty after reset
}
*/
