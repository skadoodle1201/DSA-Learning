#include <iostream>
using namespace std;

bool isSafe(char **maze, int i, int j, int row, int col)
{
    if (i == row || j == col || i < 0 || j < 0)
    {
        return false;
    }
    if (maze[i][j] == 'X' || maze[i][j] == 1)
    {
        return false;
    }

    return true;
}
bool ratMazeProblem(char **maze, int i, int j, int row, int col, int **sol)
{
    // base case
    if (i == row - 1 && j == col - 1)
    {
        sol[i][j] = 1;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                cout << sol[i][j] << " ";
            }
            cout << endl;
        }
        return true;
    }
    sol[i][j] = 1;

    // Moving Left
    if (isSafe(maze, i, j + 1, row, col) and sol[i][j + 1] != 1)
    {
        bool isSolPossible = ratMazeProblem(maze, i, j + 1, row, col, sol);
        if (isSolPossible)
        {
            return true;
        }
    }

    // Moving Right
    if (isSafe(maze, i + 1, j, row, col) and sol[i + 1][j] != 1)
    {
        bool isSolPossible = ratMazeProblem(maze, i + 1, j, row, col, sol);
        if (isSolPossible)
        {
            return true;
        }
    }

    // Moving left
    if (isSafe(maze, i - 1, j, row, col) and sol[i - 1][j] != 1)
    {
        bool isSolPossible = ratMazeProblem(maze, i - 1, j, row, col, sol);
        if (isSolPossible)
        {
            return true;
        }
    }

    if (isSafe(maze, i, j - 1, row, col) and sol[i][j - 1] != 1)
    {
        bool isSolPossible = ratMazeProblem(maze, i, j - 1, row, col, sol);
        if (isSolPossible)
        {
            return true;
        }
    }
    sol[i][j] = 0;

    return false;
}

int main()
{
    int row, col;
    cin >> row;
    cin >> col;
    char **maze = new char *[row];

    for (int i = 0; i < row; i++)
    {
        maze[i] = new char[col];
    }

    int **sol = new int *[row];
    for (int i = 0; i < row; i++)
    {
        sol[i] = new int[col];
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> maze[i][j];
            sol[i][j] = 0;
        }
    }

    bool isFound = ratMazeProblem(maze, 0, 0, row, col, sol);

    if (!isFound)
    {
        cout << "NO PATH FOUND";
    }

    for (int i = 0; i < row; i++)
    {
        delete[] maze[i];
        delete[] sol[i];
    }
    delete[] maze;
    delete[] sol;

    return 0;
}