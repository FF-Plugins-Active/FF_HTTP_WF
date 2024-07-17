// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

// Custom Includes.
#include "FF_HTTP_WF_Request.h"

#include "FF_HTTP_WF_Server.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDelegate_Wf);

UCLASS()
class FF_HTTP_WF_API AHTTP_Server_WF : public AActor
{
	GENERATED_BODY()
	
protected:

	// Called when the game starts or when spawned.
	virtual void BeginPlay() override;

	// Called when the game end or when destroyed.
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	TSharedPtr<WFHttpServer, ESPMode::ThreadSafe> WF_Server;
	bool bIsServerStarted = false;

public:	

	// Sets default values for this actor's properties.
	AHTTP_Server_WF();

	// Called every frame.
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(BlueprintAssignable, Category = "Frozen Forest|HTTP|Server|Workflow")
	FDelegate_Wf_Request Delegate_Http_Request;

	UPROPERTY(BlueprintAssignable, Category = "Frozen Forest|HTTP|Server|Workflow")
	FDelegate_Wf Delegate_HTTP_Start;

	UPROPERTY(BlueprintAssignable, Category = "Frozen Forest|HTTP|Server|Workflow")
	FDelegate_Wf Delegate_HTTP_Stop;

	UPROPERTY(BlueprintReadOnly, meta = (ToolTip = "", ExposeOnSpawn = "true"), Category = "Frozen Forest|HTTP|Server|Workflow")
	int32 Port_HTTP = 8081;

	UPROPERTY(BlueprintReadOnly, meta = (ToolTip = "", ExposeOnSpawn = "true"), Category = "Frozen Forest|HTTP|Server|Workflow")
	int32 Port_HTTPS = 8453;

	UFUNCTION(BlueprintImplementableEvent, meta = (Description = ""), Category = "Frozen Forest|HTTP|Server|Workflow")
	void OnHttWf_Start();

	UFUNCTION(BlueprintImplementableEvent, meta = (Description = ""), Category = "Frozen Forest|HTTP|Server|Workflow")
	void OnHttWf_Stop();

	UFUNCTION(BlueprintImplementableEvent, meta = (Description = ""), Category = "Frozen Forest|HTTP|Server|Workflow")
	void OnHttWf_Request(UHttpRequestWf* Request);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "HTTP Server Workflow - Start"), Category = "Frozen Forest|HTTP|Server|Workflow")
	virtual bool HTTP_Server_Start();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "HTTP Server Workflow - Stop"), Category = "Frozen Forest|HTTP|Server|Workflow")
	virtual void HTTP_Server_Stop();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "HTTP Server Workflow - Get Listen Address"), Category = "Frozen Forest|HTTP|Server|Workflow")
	virtual FString GetListenAddress();

};