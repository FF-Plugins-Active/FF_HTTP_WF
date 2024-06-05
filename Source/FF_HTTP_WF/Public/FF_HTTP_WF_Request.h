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

// Custom Includes.
#include "FF_HTTP_WF_Enums.h"

#include "FF_HTTP_WF_Request.generated.h"

using namespace protocol;

UCLASS(BlueprintType)
class FF_HTTP_WF_API UHttpRequestWf : public UObject
{
	GENERATED_BODY()

private:

	virtual int ConvertToWfStatus(EWfStatusCodes In_Status);
	virtual const char* ConvertToWfMime(EWfContentTypes In_ContenTypes);

public:

	WFHttpTask* Task = nullptr;

	UFUNCTION(BlueprintCallable)
	virtual bool SendResponse_String(TMap<FString, FString> In_Headers, FString In_Response, EWfStatusCodes In_Status = EWfStatusCodes::OK_200, EWfContentTypes In_ContentTypes = EWfContentTypes::Text_Plain);

	UFUNCTION(BlueprintCallable)
	virtual bool GetRequestUri(FString& Out_Uri);

};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateRequestWf, UHttpRequestWf*, Request);