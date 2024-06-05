#include "FF_HTTP_WF_Request.h"

int UHttpRequestWf::ConvertToWfStatus(EWfStatusCodes In_Status)
{
	switch (In_Status)
	{
	case EWfStatusCodes::Continue_100:
		return 100;

	case EWfStatusCodes::Switching_Protocols_101:
		return 101;

	case EWfStatusCodes::Processing_102:
		return 102;

	case EWfStatusCodes::OK_200:
		return 200;

	case EWfStatusCodes::Created_201:
		return 201;

	case EWfStatusCodes::Accepted_202:
		return 202;

	case EWfStatusCodes::Non_Authoratative_Information_203:
		return 203;

	case EWfStatusCodes::No_Content_204:
		return 204;

	case EWfStatusCodes::Reset_Content_205:
		return 205;

	case EWfStatusCodes::Partial_Content_206:
		return 206;

	case EWfStatusCodes::Multi_Status_207:
		return 207;

	case EWfStatusCodes::Already_Reported_208:
		return 208;

	case EWfStatusCodes::Im_Used_226:
		return 226;

	case EWfStatusCodes::Multiple_Choice_300:
		return 300;

	case EWfStatusCodes::Moved_Permanently_301:
		return 301;

	case EWfStatusCodes::Found_302:
		return 302;

	case EWfStatusCodes::See_Other_303:
		return 303;

	case EWfStatusCodes::Not_Modified_304:
		return 304;

	case EWfStatusCodes::Use_Proxy_305:
		return 305;

	case EWfStatusCodes::Switch_Proxy_306:
		return 306;

	case EWfStatusCodes::Temporary_Redirect_307:
		return 307;

	case EWfStatusCodes::Permanent_Redirect_308:
		return 308;

	case EWfStatusCodes::Bad_Request_400:
		return 400;

	case EWfStatusCodes::Unauthorized_401:
		return 401;

	case EWfStatusCodes::Payment_Required_402:
		return 402;

	case EWfStatusCodes::Forbidden_403:
		return 403;

	case EWfStatusCodes::Not_Found_404:
		return 404;

	case EWfStatusCodes::Method_Not_Allowed_405:
		return 405;

	case EWfStatusCodes::Not_Acceptable_406:
		return 406;

	case EWfStatusCodes::Proxy_Authentication_Required_407:
		return 407;

	case EWfStatusCodes::Request_Timeout_408:
		return 408;

	case EWfStatusCodes::Conflict_409:
		return 409;

	case EWfStatusCodes::Gone_410:
		return 410;

	case EWfStatusCodes::Lenght_Required_411:
		return 411;

	case EWfStatusCodes::Precondition_Failed_412:
		return 412;

	case EWfStatusCodes::Payload_Too_Large_413:
		return 413;

	case EWfStatusCodes::Uri_Too_Long_414:
		return 414;

	case EWfStatusCodes::Unsupported_Media_Type_415:
		return 415;

	case EWfStatusCodes::Range_Not_Satisfiable_416:
		return 416;

	case EWfStatusCodes::Expectation_Failed_417:
		return 417;

	case EWfStatusCodes::Misdirected_Request_421:
		return 421;

	case EWfStatusCodes::Unprocessable_Entity_422:
		return 422;

	case EWfStatusCodes::Locked_423:
		return 423;
	
	case EWfStatusCodes::Failed_Dependency_424:
		return 424;

	case EWfStatusCodes::Upgrade_Required_426:
		return 426;

	case EWfStatusCodes::Precondition_Required_428:
		return 428;

	case EWfStatusCodes::Too_Many_Requests_429:
		return 429;

	case EWfStatusCodes::Request_Header_Fields_Too_Large_431:
		return 431;

	case EWfStatusCodes::Unavailable_For_Legal_Reasons_451:
		return 451;

	case EWfStatusCodes::Internal_Server_Error_500:
		return 500;

	case EWfStatusCodes::Not_Implemented_501:
		return 501;

	case EWfStatusCodes::Bad_Gateway_502:
		return 502;

	case EWfStatusCodes::Service_Unavailable_503:
		return 503;

	case EWfStatusCodes::Gateway_Timeout_504:
		return 504;

	case EWfStatusCodes::Http_Version_Not_Supported_505:
		return 505;

	case EWfStatusCodes::Variant_Also_Negotiates_506:
		return 506;

	case EWfStatusCodes::Insufficient_Storage_507:
		return 507;

	case EWfStatusCodes::Loop_Detected_508:
		return 508;

	case EWfStatusCodes::Not_Extended_510:
		return 510;

	case EWfStatusCodes::Network_Authentication_Required_511:
		return 511;

	default:
		return 404;
	}
}

const char* UHttpRequestWf::ConvertToWfMime(EWfContentTypes In_ContenTypes)
{
	switch (In_ContenTypes)
	{
	case EWfContentTypes::Application_7z:
		return "application/x-7z-compressed";

	case EWfContentTypes::Application_Atom:
		return "application/atom+xml";

	case EWfContentTypes::Application_Docx:
		return "application/vnd.openxmlformats-officedocument.wordprocessingml.document";

	case EWfContentTypes::Application_Eot:
		return "application/vnd.ms-fontobject";

	case EWfContentTypes::Application_Excel:
		return "application/vnd.ms-excel";

	case EWfContentTypes::Application_gRPC:
		return "application/grpc";

	case EWfContentTypes::Application_gzip:
		return "application/gzip";

	case EWfContentTypes::Application_JAR:
		return "application/java-archive";

	case EWfContentTypes::Application_JS:
		return "application/javascript";

	case EWfContentTypes::Application_Json:
		return "application/json";

	case EWfContentTypes::Application_M3U8:
		return "application/vnd.apple.mpegurl";

	case EWfContentTypes::Application_Octet_Stream:
		return "application/octet-stream";

	case EWfContentTypes::Application_PDF:
		return "application/pdf";

	case EWfContentTypes::Application_PPT:
		return "application/vnd.ms-powerpoint";

	case EWfContentTypes::Application_PPTX:
		return "application/vnd.openxmlformats-officedocument.presentationml.presentation";

	case EWfContentTypes::Application_RAR:
		return "application/x-rar-compressed";

	case EWfContentTypes::Application_RSS:
		return "application/rss+xml";

	case EWfContentTypes::Application_RTF:
		return "application/rtf";

	case EWfContentTypes::Application_URLENCODED:
		return "application/x-www-form-urlencoded";

	case EWfContentTypes::Application_WASM:
		return "application/wasm";

	case EWfContentTypes::Application_WORD:
		return "application/msword";

	case EWfContentTypes::Application_XHTML:
		return "application/xhtml+xml";

	case EWfContentTypes::Application_XLSX:
		return "application/vnd.openxmlformats-officedocument.spreadsheetml.sheet";

	case EWfContentTypes::Application_XML:
		return "application/xml";

	case EWfContentTypes::Application_ZIP:
		return "application/zip";

	case EWfContentTypes::Audio_AAC:
		return "audio/aac";

	case EWfContentTypes::Audio_M4A:
		return "audio/x-m4a";

	case EWfContentTypes::Audio_MP3:
		return "audio/mpeg";

	case EWfContentTypes::Audio_OGG:
		return "audio/ogg";

	case EWfContentTypes::Audio_OPUS:
		return "audio/opus";

	case EWfContentTypes::Audio_PCMA:
		return "audio/PCMA";

	case EWfContentTypes::Content_Type_Application:
		return "";

	case EWfContentTypes::Content_Type_Audio:
		return "";

	case EWfContentTypes::Content_Type_Font:
		return "";

	case EWfContentTypes::Content_Type_Image:
		return "";

	case EWfContentTypes::Content_Type_Multipart:
		return "";

	case EWfContentTypes::Content_Type_NONE:
		return "";

	case EWfContentTypes::Content_Type_Text:
		return "";

	case EWfContentTypes::Content_Type_Undefined:
		return "";

	case EWfContentTypes::Content_Type_Video:
		return "";

	case EWfContentTypes::Font_OTF:
		return "font/otf";

	case EWfContentTypes::Font_TTF:
		return "font/ttf";

	case EWfContentTypes::Font_WOFF:
		return "font/woff";

	case EWfContentTypes::Font_WOFF2:
		return "font/woff2";

	case EWfContentTypes::Image_BMP:
		return "image/x-ms-bmp";

	case EWfContentTypes::Image_GIF:
		return "image/gif";

	case EWfContentTypes::Image_ICO:
		return "image/x-icon";

	case EWfContentTypes::Image_JPG:
		return "image/jpeg";

	case EWfContentTypes::Image_PNG:
		return "image/png";

	case EWfContentTypes::Image_SVG:
		return "image/svg+xml";

	case EWfContentTypes::Image_TIFF:
		return "image/tiff";

	case EWfContentTypes::Image_WEBP:
		return "image/webp";

	case EWfContentTypes::Multiplart_Form_Data:
		return "multipart/form-data";

	case EWfContentTypes::Text_CSS:
		return "text/css";

	case EWfContentTypes::Text_CSV:
		return "text/csv";

	case EWfContentTypes::Text_Event_Stream:
		return "text/event-stream";

	case EWfContentTypes::Text_HTML:
		return "text/html";

	case EWfContentTypes::Text_Markdown:
		return "text/markdown";

	case EWfContentTypes::Text_Plain:
		return "text/plain";

	case EWfContentTypes::Video_3GPP:
		return "video/3gpp";

	case EWfContentTypes::Video_ASF:
		return "video/x-ms-asf";

	case EWfContentTypes::Video_AVI:
		return "video/x-msvideo";

	case EWfContentTypes::Video_FLV:
		return "video/x-flv";

	case EWfContentTypes::Video_M4V:
		return "video/x-m4v";

	case EWfContentTypes::Video_MNG:
		return "video/x-mng";

	case EWfContentTypes::Video_MOV:
		return "video/quicktime";

	case EWfContentTypes::Video_MP4:
		return "video/mp4";

	case EWfContentTypes::Video_MPEG:
		return "video/mpeg";

	case EWfContentTypes::Video_TS:
		return "video/mp2t";

	case EWfContentTypes::Video_WEBM:
		return "video/webm";

	case EWfContentTypes::Video_WMV:
		return "video/x-ms-wmv";

	default:
		return "text/plain";
	}
}

bool UHttpRequestWf::SendResponse_String(TMap<FString, FString> In_Headers, FString In_Response, EWfStatusCodes In_Status, EWfContentTypes In_ContentTypes)
{
	if (!this->Task)
	{
		return false;
	}

	this->Task->get_resp()->set_http_version("HTTP/1.1");

	// Set Mime Type.
	this->Task->get_resp()->add_header_pair("Content-Type", this->ConvertToWfMime(In_ContentTypes));

	// Add Headers.
	for (TPair<FString, FString> EachHeader : In_Headers)
	{
		this->Task->get_resp()->add_header_pair(TCHAR_TO_UTF8(*EachHeader.Key), TCHAR_TO_UTF8(*EachHeader.Value));
	}

	// Set Status.
	HttpUtil::set_response_status(this->Task->get_resp(), this->ConvertToWfStatus(In_Status));

	// Set Response as String.
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