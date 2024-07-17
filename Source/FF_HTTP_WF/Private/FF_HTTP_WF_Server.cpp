// Fill out your copyright notice in the Description page of Project Settings.

#include "FF_HTTP_WF_Server.h"

// Sets default values
AHTTP_Server_WF::AHTTP_Server_WF()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AHTTP_Server_WF::BeginPlay()
{
	Super::BeginPlay();
	this->HTTP_Server_Start();
}

void AHTTP_Server_WF::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	this->HTTP_Server_Stop();
	Super::EndPlay(EndPlayReason);
}

// Called every frame
void AHTTP_Server_WF::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

bool AHTTP_Server_WF::HTTP_Server_Start()
{
	auto Callback = [this](WFHttpTask* Task)
		{
			UHttpRequestWf* Request = NewObject<UHttpRequestWf>();
			Request->Task = Task;

			this->OnHttWf_Request(Request);
			this->DelegateHttpRequest.Broadcast(Request);
		};

	try
	{
		this->WF_Server = MakeShared<WFHttpServer, ESPMode::ThreadSafe>(Callback);
		this->WF_Server->start(this->Port_HTTP);
	}

	catch (const std::exception& Exception)
	{
		FString ExceptionString = Exception.what();
		UE_LOG(LogTemp, Warning, TEXT("FF HTTP WF : Thread->Callback_HTTP_Start : %s"), *ExceptionString);

		return false;
	}

	return true;
}

void AHTTP_Server_WF::HTTP_Server_Stop()
{
	if (this->WF_Server.IsValid())
	{
		this->WF_Server->stop();
	}
}