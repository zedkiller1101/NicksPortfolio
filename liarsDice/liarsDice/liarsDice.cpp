// liarsDice.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 
//

#include <iostream>
#include <string>
#include "player.h"
using namespace std; 

int main() {
    Player p1;
    Player p2;
    Player p3;
    Player p4;
    Player p5;

    cout << "Liar's Dice Rules\n" // outputs the rules
        "\n"
        "The first player calls out two numbers : first, how many dice on the table he or she thinks have been rolled as a number between one and six.For example, player one could say \"two fives,\"\n"
        "which means he or she thinks there are at least two dice that are fives among all players (including his or her own). At this point, all players can accept what has been called out and move on to player two or call player\n"
        "one out, which will end the round and result in a winner or loser for the round.\n"
        "\n"
        "If player one calls out \"two fives,\" it does not matter whether player one has a five or not as bluffing is allowed in Liar\'s Dice. It only matters if another player believes player one is bluffing and calls him or her out on it.\n"
        "In that instance, all dice must be revealed. If player one is correct the player wins. If player one is wrong, then the player who called him / her out is the winner. The round is then over.\n"
        "\n"
        "If player one's call is accepted, then player two calls out a number. The first number must be greater than what player one called.For example, if player one called out \"two fives,\" player two must call out three or higher for his \n"
        "or her first number, so \"three fives,\" \"three fours,\" or \"four twos\" would all be acceptable. \"One five\" or \"two sixes\" would be unacceptable.\n"
        "\n"
        "Game play continues until someone is called out.\n"
        "\n";


    int playerNum = 0;

    cout << "How many players? (to a maximum of five)\n"; // prompts for how many players
    cin >> playerNum;

    if (playerNum < 2) { // filters for too few players
        cout << "Liar's dice requires at least two players. How many players?\n";
        cin >> playerNum;
    }
    if (playerNum > 5) { // caps the player count so I can make the program work
       cout << "This program cannot handle more than five players. How many players?\n";
       cin >> playerNum;
    }

    string playerName; // I wish I could set this up as a for statement, but I cannot generate an unlimited amount of Player classes

    cout << "\nWhat is player one's name?\n";
    cin >> playerName;

    p1.SetName(playerName);
    p1.RollDice();

    cout << "\nWhat is player two's name?\n";
    cin >> playerName;

    p2.SetName(playerName);
    p2.RollDice();

    if (playerNum >= 3) { // if playerNum is 3, 4, or 5, will ask player three's name and roll for them
        cout << "\nWhat is player three's name?\n";
        cin >> playerName;

        p3.SetName(playerName);
        p3.RollDice();
    }
    if (playerNum >= 4) { // if playerNum is 4, or 5, will ask player four's name and roll for them
        cout << "\nWhat is player four's name?\n";
        cin >> playerName;

        p4.SetName(playerName);
        p4.RollDice();
    }
    if (playerNum == 5) { // if playerNum is 5, will ask for player five's name and roll for them
        cout << "\nWhat is player five's name?\n";
        cin >> playerName;

        p5.SetName(playerName);
        p5.RollDice();
    }

    int diceNum;
    int guessNum;
    int guessMin = 0;
    int guessVal;
    int inputVal;


    bool gameState = true;

    cout << "\n" << p1.GetName() << "'s turn: \n"
        "Your Dice: ";
    p1.ShowDice();
    cout << "Enter how many die: ";
    cin >> guessNum;
    cout << "Enter the value on the die: ";
    cin >> guessVal;

    guessMin = guessNum;

    while (gameState = true) {
        cout << p2.GetName() << "'s turn: \n"
            "Your Dice: \n";
        p2.ShowDice();
        cout << "1: Guess\n"
            "2: Call\n";
        cin >> inputVal;

        if (inputVal == 1) {
            cout << "Enter how many die: ";
            cin >> guessNum;
            cout << "Enter the value on the die: ";
            cin >> guessVal;

            while (guessNum <= guessMin) {
                cout << "Your guess for the number of die cannot be less than the last one. Enter your guess: \n";
                cin >> guessNum >> guessVal; // filters for guesses below the minimum guess
            }
        }
        else if (inputVal == 2) { // checks all of the dice
            diceNum = p1.CheckDice(guessVal);
            diceNum = diceNum + p2.CheckDice(guessVal);
            if (playerNum >= 3) {
                diceNum = diceNum + p3.CheckDice(guessVal);
            }
            if (playerNum >= 4) {
                diceNum = diceNum + p4.CheckDice(guessVal);
            }
            if (playerNum == 5) {
                diceNum = diceNum + p5.CheckDice(guessVal);
            }

            p1.ShowDice(); // displays all of the dice
            p2.ShowDice();
            if (playerNum >= 3) { 
                p3.ShowDice(); 
            }
            if (playerNum >= 4) {
                p4.ShowDice();
            }
            if (playerNum == 5) {
                p5.ShowDice();
            }

            if (diceNum >= guessNum) {
                cout << p1.GetName() << " guessed correctly, " << p1.GetName() << " wins!";
                gameState = false; // exits the loop
                break;

            }
            else {
                cout << p2.GetName() << " called " << p1.GetName() << "'s bluff, " << p2.GetName() << " wins!";
                gameState = false; // exits the loop
                break;
            }
        }
        else {
            cout << "Invalid Input: ";
            cout << "Enter how many die: ";
            cin >> guessNum;
            cout << "Enter the value on the die: ";
            cin >> guessVal;

            while (guessNum <= guessMin) {
                cout << "Your guess for the number of die cannot be less than the last one. Enter your guess: \n";
                cout << "Enter how many die: ";
                cin >> guessNum;
                cout << "Enter the value on the die: ";
                cin >> guessVal; // filters for guesses below the minimum guess
            }
        }
        if (playerNum >= 3) { // if there is a third player in the game
            cout << p3.GetName() << "'s turn: \n"
                "Your Dice: \n";
            p3.ShowDice();
            cout << "1: Guess\n"
                "2: Call\n";
            cin >> inputVal;

            if (inputVal == 1) {
                cout << "Enter how many die: ";
                cin >> guessNum;
                cout << "Enter the value on the die: ";
                cin >> guessVal;

                while (guessNum <= guessMin) {
                    cout << "Your guess for the number of die cannot be less than the last one. Enter your guess: \n";
                    cout << "Enter how many die: ";
                    cin >> guessNum;
                    cout << "Enter the value on the die: ";
                    cin >> guessVal; // filters for guesses below the minimum guess
                }
            }
            else if (inputVal == 2) { // checks all of the dice
                diceNum = p1.CheckDice(guessVal);
                diceNum = diceNum + p2.CheckDice(guessVal);
                if (playerNum >= 3) {
                    diceNum = diceNum + p3.CheckDice(guessVal);
                }
                if (playerNum >= 4) {
                    diceNum = diceNum + p4.CheckDice(guessVal);
                }
                if (playerNum == 5) {
                    diceNum = diceNum + p5.CheckDice(guessVal);
                }

                p1.ShowDice(); // displays all of the dice
                p2.ShowDice();
                p3.ShowDice();
                if (playerNum >= 4) {
                    p4.ShowDice();
                }
                if (playerNum == 5) {
                    p5.ShowDice();
                }

                if (diceNum >= guessNum) {
                    cout << p2.GetName() << " guessed correctly, " << p2.GetName() << " wins!";
                    gameState = false; // exits the loop
                    break;

                }
                else {
                    cout << p3.GetName() << " called " << p2.GetName() << "'s bluff, " << p3.GetName() << " wins!";
                    gameState = false; // exits the loop
                    break;
                }
            }
            else {
                cout << "Invalid Input: ";
                cout << "Enter how many die: ";
                cin >> guessNum;
                cout << "Enter the value on the die: ";
                cin >> guessVal; // invalid inputs default to guessing

                while (guessNum <= guessMin) {
                    cout << "Your guess for the number of die cannot be less than the last one. Enter your guess: \n";
                    cout << "Enter how many die: ";
                    cin >> guessNum;
                    cout << "Enter the value on the die: ";
                    cin >> guessVal; // filters for guesses below the minimum guess
                }
            }
        }
        if (playerNum >= 4) { // if there is a fourth player in the game
            cout << p4.GetName() << "'s turn: \n"
                "Your Dice: \n";
            p4.ShowDice();
            cout << "1: Guess\n"
                "2: Call\n";
            cin >> inputVal;

            if (inputVal == 1) {
                cout << "Enter how many die: ";
                cin >> guessNum;
                cout << "Enter the value on the die: ";
                cin >> guessVal;

                while (guessNum <= guessMin) {
                    cout << "Your guess for the number of die cannot be less than the last one. Enter your guess: \n";
                    cout << "Enter how many die: ";
                    cin >> guessNum;
                    cout << "Enter the value on the die: ";
                    cin >> guessVal; // filters for guesses below the minimum guess
                }
            }
            else if (inputVal == 2) { // checks all of the dice
                diceNum = p1.CheckDice(guessVal);
                diceNum = diceNum + p2.CheckDice(guessVal);
                if (playerNum >= 3) {
                    diceNum = diceNum + p3.CheckDice(guessVal);
                }
                if (playerNum >= 4) {
                    diceNum = diceNum + p4.CheckDice(guessVal);
                }
                if (playerNum == 5) {
                    diceNum = diceNum + p5.CheckDice(guessVal);
                }

                p1.ShowDice(); // displays all of the dice
                p2.ShowDice();
                p3.ShowDice();
                p4.ShowDice();
                if (playerNum == 5) {
                    p5.ShowDice();
                }

                if (diceNum >= guessNum) {
                    cout << p3.GetName() << " guessed correctly, " << p3.GetName() << " wins!";
                    gameState = false; // exits the loop
                    break;

                }
                else {
                    cout << p4.GetName() << " called " << p3.GetName() << "'s bluff, " << p4.GetName() << " wins!";
                    gameState = false; // exits the loop
                    break;
                }
            }
            else {
                cout << "Invalid Input: ";
                cout << "Enter how many die: ";
                cin >> guessNum;
                cout << "Enter the value on the die: ";
                cin >> guessVal; // invalid inputs default to guessing

                while (guessNum <= guessMin) {
                    cout << "Your guess for the number of die cannot be less than the last one. Enter your guess: \n";
                    cout << "Enter how many die: ";
                    cin >> guessNum;
                    cout << "Enter the value on the die: ";
                    cin >> guessVal; // filters for guesses below the minimum guess
                }
            }
        }
        if (playerNum >= 5) { // if there is a fifth player in the game
            cout << p5.GetName() << "'s turn: \n"
                "Your Dice: \n";
            p5.ShowDice();
            cout << "1: Guess\n"
                "2: Call\n";
            cin >> inputVal;

            if (inputVal == 1) {
                cout << "Enter how many die: ";
                cin >> guessNum;
                cout << "Enter the value on the die: ";
                cin >> guessVal;

                while (guessNum <= guessMin) {
                    cout << "Your guess for the number of die cannot be less than the last one. Enter your guess: \n";
                    cout << "Enter how many die: ";
                    cin >> guessNum;
                    cout << "Enter the value on the die: ";
                    cin >> guessVal; // filters for guesses below the minimum guess
                }
            }
            else if (inputVal == 2) { // checks all of the dice
                diceNum = p1.CheckDice(guessVal);
                diceNum = diceNum + p2.CheckDice(guessVal);
                if (playerNum >= 3) {
                    diceNum = diceNum + p3.CheckDice(guessVal);
                }
                if (playerNum >= 4) {
                    diceNum = diceNum + p4.CheckDice(guessVal);
                }
                if (playerNum == 5) {
                    diceNum = diceNum + p5.CheckDice(guessVal);
                }

                p1.ShowDice(); // displays all of the dice
                p2.ShowDice();
                p3.ShowDice();
                p4.ShowDice();
                p5.ShowDice();

                if (diceNum >= guessNum) {
                    cout << p4.GetName() << " guessed correctly, " << p4.GetName() << " wins!";
                    gameState = false; // exits the loop
                    break;

                }
                else {
                    cout << p5.GetName() << " called " << p4.GetName() << "'s bluff, " << p5.GetName() << " wins!";
                    gameState = false; // exits the loop
                    break;
                }
            }
            else {
                cout << "Invalid Input: ";
                cout << "Enter how many die: ";
                cin >> guessNum;
                cout << "Enter the value on the die: ";
                cin >> guessVal; // invalid inputs default to guessing

                while (guessNum <= guessMin) { // filters for guesses below the minimum guess
                    cout << "Your guess for the number of die cannot be less than the last one. Enter your guess: \n";
                    cout << "Enter how many die: ";
                    cin >> guessNum;
                    cout << "Enter the value on the die: ";
                    cin >> guessVal;
                }
            }
        }
        cout << p1.GetName() << "'s turn: \n"
            "Your Dice: \n";
        p1.ShowDice();
        cout << "1: Guess\n"
            "2: Call\n";
        cin >> inputVal;

           if (inputVal == 1) {
               cout << "Enter how many die: ";
               cin >> guessNum;
               cout << "Enter the value on the die: ";
               cin >> guessVal;

                while (guessNum <= guessMin) { // filters for guesses below the minimum guess
                    cout << "Your guess for the number of die cannot be less than the last one. Enter your guess: \n";
                    cout << "Enter how many die: ";
                    cin >> guessNum;
                    cout << "Enter the value on the die: ";
                    cin >> guessVal;
                }
           }
            else if (inputVal == 2) { // checks all of the dice
            diceNum = p1.CheckDice(guessVal);
            diceNum = diceNum + p2.CheckDice(guessVal);
            if (playerNum >= 3) {
                diceNum = diceNum + p3.CheckDice(guessVal);
            }
            if (playerNum >= 4) {
                diceNum = diceNum + p4.CheckDice(guessVal);
            }
            if (playerNum == 5) {
                diceNum = diceNum + p5.CheckDice(guessVal);
            }

                p1.ShowDice(); // displays all of the dice
                p2.ShowDice();
                if (playerNum >= 3) {
                    p3.ShowDice();
                }
                if (playerNum >= 4) {
                    p4.ShowDice();
                }
                if (playerNum == 5) {
                    p5.ShowDice();
                }

                if (diceNum >= guessNum) {
                    if (playerNum == 5) { // several options for how many players there are in the loop
                        cout << p5.GetName() << " guessed correctly, " << p5.GetName() << " wins!"; 
                    }
                    else if (playerNum == 4) {
                        cout << p4.GetName() << " guessed correctly, " << p4.GetName() << " wins!";
                    }
                    else if (playerNum == 3) {
                        cout << p3.GetName() << " guessed correctly, " << p3.GetName() << " wins!";
                    }
                    else {
                        cout << p2.GetName() << " guessed correctly, " << p2.GetName() << " wins!";
                    }
                    gameState = false; // exits the loop
                    break;

                }
                else {
                    if (playerNum == 5) { // several options for how many players there are in the loop
                        cout << p1.GetName() << " called " << p5.GetName() << "'s bluff, " << p1.GetName() << " wins!";
                    }
                    else if (playerNum == 4) { // several options for how many players there are in the loop
                        cout << p1.GetName() << " called " << p4.GetName() << "'s bluff, " << p1.GetName() << " wins!";
                    }
                    else if (playerNum == 3) { // several options for how many players there are in the loop
                        cout << p1.GetName() << " called " << p3.GetName() << "'s bluff, " << p1.GetName() << " wins!";
                    }
                    else {
                        cout << p1.GetName() << " called " << p2.GetName() << "'s bluff, " << p1.GetName() << " wins!";
                    }
                    gameState = false; // exits the loop
                    break;
                }
            }
            else {
                cout << "Invalid Input: ";
                cout << "Enter how many die: ";
                cin >> guessNum;
                cout << "Enter the value on the die: ";
                cin >> guessVal; // invalid inputs default to guessing

                while (guessNum <= guessMin) { // filters for guesses below the minimum guess
                    cout << "Your guess for the number of die cannot be less than the last one. Enter your guess: \n";
                    cout << "Enter how many die: ";
                    cin >> guessNum;
                    cout << "Enter the value on the die: ";
                    cin >> guessVal;
                }
            }
    }
}