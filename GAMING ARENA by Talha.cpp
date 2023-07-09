#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <windows.h>
#include<string>
using namespace std;

// Hangman Game
const int MAX_TRIES = 3;

int letterFill(char, string, string&);
void drawHangman(int);

int playHangman()
{
    string name;
    char letter;
    int num_of_wrong_guesses = 0;
    string word;
    string words[] = {
        "india",
        "pakistan",
        "nepal",
        "malaysia",
        "sirilanka",
        "australia",
        "america",
        "oman",
        "indonesia"};

    // Choose and copy a word from the array of words randomly
    srand(time(NULL));
    int n = rand() % 10;
    word = words[n];

    // Initialize the secret word with the * character.
    string unknown(word.length(), '*');

    // Welcome the user
    cout << "\n\nWelcome to Hangman...Guess a Country Name";
    cout << "\n\nEach letter is represented by a star.";
    cout << "\n\nYou have to type only one letter in one try.";
    cout << "\n\nYou have " << MAX_TRIES << " tries to try and guess the word.";
    cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";

  // Loop until the maximum number of wrong guesses is reached
    while (num_of_wrong_guesses < MAX_TRIES)
    {
        cout << "\n\n" << unknown;
        cout << "\n\nGuess a letter: ";
        cin >> letter;

        // Fill secret word with letter if the guess is correct,
        // otherwise increment the number of wrong guesses.
        if (letterFill(letter, word, unknown) == 0)
        {
            cout << endl << "Whoops! That letter isn't in there!" << endl;
            num_of_wrong_guesses++;
            drawHangman(num_of_wrong_guesses);
        }
        else
        {
            cout << endl << "You found a letter! Isn't that exciting!" << endl;
        }

        // Tell the user how many guesses are left.
        cout << "You have " << MAX_TRIES - num_of_wrong_guesses;
        cout << " guesses left." << endl;

        // Check if the user guessed the word.
        if (word == unknown)
        {
            cout << word << endl;
            cout << "Yeah! You got it!";
            break;
        }
    }

    if (num_of_wrong_guesses == MAX_TRIES)
    {
        cout << "\nSorry, you lose...you've been hanged." << endl;
        drawHangman(MAX_TRIES);
        cout << "The word was: " << word << endl;
    }

    cin.ignore();
    cin.get();
    return 0;
}

/* Take a one character guess and the secret word, and fill in the
unfinished guess word. Returns the number of characters matched.
Also, returns zero if the character is already guessed. */

int letterFill(char guess, string secretword, string &guessword)
{
    int i;
    int matches = 0;
    int len = secretword.length();
    for (i = 0; i < len; i++)
    {
        // Did we already match this letter in a previous guess?
        if (guess == guessword[i])
            return 0;

        // Is the guess in the secret word?
        if (guess == secretword[i])
        {
            guessword[i] = guess;
            matches++;
        }
    }
    return matches;
}

void drawHangman(int attempts)
{
    cout << endl << endl;
    switch (attempts)
    {
    case 1:
        cout << "   ____" << endl;
        cout << "  |    |" << endl;
        cout << "  |    O" << endl;
        cout << "  |   /|\\" << endl;
        cout << "  |   / \\" << endl;
        cout << "  |      " << endl;
        cout << " _|_" << endl;
        break;
    case 2:
        cout << "   ____" << endl;
        cout << "  |    |" << endl;
        cout << "  |    O" << endl;
        cout << "  |   /|\\" << endl;
        cout << "  |   / \\" << endl;
        cout << "  |      " << endl;
        cout << " _|_" << endl;
        break;
    case 3:
        cout << "   ____" << endl;
        cout << "  |    |" << endl;
        cout << "  |    *" << endl;
        cout << "  |   /|\\" << endl;
        cout << "  |   / \\" << endl;
        cout << "  |      " << endl;
        cout << " _|_" << endl;
        break;
//    case 4:
//        cout << "   ____" << endl;
//        cout << "  |    |" << endl;
//        cout << "  |    O" << endl;
//        cout << "  |   /|\\" << endl;
//        cout << "  |   / \\" << endl;
//        cout << "  |      " << endl;
//        cout << " _|_" << endl;
//        break;
//    case 5:
//        cout << "   ____" << endl;
//        cout << "  |    |" << endl;
//        cout << "  |    *" << endl;
//        cout << "  |   /|\\" << endl;
//        cout << "  |   / \\" << endl;
//        cout << "  |      " << endl;
//        cout << " _|_" << endl;
//        break;
    default:
        break;
    }
}

// Tic Tac Toe Game
char square[10] = {'o', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

int checkwin()
{
    if (square[1] == square[2] && square[2] == square[3])
        return 1;
    else if (square[4] == square[5] && square[5] == square[6])
        return 1;
    else if (square[7] == square[8] && square[8] == square[9])
        return 1;
    else if (square[1] == square[4] && square[4] == square[7])
        return 1;
    else if (square[2] == square[5] && square[5] == square[8])
        return 1;
    else if (square[3] == square[6] && square[6] == square[9])
        return 1;
    else if (square[1] == square[5] && square[5] == square[9])
        return 1;
    else if (square[3] == square[5] && square[5] == square[7])
        return 1;
    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' &&
             square[4] != '4' && square[5] != '5' && square[6] != '6' &&
             square[7] != '7' && square[8] != '8' && square[9] != '9')
        return 0;
    else
        return -1;
}

void drawBoard()
{
    cout << "\n\n\tTic Tac Toe\n\n";

    cout << "Player 1 (X)  -  Player 2 (O)" << endl << endl;
    cout << endl;

    cout << "     |     |     " << endl;
    cout << "  " << square[1] << "  |  " << square[2] << "  |  " << square[3] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << square[4] << "  |  " << square[5] << "  |  " << square[6] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << square[7] << "  |  " << square[8] << "  |  " << square[9] << endl;

    cout << "     |     |     " << endl << endl;
}

void playTicTacToe()
{
    int player = 1, i, choice;

    char mark;
    do
    {
        drawBoard();
        player = (player % 2) ? 1 : 2;

        cout << "Player " << player << ", enter a number: ";
        cin >> choice;

        mark = (player == 1) ? 'X' : 'O';

        if (choice == 1 && square[1] == '1')
            square[1] = mark;
        else if (choice == 2 && square[2] == '2')
            square[2] = mark;
        else if (choice == 3 && square[3] == '3')
            square[3] = mark;
        else if (choice == 4 && square[4] == '4')
            square[4] = mark;
        else if (choice == 5 && square[5] == '5')
            square[5] = mark;
        else if (choice == 6 && square[6] == '6')
            square[6] = mark;
        else if (choice == 7 && square[7] == '7')
            square[7] = mark;
        else if (choice == 8 && square[8] == '8')
            square[8] = mark;
        else if (choice == 9 && square[9] == '9')
            square[9] = mark;
        else
        {
            cout << "Invalid move ";

            player--;
            cin.ignore();
            cin.get();
        }
        i = checkwin();

        player++;
    } while (i == -1);
    drawBoard();
    if (i == 1)
        cout << "==>\aPlayer " << --player << " win ";
    else
        cout << "==>\aGame draw";
    cin.ignore();
    cin.get();
}

// Snake Game
bool gameover;
const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100];
int nTail;
enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN };
Direction dir;

class SnakeGame
{
public:
    void Setup()
    {
        gameover = false;
        dir = STOP;
        x = width / 2;
        y = height / 2;
        fruitX = rand() % width;
        fruitY = rand() % height;
        score = 0;
    }

    void Draw()
    {
        system("cls");
        for (int i = 0; i < width + 2; i++)
            cout << "#";
        cout << endl;

        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                if (j == 0)
                    cout << "#";
                if (i == y && j == x)
                    cout << "O";
                else if (i == fruitY && j == fruitX)
                    cout << "F";
                else
                {
                    bool printTail = false;
                    for (int k = 0; k < nTail; k++)
                    {
                        if (tailX[k] == j && tailY[k] == i)
                        {
                            cout << "o";
                            printTail = true;
                        }
                    }
                    if (!printTail)
                        cout << " ";
                }

                if (j == width - 1)
                    cout << "#";
            }
            cout << endl;
        }

        for (int i = 0; i < width + 2; i++)
            cout << "#";
        cout << endl;

        cout << "Score: " << score << endl;
    }

    void Input()
    {
        if (_kbhit())
        {
            switch (_getch())
            {
            case 'a':
                dir = LEFT;
                break;
            case 'd':
                dir = RIGHT;
                break;
            case 'w':
                dir = UP;
                break;
            case 's':
                dir = DOWN;
                break;
            case 'x':
                gameover = true;
                break;
            }
        }
    }

    void Logic()
    {
        int prevX = tailX[0];
        int prevY = tailY[0];
        int prev2X, prev2Y;
        tailX[0] = x;
        tailY[0] = y;

        for (int i = 1; i < nTail; i++)
        {
            prev2X = tailX[i];
            prev2Y = tailY[i];
            tailX[i] = prevX;
            tailY[i] = prevY;
            prevX = prev2X;
            prevY = prev2Y;
        }

        switch (dir)
        {
        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
        case UP:
            y--;
            break;
        case DOWN:
            y++;
            break;
        default:
            break;
        }

        if (x >= width)
            x = 0;
        else if (x < 0)
            x = width - 1;

        if (y >= height)
            y = 0;
        else if (y < 0)
            y = height - 1;

        for (int i = 0; i < nTail; i++)
        {
            if (tailX[i] == x && tailY[i] == y)
            {
                gameover = true;
            }
        }

        if (x == fruitX && y == fruitY)
        {
            score += 10;
            fruitX = rand() % width;
            fruitY = rand() % height;
            nTail++;
        }
    }
};

void playSnakeGame()
{
    SnakeGame snakeGame;
    snakeGame.Setup();
    while (!gameover)
    {
        snakeGame.Draw();
        snakeGame.Input();
        snakeGame.Logic();
        Sleep(10);
    }
    cout << "\nGame Over! Your score is: " << score << endl;
    cin.ignore();
    cin.get();
}

int main()
{
    int choice;
    char playAgain;
    do
    {
        cout << "Which game would you like to play?" << endl;
        cout << "1. Hangman" << endl;
        cout << "2. Tic Tac Toe" << endl;
        cout << "3. Snake Game" << endl;
        cout << "Enter your choice (1-3): ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            playHangman();
            break;
        case 2:
            playTicTacToe();
            break;
        case 3:
            playSnakeGame();
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }

        cout << "\nDo you want to play again? (y/n): ";
        cin >> playAgain;
        cin.ignore();
    } while (playAgain == 'y' || playAgain == 'Y');

    return 0;
}

