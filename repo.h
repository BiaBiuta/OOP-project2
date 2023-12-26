#pragma once
#include<vector>
#include<fstream>
#include"student.h"
using std::vector;
class except {
private:
	string msg;
public:
	except(string msg) :msg{ msg } {}
	string getmsg() {
		return msg;
	}
};
class repo
{
private:
	vector<student>st;
	string name;
public:
	repo(vector<student>st,string name):st{st},name{name}{
		loadFromFile();
	}
	repo(const repo& rep) = delete;
	/*
	* caut in vector daca exista nr matricol
	
	*/
	int cauta(int matricol) {
		auto index = find_if(st.begin(), st.end(), [&](const student& s) {
			return s.get_matricol() == matricol;
			});
		if (index != st.end()) {
			int rez = index- st.begin();
			return rez;
		}
		return -1;
	}
	/*
	* caut daca exista obicetul daca da arunc exceptie
	* daca nu  adaug
	*/
	void adauga(student& s) {
		int index = cauta(s.get_matricol());
		if (index != -1) {
			throw except("exista");
		}
		st.push_back(s);
		writeToFile();
	}
	vector<student>& getAll() {
		return st;
	}
	/*
		scriere din fisier
	*/
	void writeToFile() {
		std::ofstream out(name);
		if (!out.is_open()) {
			throw except("nu s-a deschis\n");
		}
		
		for (auto& prod : getAll()) {
			
			out << prod.get_matricol() << " " << prod.get_nume() << " " << " " << prod.get_varsta() << " " << prod.get_facultate() << "\n";
		}
		out.close();
	}
	void loadFromFile() {
		std::ifstream in(name);
		if (!in.is_open()) {
			throw except("nu s-a deschis\n");
		}
		int matricol;
		string nume;
		int varsta;
		
		string facultate;
		
		while (in >> matricol >> nume >> varsta >> facultate ) {
			
			student p(matricol, nume, varsta, facultate);
			int index = cauta(matricol);
			st.push_back(p);
		}
		in.close();
	}
	void modifica(string x) {
	
			for (auto& student : st) {
				if (student.get_varsta() == 0) {
					if (x == "intinerire") {
						throw except("nu se mai poate\n!");
						return;
					}
				}
				student.set_varsta(x);
			}
			
			writeToFile();

	}
	/*
	* caut daca exista obicetul daca nu arunc exceptie 
	* daca da sterg
	*/
	void sterge_repo(student& stud) {
		auto index = cauta(stud.get_matricol());
		if (index == -1) {
			throw except("obiectul nu exista!\n");
		}
		st.erase(st.begin() + index);
		writeToFile();
	}
	
};

