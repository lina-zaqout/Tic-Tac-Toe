# Tic Tac Toe

A small C++ console game for two players. Take turns placing `X` and `O` on a 3x3 board until someone gets three in a row or the board is full.

## Features

- Numbered 3x3 board, drawn with large squares and borders only between them
- Board and title are centered in the terminal
- Strict input checking: only a single number from 1 to 9 is accepted
- Letters, mixed input (like `3y`), empty lines, and out-of-range numbers show a message and let you try again
- Taken squares are rejected without losing your turn
- Win and tie detection
- Exits cleanly if the input ends (Ctrl+D / Ctrl+Z)

## Build and Run

Requires a C++11 compiler (e.g. g++).

```
g++ -std=c++11 -o tictactoe TicToe.cpp
./tictactoe
```

On Windows, run `tictactoe.exe`.

## How It Works

1. Player 1 is `X` and always goes first. Player 2 is `O`.
2. The board starts with the numbers 1 to 9, one in each square.
3. On your turn, type the number of a free square and press Enter.
4. Your mark replaces the number, then it is the other player's turn.
5. The game ends when a player has three marks in a row, or when all squares are filled.

## Example Run

```
=============================
   Welcome to Tic Tac Toe!
=============================

Player 1 is X and Player 2 is O
Player 1 starts first.
Enter a number (1-9) to place your mark.

         |         |
    1    |    2    |    3
         |         |
---------+---------+---------
         |         |
    4    |    5    |    6
         |         |
---------+---------+---------
         |         |
    7    |    8    |    9
         |         |

Player X, enter your move (1-9): 3y
Invalid input. Please enter only one number from 1 to 9.

         |         |
    1    |    2    |    3
         |         |
---------+---------+---------
         |         |
    4    |    5    |    6
         |         |
---------+---------+---------
         |         |
    7    |    8    |    9
         |         |

Player X, enter your move (1-9): 5
...
Player X, enter your move (1-9): 7

         |         |
    O    |    O    |    X
         |         |
---------+---------+---------
         |         |
    4    |    X    |    6
         |         |
---------+---------+---------
         |         |
    X    |    8    |    9
         |         |

Player X wins!
```

## Rules

| Rule | Value |
|------|-------|
| Players | 2 |
| Board size | 3 x 3 |
| First player | X |
| Valid input | One number from 1 to 9 |
| Winning lines | 3 rows, 3 columns, 2 diagonals |
| Tie | Board full with no winner |

## Board Numbering

```
 1 | 2 | 3
---+---+---
 4 | 5 | 6
---+---+---
 7 | 8 | 9
```

## Customizing

The width of the left margin that centers the board is a constant at the top of `TicToe.cpp`:

```cpp
const string MARGIN(25, ' ');
```

A good value is about `(terminal width - 29) / 2`, since the board is 29 characters wide. Change it and recompile.

## Author

Lina Zaqout

## License

Released under the [MIT License](LICENSE).
