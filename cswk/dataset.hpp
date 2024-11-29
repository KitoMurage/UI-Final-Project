
#pragma once

#include <vector>
#include "pollutant.hpp"


class PollutantDataset
{
  public:
    PollutantDataset() {}
    PollutantDataset(const std::string& filename) { loadData(filename); }
    void loadData(const std::string&);
    int size() const { return data.size(); }
    Pollutant operator[](int index) const { return data.at(index); }
    double Concentration() const;

  private:
    std::vector<Pollutant> data;
    void checkDataExists() const;
};
