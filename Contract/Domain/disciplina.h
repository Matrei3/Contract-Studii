#pragma once
#include <string>
#include <iostream>
using namespace std;
class Disciplina {
private:
	string denumire;
	int numar_ore;
	string tip;
	string cadru_didactic;
public:
	Disciplina():denumire(""),numar_ore(0),tip(""),cadru_didactic(""){}
	Disciplina(const string denumire, const int numar_ore, const string tip, const string cadru_didactic) :denumire{ denumire }, numar_ore{ numar_ore }, tip{ tip }, cadru_didactic{ cadru_didactic }{}
	bool operator<(const Disciplina& other) const {
		return denumire < other.get_denumire();
	}
	string get_denumire() const;
	int get_numar_ore() const noexcept;
	string get_tip_materie() const;
	string get_cadru_didactic() const;
	void set_numar_ore(int numar_nou_ore) noexcept;
	void set_tip_materie(string tip_nou_materie);
	void set_cadru_didactic(string cadru_nou_didactic);

};