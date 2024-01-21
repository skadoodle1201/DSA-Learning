#include <iostream>
using namespace std;

bool isSafe(int board[100][100], int i, int j, int n)
{
  for (int k = n; k >= 0; k--)
  {
    if (board[k][j] == 1)
      return false;
  }

  int currentRow = i;
  int currentCol = j;
  // check Left Diagonal is Safe
  while (currentRow >= 0 and currentCol >= 0)
  {
    if (board[currentRow][currentCol] == 1)
    {
      return false;
    }
    currentRow--;
    currentCol--;
  }

  // check right diagonal
  currentRow = i;
  currentCol = j;
  while (currentRow >= 0 and currentCol < n)
  {
    if (board[currentRow][currentCol] == 1)
    {
      return false;
    }
    currentRow--;
    currentCol++;
  }

  return true;
}
bool nQueenPlace(int board[100][100], int row, int n)
{

  // base case
  if (row == n)
  {
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (board[i][j] == 1)
        {
          cout << "Q ";
        }
        else
        {
          cout << "_ ";
        }
      }
      cout << endl;
    }
    return false;
  }

  // recursive case
  // placing a queen in row
  for (int col = 0; col < n; col++)
  {
    if (isSafe(board, row, col, n) == true)
    {
      board[row][col] = 1;
      bool placeOtherQueen = nQueenPlace(board, row + 1, n);
      if (placeOtherQueen == true)
      {
        return true;
      }
      board[row][col] = 0;
    }
  }
  return false;
}

int main()
{
  int board[100][100] = {0};

  int n;
  cin >> n;

  nQueenPlace(board, 0, n);

  return 0;
}