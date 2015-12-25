#include "Header.h"
using namespace std;
struct nya {
	int x, y;
	char o;
};

void main(){
	gotoxy(width() / 2,0);
	nya girlanda[100];
	char * letter[2];
	letter[1] = '\0';
	int GirCount = 0;
	int heightOfTriangle = 5;
	int iter = 0;
	for (int i = 0;i < 3;i++) {//Цикл треугольника
		for (int j = 0; j < heightOfTriangle; j++) {//Цикл строк
			gotoxy(width() / 2 - iter, where('Y'));
			for (int k = 0; k < 2 * iter + 1;k++) {
				if (rand() % 30 < 10) {
					girlanda[GirCount].x = where('X');
					girlanda[GirCount].y = where('Y');
					switch (rand() % 3) {
						case 0: {
							girlanda[GirCount].o = 'o';
							color('o');
							break;
						}
						case 1: {
							girlanda[GirCount].o = '0';
							color('0');
							break;
						}
						case 2: {
							girlanda[GirCount].o = 'O';
							color('O');
							break;
						}
						
					}
					GirCount += 1;
				}
				else green('*');
			};
			printf_s("%c", '\n');
			iter++;
		}
		iter -= 2;
		heightOfTriangle += 1;
	}
	SetColor(Brown, Black);
	for (int i = 0; i < 4;i++) {
			gotoxy(width() / 2 - 2, where('Y'));
			printf("*****\n");
	}
	iter = 0;
	while (true){
		gotoxy(girlanda[iter].x, girlanda[iter].y);
		color(girlanda[iter].o);
		iter++;
		if (iter >= GirCount) {
			iter = 0;
			Sleep(100);
		}
	}
	_getch();
}