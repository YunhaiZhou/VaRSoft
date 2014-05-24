#-------------------------------------------------
#
# Project created by QtCreator 2014-02-12T17:09:16
#
#-------------------------------------------------

QT += core gui printsupport sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

GTCONFIG +=console

TARGET = GUI
TEMPLATE = app

SOURCES += main.cpp\
		MainWindow.cpp \
		FlowLayout.cpp \
		windows/NewPortfolioWizard.cpp \
		windows/SetWeightAssetWizardPage.cpp \
		windows/ShowAssetsWizardPage.cpp \
		windows/DocxGenPathDialog.cpp \
		windows/ImportDialog.cpp \
		portfolio/PortfolioListView.cpp \
		portfolio/PortfolioViewMediator.cpp \
		portfolio/PortfolioListModel.cpp \
		portfolio/DataModel.cpp \
		portfolio/report/ReportWidget.cpp \
		portfolio/report/ReportWidgetFactory.cpp \
		portfolio/report/ReportView.cpp \

HEADERS += MainWindow.h \
		Constantes.h \
		FlowLayout.h \
		windows/NewPortfolioWizard.h \
		windows/SetWeightAssetWizardPage.h \
		windows/ShowAssetsWizardPage.h \
		windows/DocxGenPathDialog.h \
		windows/ImportDialog.h \
		portfolio/PortfolioListView.h \
		portfolio/PortfolioViewMediator.h \
		portfolio/PortfolioListModel.h \
		portfolio/DataModel.h \
		portfolio/report/ReportWidget.h \
		portfolio/report/ReportWidgetFactory.h \
		portfolio/report/ReportView.h \
		exceptions/NoneSelectedPortfolioException.h

FORMS += MainWindow.ui \
		windows/NewPortfolioWizard.ui \
		windows/SetWeightAssetWizardPage.ui \
		windows/ShowAssetsWizardPage.ui\
		windows/import.ui \
		windows/DocxGenPathDialog.ui \
		portfolio/report/ReportWidget.ui \
		portfolio/report/ReportListScrollArea.ui

INCLUDEPATH += portfolio/ windows/ portfolio/report exceptions

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../quazip/quazip/release/ -lquazip
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../quazip/quazip/debug/ -lquazip
else:unix: LIBS += -L$$OUT_PWD/../quazip/quazip/ -lquazip

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../ModelVaR/release/ -lModelVaR
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../ModelVaR/debug/ -lModelVaR
else:unix: LIBS += -L$$OUT_PWD/../ModelVaR/ -lModelVaR

INCLUDEPATH += $$PWD/../ModelVaR
DEPENDPATH += $$PWD/../ModelVaR

RESOURCES += \
	Resources.qrc

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../qcustomplot/release/ -lqcustomplotd
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../qcustomplot/debug/ -lqcustomplotd
else:unix: LIBS += -L$$OUT_PWD/../qcustomplot/ -lqcustomplotd

INCLUDEPATH += $$PWD/../qcustomplot
DEPENDPATH += $$PWD/../qcustomplot
