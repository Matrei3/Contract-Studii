#include "repo.h"
using namespace std;

void Repository_Lab::adauga_disciplina(const Disciplina& disciplina) {
	if (discipline.find(disciplina.get_denumire()) != discipline.end())
		throw runtime_error("Disciplina exista deja!\n");
	else {
		discipline[disciplina.get_denumire()] = disciplina;
	}
}
const bool Repository_Lab::sterge_disciplina(string nume_disciplina) {
	if (discipline.find(nume_disciplina) == discipline.end())
		return false;
	else {
		discipline.erase(nume_disciplina);
		return true;}}
const bool Repository_Lab::modifica_disciplina(string nume_disciplina, int numar_ore_nou, string tip_nou, string cadru_nou) {
	if (discipline.find(nume_disciplina) == discipline.end())
		return false;
	else {
		Disciplina d(nume_disciplina, numar_ore_nou, tip_nou, cadru_nou);
		discipline.at(nume_disciplina)=d;
		return true;}}
const bool Repository_Lab::cauta_disciplina(string nume_disciplina) {
	return discipline.find(nume_disciplina) != discipline.end();
}
const vector<Disciplina> Repository_Lab::get_all()  {
	vector<Disciplina> toate;
	for (auto& cheie : discipline)
		toate.push_back(cheie.second);
	return toate;
}