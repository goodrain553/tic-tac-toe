#include<iostream>
#include<algorithm>
#include<vector>

using std::cout;
using std::endl;
using std::cin;

#define Xnumber 1
#define Onumber 2

void printBegin()
{
	cout << "***********************************************\n\n\nTIC TAC TOE\n\n\n***********************************************" << endl;
}

void printTheBoard(const std::vector<std::vector<int>>& board)
{
	for (int i = 0; i < 3; i++)
	{

		cout << "___ ___ ___" << endl;

		for (int j = 0; j < 3; j++)
		{
			if (board[i][j] == 0)
				cout << " - " ;
			else if (board[i][j] == 1)
				cout << " X ";
			else if (board[i][j] == 2)
				cout << " O ";
			else
				;

		}
		cout << "\n" << endl;
	}
}

bool inputPos(int& raw, int& col)
{
	cout << "Please enter the position where you would like to place the pieces (raw number) :" << endl;
	cin >> raw;
	
	cout << "Please enter the position where you would like to place the pieces (col number) :" << endl;
	cin >> col;
	
	cout << "\n\n";
	
	
	if (raw < 3 && raw >= 0 && col < 3 && col >= 0)
		return true;
	else
		return false;
	
}

void recordPos(std::vector<std::vector<int>> &board, const int& raw, const int& col, const int& num)
{
	board[raw][col] = num;
}

bool game_end(const int& number_rounds, const std::vector<std::vector<int>>& board)
{
	bool status_game = false;
	
	if (number_rounds >= 9)
		status_game = true;

	
	for (int i = 0; i < 3; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2]&&board[i][0]!=0)
			status_game = true;
	}

	for (int j = 0; j < 3; j++)
	{
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != 0)
			status_game = true;
	}

	if(board[0][0] == board[1][1] && board[1][1] == board[2][2]&& board[0][0]!=0)
			status_game = true;

	if(board[2][0] == board[1][1] && board[1][1] == board[0][2]&&board[2][0]!=0)
			status_game = true;


	return status_game;
}

bool  detect(const int& raw, const int& col, const std::vector<std::vector<int>>& board)
{

	if (raw >= 3 || raw < 0 || col >= 3 || col <= 0)
		return false;

	if (board[raw][col] != 0)
		return false;
	else
		return true;
}

int main()
{

	int raw=-1, col=-1;
	int number_rounds = 0;
	std::vector<int> raw_unit(3, 0);
	std::vector<std::vector<int>> board(3, raw_unit);
	printBegin();
	printTheBoard(board);
	bool status_temp;
	//loop begins
	while (true)
	{
		
		 status_temp = false;
		
		 cout << "palce X pieces\n\n" << endl;
		while (!status_temp)
		{
			status_temp = inputPos(raw, col);
			status_temp = status_temp || detect(raw, col, board);

			if(status_temp == false)
			{	
				cout << "the numbers which have been input are invalid, enter again please.\n\n" << endl;
			}
		}
		

		
		recordPos(board, raw, col, Xnumber);
		number_rounds++;
		printTheBoard(board);
		if (game_end(number_rounds, board))
		{
			cout << "game over" << endl;
			break;
		}



		status_temp = false;
		cout << "palce Y pieces\n\n" << endl;
		while (!status_temp)
		{
			status_temp = inputPos(raw, col);
			status_temp = status_temp || detect(raw, col, board);

			if (status_temp == false)
			{
				cout << "the numbers which have been input are invalid, enter again please.\n\n" << endl;
			}
		}

		recordPos(board, raw, col, Onumber);
		number_rounds++;
		printTheBoard(board);


		if (game_end(number_rounds, board))
		{
			cout << "game over" << endl;
			break;
		}

		
	}
	return 1;
	
}