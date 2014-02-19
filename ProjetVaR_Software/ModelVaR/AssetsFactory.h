#ifndef H_ASSETSFACTORY
#define H_ASSETSFACTORY

#include <QString>
#include "Asset.h"

class AssetsFactory {
private:
	static AssetsFactory* instance;

public:
    Asset* retrieveAsset(QString name);
	static AssetsFactory* getInstance() {
		if(instance == NULL) {
			instance = new AssetsFactory();
		}
		return instance;
	}

private:
	AssetsFactory();
};
#endif