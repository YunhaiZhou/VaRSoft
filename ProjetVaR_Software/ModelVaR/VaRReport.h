#ifndef H_VARREPORT
#define H_VARREPORT

#include "Report.h"

class VaRReport: public Report {
public:
    VaRReport(QString docxPath, QString pdfPath);
};

#endif