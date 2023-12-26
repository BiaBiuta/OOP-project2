
#include <QAbstractTableModel>
#include "student.h"
#include <vector>
using std::vector;
#include <QAbstractItemView>
#include <iostream>
class MyTableModel : public QAbstractTableModel {
    std::vector<student> studenti;
public:
    MyTableModel(const vector<student>& sbjs) : studenti(sbjs) {
    };
    int rowCount(const QModelIndex& parent = QModelIndex()) const override {
        return studenti.size();
    }
    int columnCount(const QModelIndex& parent = QModelIndex()) const override {
        return 4;
    }
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override {
        if (role == Qt::DisplayRole || role==Qt::BackgroundRole)
        {
            student sbj = studenti[index.row()];
            if (index.column() == 0)
            {
                if (Qt::BackgroundRole == role && sbj.get_facultate()=="info")
                    return QColor(Qt::red);
                else if (Qt::BackgroundRole == role && sbj.get_facultate() == "mate-info")
                    return QColor(Qt::green);
              
                else if (Qt::BackgroundRole == role && sbj.get_facultate() == "mate"){
                return QColor(Qt::yellow);
                }
                else if (Qt::BackgroundRole == role && sbj.get_facultate() == "ai") {
                    return QColor(Qt::darkGray);
                }
                return QString::fromStdString(std::to_string(sbj.get_matricol()));
            }
            if (index.column() == 1)
            {
                if (Qt::BackgroundRole == role && sbj.get_facultate() == "info")
                    return QColor(Qt::red);
                else if (Qt::BackgroundRole == role && sbj.get_facultate() == "mate-info")
                    return QColor(Qt::green);
              
                else if (Qt::BackgroundRole == role && sbj.get_facultate() == "mate") {
                    return QColor(Qt::yellow);
                }
                else if (Qt::BackgroundRole == role && sbj.get_facultate() == "ai") {
                    return QColor(Qt::darkGray);
                }
                return QString::fromStdString((sbj.get_nume()));
            }
            if (index.column() == 2)
            {
                if (Qt::BackgroundRole == role && sbj.get_facultate() == "info")
                    return QColor(Qt::red);
                else if (Qt::BackgroundRole == role && sbj.get_facultate() == "mate-info")
                    return QColor(Qt::green);
               
                else if (Qt::BackgroundRole == role && sbj.get_facultate() == "mate") {
                    return QColor(Qt::yellow);
                }
                else if (Qt::BackgroundRole == role && sbj.get_facultate() == "ai") {
                    return QColor(Qt::darkGray);
                }
                return QString::fromStdString(std::to_string(sbj.get_varsta()));
            }
            if (index.column() == 3)
            {   
                if (Qt::BackgroundRole == role && sbj.get_facultate() == "info")
                    return QColor(Qt::red);
                else if (Qt::BackgroundRole == role && sbj.get_facultate() == "mate-info")
                    return QColor(Qt::green);
                else if (Qt::BackgroundRole == role && sbj.get_facultate() == "mate") {
                    return QColor(Qt::yellow);
                }
              
                else if (Qt::BackgroundRole == role && sbj.get_facultate() == "ai") {
                    return QColor(Qt::darkGray);
                }
                return QString::fromStdString(sbj.get_facultate());
            }
        }
        return QVariant{};

    }
    QVariant headerData(int section, Qt::Orientation orientation, int role) const
    {
        if (orientation == Qt::Horizontal)
        {
            if (role == Qt::DisplayRole)
                switch (section)
                {
                case 0: return "Matricol";            break;
                case 1: return "Nume";   break;
                case 2: return "Varsta";       break;
                case 3: return "Facultate";   break;
                default:
                    return QString("Column %1").arg(section + 1);
                    break;
                }
        }
        else if (orientation == Qt::Vertical)
        {
            if (role == Qt::DisplayRole)
                return section + 1;
        }
        return QVariant();
    }
    student getsbj(const QModelIndex& index)
    {
        return studenti[index.row()];
    }
    
};

