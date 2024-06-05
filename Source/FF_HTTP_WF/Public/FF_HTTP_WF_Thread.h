// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

// UE Includes.
#include "HAL/Runnable.h"

THIRD_PARTY_INCLUDES_START

#ifdef _WIN64
#define UI UI_ST
#define WIN32_LEAN_AND_MEAN
#include "Windows/AllowWindowsPlatformTypes.h"

#include <winsock2.h>
#include <ws2tcpip.h>
#include <mswsock.h>
#include <stdio.h>

#include "workflow/WFHttpServer.h"
#include "workflow/HttpUtil.h"

#include "Windows/HideWindowsPlatformTypes.h"

#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")

#undef UI
#endif
THIRD_PARTY_INCLUDES_END

// Fordward Declerations.
class FRunnableThread;
class AHTTP_Server_WF;

class FHTTP_Thread_WF : public FRunnable
{
	
public:	
	
	// Sets default values for this actor's properties
	FHTTP_Thread_WF(AHTTP_Server_WF* In_Parent_Actor);

	// Destructor.
	virtual ~FHTTP_Thread_WF() override;

	virtual bool Init() override;

	virtual uint32 Run() override;

	virtual void Stop() override;

	virtual bool Toggle(bool bIsPause);

	AHTTP_Server_WF* Parent_Actor = nullptr;

private:

	bool bStartThread = false;
	FRunnableThread* RunnableThread = nullptr;
	
	TSharedPtr<WFHttpServer, ESPMode::ThreadSafe> WF_Server;

	virtual void Callback_HTTP_Start();
	virtual void Callback_HTTP_Stop();

	FString API_URI = "";
	int32 Port_HTTP = 8081;
	int32 Port_HTTPS = 8443;
	int32 ThreadNum = 4;

};