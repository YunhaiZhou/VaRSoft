#pragma once

#include "Asset.h"
#include <QtTest>
#include <QDir>
#include <QVector>

class TestAsset: public QObject {
	Q_OBJECT

private:
	Asset google;
	Asset missing;

public:
	TestAsset();

private Q_SLOTS:
	void testId();
	void testName();
	void testGetValues();
};