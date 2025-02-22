
#include "replayTable.hpp"

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
