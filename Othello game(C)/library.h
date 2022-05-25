

#ifndef SOFTWAREASSUGNMENT2________LIBRARY_H
#define SOFTWAREASSUGNMENT2________LIBRARY_H

#endif //SOFTWAREASSUGNMENT2________LIBRARY_H
char player1, player2;

#define B_MARK "  B  "
#define W_MARK "  W  "
#define POSSIBLE_MOVE_MARK "  .  "
#define EMPTY_MARK "     "
#define W 0
#define B 1
#define NULL_ 2
#define PLAYABLE 3
#define F 0
#define T 1
const char *row = "01234567";
const char *column = "01234567";

char sizeOfBoard[8][8];
int playDirection[8][8][8];
int presentPlayer;
int gameEnded = F;
int skipTurn = F;//For skipping the turn//
int wrongMove = F;//If the entered input is wrong//
int validMove = F;// CHECKING IF THE MOVE IS VALID OR NOT//
int score[2]; //Managing score of the players//