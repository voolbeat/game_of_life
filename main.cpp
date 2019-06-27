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


