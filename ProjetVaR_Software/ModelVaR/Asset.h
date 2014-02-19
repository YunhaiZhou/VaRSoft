#ifndef H_ASSET
#define H_ASSET

#include <QString>
#include <QDateTime>

class Asset {
private:
    QString file;
    QString name;
    QDateTime firstDate;
    QDateTime lastDate;

public:
    Asset(QString name, QString file, QDateTime firstDate, QDateTime lastDate);
    QString getFile() const;
    QString getName() const;
    QDateTime getFirstDate() const;
    QDateTime getLastDate() const;
    void changeName(QString name);
};
#endif