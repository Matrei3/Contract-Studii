#pragma once
#include "../Domain/disciplina.h"
#include "../Repository/repository_discipline.h"
class Undo {
public:
	virtual void doUndo() = 0;
	virtual ~Undo() = default;
};
class UndoAdauga : public Undo {
	Disciplina disciplina_adaugata;
	Repository_Discipline& repo;
public:
	UndoAdauga(Repository_Discipline& rep, const Disciplina& disc): repo{rep},disciplina_adaugata{disc} {}

	void doUndo() override{
		repo.sterge_disciplina(disciplina_adaugata.get_denumire());
	}
};
class UndoSterge : public Undo {
	Disciplina disciplina_stearsa;
	Repository_Discipline& repo;
public:
	UndoSterge(Repository_Discipline& rep, const Disciplina& disc) :repo{ rep }, disciplina_stearsa{ disc } {}

	void doUndo() override {
		repo.adauga_disciplina(disciplina_stearsa);
	}
};
class UndoModifica : public Undo {
	Disciplina disciplina_modificata;
	Repository_Discipline& repo;
public:
	UndoModifica(Repository_Discipline& rep, const Disciplina& disc) :repo{ rep }, disciplina_modificata{ disc } {}

	void doUndo() override {
		repo.modifica_disciplina(disciplina_modificata.get_denumire(),disciplina_modificata.get_numar_ore(),disciplina_modificata.get_tip_materie(),disciplina_modificata.get_cadru_didactic());
	}
};