// Fill out your copyright notice in the Description page of Project Settings.
#include "MyCustomAssetActions.h"
#include "Chapter_08Editor.h"
#include "MyCustomAsset.h"

bool FMyCustomAssetActions::HasActions(const TArray<UObject*>& InObjects) const
{
	return true;
}

void FMyCustomAssetActions::GetActions(const TArray<UObject*>& InObjects, FMenuBuilder& MenuBuilder)
{
	MenuBuilder.AddMenuEntry(
		FText::FromString("CustomAssetAction"),
		FText::FromString("Action from Cookbook Recipe"),
		FSlateIcon(FEditorStyle::GetStyleSetName(), "LevelEditor.ViewOptions"),
		FUIAction(
			FExecuteAction::CreateRaw(this, &FMyCustomAssetActions::MyCustomAssetContext_Clicked),
			FCanExecuteAction()
			));
}

uint32 FMyCustomAssetActions::GetCategories()
{
	return EAssetTypeCategories::Misc;
}

FText FMyCustomAssetActions::GetName() const
{
	return FText::FromString(TEXT("My Custom Asset"));
}

UClass* FMyCustomAssetActions::GetSupportedClass() const
{
	return UMyCustomAsset::StaticClass();
}

FColor FMyCustomAssetActions::GetTypeColor() const
{
	return FColor::Emerald;
}

/*

void FMyCustomAssetActions::OpenAssetEditor(const TArray<UObject*>& InObjects, TSharedPtr<IToolkitHost> EditWithinLevelEditor / *= TSharedPtr<IToolkitHost>()* /)
{
    FAssetTypeActions_Base::OpenAssetEditor(InObjects, EditWithinLevelEditor);
}*/

