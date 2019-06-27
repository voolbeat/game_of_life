#include "lifegame.h"

/* количество поколений */
#define NUM_GENERATIONS 100

/* функция устанавливает состояние всех ячеек
следующего поколения и вызывает
finalize_evolution() для обновления текущего состояния мира
на следующее поколение */
void next_generation(void);

/* функция возвращает состояние ячейки в позиции (x,y)
в следующем поколении в соответствии с правилами игры "Жизнь" */
int get_next_state(int x, int y);

/* функция вычисляет количество живых соседей ячейки в позиции (x,y) */
int num_neighbors(int x, int y);

int main(void)
{
	int n;

	/* инициализирует мир */
	initialize_world();

	return 0;
}

int get_next_state(int x, int y) {
	// получим количество соседей и состояние данной клетки
	int neighbors = num_neighbors(x, y), state = get_cell_state(x, y);

	// проверим условия из правил игры, когда клетка жива
	if (state == 0 && neighbors == 3) return ALIVE;
	if (state == 1 && (neighbors == 2 || neighbors == 3)) return ALIVE;
	
	//во всех остальных случаях клетка мертва
	return DEAD;
}

int num_neighbors(int x, int y) {
	int count = 0;
	// сдвиги, чтобы получить соседей от данной клетки х у
	int offset[8][2] = { { -1,-1 },{ -1,0 },{ -1,1 },
	{ 0,1 },{ 0,-1 },
	{ 1,-1 },{ 1,0 },{ 1,1 } };
	// пробежимся по всем 8 соседям и посчитаем количество живых соседей в переменную count
	for (int i = 0; i < 8; i++) {
		count = count + get_cell_state(x + offset[i][0], y + offset[i][1]);
	}
	return count;
}
