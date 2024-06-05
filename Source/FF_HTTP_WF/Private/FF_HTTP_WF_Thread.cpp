// Fill out your copyright notice in the Description page of Project Settings.

#include "FF_HTTP_WF_Thread.h"
#include "FF_HTTP_WF_Server.h"

// UE Includes.
#include "Async/Async.h"

FHTTP_Thread_WF::FHTTP_Thread_WF(AHTTP_Server_WF* In_Parent_Actor)
{
	this->Parent_Actor = In_Parent_Actor;
	
	this->Port_HTTP = this->Parent_Actor->Port_HTTP;
	this->Port_HTTPS = this->Parent_Actor->Port_HTTPS;
	this->ThreadNum = this->Parent_Actor->ThreadNum;
	this->API_URI = this->Parent_Actor->API_URI;

	this->RunnableThread = FRunnableThread::Create(this, *this->Parent_Actor->Server_Name);
}

FHTTP_Thread_WF::~FHTTP_Thread_WF()
{
	if (this->RunnableThread)
	{
		this->RunnableThread->Kill(true);
		delete this->RunnableThread;
	}
}

bool FHTTP_Thread_WF::Init()
{	
	this->Callback_HTTP_Start();
	this->bStartThread = true;

	return true;
}

uint32 FHTTP_Thread_WF::Run()
{
	while (this->bStartThread)
	{
		//FDateTime Now;
		//UE_LOG(LogTemp, Display, TEXT("Workflow server is running : %s"), *Now.ToString());
	}

	return 0;
}

void FHTTP_Thread_WF::Stop()
{
	this->Callback_HTTP_Stop();
	
	this->bStartThread = false;
}

bool FHTTP_Thread_WF::Toggle(bool bIsPause)
{
	if (!this->RunnableThread)
	{
		return false;
	}

	this->RunnableThread->Suspend(bIsPause);
	
	return true;
}

void FHTTP_Thread_WF::Callback_HTTP_Start()
{	
	auto Callback = [this](WFHttpTask* Task)
	{
		UHttpRequestWf* Request = NewObject<UHttpRequestWf>();
		Request->Task = Task;

		this->Parent_Actor->OnHttWf_Request(Request);
		this->Parent_Actor->DelegateHttpRequest.Broadcast(Request);
	};

	this->WF_Server = MakeShared<WFHttpServer, ESPMode::ThreadSafe>(Callback);
	this->WF_Server->start(this->Port_HTTP);
}

void FHTTP_Thread_WF::Callback_HTTP_Stop()
{
	this->WF_Server->stop();
}