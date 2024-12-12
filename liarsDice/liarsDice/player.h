#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>

using namespace std;

class Player
{
private:
	string player_name;
	int playerDice[5];
	int matchDice;

public:
	void SetName(string);
	string GetName();
	void RollDice();
	void ShowDice();
	int CheckDice(int diceVal);
};

	void Player::SetName(string name) {
		player_name = name;
	}

	string Player::GetName() {
		return player_name;
	}

	void Player::RollDice() {
		int elapsed_seconds = time(nullptr);
		srand(elapsed_seconds);

		for (int i = 0; i < 5; i++) {
			int die = rand() % 6;
			die = die + 1;
			playerDice[i] = die;
		}
	}
	void Player::ShowDice() {
		cout << "\n";
		for (int i = 0; i < 5; i++) {
			cout << playerDice[i] << " ";
		}
		cout << "\n\n";
	}
	int Player::CheckDice(int diceVal) {
		for (int i = 0; i < 5; i++) {
			if (playerDice[i] == diceVal) {
				matchDice++;
			}
		}
		return matchDice;
	}