#pragma once

#include "file.h"
#include "windows.h"
#include "c_defer.hpp"

bool FileExits(const wchar_t* path) {
	auto hfile = CreateFileW(path, GENERIC_READ, NULL, nullptr, OPEN_EXISTING, NULL, nullptr);
	defer(if (hfile != INVALID_HANDLE_VALUE)
	{
		CloseHandle(hfile);
	});
	return hfile != INVALID_HANDLE_VALUE;
}