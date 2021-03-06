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

#include "SQLiteManager.h"
#include <QString>
#include "Portfolio.h"
#include "Asset.h"
#include "report/GarchReport.h"
#include "report/VaRReport.h"
#include "report/StatisticsReport.h"
#include "report/CorrelationReport.h"
#include "report/BacktestingReport.h"
#include <QDate>
#include <QVector>
#include "AssetsFactory.h"
#include <QVariant>
#include "SessionSaver.h"

class Portfolio;

class MODELVARSHARED_EXPORT SessionBuilder: public SQLiteManager {
private:
	static SessionBuilder* instance;

public:
	Asset *buildAsset(QString name);
	QMap<QString, Asset*> buildAssets();
	QList<Portfolio*> buildSession();
	/**
	 * @brief Accessor to the only instance of SessionBuilder.
	 * @return The only instance of SessionBuilder.
	 */
	static SessionBuilder* getInstance() {
		if(instance == NULL) {
			QString databaseFile = SQLiteManager::buildDatabaseFilePath();
			instance = new SessionBuilder(databaseFile);
		}
		return instance;
	}

private:
	SessionBuilder(QString databaseFile);
	QList<Portfolio*> buildPortfolios();
	QList<Report*> buildReports(int idPortfolio);
	QMap<Asset*, int> buildPortfolioComposition(int idPortfolio);
};
