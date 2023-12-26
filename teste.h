#pragma once
#include"student.h"
#include"repo.h"
#include"service.h"
#include<assert.h>
#include<vector>
#include<qdebug>
using std::vector;
class teste
{
public:
	teste() {

	}
	~teste() = default;
	void run() {
		teste_domain();
		teste_repo();
		teste_service();
	}
	void teste_domain() {
		student s{ 1,"ana",3,"mate" };
		assert(s.get_matricol() == 1);
		assert(s.get_nume() == "ana");
		assert(s.get_varsta() == 3);
		assert(s.get_facultate() == "mate");
	}
	void teste_repo() {

		vector<student>cut;
		repo rep{ cut,"test.txt" };
		qDebug() << rep.getAll().size();
		assert(rep.getAll().size() == 10);
		student s{ 3,"dan",8,"mate" };
		rep.sterge_repo(s);
		assert(rep.getAll().size() == 9);
		rep.adauga(s);
		assert(rep.getAll().size() == 10);
		
	}
	void teste_service() {
		vector<student>cut;
		repo rep{ cut,"test.txt" };
		service serv{ rep };
		assert(serv.getAll().size() == 10);
		student s{ 3,"dan",8,"mate" };
		serv.sterge_service(s);
		assert(serv.getAll().size() == 9);
		serv.undo();
		assert(serv.getAll().size() == 10);
		serv.redo();
		assert(serv.getAll().size() == 9);
		rep.adauga(s);
		assert(rep.getAll().size() == 10);
	}
};

