#pragma once
#include <iostream>
#include "../Service/service_discipline.h"
#include "../Service/service_contract.h"
#include <QApplication>
#include <Qwidget>
#include <QLabel>
#include <QFormLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QTextEdit>
#include <Qlist>
#include <Qdebug>
#include <QListWidget>
#include <Qmessagebox>
#include <QTableWidget>
#include <qitemselectionmodel.h>
#include "../UI/cos.cpp"
#include "../UI/histograma.cpp"
using namespace std;

class ModelAbstract : public QAbstractTableModel {
private:
	vector<Disciplina> discipline;
	vector<Disciplina> contract;
public:
	ModelAbstract(const vector<Disciplina>& discipline, const vector<Disciplina>& contract) : discipline(discipline), contract(contract) {
	}
	void setDiscipline(const vector<Disciplina>& disc, const vector<Disciplina>& con) {
		this->discipline = disc;
		auto topLeft = createIndex(0, 0);
		auto bottomR = createIndex(rowCount(), columnCount());
		emit dataChanged(topLeft, bottomR);
	}
	int rowCount(const QModelIndex& parent = QModelIndex())const override {
		return discipline.size();
	}
	int columnCount(const QModelIndex& parent = QModelIndex())const override {
		return 4;
	}
	QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const override {
		
		if (role == Qt::DisplayRole) {
			
			Disciplina d = discipline[index.row()];
			qDebug() << d.get_denumire();
			if (index.column() == 0)
				return QString::fromStdString(d.get_denumire());
			else if (index.column() == 1)
				return QString::fromStdString(to_string(d.get_numar_ore()));
			else if (index.column() == 2)
				return QString::fromStdString(d.get_tip_materie());
			else if (index.column() == 3)
				return QString::fromStdString(d.get_cadru_didactic());

		}
		return QVariant();
	}
};
class User_Interface_Qt : public QWidget {
private:
	Service_Discipline& service_discipline;
	Service_Contract& service_contract;
	vector<Disciplina> allDiscipline;
	vector<Disciplina> allContract;
	QWidget* meniu = new QWidget;
	QTableWidget* lista = new QTableWidget;
	QListWidget* lista_laborator = new QListWidget;
	QPushButton* add = new QPushButton("&Adauga", this);
	QPushButton* update = new QPushButton("&Modifica", this);
	QPushButton* del = new QPushButton("&Sterge", this);
	QPushButton* undo = new QPushButton("&Undo", this);
	QPushButton* coscrudGUIbutton = new QPushButton("&Contract", this);
	QPushButton* histograma = new QPushButton("&Histograma Contract", this);
	QPushButton* saptamanale = new QPushButton("&Materii saptamanale", this);
	QPushButton* alternative = new QPushButton("&Materii alternative", this);
	QPushButton* sortare_nume = new QPushButton("&Sortare nume materie", this);
	QPushButton* sortare_cadru = new QPushButton("&Sortare nume profesor si tip", this);
	QPushButton* sortare_ore = new QPushButton("&Sortare numar ore", this);
	QPushButton* filtrare_ore = new QPushButton("&Filtrare numar ore", this);
	QPushButton* filtrare_cadru = new QPushButton("&Filtrare nume profesor", this);
	QHBoxLayout* sort_layout = new QHBoxLayout;
	QHBoxLayout* meniu_layout = new QHBoxLayout;
	QHBoxLayout* filter_layout = new QHBoxLayout;
	QHBoxLayout* crud_layout = new QHBoxLayout;
	QHBoxLayout* main_layout = new QHBoxLayout;
	QFormLayout* button_layout = new QFormLayout;
	QFormLayout* layout = new QFormLayout;
	QFormLayout* layout_dreapta = new QFormLayout;
	QLabel* nume_materie = new QLabel("Nume materie: ");
	QLabel* ore_materie = new QLabel("Nr. ore materie: ");
	QLabel* tip_materie = new QLabel("Tip materie: ");
	QLabel* cadru_materie = new QLabel("Nume profesor: ");
	QLineEdit* nume = new QLineEdit("Analiza");
	QLineEdit* ore = new QLineEdit("4");
	QLineEdit* tip = new QLineEdit("Saptamanal");
	QLineEdit* profesor = new QLineEdit("Berinde Stefan");

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
	QTableView* view_tabel = new QTableView;
	ModelAbstract* model;
public:
	void menu() {
		allDiscipline = service_discipline.service_get_all();
		this->setFixedSize(1280, 800);
		meniu->setFixedSize(600, 600);
		QIcon meniu_icoana("icoana.ico");
		meniu->setWindowIcon(meniu_icoana);
		this->setWindowTitle("Contract Studii");
		add->adjustSize();
		update->adjustSize();
		del->adjustSize();
		undo->adjustSize();
		add_contract->adjustSize();
		delete_contract->adjustSize();
		generate_contract->adjustSize();
		export_contract->adjustSize();
		coscrudGUIbutton->adjustSize();
		histograma->adjustSize();
		materie_de_adaugat->setFixedWidth(150);
		generat->setFixedWidth(150);
		export_line->setFixedWidth(150);
		contract_layout->addWidget(add_contract);
		contract_layout->addWidget(delete_contract);
		contract_layout->addWidget(generate_contract);
		contract_layout->addWidget(export_contract);
		contract_line_layout->addRow(mat,materie_de_adaugat);
		contract_line_layout->addRow(gen,generat);
		contract_line_layout->addRow(exp,export_line);
		nume->setFixedWidth(150);
		profesor->setFixedWidth(150);
		ore->setFixedWidth(150);
		tip->setFixedWidth(150);
		filtrare_ore->adjustSize();
		filtrare_cadru->adjustSize();
		sortare_nume->adjustSize();
		sortare_cadru->adjustSize();
		sortare_ore->setFixedWidth(150);
		layout->addRow(nume_materie, nume);
		layout->addRow(ore_materie, ore);
		layout->addRow(tip_materie, tip);
		layout->addRow(cadru_materie, profesor);
		crud_layout->addWidget(add);
		crud_layout->addWidget(update);
		crud_layout->addWidget(del);
		crud_layout->addWidget(undo);
		layout->addRow(crud_layout);
		layout->addRow(coscrudGUIbutton);
		layout->addRow(histograma);
		contract_layout->addRow(contract_line_layout);
		contract_layout->addRow(lista_contract);
		meniu->setLayout(contract_layout);
		contract_layout2 = contract_layout;
		sort_layout->addWidget(sortare_nume);
		sort_layout->addWidget(sortare_cadru);
		sort_layout->addWidget(sortare_ore);
		filter_layout->addWidget(filtrare_ore);
		filter_layout->addWidget(filtrare_cadru);
		lista->setColumnCount(4);
		lista->setSelectionMode(QAbstractItemView::SingleSelection);
		lista->setSelectionBehavior(QAbstractItemView::SelectRows);
		lista_contract->setColumnCount(4);
		model = new ModelAbstract(allDiscipline, allContract);
		view_tabel->setModel(model);
		layout_dreapta->addRow(lista);
		layout_dreapta->addRow(sort_layout);
		layout_dreapta->addRow(filter_layout);
		lista_contract->setEditTriggers(QAbstractItemView::NoEditTriggers);
		lista_contract->setSelectionBehavior(QAbstractItemView::SelectRows);
		lista_contract->setAlternatingRowColors(true);
		button_layout->addRow(lista_laborator);
		saptamanale->setFixedWidth(150);
		alternative->setFixedWidth(150);
		button_layout->addRow(saptamanale, alternative);
		main_layout->addLayout(layout);
		main_layout->addLayout(layout_dreapta);
		main_layout->addLayout(button_layout);
		this->setLayout(main_layout);
		QIcon windowIcon("2232688.ico"); 
		this->setWindowIcon(windowIcon);
		
	}
	void initConnect() {
		
		QObject::connect(add, &QPushButton::clicked, [&]() {
			auto nume_materie = nume->text();
			auto ore_materie = ore->text();
			auto tip_materie = tip->text();
			auto profesor_materie = profesor->text();
			int nr_ore = stoi(ore_materie.toStdString());
			service_discipline.service_adauga_disciplina(nume_materie.toStdString(), nr_ore, tip_materie.toStdString(), profesor_materie.toStdString());
			allDiscipline = service_discipline.service_get_all();
			load_info(allDiscipline, allContract);
			});
		
		QObject::connect(update, &QPushButton::clicked, [&]() {
			auto nume_materie = nume->text();
			auto ore_materie = ore->text();
			auto tip_materie = tip->text();
			auto profesor_materie = profesor->text();
			int nr_ore = stoi(ore_materie.toStdString());
			service_discipline.service_modifica_disciplina(nume_materie.toStdString(), nr_ore, tip_materie.toStdString(), profesor_materie.toStdString());
			allDiscipline = service_discipline.service_get_all();
			load_info(allDiscipline, allContract);
			});
		QObject::connect(del, &QPushButton::clicked, [&]() {
			auto nume_materie = nume->text();
			auto ore_materie = ore->text();
			auto tip_materie = tip->text();
			auto profesor_materie = profesor->text();
			int nr_ore = stoi(ore_materie.toStdString());
			service_discipline.service_sterge_disciplina(nume_materie.toStdString());
			allDiscipline = service_discipline.service_get_all();
			load_info(allDiscipline, allContract);
			});
		QObject::connect(undo, &QPushButton::clicked, [&]() {
			try {
				service_discipline.undo();
			}
			catch (exception& ex) {
				QMessageBox::warning(this, "Warning", QString::fromStdString(ex.what()));
			}
			allDiscipline = service_discipline.service_get_all();
			load_info(allDiscipline, allContract);
			});
		QObject::connect(coscrudGUIbutton, &QPushButton::clicked, [this]() {
				Cos* nou = new Cos(service_contract,service_discipline);
				nou->show();
			});
			QObject::connect(histograma, &QPushButton::clicked, [this]() {
				Histograma* his = new Histograma(service_contract);
				his->show();
			});
		QObject::connect(sortare_nume, &QPushButton::clicked, [&]() {
			
			allDiscipline = service_discipline.sortare_denumire();
			load_info(allDiscipline, allContract);
			});
		QObject::connect(sortare_cadru, &QPushButton::clicked, [&]() {
			
			allDiscipline = service_discipline.sortare_cadru_didactic_si_tip();
			load_info(allDiscipline, allContract);
			});
		QObject::connect(filtrare_cadru, &QPushButton::clicked, [&]() {
	
			auto profesor_materie = profesor->text();
			allDiscipline = service_discipline.filtrare_cadru_didactic(profesor_materie.toStdString());
			load_info(allDiscipline, allContract);
			});
		QObject::connect(filtrare_ore, &QPushButton::clicked, [&]() {
			auto ore_materie = ore->text();
			int nr_ore = stoi(ore_materie.toStdString());
			
			allDiscipline = service_discipline.filtrare_ore(nr_ore);
			load_info(allDiscipline, allContract);
			});
		QObject::connect(sortare_ore, &QPushButton::clicked, [&]() {
			allDiscipline = service_discipline.sortare_nr_ore();
			load_info(allDiscipline, allContract);
			});
		QObject::connect(saptamanale, &QPushButton::clicked, [&]() {
			QString saptamana;
			
			for (const auto& mat : allDiscipline)
			{
				if (mat.get_tip_materie() == "Saptamanal")
				saptamana += QString::fromStdString(mat.get_denumire()) + QString::fromStdString(" ") + QString::fromStdString(to_string(mat.get_numar_ore())) + QString::fromStdString(" ") + QString::fromStdString(mat.get_tip_materie()) + QString::fromStdString(" ") + QString::fromStdString(mat.get_cadru_didactic()) + QString::fromStdString("\n");
			}
			QMessageBox::information(nullptr, "Saptamanale",saptamana);
			});
		QObject::connect(alternative, &QPushButton::clicked, [&]() {
			QString alternativ;

			for (const auto& mat : allDiscipline)
			{
				if (mat.get_tip_materie() == "Alternativ")
				alternativ += QString::fromStdString(mat.get_denumire()) + QString::fromStdString(" ") + QString::fromStdString(to_string(mat.get_numar_ore())) + QString::fromStdString(" ") + QString::fromStdString(mat.get_tip_materie()) + QString::fromStdString(" ") + QString::fromStdString(mat.get_cadru_didactic()) + QString::fromStdString("\n");
			}
			QMessageBox::information(nullptr, "Alternative", alternativ);
			});
		QObject::connect(lista, &QTableWidget::itemSelectionChanged, [&]() {
			auto selectate = lista->selectedItems();
			if (!selectate.isEmpty()) {
				auto materie = selectate.at(0);
				nume->setText(materie->text());
				auto ore_mat = selectate.at(1);
				auto tip_mat = selectate.at(2);
				auto prof_mat = selectate.at(3);
				ore->setText(ore_mat->text());
				tip->setText(tip_mat->text());
				profesor->setText(prof_mat->text());
			}
			});
		
	}
	void load_info(vector<Disciplina> allDiscipline, vector<Disciplina> allContract) {
		lista->clear();
		lista_laborator->clear();
		lista->setRowCount(0);
		lista->setHorizontalHeaderLabels({"Nume","Nr. ore","Tip","Nume profesor"});
		lista_contract->setRowCount(0);
		lista_contract->setHorizontalHeaderLabels({ "Nume","Nr. ore","Tip","Nume profesor" });
		lista->resizeRowsToContents();
		lista_contract->resizeRowsToContents();
		int rand = 0,rand1=0;
		for (const auto& disciplina : allDiscipline)
		{
			lista->insertRow(rand);
			lista->setItem(rand, 0, new QTableWidgetItem(QString::fromStdString(disciplina.get_denumire())));
			lista->setItem(rand, 1, new QTableWidgetItem(QString::fromStdString(to_string(disciplina.get_numar_ore()))));
			lista->setItem(rand, 2, new QTableWidgetItem(QString::fromStdString(disciplina.get_tip_materie())));
			lista->setItem(rand, 3, new QTableWidgetItem(QString::fromStdString(disciplina.get_cadru_didactic())));
			rand++;		
		}
		rand = 0;
		QList lista_culori = { QColor("lightgreen"),QColor("orange"),QColor("red")};
		for (const auto& disciplina : allDiscipline)
		{	
			QListWidgetItem* item = new QListWidgetItem((QString::fromStdString(disciplina.get_denumire()) + " " + QString::fromStdString(to_string(disciplina.get_numar_ore()))
				+ " " + QString::fromStdString(disciplina.get_tip_materie()) + " " + QString::fromStdString(disciplina.get_cadru_didactic())));
			if(disciplina.get_numar_ore()==4)
			item->setBackground(QBrush(lista_culori[0]));
			if(disciplina.get_numar_ore()==6)
			item->setBackground(QBrush(lista_culori[1]));
			if(disciplina.get_numar_ore()==8)
			item->setBackground(QBrush(lista_culori[2]));
			lista_laborator->addItem(item);
			rand++;
		}
		for (const auto& disciplina : allContract)
		{
			lista_contract->insertRow(rand1);
			lista_contract->setItem(rand1, 0, new QTableWidgetItem(QString::fromStdString(disciplina.get_denumire())));
			lista_contract->setItem(rand1, 1, new QTableWidgetItem(QString::fromStdString(to_string(disciplina.get_numar_ore()))));
			lista_contract->setItem(rand1, 2, new QTableWidgetItem(QString::fromStdString(disciplina.get_tip_materie())));
			lista_contract->setItem(rand1, 3, new QTableWidgetItem(QString::fromStdString(disciplina.get_cadru_didactic())));
			rand1++;
		}
		lista->resizeRowsToContents();
		lista_contract->resizeRowsToContents();
	}
	void load_info_abstract(vector<Disciplina>& allDiscipline, vector<Disciplina>& allContract) {
		model->setDiscipline(allDiscipline,allContract);
	}
	User_Interface_Qt(Service_Discipline& service_discipline, Service_Contract& service_contract) :service_discipline{ service_discipline }, service_contract{ service_contract } {
		menu();
		initConnect();
		load_info(allDiscipline, allContract);

	}
	
};