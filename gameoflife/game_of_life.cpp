#include <iostream>
#include <ctime>
#include "game_of_life.h";
using namespace std;

game_of_life::game_of_life() {
	
	for (int i = 0; i < ROWS; ++i)
	{
		for (int j = 0; j < COLS; ++j) {
			if ((1 + rand() % 100) < 25) _generation[i][j] = 1; 
			else _generation[i][j] = 0;
		}
	}
}

void game_of_life::next_generation()  {
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			if (cell_taken(i, j)) {
				if (count_grid(i, j) < 2 || count_grid(i, j) > 3) _next_generation[i][j] = 0;
				else _next_generation[i][j] = 1;
			}
			else {
				if (count_grid(i, j) == 3) _next_generation[i][j] = 1;
				else _next_generation[i][j] = 0;
			}
		}
	}

	// Copy next generation to current generation
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			_generation[i][j] = _next_generation[i][j];
		}
	}

}

void game_of_life::draw() {

	system("CLS");

	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			if (cell_taken(i, j)) cout << '*';
			else cout << '-';
		}
		cout << endl;
	}
}

bool game_of_life::random_value() {
	return rand() % 2 == 0;
}

bool game_of_life::cell_taken(int i, int j) {
	// Check if the cell is out of bounds
	if (i < 0 || j < 0 || i >= ROWS || j >= COLS) return 0;
	return _generation[i][j];
}

int game_of_life::count_grid(int i, int j) {
	int count = 0;
	for (int k = -1; k <= 1; ++k)
	{
		count += cell_taken(i - 1, j + k);
		count += cell_taken(i + 1, j + k);
	}
	count += cell_taken(i, j - 1);
	count += cell_taken(i, j + 1);
	return count;
}

