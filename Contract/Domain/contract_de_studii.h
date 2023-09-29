#pragma once
#include "disciplina.h"
#include <vector>
#include <algorithm>
#include <random> 
#include <chrono> 
#include <fstream>
using namespace std;
class ContractStudii {
private:
	vector<Disciplina> DisciplineContract;
	int numar_discipline = 0;
public:
	ContractStudii() = default;
	ContractStudii(const ContractStudii& ot) = delete;
	const int get_numar_discipline() noexcept;
	void adauga_disciplina(Disciplina disciplina_de_adaugat) ;
	const bool sterge_disciplina(const string nume_disciplina_de_sters) ;
	void genereaza_contract(const int numar_discipline);
	void export_in_fisier(string nume_fisier);
	string toString();
	vector<Disciplina> get_all();
	const int size();

};