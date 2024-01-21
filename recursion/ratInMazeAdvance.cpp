#include <iostream>
using namespace std;

bool ratInMaze(char maze[][10], int i, int j, int n, int m, int sol[][10])
{
  // base Case
  if (i == n - 1 and j == m - 1)
  {
    sol[i][j] = 1;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        cout << sol[i][j] << " ";
      }
      cout << endl;
    }
    cout << endl;
    sol[i][j] = 0;
    // change to true if want only one path
    return false;
  }

  // recursive Case

  // make sol as 1 assuming you found the path
  sol[i][j] = 1;
  // Move Right
  if (j + 1 < m and maze[i][j + 1] != 'X' and sol[i][j + 1] != 1)
  {
    bool foundPath = ratInMaze(maze, i, j + 1, n, m, sol);
    if (foundPath == true)
    {
      return true;
    }
  }

  // move down
  if (i + 1 < n and maze[i + 1][j] != 'X' and sol[i + 1][j] != 1)
  {
    {
      bool foundPath = ratInMaze(maze, i + 1, j, n, m, sol);
      if (foundPath == true)
      {
        return true;
      }
    }
  }

  // move left
  if (j - 1 >= 0 and maze[i][j - 1] != 'X' and sol[i][j - 1] != 1)
  {
    {
      bool foundPath = ratInMaze(maze, i, j - 1, n, m, sol);
      if (foundPath == true)
      {
        return true;
      }
    }
  }

  // move down
  if (i - 1 >= 0 and maze[i - 1][j] != 'X' and sol[i - 1][j] != 1)
  {
    {
      bool foundPath = ratInMaze(maze, i - 1, j, n, m, sol);
      if (foundPath == true)
      {
        return true;
      }
    }
  }

  // not found make sol 0
  sol[i][j] = 0;
  return false;
}

int main()
{
  char maze[][10] = {
      "0X000",
      "0X000",
      "0X000",
      "000X0",
      "0X0X0",
      "000X0"};

  int sol[10][10] = {0};

  bool foundPath = ratInMaze(maze, 0, 0, 6, 5, sol);
  return 0;
}