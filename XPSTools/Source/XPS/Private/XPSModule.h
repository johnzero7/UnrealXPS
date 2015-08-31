#pragma once

#include "ModuleManager.h"


class XPSImpl : public IModuleInterface
{
private:

public:
	XPSImpl();

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

};
