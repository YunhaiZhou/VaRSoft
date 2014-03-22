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
#pragma once

#include <QDateTime>
#include "IdAlreadyAttributedException.h"
#include <QFile>
#include <QRegExp>
#include <QString>
#include <QStringList>
#include <QTextStream>
#include <QVector>
#include <stdexcept>
#include "ModelVaR_global.h"
#include "CannotOpenFileException.h"

class MODELVARSHARED_EXPORT Asset {
private:
	int id;
	QString file;
	QString name;
	QString origin;
	QDateTime firstDate;
	QDateTime lastDate;

public:
	Asset();
	Asset(QString name, QString file, QString origin, QDateTime firstDate, QDateTime lastDate);
	Asset(int id, QString name, QString file, QString origin, QDateTime firstDate, QDateTime lastDate);
	void init(int id, QString name, QString file, QString origin, QDateTime firstDate, QDateTime lastDate);

	int getId() const;
	void setId(int id);
	QString getFile() const;
	QString getName() const;
	QString getOrigin() const;
	QDateTime getFirstDate() const;
	QDateTime getLastDate() const;
	void changeName(QString name);
	QVector<double> getValues();
	QVector<double> getValues(const QDateTime &startDate, const QDateTime &endDate);

	bool operator==(const Asset& asset) const;
};
