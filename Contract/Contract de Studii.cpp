#include <iostream>
#include "Teste/teste.h"
#include "UI/user_interface.h"
#include "UI/qt_ui.cpp"
#include <stdlib.h>
#include <crtdbg.h>
#include <QApplication>
#include <qfont.h>
#include <QLabel>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QFormLayout>
#define _CRTDBG_MAP_ALLOC
int main(int argc, char** argv)
{
    QApplication a(argc, argv);
    Teste t;
    //t.testeaza_tot();
    Repository_Discipline repo_vector;
    ContractStudii contract;
    Validator vali;
    Service_Discipline service_discipline(repo_vector, vali);
    Service_Contract service_contract(repo_vector, contract);
    User_Interface_Qt ui(service_discipline, service_contract);
    ui.show();
    return a.exec();
}
