#pragma once
#include "../Domain/disciplina.h"
#include "../Domain/contract_de_studii.h"
#include "../Repository/repository_discipline.h"
#include "../Service/service_discipline.h"
#include "../Service/service_contract.h"
#include "../Repository/repo.h"
#include <vector>
#include <iostream>
class Teste {
public:
	void teste_domain();
	void teste_repository();
	void teste_service();
	void testeaza_tot();
	void teste_sortare();
	void teste_contract();
	void teste_service_contract();
	void teste_undo();
	void teste_repo_lab();
};