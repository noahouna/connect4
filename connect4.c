#include <stdio.h>
#include <stdbool.h>

bool game_over = false;

int turn = 0;
char col;

// Initialize Gameboard

int row_0[] = {0, 0, 0, 0, 0, 0};
int row_1[] = {0, 0, 0, 0, 0, 0};
int row_2[] = {0, 0, 0, 0, 0, 0};
int row_3[] = {0, 0, 0, 0, 0, 0};
int row_4[] = {0, 0, 0, 0, 0, 0};
int row_5[] = {0, 0, 0, 0, 0, 0};



//////////////////////////
// check if move is valid
//////////////////////////

bool valid_move(int row_0[], int row_1[], int row_2[], int row_3[], int row_4[], int row_5[], int col)
{

  bool validinput = (col == 1 || col == 2 || col == 3 || col == 4 || col == 5 || col == 6) && (row_0[col - 1] == 0);

  if (validinput == false)
  {

    printf("\nInvalid move. Try again.\n");

    return true; // input is invalid
  }


  return false;  // input is valid
}

////////////////////
// get next open row
////////////////////

int open(int row_0[], int row_1[], int row_2[], int row_3[], int row_4[], int row_5[], int col)
{

  int r;


  if (row_5[col - 1] == 0)
  {
    r = 5;
  }
    else if (row_4[col - 1] == 0)
    {
      r = 4;
    }
      else if (row_3[col - 1] == 0)
      {
        r = 3;
      }
        else if (row_2[col - 1] == 0)
        {
          r = 2;
        }
          else if (row_1[col - 1] == 0)
          {
            r = 1;
          }
            else if (row_0[col - 1] == 0)
            {
              r = 0;
            }

  return r;

}

//////////////////////////////////
//    Drop piece onto board     //
//////////////////////////////////

void drop(int turn, int open, int row_0[], int row_1[], int row_2[], int row_3[], int row_4[], int row_5[], int col)
{
  if (open == 5)
  {
    if (turn == 0)
    {
      row_5[col - 1] = 1;
    }
    else
    {
      row_5[col - 1] = -1;
    }

  }
    else if (open == 4)
    {
      if (turn == 0)
      {
        row_4[col - 1] = 1;
      }
      else
      {
        row_4[col - 1] = -1;
      }

    }
      else if (open == 3)
      {
        if (turn == 0)
        {
          row_3[col - 1] = 1;
        }
        else
        {
          row_3[col - 1] = -1;
        }
      }
        else if (open == 2)
        {
          if (turn == 0)
          {
            row_2[col - 1] = 1;
          }
          else
          {
            row_2[col - 1] = -1;
          }
        }
          else if (open == 1)
          {
            if (turn == 0)
            {
              row_1[col - 1] = 1;
            }
            else
            {
              row_1[col - 1] = -1;
            }
          }
            else if (open == 0)
            {
              if (turn == 0)
              {
                row_0[col - 1] = 1;
              }
              else
              {
                row_0[col - 1] = -1;
              }
            }

}

/////////////////////////////////////
//  Print board from row arrays    //
/////////////////////////////////////

int printboard(int row_0[], int row_1[], int row_2[], int row_3[], int row_4[], int row_5[])
{

  printf("\n");

  for (int i = 0; i < 6; i++)
  {
    if (row_0[i] == 0)
    {
      printf(" - ");
    }
    else if (row_0[i] == 1)
    {
      printf(" O ");
    }
    else if (row_0[i] == -1)
    {
      printf(" X ");
    }
  }

  printf("\n");

  for (int i = 0; i < 6; i++)
  {
    if (row_1[i] == 0)
    {
      printf(" - ");
    }
    else if (row_1[i] == 1)
    {
      printf(" O ");
    }
    else if (row_1[i] == -1)
    {
      printf(" X ");
    }
  }

  printf("\n");

  for (int i = 0; i < 6; i++)
  {
    if (row_2[i] == 0)
    {
      printf(" - ");
    }
    else if (row_2[i] == 1)
    {
      printf(" O ");
    }
    else if (row_2[i] == -1)
    {
      printf(" X ");
    }
  }

  printf("\n");

  for (int i = 0; i < 6; i++)
  {
    if (row_3[i] == 0)
    {
      printf(" - ");
    }
    else if (row_3[i] == 1)
    {
      printf(" O ");
    }
    else if (row_3[i] == -1)
    {
      printf(" X ");
    }
  }

  printf("\n");

  for (int i = 0; i < 6; i++)
  {
    if (row_4[i] == 0)
    {
      printf(" - ");
    }
    else if (row_4[i] == 1)
    {
      printf(" O ");
    }
    else if (row_4[i] == -1)
    {
      printf(" X ");
    }
  }

  printf("\n");

  for (int i = 0; i < 6; i++)
  {
    if (row_5[i] == 0)
    {
      printf(" - ");
    }
    else if (row_5[i] == 1)
    {
      printf(" O ");
    }
    else if (row_5[i] == -1)
    {
      printf(" X ");
    }
  }

  printf("\n");


  return 0;
}


////////////////////////////////////////////////////
//    Scan board for winning moves or a tie       //
////////////////////////////////////////////////////


bool status(int row_0[], int row_1[], int row_2[], int row_3[], int row_4[], int row_5[], int col, int turn)
{


  int board[36];


  for (int i = 0; i < 36; i++)    // Create local array to iterate through
  {
    board[i] = 0;
  }



  for (int i = 0; i < 6; i++)      // Join size 6 row arrays to size 36 board array
  {
    board[i + 30] = row_5[i];
  }

  for (int i = 0; i < 6; i++)
  {
    board[i + 24] = row_4[i];
  }

  for (int i = 0; i < 6; i++)
  {
    board[i + 18] = row_3[i];
  }

  for (int i = 0; i < 6; i++)
  {
    board[i + 12] = row_2[i];
  }

  for (int i = 0; i < 6; i++)
  {
    board[i + 6] = row_1[i];
  }

  for (int i = 0; i < 6; i++)
  {
    board[i] = row_0[i];
  }



  for (int i = 0; i < 36; i += 6)   // Check for horizontal wins
  {

    for (int k = i; (k % 6) < 3; k++)
    {
      bool horiz = (board[k] == board[k + 1]) && (board[k]== board[k + 2]) && (board[k] == board[k + 3]) && (board[k] != 0);
      if (horiz == true)
      {
        if (turn == 0)
        {
          printf("\nPlayer 1 Wins.\n");
        }
        else if (turn == 1)
        {
          printf("\nPlayer 2 Wins.\n");
        }
        return true;
      }
    }
  }




  for (int i = 0; i < 6; i++)  // Check for vertical wins
  {
    for (int k = i; (k / 6) < 3; k += 6)
    {
      bool vert = (board[k] == board[k + 6]) && (board[k] == board[k + 12]) && (board[k] == board[k + 18]) && (board[k] != 0);
      if (vert == true)
      {
        if (turn == 0)
        {
          printf("\nPlayer 1 Wins.\n");
        }
        else if (turn == 1)
        {
          printf("\nPlayer 2 Wins.\n");
        }
        return true;
      }
    }
  }



  for (int i = 18; i <= 30; i += 6)  // Check for positively sloped diagonal wins
  {
    for (int k = i; (k % 6) < 3; k++)
    {
      bool posd = (board[k] == board[k - 5]) && (board[k] == board[k - 10]) && (board[k] == board[k - 15]) && (board[k] != 0);
      if (posd == true)
      {
        if (turn == 0)
        {
          printf("\nPlayer 1 Wins.\n");
        }
        else if (turn == 1)
        {
          printf("\nPlayer 2 Wins.\n");
        }
        return true;
      }
    }
  }



  for (int i = 0; i <= 12; i += 6)  // Check for negatively sloped diagonal wins
  {
    for (int k = i; (k % 6) < 3; k++)
    {
      bool negd = (board[k] == board[k + 7]) && (board[k]== board[k + 14]) && (board[k]== board[k + 21]) && (board[k] != 0);
      if (negd == true)
      {
        if (turn == 0)
        {
          printf("\nPlayer 1 Wins.\n");
        }
        else if (turn == 1)
        {
          printf("\nPlayer 2 Wins.\n");
        }
        return true;
      }
    }
  }

      // Check for a tie

  bool tie = (board[0] != 0) && (board[1] != 0) && (board[2] != 0) && (board[3] != 0) && (board[4] != 0) && (board[5] != 0);
  if (tie == true)
  {
    printf("\nTie Game.\n");
    return true;
  }

  return false;
}



int main(void)
{

  // Welcome Message
  printf("=====================     Connect 4     =====================\n");

  printboard(row_0, row_1, row_2, row_3, row_4, row_5);

  while (game_over == false)
  {

    bool invalidinput = true;

    while (invalidinput == true)
    {

      if (turn == 0)   // Ask for Player 1 input
      {

        printf("\nPlayer 1, choose a column (1-6): ");
        scanf(" %c", &col);

      }

      else  // Ask for Player 2 input
      {

        printf("\nPlayer 2, choose a column (1-6): ");
        scanf(" %c", &col);

      }


      int temp = (int)col - 48;  // Convert ASCII to integer

      invalidinput = valid_move(row_0, row_1, row_2, row_3, row_4, row_5, temp);

    }

    col = (int)col - 48;     // Convert ASCII value to integer

    int openrow = open(row_0, row_1, row_2, row_3, row_4, row_5, col);

    drop(turn, openrow, row_0, row_1, row_2, row_3, row_4, row_5, col);

    printboard(row_0, row_1, row_2, row_3, row_4, row_5);

    bool *p = &game_over;   // pointer to address of game_over global variable

    *p = status(row_0, row_1, row_2, row_3, row_4, row_5, col, turn);  // update game_over indirectly

    turn++;                 // Increment turn
    turn = turn % 2;

  }

  return 0;
}
