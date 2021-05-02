#pragma once

#include <cstdio>
#include <locale>
#include <clocale>
#include <codecvt>
#include <io.h>
#include <fcntl.h>
#include <windows.h>
#include <cwctype>

class utf16_console
{
public:
	utf16_console()
	{

		fflush(stdout);
		_setmode(_fileno(stdout), _O_U16TEXT);
		_setmode(_fileno(stdin), _O_U16TEXT);
		// Consider this
		//std::ios_base::sync_with_stdio(false);
		GetConsoleMode(GetStdHandle(STD_OUTPUT_HANDLE), &mode);
		if (!(mode & ENABLE_VIRTUAL_TERMINAL_PROCESSING))
		{
			SetConsoleMode(GetStdHandle(STD_OUTPUT_HANDLE), mode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
		}
	}

	utf16_console(const utf16_console&) = delete;
	utf16_console(utf16_console&&) = delete;

	~utf16_console()
	{
		SetConsoleMode(GetStdHandle(STD_OUTPUT_HANDLE), mode);
	}
private:
	DWORD mode;
};

inline utf16_console utf16_console_object;