#pragma once

#include <string>
#include <iostream>

class Pollutant
{
  public:
    Pollutant(const std::string& time, const std::string& name, const std::string& location, double concentration);
    std::string getTime() const { return time; }
    std::string getName() const { return name; }
    double getConcentration() const { return concentration; }
    std::string getLocation() const { return location; }
  

  private:
    std::string time;
    std::string name;
    double concentration;
    std::string location;
};

std::ostream& operator << (std::ostream&, const Pollutant&);