#pragma once
#include <vector>
#include "../Domain/disciplina.h"
#include <iostream>
#include <fstream>
using namespace std;
class Repository_Discipline {

private:
	vector<Disciplina> discipline;
public:
	Repository_Discipline() {
		load_from_file();
	}
	~Repository_Discipline() {
		while (!discipline.empty()) {
			discipline.pop_back();
		}
	}
	virtual void adauga_disciplina(const Disciplina& disciplina);
	virtual const bool sterge_disciplina(string nume_disciplina);
	virtual const bool modifica_disciplina(string nume_disciplina, int numar_ore_nou, string tip_nou, string cadru_nou);
	virtual const bool cauta_disciplina(string nume_disciplina) const;
	virtual const vector<Disciplina> get_all() const noexcept;
	void export_in_fisier();
	void load_from_file();
};
