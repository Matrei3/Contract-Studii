#include "service_discipline.h"
#include <exception>
#include<iostream>
#include <cassert>
#include <QDebug>
using namespace std;
void Service_Discipline::service_adauga_disciplina(string nume_disciplina, int numar_ore, string tip, string cadru_didactic) {
	Disciplina disciplina_de_adaugat(nume_disciplina, numar_ore, tip, cadru_didactic);
	Validator validator;
	try{
		validator.valideaza_disciplina(disciplina_de_adaugat);
	}
	catch (const exception& ex) {
		cout << "Adaugare nereusita!\nCauze:\n";
		cout << ex.what() << "\n";
		return;}
	
	
	try {
		service_discipline.adauga_disciplina(disciplina_de_adaugat);
		actiune_undo.push_back(make_unique<UndoAdauga>(service_discipline, disciplina_de_adaugat));
	}
	catch (const exception& ex)
	{
		cout << ex.what();
		return;}
	
	cout << "Adaugare reusita!\n";
}
bool Service_Discipline::service_cauta_disciplina(string nume_disciplina) {
	return service_discipline.cauta_disciplina(nume_disciplina);
}
bool Service_Discipline::service_sterge_disciplina(string nume_disciplina) {
	if(service_discipline.cauta_disciplina(nume_disciplina))
	{	for(const auto& disc: service_discipline.get_all())
			if(disc.get_denumire()==nume_disciplina)
			{
				actiune_undo.push_back(make_unique<UndoSterge>(service_discipline, disc));
				break;
			}
	}
	return service_discipline.sterge_disciplina(nume_disciplina);
}
bool Service_Discipline::service_modifica_disciplina(string nume_disciplina, int numar_ore_nou, string tip_nou, string cadru_nou) {
	if (service_discipline.cauta_disciplina(nume_disciplina))
	{
		for (const auto& disc : service_discipline.get_all())
			if (disc.get_denumire() == nume_disciplina)
			{
				actiune_undo.push_back(make_unique<UndoModifica>(service_discipline, disc));
				break;
			}
	}
	return service_discipline.modifica_disciplina(nume_disciplina,numar_ore_nou,tip_nou,cadru_nou);
}
vector<Disciplina> Service_Discipline::service_filtrare(function<bool(const Disciplina&)> criteriu) {
	vector<Disciplina> lista;
	for(const auto& disciplina: service_discipline.get_all())
		if (criteriu(disciplina)) {
			lista.push_back(disciplina);
		}
	return lista;
}
vector<Disciplina> Service_Discipline::filtrare_ore(int numar_ore_filtrare) {
	return service_filtrare([numar_ore_filtrare](const Disciplina& d) {
		return d.get_numar_ore() == numar_ore_filtrare;
		});
}
vector<Disciplina> Service_Discipline::filtrare_cadru_didactic(string nume_cadru_filtrare) {
	return service_filtrare([nume_cadru_filtrare](const Disciplina& d) {
		return d.get_cadru_didactic() == nume_cadru_filtrare;
		});
}

vector<Disciplina> Service_Discipline::service_get_all() {
	return service_discipline.get_all();
}
bool denumire(const Disciplina& a, const Disciplina& b)
{
	return a.get_denumire() < b.get_denumire();
}
bool nr_ore(const Disciplina& a, const Disciplina& b)
{
	if (a.get_numar_ore() == b.get_numar_ore())
	return a.get_denumire() < b.get_denumire();
	return a.get_numar_ore() < b.get_numar_ore();
}
bool cadru_didactic_si_tip(const Disciplina& a, const Disciplina& b)
{
	if (a.get_cadru_didactic() == b.get_cadru_didactic())
		return a.get_tip_materie() < b.get_tip_materie();
	return a.get_cadru_didactic() <  b.get_cadru_didactic();
}
vector<Disciplina> Service_Discipline::service_sortare(bool functie(const Disciplina& a, const Disciplina& b)) {
	vector<Disciplina> lista = service_discipline.get_all();
	sort(lista.begin(), lista.end(), functie);
	return lista;
}
vector<Disciplina> Service_Discipline::sortare_denumire() {
	return service_sortare(denumire);
}
vector<Disciplina> Service_Discipline::sortare_nr_ore() {
	return service_sortare(nr_ore);
}
vector<Disciplina> Service_Discipline::sortare_cadru_didactic_si_tip() {
	return service_sortare(cadru_didactic_si_tip);
}
map<string,int> Service_Discipline::service_filtrare_map() {
	map<string, int>filtrare;
	for (auto materie : service_discipline.get_all())
			filtrare[materie.get_tip_materie()] ++;
	return filtrare;
}
void Service_Discipline::service_export_fisier() {
	service_discipline.export_in_fisier();
}
void Service_Discipline::undo() {
	if (actiune_undo.empty())
		throw runtime_error("Nu mai exista operatii.\n");
	actiune_undo.back()->doUndo();
	actiune_undo.pop_back();
}
