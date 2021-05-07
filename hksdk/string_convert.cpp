#include "string_convert.h"

#define new_str(_name,_len,_type) std::shared_ptr<_type> ##_name(new _type[_len + 1]); RtlZeroMemory(##_name.get(), _len + 1);

std::wstring UTF8ToUnicode(const char* str)
{
	auto len = MultiByteToWideChar(CP_UTF8, 0, str, -1, NULL, 0);
	new_str(result, len, wchar_t);
	MultiByteToWideChar(CP_UTF8, 0, str, -1, result.get(), len);
	return std::wstring(result.get());
}

std::string UnicodeToUTF8(const wchar_t* str)
{
	auto len = WideCharToMultiByte(CP_UTF8, 0, str, -1, NULL, 0, NULL, NULL);
	new_str(result, len, char);
	WideCharToMultiByte(CP_UTF8, 0, str, -1, result.get(), len, NULL, NULL);
	return std::string(result.get());
}

std::wstring ANSIToUnicode(const char* str)
{
	auto len = MultiByteToWideChar(CP_ACP, 0, str, -1, NULL, 0);
	new_str(result, len, wchar_t);
	MultiByteToWideChar(CP_ACP, 0, str, -1, result.get(), len);
	return std::wstring(result.get());
}

std::string UnicodeToANSI(const wchar_t* str)
{
	auto len = WideCharToMultiByte(CP_ACP, 0, str, -1, NULL, 0, NULL, NULL);
	new_str(result, len, char);
	WideCharToMultiByte(CP_ACP, 0, str, -1, result.get(), len, NULL, NULL);
	return std::string(result.get());
}

std::string ANSIToUTF8(const char* str)
{
	return UnicodeToUTF8(ANSIToUnicode(str).c_str());
}

std::string UTF8ToANSI(const char* str)
{
	return UnicodeToANSI(UTF8ToUnicode(str).c_str());
}

