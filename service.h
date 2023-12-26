#pragma once
#include"repo.h"
#include"Undo.h"
#include <memory>
#include <functional>
using std::unique_ptr;
class service
{
private:
	repo& rep;
	vector<unique_ptr<ActiuneUndo>> undoActions;
	vector<unique_ptr<ActiuneRedo>> redoActions;

public:
	service(repo& rep) :rep{ rep }{}
	vector<student>& getAll() {
		return rep.getAll();
	}
	void modifica_serv(string x) {
		try {
			rep.modifica(x);
			undoActions.push_back(std::make_unique<undoimbatranire>(rep, x));
			redoActions.push_back(std::make_unique<redoimbatranire>(rep, x));
		}
		catch (except& e) {

		}
	}
	void sterge_service(student& stud) {
		rep.sterge_repo(stud);
		undoActions.push_back(std::make_unique<undosterge>(rep, stud));
		redoActions.push_back(std::make_unique<redosterge>(rep, stud));
	}
	/*
			 undocare scoate din vectori ultimele operatii
		*/
	void undo() {
		if (undoActions.empty()) {
			throw except{ "Nu mai exista operatii" };
		}
		else {
			undoActions.back()->doUndo();
			undoActions.pop_back();
		}
	}
	/*
			 redo care scoate din redoAction ultimele operatii
		*/
	void redo() {
		if (redoActions.empty()) {
			throw except{ "Nu mai exista operatii" };
		}
		else {
			redoActions.back()->doUndo();
			redoActions.pop_back();
		}
	}

};

