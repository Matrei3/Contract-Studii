#include "user_interface.h"

void User_Interface::meniu() {
	cout << "					~Gestiune Contracte de Studii~\n\n";
	cout << "			1) Adauga disciplina.				a) Adauga disciplina contract.\n";				
	cout << "			2) Modifica disciplina.				b) Goleste contract.\n";
	cout << "			3) Sterge disciplina.				c) Genereaza contract.\n";
	cout << "			x) Undo. 					d) Export contract.\n";
	cout << "			4) Afiseaza discipline.\n";
	cout << "			5) Filtrare dupa cadru didactic.\n";
	cout << "			6) Filtrare dupa numar de ore.\n";
	cout << "			7) Sortare dupa denumire.\n";
	cout << "			8) Sortare dupa numar de ore.\n";
	cout << "			9) Sortare dupa cadru didactic si tip.\n";
	cout << "			10) Filtrare map.\n";
	cout << "			0) Exit.\n";
	
}
void User_Interface::ui_adauga_disciplina() {
	string nume_disciplina, tip, cadru_didactic,numar_ore;
	cout << "Introdu numele disciplinei: ";
	getline(cin,nume_disciplina,'\n');
	cout << "Introdu numarul de ore ale disciplinei: ";
	getline(cin, numar_ore, '\n');
	cout << "Introdu tipul disciplinei (Saptamanal/Alternativ): ";
	getline(cin, tip, '\n');
	cout << "Introdu profesorul disciplinei: ";
	getline(cin, cadru_didactic, '\n');
	const int numar_ore_int = stoi(numar_ore);
	service_discipline.service_adauga_disciplina(nume_disciplina, numar_ore_int, tip, cadru_didactic);

}
void User_Interface::ui_modifica_disciplina() {
	string nume_de_modificat,tip_de_modificat,cadru_de_modificat, numar_ore_de_modificat;
	cout << "Introdu numele disciplinei pt. modificare: ";
	getline(cin, nume_de_modificat, '\n');
	if(service_discipline.service_cauta_disciplina(nume_de_modificat)==true)
	{
		cout << "Introdu nr. de ore pt. modificare: ";
		getline(cin, numar_ore_de_modificat, '\n');
		cout << "Introdu tipul disciplinei pt. modificare (Saptamanal/Alternativ): ";
		getline(cin, tip_de_modificat, '\n');
		cout << "Introdu numele cadrului pt. modificare: ";
		getline(cin, cadru_de_modificat, '\n');
		const int numar_ore_de_modificat_int = stoi(numar_ore_de_modificat);
		if (service_discipline.service_modifica_disciplina(nume_de_modificat, numar_ore_de_modificat_int, tip_de_modificat, cadru_de_modificat) == true)
			cout << "Modificare realizata cu succes!\n";
		else
			cout << "Nu s-a efectuat modificarea! :(\n";
	}
	else
		cout << "Nu s-a efectuat modificarea! :(\n";
}
void User_Interface::ui_sterge_disciplina() {
	string nume_de_sters;
	cout << "Introdu numele disciplinei pt. stergere: ";
	getline(cin, nume_de_sters, '\n');
	if(service_discipline.service_sterge_disciplina(nume_de_sters)==true)
		cout << "Stergere realizata cu succes!\n";
	else
		cout << "Nu s-a efectuat stergerea! :(\n";
}
void User_Interface::ui_undo() {
	try {
		service_discipline.undo();
	}
	catch (const exception& ex) {
		cout << ex.what() << "\n";
	}
	cout << "S-a realizat undo la ultima operatie.\n";
}
void User_Interface::ui_print_all() {
	vector<Disciplina> all = service_discipline.service_get_all();
	for (auto i = all.begin();i != all.end();++i)
	{
		cout << "Nume disciplina: " << i->get_denumire()<<"\n";
		cout << "Numar ore disciplina: " << i->get_numar_ore() << "\n";
		cout << "Tip disciplina: " << i->get_tip_materie() << "\n";
		cout << "Nume profesor: " << i->get_cadru_didactic() << "\n\n";

	}
}
void  User_Interface::ui_filtrare_dupa_numar_ore() {
	string numar_ore_filtrare;
	cout << "Introdu numarul de ore pt. filtrare: ";
	getline(cin, numar_ore_filtrare, '\n');
	const int numar_ore_filtrare_int = stoi(numar_ore_filtrare);
	vector<Disciplina> all = service_discipline.filtrare_ore(numar_ore_filtrare_int);
	for (auto i = all.begin();i != all.end();++i)
	{
		cout << "Nume disciplina: " << i->get_denumire() << "\n";
		cout << "Numar ore disciplina: " << i->get_numar_ore() << "\n";
		cout << "Tip disciplina: " << i->get_tip_materie() << "\n";
		cout << "Nume profesor: " << i->get_cadru_didactic() << "\n\n";

	}
}
void  User_Interface::ui_filtrare_dupa_cadru_didactic() {
	string cadru_didactic;
	cout << "Introdu numarul de ore pt. filtrare: ";
	getline(cin, cadru_didactic, '\n');
	vector<Disciplina> all = service_discipline.filtrare_cadru_didactic(cadru_didactic);
	for (auto i = all.begin();i != all.end();++i)
	{
		cout << "Nume disciplina: " << i->get_denumire() << "\n";
		cout << "Numar ore disciplina: " << i->get_numar_ore() << "\n";
		cout << "Tip disciplina: " << i->get_tip_materie() << "\n";
		cout << "Nume profesor: " << i->get_cadru_didactic() << "\n\n";

	}
}
void User_Interface::ui_sortare_dupa_denumire() {
	vector<Disciplina> all = service_discipline.sortare_denumire();
	for (auto i = all.begin();i != all.end();++i)
	{
		cout << "Nume disciplina: " << i->get_denumire() << "\n";
		cout << "Numar ore disciplina: " << i->get_numar_ore() << "\n";
		cout << "Tip disciplina: " << i->get_tip_materie() << "\n";
		cout << "Nume profesor: " << i->get_cadru_didactic() << "\n\n";

	}
}
void User_Interface::ui_sortare_dupa_numar_ore() {
	vector<Disciplina> all = service_discipline.sortare_nr_ore();
	for (auto i = all.begin();i != all.end();++i)
	{
		cout << "Nume disciplina: " << i->get_denumire() << "\n";
		cout << "Numar ore disciplina: " << i->get_numar_ore() << "\n";
		cout << "Tip disciplina: " << i->get_tip_materie() << "\n";
		cout << "Nume profesor: " << i->get_cadru_didactic() << "\n\n";

	}
}
void User_Interface::ui_sortare_dupa_cadru_didactic_si_tip() {
	vector<Disciplina> all = service_discipline.sortare_cadru_didactic_si_tip();
	for (auto i = all.begin();i != all.end();++i)
	{
		cout << "Nume disciplina: " << i->get_denumire() << "\n";
		cout << "Numar ore disciplina: " << i->get_numar_ore() << "\n";
		cout << "Tip disciplina: " << i->get_tip_materie() << "\n";
		cout << "Nume profesor: " << i->get_cadru_didactic() << "\n\n";

	}
}
void  User_Interface::ui_numar_discipline_din_contract() {
	cout << "Numar discipline din contract: " << service_contract.size() << "\n";
}
void  User_Interface::ui_adauga_disciplina_contract() {
	string nume_disciplina;
	cout << "Nume disciplina de adaugat: ";
	getline(cin, nume_disciplina, '\n');
	if (service_contract.service_adauga_disciplina_contract(nume_disciplina) == true)
		cout << "Disciplina adaugata in contract!\n";
	else
		cout << "Disciplina nu a fost adaugata!\n";
}
void User_Interface::ui_goleste_contract() {
	try {
		service_contract.service_goleste_contract();
	}
	catch (const exception& ex)
	{
	cout << ex.what();
	return;
	}
	cout << "Contract golit!\n";
}
void User_Interface::ui_genereaza_contract() {
	string numar_discipline;
	cout << "Numar discipline pt. generare: ";
	getline(cin, numar_discipline, '\n');
	const int numar_discipline_int = stoi(numar_discipline);
	try {
		service_contract.service_genereaza_contract(numar_discipline_int);
	}
	catch (const exception& ex) {
		cout << ex.what();
		return;
	}
	cout << "Contract generat cu succes!\n";
}
void User_Interface::ui_export_contract_fisier() {
	string nume_fisier;
	cout << "Nume fisier pt. export: ";
	getline(cin, nume_fisier, '\n');
	try {
		service_contract.service_export_fisier(nume_fisier);
	}
	catch (const exception& ex) {
		cout << ex.what();
		return;
	}
	cout << "Exportul in fisierul " << nume_fisier << ".csv s-a realizat cu succes!\n";
}
void User_Interface::ui_filtrare_map() {
	map<string, int> rez = service_discipline.service_filtrare_map();
	map<string, int>::iterator it = rez.begin();
	while(it!=rez.end())
	{
		cout << it->first << " " << it->second << "\n";
		it++;
	}
}
void User_Interface::run() {
	meniu();
	while (true) {
		cout << "Comanda: ";
		string comanda;
		getline(cin, comanda, '\n');
		cout << "\n";
		if (comanda == "1")
			ui_adauga_disciplina();
		else if (comanda == "2")
			ui_modifica_disciplina();
		else if (comanda == "3")
			ui_sterge_disciplina();
		else if (comanda == "x")
			ui_undo();
		else if (comanda == "4")
			ui_print_all();
		else if (comanda == "5")
			ui_filtrare_dupa_cadru_didactic();
		else if (comanda == "6")
			ui_filtrare_dupa_numar_ore();
		else if (comanda == "7")
			ui_sortare_dupa_denumire();
		else if (comanda == "8")
			ui_sortare_dupa_numar_ore();
		else if (comanda == "9")
			ui_sortare_dupa_cadru_didactic_si_tip();
		else if (comanda == "10")
			ui_filtrare_map();
		else if (comanda == "a")
			ui_adauga_disciplina_contract();
		else if (comanda == "b")
			ui_goleste_contract();
		else if (comanda == "c")
			ui_genereaza_contract();
		else if (comanda == "d")
			ui_export_contract_fisier();
		else if (comanda == "0")
			return;
		else cout << "Comanda invalida!\n";
		ui_numar_discipline_din_contract();
	}
	
}