// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

// Custom Includes.
#include "FF_HTTP_WF_Request.h"

#include "FF_HTTP_WF_Server.generated.h"

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

public:	

	// Sets default values for this actor's properties.
	AHTTP_Server_WF();

	// Called every frame.
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(BlueprintAssignable, Category = "Frozen Forest|HTTP|Server|NGHTTP2")
	FDelegateRequestWf DelegateHttpRequest;

	UPROPERTY(BlueprintReadOnly, meta = (ToolTip = "If you want to change API parameter, just put /* to the end. If you don't do that, server won't detect dynamic API requests.", ExposeOnSpawn = "true"), Category = "Frozen Forest|HTTP|Server|NGHTTP2")
	FString API_URI = "api/*";

	UPROPERTY(BlueprintReadOnly, meta = (ToolTip = "", ExposeOnSpawn = "true"), Category = "Frozen Forest|HTTP|Server|NGHTTP2")
	int32 Port_HTTP = 8081;

	UPROPERTY(BlueprintReadOnly, meta = (ToolTip = "", ExposeOnSpawn = "true"), Category = "Frozen Forest|HTTP|Server|NGHTTP2")
	int32 Port_HTTPS = 8453;

	UPROPERTY(BlueprintReadOnly, meta = (ToolTip = "", ExposeOnSpawn = "true"), Category = "Frozen Forest|HTTP|Server|POCO")
	int32 ThreadNum = 4;

	UFUNCTION(BlueprintImplementableEvent, meta = (Description = ""), Category = "Frozen Forest|HTTP|Server|NGHTTP2")
	void OnHttWf_Start();

	UFUNCTION(BlueprintImplementableEvent, meta = (Description = ""), Category = "Frozen Forest|HTTP|Server|NGHTTP2")
	void OnHttWf_Stop();

	UFUNCTION(BlueprintImplementableEvent, meta = (Description = ""), Category = "Frozen Forest|HTTP|Server|NGHTTP2")
	void OnHttWf_Request(UHttpRequestWf* Request);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "HTTP Server NGHTTP2 - Start"), Category = "Frozen Forest|HTTP|Server|NGHTTP2")
	virtual bool HTTP_Server_Start();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "HTTP Server NGHTTP2 - Stop"), Category = "Frozen Forest|HTTP|Server|NGHTTP2")
	virtual void HTTP_Server_Stop();

};