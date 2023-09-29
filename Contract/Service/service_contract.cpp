#include "service_contract.h"

bool Service_Contract::service_adauga_disciplina_contract(string nume_disciplina_de_adaugat) {
	for (auto disciplina : contract.get_all()) {
		if (disciplina.get_denumire() == nume_disciplina_de_adaugat)
		{
			return false;
		}
	}
	for (auto disciplina: repo_discipline.get_all())
	{
		if (disciplina.get_denumire() == nume_disciplina_de_adaugat)
		{	
			contract.adauga_disciplina(disciplina);
			return true;
		}
	}
	return false;
}
int Service_Contract::size() {
	return contract.size();
}
void Service_Contract::service_goleste_contract() {
	if (contract.size() == 0)
	{
		throw runtime_error("Contractul e gol!\n");}
	else
	{
		vector<Disciplina> all = contract.get_all();
		for (auto i =all.begin();i != all.end();++i)
			contract.sterge_disciplina(i->get_denumire());
	}
}
void Service_Contract::service_genereaza_contract(int numar_discipline) {
	if (numar_discipline <= 0 or numar_discipline==NULL)
	{
		throw runtime_error("Numarul trebuie sa fie strict pozitiv!\n");}
	else {
		contract.genereaza_contract(numar_discipline);
	}
}
void Service_Contract::service_export_fisier(string nume_fisier) {
	if (nume_fisier == "")
	{
		throw runtime_error("Numele nu trebuie sa fie nul!\n");}
	
	else {
		contract.export_in_fisier(nume_fisier);
	}
}