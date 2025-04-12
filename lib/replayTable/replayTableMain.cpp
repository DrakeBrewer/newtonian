// Example main

#include "replayTable.hpp"

int main() {
    // Create RigidBody objects (with position, velocity, acceleration, mass, and static status)
    RigidBody body1(Vector3d(10.0f, 0.0f, 0.0f), Vector3d(5.0f, 2.0f, 0.0f), Vector3d(0.0f, 0.0f, 3.0f), 2.0f, false);
    //RigidBody body2(Vector3d(20.0f, 0.0f, 0.0f), Vector3d(3.0f, 0.0f, 0.0f), Vector3d(0.0f, 0.0f, 0.0f), 3.0f, false);
    //RigidBody body3(Vector3d(30.0f, 0.0f, 0.0f), Vector3d(2.0f, 0.0f, 0.0f), Vector3d(0.0f, 0.0f, 0.0f), 4.0f, false);

    // Create a replayTable
    replayTable table;

    // Add RigidBody attributes to the replayTable
    std::vector<std::string> attributes = {"position.x","position.y", "position.z", "velocity.x", "velocity.y", "velocity.z", "acceleration.x", "acceleration.y", "acceleration.z", "mass"};

    replayTableUpdater updater1(&body1, &table, attributes, 1);
    //replayTableUpdater updater2(&body2, &table, attributes, 1);
    //replayTableUpdater updater3(&body3, &table, attributes, 1);
    //updater1.update();
    // Simulate a few updates and add the attributes to the replayTable
    updater1.update();
    body1.update(1);
    updater1.update();
    body1.update(1);
    updater1.update();
    body1.update(1);
    updater1.update();

    // Print the current table after updates
    std::cout << "Original Table:" << std::endl;
    table.printTable();
    std::cout << std::endl;

    // Perform a select query to select only the "position" and "mass" columns
    std::vector<std::string> selectedColumns = {"position.x", "position.y", "position.z", "mass"};
    replayTable selectResult = table.select(selectedColumns);
    std::cout << "Select Query Result (Position and Mass):" << std::endl;
    selectResult.printTable();
    std::cout << std::endl;

    table.exportCSV("test_replay_table.csv");

}

