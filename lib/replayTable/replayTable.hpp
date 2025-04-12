#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <fstream>
#include <sstream>
#include <variant>
#include <algorithm>
#include "world.hpp"
#include "object.hpp"
#include "deltaTime.hpp"

// create aliases for table structure
using value = std::variant<int, double, std::string, float>;
using attributeMap = std::unordered_map<std::string, value>;

// Function to convert variant to string
std::string variantToString(const value& val);

// example test object
class testObject{
    public:
        double pos;
        double vel;
        std::unordered_map<std::string, double> attributes; 
        testObject(double p, double v);
        void update(double time);
        const std::unordered_map<std::string, double>& getAttributes() const;
};

class replayTable{
    public:
        // Table structure
        std::vector<attributeMap> table;
        // add new rows to table
        void addRow(const attributeMap& newData);
        // print out the table
        void printTable() const;
        void reset();
        // get the table
        const std::vector<attributeMap>& getTable() const;
        void exportCSV(const std::string& filename) const;
        // perform select
        replayTable select(const std::vector<std::string>& columns);
};

class replayTableUpdater{
    public:
        RigidBody* obj; // placeholder
        replayTable * table;
        std::vector<std::string> trackedAttributes;
        int updateFrequency;
        int tickCount;
        // constructor
        //replayTableUpdater(testObject* obj, replayTable* tab, const std::vector<std::string>& attrName, int freq);
        //
        void setUpdateFrequency(int freq);
        void setTrackedAttributes(const std::vector<std::string>& attrName);
        replayTableUpdater(RigidBody* body, replayTable* tab, const std::vector<std::string>& attrName, int freq);
        void update(); // update the table
};
