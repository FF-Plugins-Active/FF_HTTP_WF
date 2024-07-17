#pragma once

#include "CoreMinimal.h"

// Custom Includes.
#include "FF_HTTP_WF_Includes.h"
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
	virtual bool SendResponse_Buffer(TMap<FString, FString> In_Headers, TArray<uint8> In_Response, EWfStatusCodes In_Status = EWfStatusCodes::OK_200, EWfContentTypes In_ContentTypes = EWfContentTypes::Text_Plain);

	UFUNCTION(BlueprintCallable)
	virtual bool GetRequestUri(FString& Out_Uri);

	UFUNCTION(BlueprintCallable)
	virtual bool GetRequestQuery(TMap<FString, FString>& Out_Query, FString& Query_Title);

	UFUNCTION(BlueprintCallable)
	virtual bool GetAllHeaders(TMap<FString, FString>& Out_Headers);

	UFUNCTION(BlueprintCallable)
	virtual bool GetHeader(FString& ErrorCode, FString& Value, FString Key);

	UFUNCTION(BlueprintCallable)
	virtual bool GetBody(FString& Out_Body);

	UFUNCTION(BlueprintCallable)
	virtual bool GetMethod(FString& Out_Method);

	UFUNCTION(BlueprintCallable)
	virtual bool GetContentLenght(int64& Out_Lenght);

	UFUNCTION(BlueprintCallable)
	virtual bool GetClientAddress(FString& Out_Address);

};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateRequestWf, UHttpRequestWf*, Request);