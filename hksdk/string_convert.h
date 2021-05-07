#pragma once
#include <windows.h>
#include <sstream>
#include <string>
#include <memory>
#include "c_defer.hpp"

std::wstring UTF8ToUnicode(const char* str);

std::string UnicodeToUTF8(const wchar_t* str);

std::wstring ANSIToUnicode(const char* str);

std::string UnicodeToANSI(const wchar_t* str);

std::string ANSIToUTF8(const char* str);

std::string UTF8ToANSI(const char* str);

static std::stringstream stream;

template<class out_type, class in_value>
static out_type convert(const in_value& t)
{
	stream.clear();
	stream.str("");
	stream << t;
	out_type result;
	stream >> result;

	return result;
}

template <typename... Args>
std::string format(const char* fmt, Args... args) {
	auto size = snprintf(nullptr, 0, fmt, args...);
	if (!size) {
		return nullptr;
	}
	size += 1;
	auto formatted = new char[size]();
	defer(if (formatted) {
		delete[]formatted; formatted = nullptr;
	});
	sprintf_s(formatted, size, fmt, args...);
	return formatted;
}