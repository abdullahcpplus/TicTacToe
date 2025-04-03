#include <iostream>
#include <ctime>
#include <Windows.h>
using namespace std;
void drowBoard(char *spaces);
void playerMove(char *spaces, char player);
void computerMove(char *spaces, char computer);
bool checkWinner(char *spaces, char player, char computer);
bool checkTie(char *spaces);

int main()
{
    char spaces[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char palyer = 'X';
    char computer = 'O';
    bool running = true;
    drowBoard(spaces);

    while (running)
    {
        playerMove(spaces, palyer);
        drowBoard(spaces);
        if (checkWinner(spaces, palyer, computer))
        {
            running = false;
            break;
        }
        if (checkTie(spaces))
        {
            running = false;
            break;
        }
        computerMove(spaces, computer);
        drowBoard(spaces);
        if (checkWinner(spaces, palyer, computer))
        {
            running = false;
            break;
        }
        if (checkTie(spaces))
        {
            running = false;
            break;
        }
    }

    return 0;
}
void drowBoard(char *spaces)
{
    system("cls");
    cout << endl;
    cout << "_________________" << endl;
    cout << "|    |     |    |" << endl;
    cout << "| " << spaces[0] << "  |  " << spaces[1] << "  |  " << spaces[2] << " |" << endl;
    cout << "|____|_____|____|" << endl;
    cout << "|    |     |    |" << endl;
    cout << "| " << spaces[3] << "  |  " << spaces[4] << "  |  " << spaces[5] << " |" << endl;
    cout << "|____|_____|____|" << endl;

    cout << "| " << spaces[6] << "  |  " << spaces[7] << "  |  " << spaces[8] << " |" << endl;
    cout << "|____|_____|____|" << endl;
    cout << endl;
    cout << endl;
}
void playerMove(char *spaces, char player)
{
    int number;

    do
    {
        cout << "enter number between 1 to 9 " << endl;
        cin >> number;
        number--;
        if (spaces[number] == ' ')
        {
            spaces[number] = player;
        }
    } while (number < 0 || number > 9);
}
void computerMove(char *spaces, char computer)
{
    int number;
    srand(time(0));

    while (true)
    {
        number = rand() % 9;
        if (spaces[number] == ' ')
        {
            spaces[number] = computer;
            break;
        }
    }
}

bool checkWinner(char *spaces, char player, char computer)
{
    if (spaces[0] != ' ' && spaces[0] == spaces[1] && spaces[1] == spaces[2])
    {
        spaces[0] == player ? cout << "You win!" << endl : cout << "You loss" << endl;
        Sleep(1000);
    }
    else if (spaces[3] != ' ' && spaces[3] == spaces[4] && spaces[4] == spaces[5])
    {
        spaces[3] == player ? cout << "You win!" << endl : cout << "You loss" << endl;
        Sleep(1000);
    }
    else if (spaces[6] != ' ' && spaces[6] == spaces[7] && spaces[7] == spaces[8])
    {
        spaces[6] == player ? cout << "You win!" << endl : cout << "You loss" << endl;
        Sleep(1000);
    }
    else if (spaces[0] != ' ' && spaces[0] == spaces[3] && spaces[3] == spaces[6])
    {
        spaces[0] == player ? cout << "You win!" << endl : cout << "You loss" << endl;
        Sleep(1000);
    }
    else if (spaces[1] != ' ' && spaces[1] == spaces[4] && spaces[4] == spaces[7])
    {
        spaces[1] == player ? cout << "You win!" << endl : cout << "You loss" << endl;
        Sleep(1000);
    }
    else if (spaces[2] != ' ' && spaces[2] == spaces[5] && spaces[5] == spaces[8])
    {
        spaces[2] == player ? cout << "You win!" << endl : cout << "You loss" << endl;
        Sleep(1000);
    }
    else if (spaces[0] != ' ' && spaces[0] == spaces[4] && spaces[4] == spaces[8])
    {
        spaces[0] == player ? cout << "You win!" << endl : cout << "You loss" << endl;
        Sleep(1000);
    }
    else if (spaces[2] != ' ' && spaces[2] == spaces[4] && spaces[4] == spaces[6])
    {
        spaces[2] == player ? cout << "You win!" << endl : cout << "You loss" << endl;
        Sleep(1000);
    }
    else
    {
        return false;
    }
    return true;
}

bool checkTie(char *spaces)
{
    for (int i = 0; i < 9; i++)
    {
        if (spaces[i] == ' ')
        {
            return false;
        }
    }
    cout << "its a tie" << endl;
    return true;
}
