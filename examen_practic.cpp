#include "examen_practic.h"
#include<qdebug.h>



void gui::initgui() {
	setLayout(lyMain);
	view = new QTableView;
	lyMain->addWidget(view);
	initnerire = new QPushButton("intinerire");
	batran = new QPushButton("imbatranire");
	sterge = new QPushButton("sterge");
	undo = new QPushButton("undo");
	redo = new QPushButton("redo");
	lyMain->addWidget(initnerire);
	lyMain->addWidget(sterge);
	lyMain->addWidget(redo);
	lyMain->addWidget(batran);
	lyMain->addWidget(undo);
}
void gui::reloadList(vector<student>& ve) {
	table = new MyTableModel{ ve };
	view->setModel(table);
	
}
void gui::connect() {
	QObject::connect(initnerire, &QPushButton::clicked, [&]() {
		string x = "intinerire";
		try {
			serv.modifica_serv(x);
			qDebug() << "aici";
		}
		catch (except& e) {
			/*QMessageBox::warning(this, "!", QString::fromStdString(e.getmsg()));
			return;*/
		}
		reloadList(serv.getAll());
		});
	QObject::connect(batran, &QPushButton::clicked, [&]() {
		string x = "imbatranire";
		
			serv.modifica_serv(x);
		
		
		reloadList(serv.getAll());
	});
	QObject::connect(sterge, &QPushButton::clicked, [&]() {
			if (&QListView::pressed) {
				auto selectionModel = view->selectionModel();
				if (selectionModel->hasSelection()) {
					QModelIndexList selectedRows = selectionModel->selectedRows();//selectez linie tabel
					for (int i = 0; i < selectedRows.size(); i++) {//in functie de cate sunt selecatate stergem de atatea ori
						auto selItem = selectedRows.at(i);
						student p = table->getsbj(selItem);
						serv.sterge_service(p);
					}
					reloadList(serv.getAll());
				}
		}
		});
	QObject::connect(undo, &QPushButton::clicked, [&]() {
		/*
			buton undo apeleaza undo sercice
		*/
		try {
			serv.undo();
		}
		catch (except& e) {
			QMessageBox::warning(this, "!", QString::fromStdString(e.getmsg()));
		}
		reloadList(serv.getAll());
		});
	QObject::connect(redo, &QPushButton::clicked, [&]() {
		/*
			buton redo apeleaza undo sercice
		*/
		try {
			serv.redo();
		}
		catch (except& e) {
			QMessageBox::warning(this, "!", QString::fromStdString(e.getmsg()));
		}
		reloadList(serv.getAll());
		});
}
