#pragma once

#include <string>
#include <iostream>

class Pollutant
{
  public:

    Pollutant(const std::string& time, const std::string& name, const std::string& location, double concentration,
              const std::string& qualifier = "", const std::string& unit = "");

    
    std::string getTime() const { return time; }
    std::string getName() const { return name; }
    double getConcentration() const { return concentration; }
    std::string getLocation() const { return location; }
    std::string getQualifier() const { return qualifier; }
    std::string getUnit() const { return unit; }

  private:
    std::string time;
    std::string name;
    double concentration;
    std::string location;
    std::string qualifier;
    std::string unit;       
};

std::ostream& operator << (std::ostream&, const Pollutant&);