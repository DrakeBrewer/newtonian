// Example main

#include "replayTable.hpp"

int main() {
    testObject obj1(10.0, 2.0);  
    testObject obj2(20.0, 1.0);  
    replayTable table;

    std::vector<std::string> trackedAttributes = {"pos", "vel"};
    replayTableUpdater updater1(&obj1, &table, trackedAttributes, 1);
    replayTableUpdater updater2(&obj2, &table, trackedAttributes, 1);

    // start basic simulation
    for (int i = 0; i < 5; ++i) 
    {
        obj1.update(1.0); // pass 1 sec
        obj2.update(1.0);
        updater1.update();
        updater2.update();
    }

    table.printTable();  // print table
    table.exportCSV("replayData.csv");
    table.reset();
    table.printTable();
    return 0;
}

