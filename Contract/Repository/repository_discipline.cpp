#include "repository_discipline.h"
#include <qdebug.h>
void Repository_Discipline::adauga_disciplina(const Disciplina& disciplina) {
	for (auto i = discipline.begin();i != discipline.end();++i)
		if (i->get_denumire() == disciplina.get_denumire())
			throw runtime_error("Disciplina exista deja!\n");
	discipline.push_back(disciplina);
	export_in_fisier();
}
const bool Repository_Discipline::sterge_disciplina(string nume_disciplina) {
	for (auto i = discipline.begin();i != discipline.end();++i)
		if (i->get_denumire() == nume_disciplina)
		{
			discipline.erase(i);
			export_in_fisier();
			return true;
		}
	return false;

}
const bool Repository_Discipline::modifica_disciplina(string nume_disciplina,int numar_ore_nou,string tip_nou,string cadru_nou) {
	for (auto i = discipline.begin();i != discipline.end();++i)
		if (i->get_denumire() == nume_disciplina and (tip_nou == "Saptamanal" or tip_nou == "Alternativ"))
		{
			i->set_numar_ore(numar_ore_nou);
			i->set_tip_materie(tip_nou);
			i->set_cadru_didactic(cadru_nou);
			export_in_fisier();
			return true;
		}
	return false;
}
const bool Repository_Discipline::cauta_disciplina(string nume_disciplina) const{
	for (auto i = discipline.begin();i != discipline.end();++i)
		if (i->get_denumire() == nume_disciplina)
			return true;
	return false;
}
const vector<Disciplina> Repository_Discipline::get_all() const noexcept{
	return discipline;
}
void Repository_Discipline::export_in_fisier() {
	string mesaj;
	ofstream iesire;
	iesire.open("baza_de_date.txt", ios::out);
	for (const auto& disciplina : discipline)
	{
		string nr_ore = to_string(disciplina.get_numar_ore());
		mesaj = mesaj + disciplina.get_denumire() + ',' + nr_ore + ',' + disciplina.get_tip_materie() + ',' + disciplina.get_cadru_didactic() + '\n';
	}
	iesire<< mesaj;
}
vector<string> split(string str) {
	// declaring temp string to store the curr "word" upto del
	string temp = "";
	vector<string> rez;
	for (int i = 0; i < (int)str.size(); i++) {
		// If cur char is not del, then append it to the cur "word", otherwise
		  // you have completed the word, print it, and start a new word.
		if (str[i] != ',') {
			temp += str[i];
		}
		else {
			rez.push_back(temp);
			temp = "";
		}
	}
	rez.push_back(temp);
	return rez;
}
void  Repository_Discipline::load_from_file() {
	string linie;
	ifstream citire;
	citire.open("baza_de_date.txt", ios::in);
	while (getline(citire, linie)) {
		vector<string> rez = split(linie);
		string nume = rez[0];
		string ore = rez[1];
		string tip = rez[2];
		string prof = rez[3];
		int nr_ore = stoi(ore);
		Disciplina d(nume, nr_ore, tip, prof);
		discipline.push_back(d);
	}
	citire.close();
}