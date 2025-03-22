
#include "replayTable.hpp"

// Function to convert std::variant to string
std::string variantToString(const value& val) 
{
    // lamda that takes a value and returns a string
    return std::visit([](const auto& v) -> std::string {
        std::stringstream stream;
        // Handle floating point nums
        if constexpr (std::is_floating_point_v<std::decay_t<decltype(v)>>) 
        {
            stream.precision(3);  // 3 decimal places
            stream << std::fixed << v;  // avoid scientific notation
        }
        else
        {
            stream << v; // stringstream automatically converts to a string
        }
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

const std::unordered_map<std::string, double>& testObject::getAttributes() const
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
            std::cout << variantToString(elm.second);
            std::cout << ";" << std::endl;
        }
    std::cout << "}" << std::endl;
    }
}

void replayTable::reset()
{
    table.clear();
}

const std::vector<attributeMap>& replayTable::getTable() const
{
    return table;
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

// Perform range query
replayTable replayTable::rangeQuery(const std::string& column, const value& minVal, const value& maxVal)
{
    // Want to return seperate table
    replayTable result;
    for (const auto& row : table)
    {
        // make sure the table is not empty
        if(row.count(column) > 0)
        {
            // Handle ints
            if (auto val = std::get_if<int>(&row.at(column)))
            {
                if (auto minInt = std::get_if<int>(&minVal), maxInt = std::get_if<int>(&maxVal); minInt && maxInt)
                {
                    // if value is in the range
                    if(*val >= *minInt && *val <= *maxInt)
                    {
                        result.addRow(row);
                    }
                }
                
            }
            // handle floats
            else if(auto val = std::get_if<float>(&row.at(column)))
            {
                if (auto minFloat = std::get_if<float>(&minVal), maxFloat = std::get_if<float>(&maxVal); minFloat && maxFloat)
                {
                    if(*val >= *minFloat && *val <= *maxFloat)
                    {
                        result.addRow(row);
                    }
                }
            }
            // handle doubles
            else if(auto val = std::get_if<double>(&row.at(column)))
            {
                if (auto minDouble = std::get_if<double>(&minVal), maxDouble = std::get_if<double>(&maxVal); minDouble && maxDouble)
                {
                    if(*val >= *minDouble && *val <= *maxDouble)
                    {
                        result.addRow(row);
                    }
                }

            }
            else
            {
                std::cerr << "Error: invalid type for range query: " << column << std::endl;
            }
        }
    }
    return result;
}

// Filter for a condtion
replayTable replayTable::filter(const std::string& column, const value& condition)
{
    replayTable result;
    for(const auto& row : table)
    {
        if(row.count(column) > 0 && row.at(column) == condition)
        {
            result.addRow(row);
        }
    }
    return result;
}

// Select columns from table
replayTable replayTable::select(const std::vector<std::string>& columns)
{
    replayTable result;
    for (const auto& row : table)
    {
        attributeMap newRow;
        for(const auto& col : columns)
        {
            if(row.count(col) > 0)
            {
                newRow[col] = row.at(col);
            }
        }
        result.addRow(newRow);
    }
    return result;
}

replayTableUpdater::replayTableUpdater(RigidBody* body, replayTable* tab, const std::vector<std::string>& attrName, int freq)
{
    obj = body;
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
        std::cout << "Updating table at tick " << tickCount << std::endl;  // Debugg stuff
        
        std::cout << "Tracking the following attributes:" << std::endl;
        for (const auto& attr : trackedAttributes) {
            std::cout << "Tracked attribute: " << attr << std::endl;
        }

        // Get the attributes from the object
        const auto& objectAttributes = obj->getAttributes();
        std::cout << "Object attributes map contains:" << std::endl;

        for (const auto& attr : objectAttributes) {
            std::cout << "Key: " << attr.first << " | Value: " 
                      << variantToString(attr.second) << std::endl;
        }

        for (const auto& attr : trackedAttributes)
        {
            auto iter = obj->getAttributes().find(attr);
            if(iter != obj->getAttributes().end())
            {
                std::cout << "Adding attribute " << attr << " with value: " << variantToString(iter->second) << std::endl;  
                newRow[attr] = iter->second;
            }
        }
        std::cout << "Adding row to table: " << std::endl;
        for (const auto& row : newRow)
        {
            std::cout << row.first << ": " << variantToString(row.second) << std::endl;
        }

        table->addRow(newRow);
    }
}

/*
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
*/
