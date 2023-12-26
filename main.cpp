#include "examen_practic.h"
#include "teste.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    vector<student>stud;
    teste t;
    t.run();
    repo rep{ stud,"txt.txt"};
    service serv{ rep };
    gui w{ serv };
    w.show();
    return a.exec();
}
