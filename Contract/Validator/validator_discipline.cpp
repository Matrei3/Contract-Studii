#include "validator_discipline.h"

using namespace std;
void Validator::valideaza_disciplina(Disciplina disciplina) {
	string mesaj;
	if (disciplina.get_denumire() == "")
		mesaj += "Denumire invalida!\n";
	if (disciplina.get_numar_ore() <= 0)
		mesaj += "Numar ore invalid!\n";
	if (disciplina.get_tip_materie() == "Saptamanal" or disciplina.get_tip_materie() == "Alternativ") {
	}
	else
		mesaj += "Tip materie invalid!\n";
	if (disciplina.get_cadru_didactic() == "")
		mesaj += "Cadru didactic invalid!\n";
	if (mesaj.size() != 0)
		throw runtime_error(mesaj);
}