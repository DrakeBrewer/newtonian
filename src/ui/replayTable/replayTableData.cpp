
#include "replayTable.hpp"

// Function to convert std::variant to string
std::string variantToString(const value& val) 
{
    // lamda that takes a value and returns a string
    return std::visit([](const auto& v) -> std::string {
        std::stringstream stream;
        stream << v; // stringstream automatically converts to a string
        return stream.str();
    }, val);
}

// basic testObject
testObject::testObject(double p, double v)
{
    pos = p;
    vel = v;
    attributes["pos"] = pos;
    attributes["vel"] = vel;
}

const std::map<std::string, double>& testObject::getAttributes() const
{
    return attributes;
}

void testObject::update(double time)
{
    pos += vel*time;
    attributes["pos"] = pos;
}

void replayTable::addRow(const attributeMap& newData)
{
    table.push_back(newData);
}

void replayTable::printTable() const
{
    for (const auto& row : table)
    {
        std::cout << "{" << std::endl;
        for (const auto& elm : row)
        {
            std::cout << " " << elm.first << ": ";
            // lamda function taken from 
            // https://stackoverflow.com/questions/62355613/stdvariant-cout-in-c top answer
            std::visit([](const auto& val) { std::cout << val; }, elm.second); 
            std::cout << ";" << std::endl;
        }
    std::cout << "}" << std::endl;
    }
}

void replayTable::reset()
{
    table.clear();
}

void replayTable::exportCSV(const std::string& filename) const 
{
    std::ofstream file(filename);
    if (!file.is_open()) 
    {
        std::cerr << "ERROR opening file: " << filename << std::endl;
        return;
    }

    // Check if the table is empty
    if (table.empty()) 
    {
        std::cerr << "Table is empty" << std::endl;
        return;
    }
    // write the header with the attribute names first
    const auto& firstRow = table.front();
    bool firstElem = true;
    for (const auto& elem : firstRow) 
    {
        if (!firstElem) file << ","; // commas between elements
        file << elem.first; // attribute name
        firstElem = false;
    }
    file << "\n"; // move on to the actual data

    // start writing rows
    for (const auto& row : table) 
    {
        firstElem = true;
        for (const auto& elem : row) 
        {
            if (!firstElem) file << ",";
            file << variantToString(elem.second); // convert to string
            firstElem = false;
        }
        file << "\n"; // move on to next row
    }
    file.close();
}

replayTableUpdater::replayTableUpdater(testObject* obj, replayTable* tab, const std::vector<std::string>& attrName, int freq)
{
    object = obj;
    table = tab;
    trackedAttributes = attrName;
    updateFrequency = freq;
    tickCount = 0;
}

void replayTableUpdater::update()
{
    tickCount++;
    if (tickCount % updateFrequency == 0)
    {
        attributeMap newRow;
        newRow["timestamp"] = tickCount;
        for (const auto& attr : trackedAttributes)
        {
            auto iter = object->getAttributes().find(attr);
            if(iter != object->getAttributes().end())
            {
                newRow[attr] = static_cast<value>(iter->second);
            }
        }
        table->addRow(newRow);
    }
}
