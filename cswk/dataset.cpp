#include <stdexcept>
#include "dataset.hpp"
#include "csv.hpp"

using namespace std;


void PollutantDataset::loadData(const string& filename)
{
  csv::CSVReader reader(filename);

  data.clear();

  for (const auto& row: reader) {
    Pollutant pollutant
    {
      row["pollutant_name"].get<>(),
      row["time"].get<>(),
      row["concentration"].get<double>(),
      row["location"].get<>()
    };
    data.push_back(pollutant);
  }
}

void PollutantDataset::checkDataExists() const
{
  if (size() == 0) {
    throw std::runtime_error("Dataset is empty!");
  }
}

