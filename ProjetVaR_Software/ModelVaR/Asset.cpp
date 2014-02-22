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
