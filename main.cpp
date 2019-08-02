#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>
#include <iomanip>

using namespace std;

struct player {

	int health;
	int pos_x;  //x position on board
	int pos_y;  //y position
	int damage;
	char symbol;
}player1;

int player_damage() {

	player1.health -= player1.damage;
	return player1.health;
}

int main() {

	bool update = false;
	
	player player1;  //the object of the player struct
	player1.health = 100;  //health starts at 100 pts
	player1.pos_x = 3;
	player1.pos_y = 1;
	player1.damage = rand()%31;  //randomly generates number of damage points 0 to 30
	player1.symbol = '^';
	int points = 100;  //initialize points to 100

	cout << "Welcome to the Dungeon Crawler\n" << endl;
	cout << "Use 'WASD' to move around the board" << endl;
	cout << "Press 'Q' to quit at any time" << endl;
	cout << "PLAYER HEALTH: " << player1.health << endl;
	cout << "TOTAL POINTS: " << points;
	cout << endl;
	cout << "--------------------";

//The game board
	const char width = 20;
	const char height = 20;

	char board[height][width] = 

		{ { 'x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x' },
		{ 'x',' ','$',' ',' ',' ','x','x','x','x','0',' ','x',' ',' ','$','x','0','$','x' },
		{ 'x',' ','x',' ','x',' ','x','$',' ',' ',' ',' ','x',' ',' ',' ','x',' ',' ','x' },
		{ 'x',' ','x',' ','x',' ','x','x','x','x','x',' ','x',' ','x',' ','x',' ','x','x' },
		{ 'x',' ','x',' ','x',' ',' ',' ',' ','x','x',' ','x',' ','x',' ',' ',' ','x','x' },
		{ 'x',' ','x',' ','x','x','x','x',' ','$','x',' ','x',' ','x',' ','x',' ',' ','x' },
		{ 'x',' ','x',' ','x','x','x','x',' ',' ',' ',' ',' ',' ',' ',' ','x','x',' ','x' },
		{ 'x',' ',' ',' ','x',' ','$','x',' ','x','x',' ','x','x',' ',' ','x','$',' ','x' },
		{ 'x',' ','x','x','x',' ',' ','x',' ','x','x',' ','0','x',' ',' ',' ','x',' ','x' },
		{ 'x',' ',' ',' ','x','$',' ','x',' ','x','x',' ','x','x',' ','x',' ','x',' ','x' },
		{ 'x',' ','x','x','x',' ',' ','x',' ','x','x',' ','x','x',' ','x',' ','0',' ','x' },
		{ 'x',' ','x','x','x',' ',' ','x',' ','x','x',' ','$','x',' ','x',' ','x',' ','x' },
		{ 'x',' ','x','x','x','0',' ',' ',' ','x',' ',' ',' ',' ',' ','x',' ','x',' ','x' },
		{ 'x',' ','x','x','x','x','x','x',' ','x',' ','x','x','x','x','x',' ','x',' ','x' },
		{ 'x',' ','$','x','x','x','x','x',' ','x',' ','x',' ',' ','x','x',' ','$',' ','x' },
		{ 'x',' ','x','x','x','x','x','x',' ','x',' ','x',' ',' ','0','x',' ','x',' ','x' },
		{ 'x',' ',' ',' ',' ',' ','$','x',' ','x',' ','x',' ',' ',' ','x',' ','x',' ','x' },
		{ 'x',' ','x','x','x',' ','0','x',' ','x',' ','x','$','x',' ',' ',' ',' ',' ','x' },
		{ 'x',' ',' ',' ',' ',' ',' ',' ',' ','x',' ',' ',' ',' ',' ','x','x',' ',' ','x' },
		{ 'x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x' } };
	

////////Printing the game board

	for (int y = 0; y < height; y++) {
		cout << endl;
		for (int x  = 0; x < width; x++) {
			cout << board[y][x];
		}
	}

/////////////////////////////////

	char move_key = 'd';
	while (move_key != 'q') {   //game loop starts here

		cin >> move_key;
		update = true;


		if (update == true) {

			system("CLS");
			board[player1.pos_x][player1.pos_y] = player1.symbol;

		}

	switch(move_key) {

		case('w'):  // Up
			update = true;
			if (board[player1.pos_y - 1][player1.pos_x] != 'x') {
				board[player1.pos_y][player1.pos_x] = ' ';
				player1.pos_y--;

				if (board[player1.pos_y][player1.pos_x] == '0') {
					player_damage();
				}
				if (board[player1.pos_y][player1.pos_x] == '$') {
					points += 20;
				}

				cout << player1.pos_y << ' ' << player1.pos_x << endl;
			}

		break;

		case('s'):  // Down
			update = true;

			if (board[player1.pos_y + 1][player1.pos_x] != 'x') {
				board[player1.pos_y][player1.pos_x] = ' ';
				player1.pos_y++;

				if (board[player1.pos_y][player1.pos_x] == '0') {
					player_damage();
				}
				if (board[player1.pos_y][player1.pos_x] == '$') {
					points += 20;
				}
				cout << player1.pos_y << ' ' << player1.pos_x << endl;
			}

		break;

		case('a'):  // Left
			update = true;

			if (board[player1.pos_y][player1.pos_x - 1] != 'x') {
				board[player1.pos_y][player1.pos_x] = ' ';
				player1.pos_x--;

				if (board[player1.pos_y][player1.pos_x] == '0') {
					player_damage();
				}
				if (board[player1.pos_y][player1.pos_x] == '$') {
					points += 20;
				}
				cout << player1.pos_y << ' ' << player1.pos_x << endl;
			}

		break;

		case('d'):  // Right
			update = true;

			if (board[player1.pos_y][player1.pos_x + 1] != 'x') {
				board[player1.pos_y][player1.pos_x] = ' ';
				player1.pos_x++;

				if (board[player1.pos_y][player1.pos_x] == '0') {
					player_damage();
				}
				if (board[player1.pos_y][player1.pos_x] == '$') {
					points += 20;
				}
				cout << player1.pos_y << ' ' << player1.pos_x << endl;
			}

		break;
	}

	if (player1.health == 0 || points == 0) {

		move_key = 'q';
		cout << "Game Over\n";
	}

	if (points == 300) {
		move_key = 'q';
		cout << "You Win\n";
	}


	}//while

	system("pause");
	
	return 0;
}