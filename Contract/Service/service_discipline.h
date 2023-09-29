#pragma once
#include "../Repository/repository_discipline.h"
#include "../Validator/validator_discipline.h"
#include <algorithm>
#include <map>
#include "undo.h"
#include <functional>
using namespace std;
using std::function;

class Service_Discipline {
private:
	Repository_Discipline& service_discipline;
	Validator& vali;
	vector<unique_ptr<Undo>> actiune_undo;
public:
	Service_Discipline(Repository_Discipline& repo, Validator& vali) :service_discipline{ repo },vali{vali}{
		
	}
	Service_Discipline(const Service_Discipline& alt) = delete;
	void service_adauga_disciplina(string nume_disciplina, int numar_ore, string tip, string cadru_didactic);
	bool service_cauta_disciplina(string nume_disciplina);
	bool service_sterge_disciplina(string nume_disciplina);
	bool service_modifica_disciplina(string nume_disciplina, int numar_ore_nou, string tip_nou, string cadru_nou);
	vector<Disciplina> service_get_all();
	vector<Disciplina> service_sortare(bool (*criteriu)(const Disciplina& a, const Disciplina& b));
	vector<Disciplina> service_filtrare(function<bool(const Disciplina&)> criteriu);
	vector<Disciplina> filtrare_ore(int numar_ore_filtrare);
	vector<Disciplina> filtrare_cadru_didactic(string cadru_didactic_filtrare);
	vector<Disciplina> sortare_denumire();
	vector<Disciplina> sortare_nr_ore();
	vector<Disciplina> sortare_cadru_didactic_si_tip();
	map<string, int> service_filtrare_map();
	void service_export_fisier();
	void undo();
};
bool denumire(const Disciplina& a, const Disciplina& b);
bool nr_ore(const Disciplina& a, const Disciplina& b);
bool cadru_didactic_si_tip(const Disciplina& a, const Disciplina& b);

