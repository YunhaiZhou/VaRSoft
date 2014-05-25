/**
 * Copyright (C) 2013 Benjamin Bouguet, Damien Carduner, Paul Chaignon,
 * Eric Chauty, Xavier Fraboulet, Clement Gautrais, Ulysse Goarant.

 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2.1 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.

 * You should have received a copy of the GNU Lesser General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "CorrelationDialog.h"

/**
* @brief Correlation Constructor
* Range of date is limited by the file's range dates
* @param portfolio The Portfolio
* @param startDate The oldest date in the file
* @param endDate The latest date in the file
* @param parent QDialog Widget to use
*/
Correlation::Correlation(Portfolio *portfolio, QWidget *parent): QDialog(parent), ui(new Ui::Correlation) {
	ui->setupUi(this);
	this->portfolio = portfolio;
	QDate date = portfolio->retrieveEndDate();
	ui->date->setMinimumDate(date);
	ui->date->setMaximumDate(portfolio->retrieveStartDate());
	ui->date->setDate(date);
	ui->date->setCalendarPopup(true);
	results = new QList<CorrelationResults>();
	//delete automatically the QDialog
	this->setAttribute(Qt::WA_DeleteOnClose);
}

Correlation::~Correlation() {
	delete ui;
	//delete portfolio;
	delete results;
}

/**
* @brief Called when Correlation file window's "Generate" button is pushed
* Emit a signal with all data set in the window
*/
void Correlation::on_pushButton_clicked() {
	QPair<double,double> res;
	//QDate date = new QDate(ui->date->date());
	const QDate &date = (const QDate&)(ui->date->date());
	//QDate* pf = new QDate(ui->date->date());
	//const QDate &date = (const QDate&)pf;
	if(ui->comboBox->currentText() == "Correlation")
		res = RInterface::checkCorrelation(*this->portfolio,ui->timelag->value(),date,ui->period->value());
	else
		res = RInterface::checkSquareCorrelation(*this->portfolio,ui->timelag->value(),date,ui->period->value());
	CorrelationResultsDialog *cr = new CorrelationResultsDialog(results, ui->comboBox->currentText(), res, this);
	cr->show();
}

/**
* @brief Called when Importing file window's "Cancel" button is pushed
* Cancel csv's import
*/
void Correlation::on_pushButton_2_clicked() {
	this->close();
}

/**
 * @brief Correlation::quit
 */
void Correlation::quit(){
	this->close();
}
