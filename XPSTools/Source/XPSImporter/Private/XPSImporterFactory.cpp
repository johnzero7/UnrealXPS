#include "XPSImporterPrivatePCH.h"
#include "XPSImporterFactory.h"
//#include "AssetToolsModule.h"
#include "AssetRegistryModule.h"
#include "PackageTools.h"

#define LOCTEXT_NAMESPACE "XPSImporter"
#define TILED_IMPORT_ERROR(FormatString, ...) \
	if (!bSilent) { UE_LOG(LogXPSImporter, Warning, FormatString, __VA_ARGS__); }
#define TILED_IMPORT_WARNING(FormatString, ...) \
	if (!bSilent) { UE_LOG(LogXPSImporter, Warning, FormatString, __VA_ARGS__); }


//////////////////////////////////////////////////////////////////////////
// UXPSImporterFactory

UXPSImporterFactory::UXPSImporterFactory(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	//1~
	UE_LOG(LogXPSImporter, Warning, TEXT("UXPSImporterFactory--"));
	bEditorImport = true; //Enable import from content manager IMPORT BUTTON
	bCreateNew = false; //True creates object from scratch
	bText = false;

	SupportedClass = UXPSImporterFactory::StaticClass();

	Formats.Add(TEXT("xps;XPS Model (binary)"));
	Formats.Add(TEXT("mesh;XPS Model (binary)"));
	Formats.Add(TEXT("mesh.ascii;XPS Model (ascii)"));
}

FText UXPSImporterFactory::GetToolTip() const
{
	UE_LOG(LogXPSImporter, Warning, TEXT("GetToolTip--"));
	return LOCTEXT("XPSImporterFactoryDescription", "XPS models importer");
}

bool UXPSImporterFactory::FactoryCanImport(const FString& Filename) 
{
	//2~
	Super::FactoryCanImport(Filename);
	FString CleanFilename = FPaths::GetCleanFilename(Filename);
	FString BaseFilename = FPaths::GetBaseFilename(CleanFilename);
	FString FileExtension = FPaths::GetExtension(Filename, false);
	FString FilePath = FPaths::GetPath(Filename);

	UE_LOG(LogXPSImporter, Warning, TEXT("FactoryCanImport-- Filename: %s"), *Filename);
	UE_LOG(LogXPSImporter, Warning, TEXT("FactoryCanImport-- CleanFilename: %s"), *CleanFilename);
	UE_LOG(LogXPSImporter, Warning, TEXT("FactoryCanImport-- BaseFilename: %s"), *BaseFilename);
	UE_LOG(LogXPSImporter, Warning, TEXT("FactoryCanImport-- FileExtension: %s"), *FileExtension);
	UE_LOG(LogXPSImporter, Warning, TEXT("FactoryCanImport-- FilePath: %s"), *FilePath);

	bool isXpsBin = (FCString::Stricmp(*FileExtension, TEXT("xps")) == 0);
	bool isMeshBin = (FCString::Stricmp(*FileExtension, TEXT("mesh")) == 0);
	bool isMeshAscii = (FCString::Stricmp(*FileExtension, TEXT("ascii")) == 0);
	bool result = isXpsBin || isMeshBin || isMeshAscii;
	return result;
}

UObject* UXPSImporterFactory::FactoryCreateText(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, const TCHAR* Type, const TCHAR*& Buffer, const TCHAR* BufferEnd, FFeedbackContext* Warn)
{
	//3~
	UE_LOG(LogXPSImporter, Warning, TEXT("FactoryCreateText--"));
	UObject* Result = NULL;
	return Result;
}

UObject* UXPSImporterFactory::FactoryCreateBinary(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, const TCHAR* Type, const uint8*& Buffer, const uint8* BufferEnd, FFeedbackContext* Warn)
{
	//3~
	UE_LOG(LogXPSImporter, Warning, TEXT("FactoryCreateBinary--"));
	UObject* Result = NULL;
	return Result;
}

UObject* UXPSImporterFactory::FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn)
{
	UE_LOG(LogXPSImporter, Warning, TEXT("FactoryCreateNew--"));
	UObject* Result = NULL;
	return Result;
}

bool UXPSImporterFactory::CanReimport(UObject* Obj, TArray<FString>& OutFilenames)
{
	/*
	if (UPaperTileMap* TileMap = Cast<UPaperTileMap>(Obj))
	{
		if (TileMap->AssetImportData != nullptr)
		{
			OutFilenames.Add(FReimportManager::ResolveImportFilename(TileMap->AssetImportData->SourceFilePath, TileMap));
		}
		else
		{
			OutFilenames.Add(TEXT(""));
		}
		return true;
	}
	*/
	UE_LOG(LogXPSImporter, Warning, TEXT("CanReimport--"));
	return false;
}

void UXPSImporterFactory::SetReimportPaths(UObject* Obj, const TArray<FString>& NewReimportPaths)
{
	/*
	if (UPaperTileMap* TileMap = Cast<UPaperTileMap>(Obj))
	{
		if (ensure(NewReimportPaths.Num() == 1))
		{
			UTileMapAssetImportData* ImportData = UTileMapAssetImportData::GetImportDataForTileMap(TileMap);

			ImportData->SourceFilePath = FReimportManager::SanitizeImportFilename(NewReimportPaths[0], TileMap);
		}
	}
	*/
	UE_LOG(LogXPSImporter, Warning, TEXT("SetReimportPaths--"));
}

EReimportResult::Type UXPSImporterFactory::Reimport(UObject* Obj)
{
	UE_LOG(LogXPSImporter, Warning, TEXT("Reimport--"));
	return EReimportResult::Cancelled;
}

int32 UXPSImporterFactory::GetPriority() const
{
	UE_LOG(LogXPSImporter, Warning, TEXT("GetPriority--"));
	return ImportPriority;
}

//////////////////////////////////////////////////////////////////////////

#undef TILED_IMPORT_ERROR
#undef LOCTEXT_NAMESPACE