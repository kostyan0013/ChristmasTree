#include "Header.h"

int width() {
	HANDLE hWndConsole = GetStdHandle(-12);
	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
	GetConsoleScreenBufferInfo(hWndConsole, &consoleInfo);
	return consoleInfo.srWindow.Right - consoleInfo.srWindow.Left + 1;
}

void gotoxy(int column, int line) {
	COORD coord;
	coord.X = column;
	coord.Y = line;
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE),
		coord
		);
}

int where(char xy) {
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	COORD result;
	if (!GetConsoleScreenBufferInfo(
		GetStdHandle(STD_OUTPUT_HANDLE),
		&csbi
		))
		return -1;
	result = csbi.dwCursorPosition;
	if (xy == 'X') return result.X;
	else if (xy == 'Y') return result.Y;
	return 0;
}

void SetColor(ConsoleColor text, ConsoleColor background) {
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

void green(char sym) {
	SetColor(Green, Black);
	printf("%c", sym);
}

void color(char sym) {
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)(rand() % 15 + 1));
	printf("%c", sym);
}
