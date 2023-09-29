#pragma once
#include <iostream>
#include "../Service/service_discipline.h"
#include "../Service/service_contract.h"
using namespace std;
class User_Interface {
private:
	Service_Discipline& service_discipline;
	Service_Contract& service_contract;
public:
	User_Interface(Service_Discipline& service_discipline, Service_Contract& service_contract) :service_discipline{ service_discipline }, service_contract{ service_contract } {
	}
	User_Interface(const User_Interface& ot) = delete;
	void meniu();
	void ui_adauga_disciplina();
	void ui_modifica_disciplina();
	void ui_sterge_disciplina();
	void ui_undo();
	void ui_print_all();
	void ui_filtrare_dupa_numar_ore();
	void ui_filtrare_dupa_cadru_didactic();
	void ui_sortare_dupa_denumire();
	void ui_sortare_dupa_numar_ore();
	void ui_sortare_dupa_cadru_didactic_si_tip();
	void run();
	void ui_numar_discipline_din_contract();
	void ui_adauga_disciplina_contract();
	void ui_goleste_contract();
	void ui_genereaza_contract();
	void ui_export_contract_fisier();
	void ui_filtrare_map();
};