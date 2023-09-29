#include <iostream>
#include "disciplina.h"
using namespace std;
string Disciplina::get_denumire() const{
	return this->denumire;
}
int Disciplina::get_numar_ore() const noexcept{
	return this->numar_ore;
}
string Disciplina::get_tip_materie() const {
	return this->tip;
}
string Disciplina::get_cadru_didactic() const {
	return this->cadru_didactic;
}
void Disciplina::set_numar_ore(int numar_nou_ore) noexcept{
	this->numar_ore = numar_nou_ore;
}
void Disciplina::set_tip_materie(string tip_nou_materie) {
	this->tip = tip_nou_materie;
}
void Disciplina::set_cadru_didactic(string cadru_nou_didactic) {
	this->cadru_didactic = cadru_nou_didactic;
}




