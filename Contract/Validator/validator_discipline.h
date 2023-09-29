#pragma once
#include <string>
#include <exception>
#include <stdexcept>
#include "../Domain/disciplina.h"
using namespace std;
class Validator {
public:
	void valideaza_disciplina(Disciplina disciplina);
};