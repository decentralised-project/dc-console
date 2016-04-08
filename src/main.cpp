#include <iostream>
#include <cstdlib>
#include <list>
#include <iomanip>
#include <string>

#if WIN32
	#include <windows.h>
#else
	#include <sys/ioctl.h>
	#include <stdio.h>
	#include <unistd.h>
#endif

int main(int argc, char** argv)
{
	std::list<std::wstring> consoleLines;
	int columns, rows;
	bool isRunning = true;

	consoleLines.push_front(std::wstring(L"[00:00] System: dc-console v1.0"));

	while (isRunning)
	{
#if WIN32
		std::system("cls");

		CONSOLE_SCREEN_BUFFER_INFO csbi;
		GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
		columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
		rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
#else
		std::system("clear");

		struct winsize w;
		ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
		columns = w.ws_col;
		rows = w.ws_row;
#endif

		for (int i = 0; i < rows - 1; ++i)
		{
			if (consoleLines.size() > rows - i - 2)
			{
				std::list<std::wstring>::iterator it = std::next(consoleLines.begin(), rows - i - 2);
				std::cout << std::setiosflags(std::ios::left) << std::setw(columns) << std::string(it->begin(), it->end());
			}
			else
				std::cout << std::setiosflags(std::ios::left) << std::setw(columns) << " ";
		}
		std::cout << "> ";

		std::string line; 
		std::getline(std::cin, line);
		if (line == "exit")
			isRunning = false;
		else
			consoleLines.push_front(std::wstring(L"[00:00] User: ").append(std::wstring(line.begin(), line.end())));

	}

	return 0;
}