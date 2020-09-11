// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "SlateBrush.h"

struct FProjectInfo;

class FUPTManager :public TSharedFromThis<FUPTManager>
{
public:
	FUPTManager()
	{	}

	static TSharedPtr<FUPTManager> Get();

	void Initialize();


	/*
	*	获取所有引擎根目录
	*/
	TArray<FString> GetAllEngineRootDir();

	void GetEngineVersion(TArray<FString>& EngineDirs, TArray<FString>& Versions);

	/*
	*	根据引擎根目录获取该版本引擎的所有工程路径
	*/
	TArray<FString> GetProjectPathsByEngineRootDir(const FString& RootDir);

	void GetProjectNames(TArray<FString>& ProjectPaths, TArray<FString>& ProjectNames);

	TArray<TSharedPtr<FProjectInfo>> GetAllProjectInfos();

	/*
	*	根据工程路径获取项目缩略图
	*/
	TSharedPtr<FSlateBrush> GetProjectThumbnail(const FString& ProjectPath);

	/*
	*	引擎是否是源码版，返回true
	*/
	const bool EngineIsDistribution(const FString& Identifer);

	bool OpenProject(TSharedRef<FProjectInfo> Info);
	bool OpenCodeIDE(TSharedRef<FProjectInfo> Info);
	bool GenerateSolution(TSharedRef<FProjectInfo> Info);
	bool ShowInExplorer(TSharedRef<FProjectInfo> Info);
	//弹出清理Binares和Immediate文件夹窗口
	void OpenClearSolutionWindow(TSharedRef<FProjectInfo> Info);

	void OpenManagedCodeWindow(TSharedRef<FProjectInfo> Info);

private:
	TSharedPtr<FJsonObject> LoadProjectFile(const FString &FileName);
};