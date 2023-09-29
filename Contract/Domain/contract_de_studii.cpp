#include "contract_de_studii.h"
const int ContractStudii::get_numar_discipline() noexcept{
	return numar_discipline;
}
void ContractStudii::adauga_disciplina(const Disciplina materie_de_adaugat) {
	DisciplineContract.push_back(materie_de_adaugat);
	numar_discipline++;
}
const bool ContractStudii::sterge_disciplina(const string nume_materie_de_sters) {
	if (numar_discipline == 0)
		return false;
	for(auto i=DisciplineContract.begin();i!=DisciplineContract.end();++i)
		if (nume_materie_de_sters == i->get_denumire())
		{
			DisciplineContract.erase(i);
			numar_discipline--;
			return true;
		}
	return false;
}
void ContractStudii::genereaza_contract(const int numar_discipline_de_generat) {
	vector<Disciplina>random;
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
	Disciplina d10("Metode avansate de programare", 4, "Alternativ", "Marcel Gergel");
	Disciplina d11("Baze de date", 4, "Saptamanal", "Beldean Razvan");
	Disciplina d12("Programare logica si functionala", 6, "Saptamanal", "Pop Bogdan");
	Disciplina d13("Probabilitati si statistica", 4, "Alternativ", "Morar Horea");
	Disciplina d14("Retele de calculatoare", 4, "Saptamanal", "Pintea George");
	Disciplina d15("Ingineria sistemelor soft", 4, "Alternativ", "Mocut Raul");
	Disciplina d16("Sisteme de gestiune a bazelor de date", 6, "Saptamanal", "Erhan Bianca");
	Disciplina d17("Inteligenta artificiala", 6, "Saptamanal", "Gergel Marcel");
	Disciplina d18("Programare Web", 4, "Saptamanal", "Baidoc Alexandru");
	Disciplina d19("Medii de proiectare si programare", 6, "Saptamanal", "Anton Radu");
	random.push_back(d);
	random.push_back(d1);
	random.push_back(d2);
	random.push_back(d3);
	random.push_back(d4);
	random.push_back(d5);
	random.push_back(d6);
	random.push_back(d7);
	random.push_back(d8);
	random.push_back(d9);
	random.push_back(d10);
	random.push_back(d11);
	random.push_back(d12);
	random.push_back(d13);
	random.push_back(d14);
	random.push_back(d15);
	random.push_back(d16);
	random.push_back(d17);
	random.push_back(d18);
	random.push_back(d19);
	auto seed = chrono::system_clock::now().time_since_epoch().count();
	shuffle(random.begin(), random.end(),default_random_engine(seed));
	while (!DisciplineContract.empty()) {
		DisciplineContract.pop_back();
	}
	int j = 0;
	for (auto i = random.begin();i != random.end();++i)
	{
		if (j < numar_discipline_de_generat)
		{
			DisciplineContract.push_back(*i);
			j++;
		}
		else
			break;
		
	}
	numar_discipline = numar_discipline_de_generat;
}
string ContractStudii::toString() {
	string mesaj;
	for (auto i = DisciplineContract.begin();i != DisciplineContract.end();++i)
	{
		string nr_ore = to_string(i->get_numar_ore());
		mesaj = mesaj + i->get_denumire() + ',' + nr_ore + ',' + i->get_tip_materie() + ',' + i->get_cadru_didactic() + '\n';
	}
	return mesaj;
}
void ContractStudii::export_in_fisier(string nume_fisier) {
	nume_fisier += ".csv";
	ofstream fisier;
	fisier.open(nume_fisier);
	fisier << toString();
	fisier.close();
}
vector<Disciplina> ContractStudii::get_all() {
	return DisciplineContract;
}
const int ContractStudii::size() {
	return numar_discipline;
}
