#pragma once

#include "CoreMinimal.h"

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

#include "FF_HTTP_WF_Request.generated.h"

UCLASS(BlueprintType)
class FF_HTTP_WF_API UHttpRequestWf : public UObject
{
	GENERATED_BODY()

public:

	WFHttpTask* Task = nullptr;

	UFUNCTION(BlueprintCallable)
	virtual bool SendResponse(FString In_Response = "<html>Hello World!</html>");

	UFUNCTION(BlueprintCallable)
	virtual bool GetRequestUri(FString& Out_Uri);
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateRequestWf, UHttpRequestWf*, Request);