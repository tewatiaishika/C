////!!!!!!!! ALL THE REFERENCE TAKEN FROM  https://github.com/petersieg/c/blob/master/othello.c AND https://github.com/rodolfoams/reversi-c !!! ////
////!!!!!!!! ALL THE REFERENCE TAKEN FROM  https://github.com/petersieg/c/blob/master/othello.c AND https://github.com/rodolfoams/reversi-c !!! ////
////!!!!!!!! ALL THE REFERENCE TAKEN FROM  https://github.com/petersieg/c/blob/master/othello.c AND https://github.com/rodolfoams/reversi-c !!! ////


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "library.h"

//Starting the game //
void startGame() {
    //memset copies the character to the first n characters of the string pointed to, by the argument str.//
    memset(sizeOfBoard, NULL_, sizeof(sizeOfBoard));
    //
    //Initialising the tokens on the board for both players//
    sizeOfBoard[3][3] = B;
    sizeOfBoard[3][4] = W;
    sizeOfBoard[4][4] = B;
    sizeOfBoard[4][3] = W;
    // Both player have 2 token in the starting so initialising the score as 2 for both players//
    score[W] = 2;
    score[B] = 2;
    // The game is started by the 1st player and it's assigned black token//
    presentPlayer = B;
}

// For the distance moved by the player//
int distance(int x1, int y1, int x2, int y2) {
    //initialising variables for absolute value//
    int dx;
    int dy;
    // checking the absolute value for both the players//
    dx = abs(x1 - x2);
    dy = abs(y1 - y2);
    if (dx > 0)
        return dx;
    return dy;
}

// If the input by the user is valid or not//
int validPosition(int x, int y) {
    //when the input is between this limit then only it's valid//
    if (x < 0 || x >= 8 || y < 0 || y >= 8)
        return F;
    return T;
}

// For playing the game between the 2 players//
int play(int x, int y) {
    //memset copies the character to the first n characters of the string pointed to, by the argument str.//
    memset(playDirection[x][y], 0, 8);
    //if position entered by the user is not valid then return false//
    if (!validPosition(x, y))
        return F;
    if (sizeOfBoard[x][y] != NULL_)
        return F;

    int can_play = F;

    int opponentPlayer = (presentPlayer + 1) % 2;

    //  diagonal check//
    int a = x - 1, b = y - 1;
    while (validPosition(a, b) && sizeOfBoard[a][b] == opponentPlayer) {
        a -= 1;
        b -= 1;
    }
    if (validPosition(a, b) && distance(x, y, a, b) > 1 && sizeOfBoard[a][b] == presentPlayer) {
        //valid play move//
        playDirection[x][y][0] = 1;
        can_play = T;
    }

    // UP
    a = x - 1, b = y;
    while (validPosition(a, b) && sizeOfBoard[a][b] == opponentPlayer)
        a -= 1;

    if (validPosition(a, b) && distance(x, y, a, b) > 1 && sizeOfBoard[a][b] == presentPlayer) {
        playDirection[x][y][1] = 1;
        can_play = T;
    }

    // diagonal
    a = x - 1, b = y + 1;
    while (validPosition(a, b) && sizeOfBoard[a][b] == opponentPlayer) {
        a -= 1;
        b += 1;
    }
    if (validPosition(a, b) && distance(x, y, a, b) > 1 && sizeOfBoard[a][b] == presentPlayer) {
        playDirection[x][y][2] = 1;
        can_play = T;
    }

    // LEFT
    a = x, b = y - 1;
    while (validPosition(a, b) && sizeOfBoard[a][b] == opponentPlayer)
        b -= 1;

    if (validPosition(a, b) && distance(x, y, a, b) > 1 && sizeOfBoard[a][b] == presentPlayer) {
        playDirection[x][y][3] = 1;
        can_play = T;
    }

    // RIGHT
    a = x, b = y + 1;
    while (validPosition(a, b) && sizeOfBoard[a][b] == opponentPlayer)
        b += 1;

    if (validPosition(a, b) && distance(x, y, a, b) > 1 && sizeOfBoard[a][b] == presentPlayer) {
        playDirection[x][y][4] = 1;
        can_play = T;
    }

    // diagonal
    a = x + 1, b = y - 1;
    while (validPosition(a, b) && sizeOfBoard[a][b] == opponentPlayer) {
        a += 1;
        b -= 1;
    }
    if (validPosition(a, b) && distance(x, y, a, b) > 1 && sizeOfBoard[a][b] == presentPlayer) {
        playDirection[x][y][5] = 1;
        can_play = T;
    }

    // DOWN
    a = x + 1, b = y;
    while (validPosition(a, b) && sizeOfBoard[a][b] == opponentPlayer)
        a += 1;

    if (validPosition(a, b) && distance(x, y, a, b) > 1 && sizeOfBoard[a][b] == presentPlayer) {
        playDirection[x][y][6] = 1;
        can_play = T;
    }

    // diagonal
    a = x + 1, b = y + 1;
    while (validPosition(a, b) && sizeOfBoard[a][b] == opponentPlayer) {
        a += 1;
        b += 1;
    }
    if (validPosition(a, b) && distance(x, y, a, b) > 1 && sizeOfBoard[a][b] == presentPlayer) {
        playDirection[x][y][7] = 1;
        can_play = T;
    }
    return can_play;
}

//  All the possible next move for both players are marked by a dot//
void possible_next_move() {
    validMove = F;
    for (int x = 0; x < 8; ++x) {
        for (int y = 0; y < 8; ++y) {
            if (sizeOfBoard[x][y] == PLAYABLE)
                sizeOfBoard[x][y] = NULL_;
            if (play(x, y)) {
                sizeOfBoard[x][y] = PLAYABLE;
                validMove = T;
            }
        }
    }
}

// board drawing//
void draw_board() {
    printf("     %c     %c     %c     %c     %c     %c     %c     %c\n", column[0], column[1], column[2], column[3],
           column[4], column[5], column[6], column[7]);
    printf("   _____ _____ _____ _____ _____ _____ _____ _____\n");
    for (int x = 0; x < 8; ++x) {
        printf("  |     |     |     |     |     |     |     |     |\n");
        printf("%c |", row[x]);
        for (int y = 0; y < 8; ++y) {
            if (sizeOfBoard[x][y] == W) {
                printf("%s", W_MARK);
            } else if (sizeOfBoard[x][y] == B) {
                printf("%s", B_MARK);
            } else if (sizeOfBoard[x][y] == PLAYABLE) {
                printf("%s", POSSIBLE_MOVE_MARK);
            } else {
                printf("%s", EMPTY_MARK);
            }
            printf("|");
        }
        printf("\n");
        printf("  |_____|_____|_____|_____|_____|_____|_____|_____|\n");
    }
    printf("\n");
}

// for showing the invalid move//
void showinvalidMove() {
    // if the move is wrong
    if (wrongMove) {
        printf("You entered an invalid move!\n");
        wrongMove = F;
    }
}

void display_Present_player() {
    printf(" Turn of player:");
    printf("%s[%s]", &player1, presentPlayer == W ? W_MARK : B_MARK);
    printf("\n");
}

void change_Present_player() {
    presentPlayer = (presentPlayer + 1) % 2;
}

void Move(int *Row, int *Column) {
    printf("Enter row and column separated by a space:-\n");
   scanf("%d %d", Row, Column);
}

void capture_pieces(int x, int y) {
    int opponent_player = (presentPlayer + 1) % 2;
    int a, b;

    // Capture UL diagonal
    if (playDirection[x][y][0]) {
        a = x - 1, b = y - 1;
        while (sizeOfBoard[a][b] == opponent_player) {
            sizeOfBoard[a][b] = presentPlayer;
            score[presentPlayer]++;
            score[opponent_player]--;
            a -= 1;
            b -= 1;
        }
    }

    // Capture UP path
    if (playDirection[x][y][1]) {
        a = x - 1, b = y;
        while (sizeOfBoard[a][b] == opponent_player) {
            sizeOfBoard[a][b] = presentPlayer;
            score[presentPlayer]++;
            score[opponent_player]--;
            a -= 1;
        }
    }

    // Capture UR diagonal
    if (playDirection[x][y][2]) {
        a = x - 1, b = y + 1;
        while (sizeOfBoard[a][b] == opponent_player) {
            sizeOfBoard[a][b] = presentPlayer;
            score[presentPlayer]++;
            score[opponent_player]--;
            a -= 1;
            b += 1;
        }
    }

    // Capture LEFT path
    if (playDirection[x][y][3]) {
        a = x, b = y - 1;
        while (sizeOfBoard[a][b] == opponent_player) {
            sizeOfBoard[a][b] = presentPlayer;
            score[presentPlayer]++;
            score[opponent_player]--;
            b -= 1;
        }
    }

    // Capture RIGHT path
    if (playDirection[x][y][4]) {
        a = x, b = y + 1;
        while (sizeOfBoard[a][b] == opponent_player) {
            sizeOfBoard[a][b] = presentPlayer;
            score[presentPlayer]++;
            score[opponent_player]--;
            b += 1;
        }
    }

    // Capture DL diagonal
    if (playDirection[x][y][5]) {
        a = x + 1, b = y - 1;
        while (sizeOfBoard[a][b] == opponent_player) {
            sizeOfBoard[a][b] = presentPlayer;
            score[presentPlayer]++;
            score[opponent_player]--;
            a += 1;
            b -= 1;
        }
    }

    // Capture DOWN path
    if (playDirection[x][y][6]) {
        a = x + 1, b = y;
        while (sizeOfBoard[a][b] == opponent_player) {
            sizeOfBoard[a][b] = presentPlayer;
            score[presentPlayer]++;
            score[opponent_player]--;
            a += 1;
        }
    }

    // Capture DR diagonal
    if (playDirection[x][y][7]) {
        a = x + 1, b = y + 1;
        while (sizeOfBoard[a][b] == opponent_player) {
            sizeOfBoard[a][b] = presentPlayer;
            score[presentPlayer]++;
            score[opponent_player]--;
            a += 1;
            b += 1;
        }
    }
}

//CHECKING THE NEXT MOVE FOR BOTH PLAYERS//
void next_move() {

    int row;
    int column;
    Move(&row, &column);
    if (validPosition(row, column) && sizeOfBoard[row][column] == PLAYABLE) {
        sizeOfBoard[row][column] = presentPlayer;
        score[presentPlayer]++;
        capture_pieces(row, column);
        change_Present_player();
    } else wrongMove = T;
}

//displaying the winner of the game [the one with more token]//
void winner() {
    //printing final score//
    printf("END score:\n%s: %d %s: %d\n", W_MARK, score[W], B_MARK, score[B]);
    //if score of player 1[b] is more then print //
    if (score[W] < score[B])
        printf("%s wins.\n", B_MARK);
        //if score of player 2[w] is more then print //
    else if (score[W] > score[B])
        printf("%s wins.\n", W_MARK);
    else
        //if both players have same tokens then it's a draw//
        printf("GAME DRAW.\n");
}

// managing and displaying score of both player at every step//
void display_score() {
    printf("%s[%s]: %d  && %s[%s]: %d\n", &player1, B_MARK, score[B], &player2, W_MARK, score[W]);
}

int main() {
    printf("**Welcome to Othello! **\n");
    printf("Enter Name of player-1(Black) : \n");
    scanf("%s", &player1);
    printf("Enter Name of player-2(White) : \n");
    scanf("%s", &player2);
    startGame();

    while (!gameEnded) {
        if (!wrongMove)
            possible_next_move();
        if (!validMove) {
            if (skipTurn) {
                gameEnded = 1;
                draw_board();
                continue;
            }
            skipTurn = 1;
            change_Present_player();
            continue;
        }
        skipTurn = 0;
        draw_board();
        display_score();
        display_Present_player();
        showinvalidMove();
        next_move();
    }
    winner();
}