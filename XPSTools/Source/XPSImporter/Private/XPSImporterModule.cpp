#include "XPSImporterPrivatePCH.h"

//////////////////////////////////////////////////////////////////////////
// FXPSImporterModule

class FXPSImporterModule : public FDefaultModuleImpl
{
public:
	virtual void StartupModule() override
	{
		float xxx;
		xxx = 0.0;
	}

	virtual void ShutdownModule() override
	{
	}
};

//////////////////////////////////////////////////////////////////////////

IMPLEMENT_MODULE(FXPSImporterModule, XPSImporter);
DEFINE_LOG_CATEGORY(LogXPSImporter);
