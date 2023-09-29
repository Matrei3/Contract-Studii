#pragma once
#include <map>
#include <vector>
#include "../Domain/disciplina.h"
#include "repository_discipline.h"
#include <iostream>
using namespace std;
class RepoAbstract {
public:
	virtual void adauga_disciplina(const Disciplina& disciplina) = 0;
	virtual const bool sterge_disciplina(string nume_disciplina) = 0;
	virtual const bool modifica_disciplina(string nume_disciplina, int numar_ore_nou, string tip_nou, string cadru_nou) = 0;
	virtual const bool cauta_disciplina(string nume_disciplina)= 0 ;
	virtual const vector<Disciplina> get_all() = 0;
	virtual ~RepoAbstract() = default;
};
class Repository_Lab : public RepoAbstract {
private:
	map<string,Disciplina> discipline;
	double probabilitate;
public:
	Repository_Lab(double prob) :probabilitate{ prob } {
		
	}
	double get_prob() {
		return probabilitate;
	}
	void adauga_disciplina(const Disciplina& disciplina) override;
	const bool sterge_disciplina(string nume_disciplina) override;
	const bool modifica_disciplina(string nume_disciplina, int numar_ore_nou, string tip_nou, string cadru_nou) override;
	const bool cauta_disciplina(string nume_disciplina) override;
	const vector<Disciplina> get_all() override;
};