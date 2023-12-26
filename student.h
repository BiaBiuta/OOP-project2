#pragma once
#include<string>
using std::string;
class student
{
private:
	int matricol;
	string nume;
	int varsta;
	string facultate;
public:
	student(int matricol, string nume, int varsta, string facultate) :matricol{ matricol }, nume{ nume },varsta{varsta},facultate{facultate}{}
	student(const student& s) :matricol{ s.matricol }, nume{ s.nume },varsta{s.varsta},facultate{s.facultate}{}
	/*
	
	gettere*/
	int get_matricol() const{
		return matricol;
	}
	string get_nume() const{
		return nume;
	}
	int get_varsta() const {
		return varsta;
	}
	string get_facultate() const {
		return facultate;
	}
	/*
	setter pt modificare varsta
	*/
	void set_varsta(string i) {
		if (i == "intinerire") {
			this->varsta--;
		}
		else {
			this->varsta++;
		}
	}
	
};

