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
      row["sample.sampleDateTime"].get<std::string>(),
      row["determinand.label"].get<std::string>(),
      row["sample.samplingPoint.label"].get<std::string>(),
      row["result"].get<double>()
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

