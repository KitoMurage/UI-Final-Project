#include "model.hpp"

void PollutantModel::updateFromFile(const QString& filename)
{
    beginResetModel();
    dataset.loadData(filename.toStdString());
    endResetModel();
}

QVariant PollutantModel::data(const QModelIndex& index, int role) const
{
    if (!index.isValid()) {
        return QVariant();
    }

    if (role == Qt::TextAlignmentRole) {
        return int(Qt::AlignRight | Qt::AlignVCenter);
    } 
    else if (role == Qt::DisplayRole) {
        Pollutant p = dataset[index.row()];
        switch (index.column()) {
            case 0: return QVariant(p.getTime().c_str());
            case 1: return QVariant(p.getName().c_str());
            case 2: return QVariant(p.getConcentration());
            case 3: return QVariant(p.getLocation().c_str());
            case 4: return QVariant(p.getQualifier().c_str()); 
            case 5: return QVariant(p.getUnit().c_str());   
        }
    }

    return QVariant();
}

QVariant PollutantModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole) {
        return QVariant();
    }

    if (orientation == Qt::Vertical) {
        return QVariant(section + 1);
    }

    switch (section) {
        case 0: return QString("Time");
        case 1: return QString("Pollutant");
        case 2: return QString("Concentration");
        case 3: return QString("Location");
        case 4: return QString("Qualifier");  
        case 5: return QString("Unit");       
        default: return QVariant();
    }
}
