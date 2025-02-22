#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <variant>

// create aliases for table structure
using value = std::variant<int, double, std::string, float>;
using attributeMap = std::map<std::string, value>;

// example test object
class testObject{
    public:
        double pos;
        double vel;
        std::map<std::string, double> attributes; 
        testObject(double p, double v);
        void update(double time);
        const std::map<std::string, double>& getAttributes() const;
};

class replayTable{
    public:
        // Table structure
        std::vector<attributeMap> table;
        // add new rows to table
        void addRow(const attributeMap& newData);
        // print out the table
        void printTable() const;
};

class replayTableUpdater{
    public:
        testObject* object; // placeholder
        replayTable * table;
        std::vector<std::string> trackedAttributes;
        int updateFrequency;
        int tickCount;
        // constructor
        replayTableUpdater(testObject* obj, replayTable* tab, const std::vector<std::string>& attrName, int freq);
        void update(); // update the table
};
