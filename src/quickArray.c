        /************************************************************************
        *                   Code witten by Eric/Maxow234/ItsEric                *
        *                     Published under GNU GPL license                   *
        *                       https://github.com/ItsEric                      *
        *                                                                       *
        *  quickArray is a small library allowing you to quickly get some meta  *
        *     informations about an array, or a variable and displaying it      *
        *                           in a formatted way.                         *
        *                                                                       *
        *  The HowTo use it is avaliable on my github repo (user/ItsEric)       *
        *  This program is free software: you can redistribute it and/or modify *
        *  it under the terms of the GNU General Public License as published by *
        *    the Free Software Foundation, either version 3 of the License, or  *
        *                  (at your option) any later version.                  *
        *                                                                       *
        *    This program is distributed in the hope that it will be useful,    *
        *    but WITHOUT ANY WARRANTY; without even the implied warranty of     *
        *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the      *
        *           GNU General Public License for more details.                *
        *                                                                       *
        *   You should have received a copy of the GNU General Public License   *
        *  along with this program.  If not, see <http://www.gnu.org/licenses/>.*
        *************************************************************************/

/* Thanks for trying my very very small library, it isn't ifnished yet. Here are the next things I plan to implement:
    - repeat() function that will return a concated string
    - make prepeat() accept a string instead of an array
    - add some debugging functions (to print a variable quickly per example) */

#include <stdio.h>
#include <stdlib.h>

#include "quickArray.h"

#define ROWSEPARATOR  '-'
#define COLUMNSEPARATOR  '|'

int getIntLen(int number);
int metaBoard (int row, int column, int board[row][column]);
void prepeat(int times, char charToRepeat);
int lineLenght (int row, int column, int board[row][column]);
void printf_array(int row, int column, int board[row][column]);


/* int main(void)           FOR DEBBUGING PURPOSES ONLY
{
    int array[4][7] = {{1, 22, 3, 99, 1, 1234, 2} , {4, 5, 6, 80, 40, 14504, 90000} , {7, 8, 9, 10, 4500, 3, 4} , {9, 100001, 9, 4, 42, 3, 10000} };
    printf_array(4, 7, array);
} */


void printf_array(int row, int column, int board[row][column])
{
    int maxNbrLen = metaBoard(row, column, board);
    char rowSeparator = ROWSEPARATOR;
    char columnSeparator = COLUMNSEPARATOR;
    int i = 0 ; 
    int j = 0;

    printf("\ni/j");
    for (int j = 0; j < column; j++)
    {
        prepeat(maxNbrLen , ' ') ; // Prints he good number of spaces BEFORE the number of the column
        printf("%d  ", j );
    }

    // This block handdles the formatting of the very first line of ROWSEPARATORs
    printf("\n   ");
    prepeat(maxNbrLen * column + (3 * column + 1), rowSeparator);
    printf("\n");

    //  This first loop will go through every row of the array (or will execute only once if it is NOT a 2D array)
    for (i = 0; i < row ; i++)
    {
        printf(" %d %c", i, columnSeparator);

        // The second loop go trough every column (of every row thnks to the first loop) and displays the value of each entry in a formatted fashion
        for (j = 0; j < column; j++)
        {
            prepeat(maxNbrLen - getIntLen(board[i][j]) + 1, ' ') ; // Put the good number of spaces BEFORE the number so the the units are aligned
            printf("%d %c", board[i][j], columnSeparator); 
        }
    // Put ROWSEPARATORs between each row
        printf("\n   ");
        prepeat(maxNbrLen * column + (3 * column + 1), rowSeparator);
        printf("\n");
    }
    printf("\n");
}

    /* This block of code will go trough the whole array for the first time.
       without displaying anything it will store into  "maxLen" the number which requires the most digits to be printed */
int metaBoard (int row, int column, int board[row][column])
{
    int maxNbrLen = 0;
    int lineLen = 0;
    int maxLineLen = 0;

// We go trough the whole array in order to determine the number with the most digits. It will be used to print the good number of spaced before every number
    for (int w = 0; w < row; w++)
    {
        for (int x = 0; x < column; x++)
        {
            if ( (getIntLen(board[w][x])) > maxNbrLen)
                maxNbrLen = getIntLen(board[w][x]);

            lineLen = lineLen + getIntLen(board[w][x]);
        }

        if (lineLen > maxLineLen)
            maxLineLen = lineLen ;

        lineLen = 0;
    }

    return maxNbrLen;
}

int getIntLen (int number)
{
    int intLen;
    if (number < 0)
    {
        intLen = 2; // The "units columns" + the minus sign

        while (number > -9)
        {
            number/=10;
            intLen++;
        }
    }

    else
    {
        intLen = 1; // The "units column"

        while (number > 9)
        {
            number/=10;
            intLen++;
        }
    }
    return intLen;
}

void prepeat(int times, char charToRepeat)
{
    for (int l = 0; l < times; l++)
        printf("%c", charToRepeat);
}