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

#include <QtTest>
#include "Portfolio.h"
#include "Asset.h"
#include "report/GarchReport.h"
#include "report/VaRReport.h"
#include "SessionSaver.h"
#include "SessionBuilder.h"

class TestSQLiteManagers: public QObject {
	Q_OBJECT

private:
	QList<Portfolio*> portfolios;
	Asset google;
	Asset apple;
	Report* garchReport;
	Report* varReport;

public:
	TestSQLiteManagers();

private Q_SLOTS:
	void testSaveSession();
	void testUpdateSession();
};
