#include <stdexcept>
#include <sstream>
#include "pollutant.hpp"

using namespace std;


Pollutant::Pollutant(const std::string& time, const std::string& name, const std::string& location, double concentration,
                     const std::string& qualifier, const std::string& unit)
    : time(time), name(name), concentration(concentration), location(location), qualifier(qualifier), unit(unit) {}

ostream& operator<<(ostream& out, const Pollutant& pollutant) 
{
    return out << "Pollutant: " << pollutant.getName()
               << "\nTime: " << pollutant.getTime()
               << "\nConcentration: " << pollutant.getConcentration() << " " << pollutant.getUnit()
               << "\nQualifier: " << pollutant.getQualifier()
               << "\nLocation: " << pollutant.getLocation() << endl;
}
