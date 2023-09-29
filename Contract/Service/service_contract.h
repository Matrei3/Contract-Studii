#pragma once
#include "../Repository/repository_discipline.h"
#include "../Validator/validator_discipline.h"
#include "../Domain/contract_de_studii.h"
#include "undo.h"
#include <map>
#include "../UI/observer.cpp"
using namespace std;
class Service_Contract: public Observable {
private:
	Repository_Discipline& repo_discipline;
	ContractStudii& contract;
public:
	Service_Contract(Repository_Discipline& repo, ContractStudii& contract_studii) :repo_discipline{ repo }, contract{ contract_studii } {

	}
	bool service_adauga_disciplina_contract(string nume_disciplina);
	void service_goleste_contract();
	int size();
	void service_genereaza_contract(int numar_discipline);
	void service_export_fisier(string nume_fisier);
	vector<Disciplina> service_get_all() {
		return contract.get_all();
	}
};