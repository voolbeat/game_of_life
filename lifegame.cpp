#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "lifegame.h"

/* ����������� ���� */
#define WORLDWIDTH 39
#define WORLDHEIGHT 20

/* ������� �������������� ��������� ����� */
#define CHAR_ALIVE '*'
#define CHAR_DEAD ' '

/* ������� ��������� ����� */
static int world[WORLDWIDTH][WORLDHEIGHT];

/* ��������� ����� ���������� ����������� */
static int nextstates[WORLDWIDTH][WORLDHEIGHT];

/* �������������� ��� ������� �������� ��������,
���������� ��� ������ ���������� ��������� � DEAD */
void initialize_world(void) {
	int i, j;

	for (i = 0; i < WORLDWIDTH; i++)
		for (j = 0; j < WORLDHEIGHT; j++)
			world[i][j] = nextstates[i][j] = DEAD;
	/* ������ "������" */
	world[1][2] = ALIVE;
	world[3][1] = ALIVE;
	world[3][2] = ALIVE;
	world[3][3] = ALIVE;
	world[2][3] = ALIVE;
}

int get_world_width(void) {
	return WORLDWIDTH;
}

int get_world_height(void) {
	return WORLDHEIGHT;
}

int get_cell_state(int x, int y) {
	if (x < 0 || x >= WORLDWIDTH || y < 0 || y >= WORLDHEIGHT)
		return DEAD;
	return world[x][y];
}

void set_cell_state(int x, int y, int state) {
	if (x < 0 || x >= WORLDWIDTH || y < 0 || y >= WORLDHEIGHT) {
		fprintf(stderr, "Error: coordinates (%d,%d) are invalid.\n", x, y);
		abort();
	}
	nextstates[x][y] = state;
}

void display(void) {
	char worldstr[2 * WORLDWIDTH + 2];
	int i, j;

	worldstr[2 * WORLDWIDTH + 1] = '\0';
	worldstr[0] = '+';
	for (i = 1; i < 2 * WORLDWIDTH; i++)
		worldstr[i] = '-';
	worldstr[2 * WORLDWIDTH] = '+';
	puts(worldstr);
	for (i = 0; i <= 2 * WORLDWIDTH; i += 2)
		worldstr[i] = '|';
	for (i = 0; i < WORLDHEIGHT; i++) {
		for (j = 0; j < WORLDWIDTH; j++)
			worldstr[2 * j + 1] = world[j][i] == ALIVE ? CHAR_ALIVE : CHAR_DEAD;
		puts(worldstr);
	}
	worldstr[0] = '+';
	for (i = 1; i < 2 * WORLDWIDTH; i++)
		worldstr[i] = '-';
	worldstr[2 * WORLDWIDTH] = '+';
	puts(worldstr);
}