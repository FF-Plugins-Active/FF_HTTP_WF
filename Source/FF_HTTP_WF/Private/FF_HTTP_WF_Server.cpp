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
#ifdef _WIN64
	this->HTTP_Server_Start();
#endif
	
	Super::BeginPlay();
}

void AHTTP_Server_WF::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
#ifdef _WIN64
	this->HTTP_Server_Stop();
#endif

	Super::EndPlay(EndPlayReason);
}

// Called every frame
void AHTTP_Server_WF::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

bool AHTTP_Server_WF::HTTP_Server_Start()
{
#ifdef _WIN64
	
	if (this->Server_Name.IsEmpty())
	{
		return false;
	}

	this->Thread_WF = new FHTTP_Thread_WF(this);

	if (this->Thread_WF)
	{
		return true;
	}

	else
	{
		return false;
	}

#else

	return false;

#endif
}

void AHTTP_Server_WF::HTTP_Server_Stop()
{
#ifdef _WIN64
	
	if (this->Thread_WF)
	{
		delete this->Thread_WF;
		return;
	}

	else
	{
		return;
	}

#else

#endif
}

bool AHTTP_Server_WF::HTTP_Server_Toggle(bool bIsPause)
{
	if (!this->Thread_WF)
	{
		return false;
	}

	return this->Thread_WF->Toggle(bIsPause);
}

bool UHttpRequestWf::SendResponse(FString In_Response)
{
	if (!this->Task)
	{
		return false;
	}

	return this->Task->get_resp()->append_output_body(TCHAR_TO_UTF8(*In_Response));
}

bool UHttpRequestWf::GetRequestUri(FString& Out_Uri)
{
	if (!this->Task)
	{
		return false;
	}

	const char* RequestUri = this->Task->get_req()->get_request_uri();
	
	if (strlen(RequestUri) > 0)
	{
		Out_Uri = RequestUri;
		return true;
	}

	else
	{
		return false;
	}
}