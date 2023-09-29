#include "teste.h"
#include <iostream>
#include <exception>
#include <cassert>

void Teste::teste_domain() {
	Disciplina d("Algebra",4,"Saptamanal","Modoi George");
	assert(d.get_cadru_didactic() == "Modoi George");
	assert(d.get_denumire() == "Algebra");
	assert(d.get_numar_ore() == 4);
	assert(d.get_tip_materie() == "Saptamanal");
	d.set_cadru_didactic("Orzan Alexandru");
	d.set_numar_ore(2);
	d.set_tip_materie("Alternativ");
	assert(d.get_cadru_didactic() == "Orzan Alexandru");
	assert(d.get_numar_ore() == 2);
	assert(d.get_tip_materie() == "Alternativ");
}
void Teste::teste_repository() {
	Disciplina d("Algebra", 4, "Saptamanal", "Modoi George");
	Disciplina d1("Analiza", 4, "Saptamanal", "Berinde Stefan");
	Disciplina d2("Logica Computationala", 4, "Saptamanal", "Pop Andreea");
	Disciplina d3("Sisteme Dinamice", 4, "Alternativ", "Minuta Aurelian");
	Repository_Discipline repo;
	assert(repo.get_all().size() == 0);
	repo.adauga_disciplina(d);
	assert(repo.get_all().size() == 1);
	repo.adauga_disciplina(d1);
	repo.adauga_disciplina(d2);
	repo.adauga_disciplina(d3);
	assert(repo.get_all().size() == 4);
	assert(repo.modifica_disciplina("Analiza", 6, "Alternativ", "Gabi Mircea")==true);
	assert(repo.modifica_disciplina("Analizzza", 6, "Alternativ", "Gabi Mircea") == false);
	assert(repo.cauta_disciplina("Analiza") == true);
	assert(repo.cauta_disciplina("Analizzza") == false);
	assert(repo.sterge_disciplina("Analiza") == true);
	assert(repo.sterge_disciplina("Geometrie") == false);
	assert(repo.get_all().size() == 3);
}
void Teste::teste_service() {
	Repository_Discipline repo;
	Validator vali;
	Service_Discipline service_discipline(repo,vali);
	service_discipline.service_adauga_disciplina("Baze de date", 6, "Saptamanal", "Suciu Dan");
	service_discipline.service_adauga_disciplina("", 0, "", "");
	vector <Disciplina> all = service_discipline.service_get_all();
	assert(all.size() == 1);
	service_discipline.service_adauga_disciplina("Sisteme de operare", 6, "Alternativ", "Boian Rares");
	all = service_discipline.service_get_all();
	assert(all.size() == 2);
	assert(service_discipline.service_modifica_disciplina("Sisteme de operare", 4, "Saptamanal", "Bota Daniel")==true);
	assert(service_discipline.service_modifica_disciplina("Sisteme de operrrare", 4, "Saptamanal", "Bota Daniel") == false);
	assert(service_discipline.service_cauta_disciplina("Sisteme de operare") == true);
	assert(service_discipline.service_cauta_disciplina("Sisteme de ooperare") == false);
	service_discipline.service_adauga_disciplina("Baze de date 1", 4, "Saptamanal", "Suciu Dan");
	service_discipline.service_adauga_disciplina("Baze de date 2", 4, "Saptamanal", "Gergel Marcel");
	vector <Disciplina> all1 = service_discipline.filtrare_ore(4);
	assert(all1.size() == 3);
	vector <Disciplina> all2 = service_discipline.filtrare_cadru_didactic("Suciu Dan");
	assert(all2.size() == 2);
	assert(service_discipline.service_sterge_disciplina("Sisteme de operare") == true);
	assert(service_discipline.service_sterge_disciplina("Sisteme de operare") == false);
	assert(service_discipline.service_get_all().size() == 3);
	service_discipline.service_adauga_disciplina("Baze de date", 8, "Saptamanal", "Suciu Dan");
	assert(service_discipline.service_get_all().size() == 3);

	
}
void Teste::teste_sortare() {
	Repository_Discipline repo;
	Validator vali;
	Service_Discipline service_discipline(repo, vali);
	service_discipline.service_adauga_disciplina("Analiza Matematica", 6, "Saptamanal", "Berinde Stefan");
	service_discipline.service_adauga_disciplina("Algebra", 4, "Alternativ", "Modoi George");
	service_discipline.service_adauga_disciplina("Fundamentele Programarii", 8, "Saptamanal", "Czibula Istvan");
	service_discipline.service_adauga_disciplina("ASC", 8, "Alternativ", "Vancea Alexandru");
	service_discipline.service_adauga_disciplina("Logica Computationala", 4, "Saptamanal", "Pop Andreea");
	vector <Disciplina> sortare = service_discipline.sortare_denumire();
	map<string, int>filtrare = service_discipline.service_filtrare_map();
	assert(filtrare["Saptamanal"] == 3);
	assert(filtrare["Alternativ"] == 2);
	int nr = 0;
	for (auto i = sortare.begin();i < sortare.end();++i)
	{
		if (nr == 0)
			assert(i->get_denumire()=="ASC");
		if (nr == 1)
			assert(i->get_denumire() == "Algebra");
		if (nr == 2)
			assert(i->get_denumire() == "Analiza Matematica");
		if (nr == 3)
			assert(i->get_denumire() == "Fundamentele Programarii");
		if (nr == 4)
			assert(i->get_denumire() == "Logica Computationala");
		nr++;
	}
	vector <Disciplina> sortare1 = service_discipline.sortare_cadru_didactic_si_tip();
	nr = 0;
	for (auto i = sortare1.begin();i < sortare1.end();++i)
	{
		if (nr == 3)
			assert(i->get_denumire() == "Logica Computationala");
		if (nr == 0)
			assert(i->get_denumire() == "Analiza Matematica");
		if (nr == 2)
			assert(i->get_denumire() == "Algebra");
		if (nr == 4)
			assert(i->get_denumire() == "ASC");
		if (nr == 1)
			assert(i->get_denumire() == "Fundamentele Programarii");
		nr++;
	}
	vector <Disciplina> sortare2 = service_discipline.sortare_nr_ore();
	nr = 0;
	for (auto i = sortare2.begin();i < sortare2.end();++i)
	{
		if (nr == 3)
			assert(i->get_denumire() == "ASC");
		if (nr == 0)
			assert(i->get_denumire() == "Algebra");
		if (nr == 2)
			assert(i->get_denumire() == "Analiza Matematica");
		if (nr == 4)
			assert(i->get_denumire() == "Fundamentele Programarii");
		if (nr == 1)
			assert(i->get_denumire() == "Logica Computationala");
		nr++;
	}
	service_discipline.service_adauga_disciplina("OOP", 4, "Alternativ", "Czibula Istvan");
	vector <Disciplina> sortare3 = service_discipline.sortare_cadru_didactic_si_tip();
	nr = 0;
	for (auto i = sortare3.begin();i < sortare3.end();++i)
	{
		cout << i->get_denumire() << " " << i->get_tip_materie() << "\n";
		if (nr == 5)
			assert(i->get_denumire() == "ASC");
		if (nr == 3)
			assert(i->get_denumire() == "Algebra");
		if (nr == 0)
			assert(i->get_denumire() == "Analiza Matematica");
		if (nr == 2)
			assert(i->get_denumire() == "Fundamentele Programarii");
		if (nr == 4)
			assert(i->get_denumire() == "Logica Computationala");
		if(nr==1)
			assert(i->get_denumire() == "OOP");
		nr++;
	}

}
void Teste::teste_contract() {
	ContractStudii contract;
	assert(contract.get_numar_discipline() == 0);
	Disciplina d5("Geometrie 2", 4, "Saptamanal", "Blaga Paul");
	Disciplina d6("Sisteme de Operare", 4, "Alternativ", "Boian Rares");
	assert(contract.sterge_disciplina("Geomtrie") == false);
	contract.adauga_disciplina(d5);
	contract.adauga_disciplina(d6);
	assert(contract.get_numar_discipline() == 2);
	assert(contract.sterge_disciplina("Geometrie 2") == true);
	assert(contract.get_numar_discipline() == 1);
	assert(contract.sterge_disciplina("Geometrie 2") == false);
	assert(contract.get_numar_discipline() == 1);
	assert(contract.toString() == "Sisteme de Operare,4,Alternativ,Boian Rares\n");
	contract.genereaza_contract(6);
	assert(contract.get_numar_discipline() == 6);
	contract.adauga_disciplina(d5);
	assert(contract.size() == 7);
	assert(contract.get_all().size() == 7);
	contract.export_in_fisier("testfisier");
}
void Teste::teste_service_contract() {
	Disciplina d("Algebra", 4, "Saptamanal", "Modoi George");
	Disciplina d1("Analiza Matematica", 4, "Saptamanal", "Berinde Stefan");
	Disciplina d2("Fundamentele Programarii", 6, "Saptamanal", "Czibula Istvan");
	Disciplina d3("Logica Computationala", 4, "Saptamanal", "Pop Andreea");
	Disciplina d4("Arhitectura Sistemelor de Calcul", 6, "Saptamanal", "Vancea Alexandru");
	Disciplina d5("Geometrie", 4, "Saptamanal", "Blaga Paul");
	Disciplina d6("Sisteme de Operare", 4, "Alternativ", "Boian Rares");
	Disciplina d7("Sisteme Dinamice", 4, "Alternativ", "Serban Marcel");
	Disciplina d8("Structuri de Date si Algoritmi", 4, "Alternativ", "Czibula Gabriela");
	Disciplina d9("Programare Orientata Obiect", 4, "Alternativ", "Czibula Istvan");
	Repository_Discipline repo;
	repo.adauga_disciplina(d1);
	repo.adauga_disciplina(d2);
	repo.adauga_disciplina(d3);
	repo.adauga_disciplina(d4);
	repo.adauga_disciplina(d5);
	repo.adauga_disciplina(d6);
	
	ContractStudii contract;
	Service_Contract service_contract(repo, contract);
	assert(service_contract.size() == 0);
	try {
		service_contract.service_goleste_contract();
	}
	catch (const exception& ex) {
		cout << ex.what();
	}
	assert(service_contract.service_adauga_disciplina_contract("Analiza Matematica")==true);
	assert(service_contract.service_adauga_disciplina_contract("Analiza Matematica") == false);
	assert(service_contract.size() == 1);
	assert(service_contract.service_adauga_disciplina_contract("Inteligenta artificiala") == false);
	assert(service_contract.size() == 1);
	assert(service_contract.service_adauga_disciplina_contract("Geometrie") == true);
	
	service_contract.service_goleste_contract();
	assert(service_contract.size() == 0);
	service_contract.service_genereaza_contract(3);
	assert(service_contract.size() == 3);
	service_contract.service_export_fisier("fisiertest2");
	try {
		service_contract.service_genereaza_contract(0);
	}
	catch (const exception& ex) {
		cout << ex.what();
	}
	try {
		service_contract.service_export_fisier("");
	}
	catch (const exception& ex) {
		cout << ex.what();
	}

}
void Teste::teste_undo() {
	Disciplina d("Algebra", 4, "Saptamanal", "Modoi George");
	Disciplina d1("Analiza Matematica", 4, "Saptamanal", "Berinde Stefan");
	Disciplina d2("Fundamentele Programarii", 6, "Saptamanal", "Czibula Istvan");
	Disciplina d3("Logica Computationala", 4, "Saptamanal", "Pop Andreea");
	Disciplina d4("Arhitectura Sistemelor de Calcul", 6, "Saptamanal", "Vancea Alexandru");
	Repository_Discipline repo;
	Validator vali;
	Service_Discipline service_discipline(repo, vali);
	try {
		service_discipline.undo();
	}
	catch (...) {
		assert(true);
	}
	service_discipline.service_adauga_disciplina("Algebra", 4, "Saptamanal", "Modoi George");
	vector <Disciplina> all = service_discipline.service_get_all();
	assert(all.size() == 1);
	service_discipline.undo();
	vector <Disciplina> all1 = service_discipline.service_get_all();
	assert(all1.size() == 0);
	service_discipline.service_adauga_disciplina("Algebra", 4, "Saptamanal", "Modoi George");
	Disciplina disc = service_discipline.service_get_all().back();
	assert(disc.get_cadru_didactic() == "Modoi George");
	service_discipline.service_modifica_disciplina("Algebra", 8, "Alternativ", "Orzan Alexandru");
	Disciplina disc2 = service_discipline.service_get_all().back();
	assert(disc2.get_cadru_didactic() == "Orzan Alexandru");
	service_discipline.undo();
	Disciplina disc3 = service_discipline.service_get_all().back();
	assert(disc3.get_cadru_didactic() == "Modoi George");
	service_discipline.service_sterge_disciplina("Algebra");
	vector <Disciplina> all3 = service_discipline.service_get_all();
	assert(all3.size() == 0);
	service_discipline.undo();
	vector <Disciplina> all13 = service_discipline.service_get_all();
	assert(all13.size() == 1);
}
void Teste::teste_repo_lab() {
	Repository_Lab repo(0.33);
	try {
		throw repo;
	}
	catch (Repository_Lab b) {
		assert(repo.get_prob() == 0.33);
	}
	Disciplina d("Algebra", 4, "Saptamanal", "Modoi George");
	Disciplina d1("Analiza", 4, "Saptamanal", "Berinde Stefan");
	Disciplina d2("Logica Computationala", 4, "Saptamanal", "Pop Andreea");
	Disciplina d3("Sisteme Dinamice", 4, "Alternativ", "Minuta Aurelian");
	assert(repo.get_all().size() == 0);
	repo.adauga_disciplina(d);
	assert(repo.get_all().size() == 1);
	repo.adauga_disciplina(d1);
	try {
		repo.adauga_disciplina(d1);
	}
	catch (const exception& ex) {
		string nume = ex.what();
		assert(nume == "Disciplina exista deja!\n");
	}
	repo.adauga_disciplina(d2);
	repo.adauga_disciplina(d3);
	assert(repo.get_all().size() == 4);
	assert(repo.modifica_disciplina("Analiza", 6, "Alternativ", "Gabi Mircea") == true);
	assert(repo.modifica_disciplina("Analizzza", 6, "Alternativ", "Gabi Mircea") == false);
	assert(repo.cauta_disciplina("Analiza") == true);
	assert(repo.cauta_disciplina("Analizzza") == false);
	assert(repo.sterge_disciplina("Analiza") == true);
	assert(repo.sterge_disciplina("Geometrie") == false);
	assert(repo.get_all().size() == 3);
}
void Teste::testeaza_tot() {
	teste_domain();
	teste_repository();
	teste_service();
	teste_sortare();
	teste_contract();
	teste_service_contract();
	teste_undo();
	teste_repo_lab();
	cout << "Merg testele boss!\n";
	system("cls");
}