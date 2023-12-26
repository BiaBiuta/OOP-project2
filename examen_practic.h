#pragma once

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QTableView>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMessageBox>
#include "service.h"
#include"MyTableModel.h"

class gui : public QWidget
{
private:
    service& serv;
    QHBoxLayout* lyMain =new  QHBoxLayout;
    MyTableModel* table;
    QTableView* view;
    QPushButton* initnerire;
    QPushButton* batran;
    QPushButton* sterge;
    QPushButton* undo;
    QPushButton* redo;

public:
    gui(service&serv):serv{serv}{
        initgui();
        reloadList(serv.getAll());
        connect();
    }
    ~gui() = default;
    void initgui();
    void reloadList(vector<student>&stud);
    void connect();
   
};
