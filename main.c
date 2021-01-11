#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ncurses.h>

void pfigure();
void movement();

int x = 0;
int y = 0;
int flen = 5;
int fhig = 5;
int maxX;
int maxY;

int main(){
	initscr();
	cbreak();
	noecho();
	keypad(stdscr,TRUE);
	nodelay(stdscr,TRUE);
	curs_set(0);
	getmaxyx(stdscr,maxY,maxX);

	x = maxX / 2;
	y = (maxY / 2) + fhig;

	while(1){
		movement();
		pfigure();

		refresh();
		clear();
		getmaxyx(stdscr,maxY,maxX); /* Check screen size */
		usleep(4000);
	}
	endwin();

	exit(EXIT_SUCCESS);
}

void pfigure(){
	mvaddstr(y-5,x,"  _  ");
	mvaddstr(y-4,x," /o\\ ");
	mvaddstr(y-3,x," |o| ");
	mvaddstr(y-2,x,"<ooo>");
	mvaddstr(y-1,x," ||| ");
}

void movement(){
	int ch = getch();

	switch(ch){

		case KEY_LEFT:
		case 97:
			if(x > 0){
				x--;
			}
			break;

		case KEY_RIGHT:
		case 100:
			if(x+flen < maxX){
				x++;
			}
			break;


		case KEY_UP:
		case 119:
			if(y-fhig > 0){
				y--;
			}
			break;

		case KEY_DOWN:
		case 115:
			if(y < maxY){
				y++;
			}
			break;
	}
}
