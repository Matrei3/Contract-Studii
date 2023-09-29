#include <qwidget.h>
#include "../Service/service_contract.h"
#include "../Service/service_discipline.h"
#include <QTableWidget>
#include <QPushButton>
#include <QLabel>
#include <QFormLayout>
#include <QLineEdit>
#include "../UI/observer.cpp"
using namespace std;

class Cos : public QWidget,public Observer {
private:
	vector<Disciplina> allDiscipline;
	vector<Disciplina> allContract;
	Service_Contract& service_contract;
	Service_Discipline& service_discipline;
	QTableWidget* lista_contract = new QTableWidget;
	QLabel* mat = new QLabel("Materie pentru adaugat:");
	QLabel* gen = new QLabel("Numar materii pentru generat:");
	QLabel* exp = new QLabel("Nume fisier pentru export:");
	QLineEdit* materie_de_adaugat = new QLineEdit;
	QLineEdit* generat = new QLineEdit;
	QLineEdit* export_line = new QLineEdit;
	QPushButton* add_contract = new QPushButton("&Adauga la contract");
	QPushButton* generate_contract = new QPushButton("&Genereaza contract");
	QPushButton* delete_contract = new QPushButton("&Goleste contract");
	QPushButton* export_contract = new QPushButton("&Export contract");
	QFormLayout* contract_layout = new QFormLayout;
	QFormLayout* contract_layout2 = new QFormLayout;
	QFormLayout* contract_line_layout = new QFormLayout;
public:
	void update() override {
		allContract = service_contract.service_get_all();
		allDiscipline = service_discipline.service_get_all();
		load(allContract, allDiscipline);
	}
	Cos(Service_Contract& service,Service_Discipline& service1) : service_contract(service),service_discipline(service1) {
		init();
		meniu();
		load(allContract,allDiscipline);
	}
	~Cos() {

		service_contract.removeObserver(this);
	}
	void meniu() {
		add_contract->adjustSize();
		delete_contract->adjustSize();
		generate_contract->adjustSize();
		export_contract->adjustSize();
		lista_contract->setColumnCount(4);
		this->setFixedSize(600, 600);
		QIcon meniu_icoana("icoana.ico");
		this->setWindowIcon(meniu_icoana);
		lista_contract->setEditTriggers(QAbstractItemView::NoEditTriggers);
		lista_contract->setSelectionBehavior(QAbstractItemView::SelectRows);
		lista_contract->setAlternatingRowColors(true);
		contract_layout->addWidget(add_contract);
		contract_layout->addWidget(delete_contract);
		contract_layout->addWidget(generate_contract);
		contract_layout->addWidget(export_contract);
		contract_line_layout->addRow(mat, materie_de_adaugat);
		contract_line_layout->addRow(gen, generat);
		contract_line_layout->addRow(exp, export_line);
		contract_layout->addRow(contract_line_layout);
		contract_layout->addRow(lista_contract);
		this->setLayout(contract_layout);

	}
	void init() {
		allContract = service_contract.service_get_all();
		allDiscipline = service_discipline.service_get_all();
		service_contract.addObserver(this);
		QObject::connect(add_contract, &QPushButton::clicked, [&]() {
			auto materie_adaugare = materie_de_adaugat->text();
			service_contract.service_adauga_disciplina_contract(materie_adaugare.toStdString());
			allContract = service_contract.service_get_all();
			load(allContract, allDiscipline);
			service_contract.notify();
			});
		QObject::connect(generate_contract, &QPushButton::clicked, [&]() {
			if(generat->text().toStdString().size()!=0)
			{
				auto nr_gen = generat->text();
				int nr = stoi(nr_gen.toStdString());
				try {
					service_contract.service_genereaza_contract(nr);
				}
				catch (exception& ex) {

				}

				allContract = service_contract.service_get_all();
				load(allContract, allDiscipline);
				service_contract.notify();
			}
			});
		QObject::connect(export_contract, &QPushButton::clicked, [&]() {
			auto nume_fisier = export_line->text();
			try {
				service_contract.service_export_fisier(nume_fisier.toStdString());
			}
			catch (exception& ex) {
				
			}
			});
		QObject::connect(delete_contract, &QPushButton::clicked, [&]() {
			try
			{
				service_contract.service_goleste_contract();
			}
			catch (exception& ex) {

			}
			allContract = service_contract.service_get_all();
			load(allContract, allDiscipline);
			service_contract.notify();
			});
	}
	void load(vector<Disciplina> allContract, vector<Disciplina> allDiscipline) {
		lista_contract->setRowCount(0);
		lista_contract->resizeRowsToContents();
		lista_contract->setHorizontalHeaderLabels({ "Nume","Nr. ore","Tip","Nume profesor" });
		int  rand1 = 0;
		for (auto disciplina : allContract)
		{
			lista_contract->insertRow(rand1);
			lista_contract->setItem(rand1, 0, new QTableWidgetItem(QString::fromStdString(disciplina.get_denumire())));
			lista_contract->setItem(rand1, 1, new QTableWidgetItem(QString::fromStdString(to_string(disciplina.get_numar_ore()))));
			lista_contract->setItem(rand1, 2, new QTableWidgetItem(QString::fromStdString(disciplina.get_tip_materie())));
			lista_contract->setItem(rand1, 3, new QTableWidgetItem(QString::fromStdString(disciplina.get_cadru_didactic())));
			rand1++;
		}
		lista_contract->resizeRowsToContents();
	}
	
};