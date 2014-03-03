#include "Asset.h"

/**
* @brief Empty constructor
* Should only be used by Qt containers.
*/
Asset::Asset() {

}

/**
 * @brief An asset.
 * @param name The name of the asset.
 * @param file The file where are located the values.
 * @param firstDate The date of the first value defined.
 * @param lastDate The date of the last value defined.
 */
Asset::Asset(QString name, QString file, QDateTime firstDate, QDateTime lastDate) {
	this->name = name;
	this->file = file;
	this->firstDate = firstDate;
	this->lastDate = lastDate;
}

/**
 * @brief Accessor to file.
 * @return The file where are located the values.
 */
QString Asset::getFile() const {
	return this->file;
}

/**
 * @brief Accessor to name.
 * @return The name of the asset.
 */
QString Asset::getName() const {
	return this->name;
}

/**
 * @brief Accessor to the first date defined.
 * @return The date of the first value defined.
 */
QDateTime Asset::getFirstDate() const {
	return this->firstDate;
}

/**
 * @brief Accessor to the last date defined.
 * @return The date of the last value defined.
 */
QDateTime Asset::getLastDate() const {
	return this->lastDate;
}

/**
 * @brief Change the asset's name.
 * @param name The new name.
 */
void Asset::changeName(QString name) {
	this->name = name;
}

/**
 * @brief Getter of the asset values.
 * @param startDate The starting date
 * @param endDate The ending date
 * @return A vector containing the values of the asset according to the parameters
 */
QVector<double> Asset::getAsQVectors(QDateTime startDate, QDateTime endDate) {
    QVector<double> values;
    QFile inputFile(this->getFile());

    if(!inputFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << inputFile.errorString();
    } else {
        QTextStream in(&inputFile);

        bool startDetected = false;
        while(!in.atEnd()) {
            QString line = in.readLine();
            QRegExp rx("\\s*,\\s*");
            QStringList row = line.split(rx);
            QString date = row.value(0);
            QString value = row.value(1);

            if(startDate != QDateTime::fromString(date,"yyyy-MM-dd") && !startDetected)
                continue;

            if(startDetected == false) startDetected = true;

            values.push_back(value.toDouble());

            if(endDate == QDateTime::fromString(date,"yyyy-MM-dd"))
                break;
        }
        inputFile.close();
    }

    return values;
}
