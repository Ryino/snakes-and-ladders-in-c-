
//2021535 Rayyan Hassan//
#include <iostream>
#include<string>
#include<cstdlib>
#include<ctime>

using namespace std;
int dice_roll()
{
	srand(time(0));
	int dice = 1 + (rand() % 6);
	return(dice);
}



int main()
{
	int pos1 = 0, pos2 = 0, dice, num = 0, snake[10] = { 11,25,63,55,71,88,93,99,40,42 }, ladder[10] = { 2,10 ,43,24,62,54,70,78,83,88 };
	string player1, player2, d;


	//both players will input their names.
	cout << "Enter Player 1 Name:" << endl;
	getline(cin, player1);
	cout << "Enter Player 2 Name: " << endl;;
	getline(cin, player2);


	//players will be notified of their starting point 

	cout << "Start Point of Players:" << endl << player1 << ": " << pos1 << endl << player2 << ": " << pos2 << endl;




	for (pos1 = 0; pos1 < 100 && pos2 < 100; )
	{
		dice = dice_roll();
		num++;//this is to record the number of turns it takes for a player to finish the game
		cout << num << "-> ";


		cout << player1 << " please press any button to throw the dice" << endl;
		cin >> d;
		cout << "dice Roll is: \n" << dice << endl;
		pos1 += dice;

		for (int j = 0; j < 10; j++)
		{
			if (pos1 == snake[j])
			{
				cout << "You got bit by a snake! You have been sent back 10 places!";
				pos1 -= 10;
			}
			else if (pos1 == ladder[j])
			{
				cout << "You reached a ladder! You have been sent 10 spaces ahead! \n";
				pos1 += 10;
			}
		}
		if (pos1 > 100)
		{
			pos1 -= dice;
		}
		cout << "New Place is: \n" << pos1 << endl;

		//player 2 code begins 
		dice = dice_roll();
		num++;//this is to record the number of turns it takes for a player to finish the game
		cout << num << "-> ";


		cout << player2 << " please press any button to throw the dice" << endl;
		cin >> d;
		cout << "dice Roll is: \n" << dice << endl;
		pos2 += dice;

		for (int j = 0; j < 10; j++)
		{
			if (pos2 == snake[j])
			{
				cout << "You got bit by a snake! You have been sent back 10 places!";
				pos2 -= 10;
			}
			else if (pos2 == ladder[j])
			{
				cout << "You reached a ladder! You have been sent 10 spaces ahead! \n";
				pos2 += 10;
			}
		}
		if (pos2 > 100)
		{
			pos2 -= dice;
		}
		cout << "New Place is: \n" << pos2 << endl;

	}
	//winning code 
	if (pos1 == 100)
	{
		cout << player1 << " Is The WINNER!!!" << endl;
		cout << "It took you " << num << " turns!";
	}
	else if (pos2 == 100)
	{
		cout << player2 << " Is The WINNER!!!" << endl;
		cout << "It took you " << num << " turns!";
	}

	return 0;
}




