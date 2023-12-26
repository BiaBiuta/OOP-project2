#pragma once
#include"student.h"
#include"repo.h"
class ActiuneUndo {
public:
	virtual void doUndo() = 0;
	virtual ~ActiuneUndo() = default;
};
class undosterge:public ActiuneUndo
{
private:
	student studentsters;
	repo& rep;
public:
	undosterge(repo& rep,const student& studentsters):rep{rep},studentsters{studentsters}{}
	void doUndo() override {
		rep.adauga(studentsters);
	}
};

class undoimbatranire :public ActiuneUndo
{
private:
	string x;
	repo& rep;
public:
	undoimbatranire(repo& rep, string x) :rep{ rep }, x{ x } {}
	void doUndo() override {
		if (x == "intinerire") {
			rep.modifica("imbatranire");
		}
		else if (x == "imbatranire") {
			rep.modifica("intinerire");
		}
		
	}
};
class ActiuneRedo {
public:
	virtual void doUndo() = 0;
	virtual ~ActiuneRedo() = default;
};
class redosterge :public ActiuneRedo
{
private:
	student studentsters;
	repo& rep;
public:
	redosterge(repo& rep, const student& studentsters) :rep{ rep }, studentsters{ studentsters } {}
	void doUndo() override {
		rep.sterge_repo(studentsters);
	}
};

class redoimbatranire :public ActiuneRedo
{
private:
	string x;
	repo& rep;
public:
	redoimbatranire(repo& rep, string x) :rep{ rep }, x{ x } {}
	void doUndo() override {
		if (x == "intinerire") {
			rep.modifica("intinerire");
		}
		else if (x == "imbatranire") {
			rep.modifica("imbatranire");
		}

	}
};

