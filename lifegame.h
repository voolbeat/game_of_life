#ifndef LIFEGAME_H_
#define LIFEGAME_H_

/* ��������� ��������� */
#define DEAD 0
#define ALIVE 1

/* initialize_world -- ��������� ����, ��� ������ �������� ���� ����������������
������ (ALIVE) ��� �������� (DEAD); ��� ������ ���������� ���������
���������������� �������� (DEAD) */
void initialize_world(void);

/* ���������� ������ (width) � ������ (height) ���� */
int get_world_width(void);
int get_world_height(void);

/* ���������� ��������� (����� ��� �������) ������ � ������������ (x,y) �� �������� ����;
��� x = 0,...,width-1 � y = 0,...,height-1; ���������� ������� (DEAD)
��� ����� ��� ����� ��������� */
int get_cell_state(int x, int y);

/* ������������� ��������� ������ (����� ��� �������) � ������� (x,y) �
��������� ���������; �������� �������� ��������� ����� ��, ��� � �
get_cell_state(); �������� abort() ���� ������� ������������ ���������� */
void set_cell_state(int x, int y, int state);

/* ������� ������� ��������� ���� �� ������� */
void output_world(void);

#endif /* LIFEGAME_H_ */

