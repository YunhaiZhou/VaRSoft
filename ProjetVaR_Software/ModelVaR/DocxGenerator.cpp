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
#include "DocxGenerator.h"

DocxGenerator::DocxGenerator(Report *report) : ReportGenerator(report) {

}

/**
 * @brief Generates the DOCX file
 */
void DocxGenerator::generate() {
	QString prog = "../DocxGenerator/DocXGenerator.jar";
	if (QFile::exists(prog) && QFile::exists(report->getTemplateFile()))
	{
		QProcess docx;
		docx.start("java", QStringList() << "-jar" << prog << report->getTemplateFile() << report->getFile());
		docx.waitForStarted();

		QString data = report->getDataJson()->toString();
		docx.write(data.toLatin1(),data.length());
		docx.closeWriteChannel();

		docx.waitForFinished();
		int exitCode=docx.exitCode();
		bool hasCrashed = docx.exitStatus()==QProcess::CrashExit;
		if (exitCode != 0 || hasCrashed)
		{
			throw std::runtime_error("exitcode: "+QString::number(exitCode).toStdString());
		}
	}
	else
	{
		if (!QFile::exists(prog))
			throw std::invalid_argument("DocXGenerator does not exists on the disk.");
		else if (!QFile::exists(report->getTemplateFile()))
			throw std::invalid_argument("Template report ("+report->getTemplateFile().toStdString()+") does not exist.");
	}
}
