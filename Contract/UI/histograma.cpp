#pragma once
#include "observer.cpp"
#include <qwidget.h>
#include <qpainter.h>
#include "../Service/service_contract.h"
#include <QLineEdit>
#include <QFormLayout>
#include <qlist.h>
using namespace std;

class Histograma : public QWidget,public Observer {
	Service_Contract& contract;
	QHBoxLayout* lay = new QHBoxLayout;
	QLineEdit* linie = new QLineEdit("Numar elemente : " + QString::fromStdString(to_string(contract.service_get_all().size())));
	
public:
	Histograma(Service_Contract& contract):contract(contract) {
		this->setWindowTitle("Histograma Contract");
		this->setWindowIcon(QIcon("statistica.png"));
		linie->setFixedWidth(150);
		lay->addWidget(linie);
		this->setLayout(lay);
		this->setFixedSize(800, 300);

		contract.addObserver(this);
	};
	void update() override {
		linie->setText("Numar elemente : " + QString::fromStdString(to_string(contract.service_get_all().size())));
		repaint();
	}
	void paintEvent(QPaintEvent* ev) override {
		QPainter p{ this };
		int x = 10;
		linie->setReadOnly(true);
		int rand = 0;
		QList lista_culori = { QColor("red"),QColor("orange"),QColor("yellow"),QColor("green"), QColor("blue"), QColor("orchid"), QColor("darkorchid") };
		for (auto mat : contract.service_get_all()) {
			p.setBrush(QBrush(lista_culori[rand % lista_culori.size()]));
			p.drawRect(x, 50, 20, 10);
			
			x += 40;
			rand++;
		}
	}
};