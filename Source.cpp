#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <Windows.h>

const int PADDLE_SIZE = 5;
const int WIDTH = 30;
const int HEIGHT = 30;

bool game_on = true;

int player_1_score = 0;

struct Board {

	char line1[WIDTH]    = { "#                          #" };
	char line2[WIDTH]  = { "\n#                          #" };
	char line3[WIDTH]  = { "\n#                          #" };
	char line4[WIDTH]  = { "\n#                          #" };
	char line5[WIDTH]  = { "\n#                          #" };
	char line6[WIDTH]  = { "\n#                          #" };
	char line7[WIDTH]  = { "\n#                          #" };
	char line8[WIDTH]  = { "\n#                          #" };
	char line9[WIDTH]  = { "\n#                          #" };
	char line10[WIDTH] = { "\n#                          #" };
	char line11[WIDTH] = { "\n#                          #" };
	char line12[WIDTH] = { "\n#                          #" };
	char line13[WIDTH] = { "\n#                          #" };
	char line14[WIDTH] = { "\n#                          #" };
	char line15[WIDTH] = { "\n#                          #" };
	char line16[WIDTH] = { "\n#                          #" };
	char line17[WIDTH] = { "\n#                          #" };
	char line18[WIDTH] = { "\n#                          #" };
	char line19[WIDTH] = { "\n#                          #" };
	char line20[WIDTH] = { "\n#                          #" };
	char line21[WIDTH] = { "\n#                          #" };
	char line22[WIDTH] = { "\n#                          #" };
	char line23[WIDTH] = { "\n#                          #" };
	char line24[WIDTH] = { "\n#                          #" };
	char line25[WIDTH] = { "\n#                          #" };
	char line26[WIDTH] = { "\n#                          #" };
	char line27[WIDTH] = { "\n#                          #" };
	char line28[WIDTH] = { "\n#                          #" };
	char line29[WIDTH] = { "\n#                          #" };
	char line30[WIDTH] = { "\n#                          #" };

	char* rows[30] = { line1,line2,line3,line4,line5,line6,line7,line8,line9,line10,
		line11,line12,line13,line14,line15,line16,line17,line18,line19,line20,
		line21,line22,line23,line24,line25,line26,line27,line28,line29,line30 };
};

struct brick {
	int x;
	int y;
};

struct player {
	int x;
	int y;
	bool alive;
};

void create(brick *array[]);
void draw(brick *array[], player *me);
void update(brick *array[]);

void main() {
	int level = 0;

	player* me = new player;
	me->alive = true;
	me->x = 14;
	me->y = 28;

	brick* bricks[30];
	create(bricks);
	
	while (true) {
		Sleep(1000 - level);
		draw(bricks, me);
		update(bricks);
		level+=5;
	}
}

void draw(brick* bricks[], player *me) {
	system("cls");
	if (GetAsyncKeyState(VK_UP)) {
		if (me->y < 0) {
			me->y--;
		}
	}
	if (GetAsyncKeyState(VK_DOWN)) {
		if (me->y > 29) {
			me->y++;
		}
	}
	if (GetAsyncKeyState(VK_LEFT)) {
		if (me->x > 2) {
			me->x--;
		}
	}
	if (GetAsyncKeyState(VK_RIGHT)) {
		if (me->x < 29) {
			me->x++;
		}
	}
	Board *board = new Board;
	
	board->rows[me->y][me->x] = '_';

	for (int i = 0; i < 30; i++) {
		if (bricks[i]->x != 0) {
			board->rows[i][bricks[i]->x] = 'o';
		}
		std::cout << board->rows[i];
	}


}

void update(brick* bricks[]) {
	for (int i = 29; i > 0; i--) {
		bricks[i]->x = bricks[i-1]->x;
	}
	bricks[0]->x = rand() % 26 + 3;
}

void update(player* me) {
	if (GetAsyncKeyState(VK_UP)) {
		if (me->y < 0) {
			me->y--;
		}
	}
	if (GetAsyncKeyState(VK_DOWN)) {
		if (me->y > 29) {
			me->y++;
		}
	}
	if (GetAsyncKeyState(VK_LEFT)) {
		if (me->x > 2) {
			me->x--;
		}
	}
	if (GetAsyncKeyState(VK_RIGHT)) {
		if (me->x < 29) {
			me->x++;
		}
	}
}

void create(brick* bricks[]) {
	for (int i = 0; i < 30; i++) {
		brick* new_brick = new brick;
		bricks[i] = new_brick;
		bricks[i]->x = 0;
		bricks[i]->y = i;
	}
}