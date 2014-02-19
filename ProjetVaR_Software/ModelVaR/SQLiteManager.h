#ifndef H_SQLITEMANAGER
#define H_SQLITEMANAGER

#include <QString>
#include "sqlite3.h"


class SQLiteManager {
protected:
    const QString databaseFile;

protected:
    SQLiteManager(const QString databaseFile);

private:
	// TODO Change returned object.
	void openConnection();
	void createDatabase();
};
#endif