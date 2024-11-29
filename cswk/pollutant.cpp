#include <stdexcept>
#include <sstream>
#include "pollutant.hpp"

using namespace std;

Pollutant::Pollutant(const std::string& time, const std::string& name, double concentration, const std::string& location)
    : time(time), name(name), concentration(concentration), location(location) {}

ostream& operator<<(ostream& out, const Pollutant& pollutant) 
{
    return out << "Pollutant: " << pollutant.getName()
               << "\nTime: " << pollutant.getTime()
               << "\nConcentration: " << pollutant.getConcentration() << " µg/m³"
               << "\nLocation: " << pollutant.getLocation() << endl;
}
