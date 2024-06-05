#include "FF_HTTP_WF_Request.h"

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