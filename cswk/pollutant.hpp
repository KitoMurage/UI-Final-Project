#pragma once

#include <string>
#include <iostream>

class Pollutant
{
  public:
    Pollutant(const std::string&, const std::string&, const std::string&, double);
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