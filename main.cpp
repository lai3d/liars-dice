#include <iostream>
#include <curses.h>
//change this to cursus.h while working on windows and to ncurses.h while working on linux
// also to setup Ncurses and PDcurses: Settings > Compiler > Linker Settings and add either pdcurses.a (WINDOWS)or /lib/libncurses.a (LINUX)
#include <cstdlib>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define version "pre-alpha build v0.0.1"

//using namespace std;

int row,col;

char *menu_options[] =
{
    " Campaign ",
    "Single Game",
    "   Help   ",
    "  Credits  ",
    "   Exit   ",
};
//int n_choices = sizeof(choices) / sizeof(char *);


int ch; //KEYBOARD INPUT
int highlight = 1;

void spacecontinue()
{
    ch = getch();
    while(ch != ' ')
    {
        ch = getch();
        if(ch==' ')
        {
            break;
        }




    }

}

void menusplash()
{
    start_color();

    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_WHITE, COLOR_RED);
    init_pair(3, COLOR_BLACK, COLOR_WHITE);
    init_pair(4, COLOR_BLACK, COLOR_RED);
    init_pair(5, COLOR_GREEN, COLOR_BLACK);

    curs_set(0); //make cursor invisible

    attron(COLOR_PAIR(1)| A_BOLD);

    printw("                                                    ");
    printw(version);
    printw("\n                 i@BL .M@B@             B@MPUZBB          LBuBv             uB@B@@7                ,XBOMk7,\n");
    printw("                  r@B@B@B@B@            i@B@B@@:         uB@B@Bi          P@B@B@B@B@L            FB@B@@@@@B@:\n");
    printw("                   7@B@O   @@           ZB@B@B@Y         B@:OB@B        M@@B@@@N0B@B@B          @B@B@7XB@B@Y \n");
    printw("                   i@@BM    B           L@B@B@ @         @B2B@@@7      OB@B@B@@.   @B@B        7@@B@@  ,B@.\n");
    printw("                   i@B@B@   @            r@B@@ O          SB@B@Bi       rB@B@ @B@7 i@B@. ,@j   J@B@B@M  ,B  \n");
    printw("                   rB@BJ   YF             B@@@Yv           @OB@@1        @B@5.@    GB@B, @@:    B@B@@0i  Y  \n");
    printw("                   i@@@J  :E              @@@@u        i7 LB :@B@        B@BS7@.  YB@@@  B@     :B@B@B@B@M: \n");
    printw("                   rB@BY vBv7r            @@B@:7.     B@B@B@ 7B@Bi       @@@0 @@@@B@@@: j@         iP@B@B@B@ \n");
    printw("                   i@B@O:    @@.          @B@B  @r    @B v@B, B@@B       B@BM iB@B@B@M  i:      1PY  ,.Y@B@@B\n");
    printw("                   iB@B1  Si 2B@         ;@@B@  @@    .: @B@M.B@B@       @B@E ..@@B@@@        :@B@B@@   B@@@B \n");
    printw("                   u@B@Y  jB@B@B      iLu OB@B@B@       @B1 @B@B@Bu      B@@@J  .B@B@.        @@@@L7U7  @B@B@ \n");
    printw("                   uB@B@    .@B@      k@q M@B@.:   MBu:@B@  q@ NB@B      @B@B  , kB@Bu        B@BBk  .   @B@B \n");
    printw("                   7@B@B@E::OB@B       OE @B@B    uB@B@B@rrB1,  @@@r     B@B@ XBJ.@B@@i        B@@@.@Bu5@@@B  \n");
    printw("                 .M@B@B@B@B@B@B@1       B@B@B@Bu  i@B@B@q7vUJ. MB@@@M  LB@B@B@SJrFB@B@B@:       u@B@B@B@B@U  \n");
    printw("                 .ZuLvvvLvLLLvLJL       vXuYJJqE   iMBN.  r::  U7rrvk  P0jjYuSY,,12YJY1OJ          :LjLi.  \n");
    printw("\n\n\n\n\n");
    printw("                             .iv7vJiJ              YuY7ivJE          :2MBBX:         ,i2S0S5J7, \n");
    printw("                           F@B@B@@@B@Bi            u@B@B@Bj        J@@@B@B@Bq    v@B@B@B@B@B@@@@  \n");
    printw("                          G@B@B@B@U@B@@@i          GB@B@B@u      .B@B@B@B@B@@   8@B@B@B:   @B@@@: \n");
    printw("                          7@@B. @Bi  v@B@M         v@B@@@ @     :B@@@B2:0B@B@,  .5@B@@@:  YM@B@B \n");
    printw("                           @@  ZB@B,  1@B@B         r@B@B G    .B@B7 @B: GB@B     @@B@1@B @@B@8  \n");
    printw("                           @@:@B@B    1:@B@i         B@@@Yv    B@B@  @,  N@BB     @B@M  @  O.  \n");
    printw("                              8@B@   O  B@B@         @B@Bu     @B@v ,@FiO@BM      B@B@.@B r,  \n");
    printw("                              v@@B ,@2r BB@B         B@B@:7.  :B@Bi  :@B@B@r      @B@B@@@BYiv  \n");
    printw("                              J@B@7.   2@@@@         @B@B  @r  @B@r   i,   rB     B@BM LB@  J@ \n");
    printw("                              vB@B  :X  @B@B        iB@B@  B@  @@@@  U   M  @v    @@@B:  B@  B, \n");
    printw("                             .X@B@   @E@B@@U     iLu OB@B@B@   LB@B57    @B@BO    B@B@    B@B@v \n");
    printw("                             ,@@@B:   @B@@@      S@N M@B@.:     @B@B0 .   1B@:    @B@B.     NB@ \n");
    printw("                              2@B@B@B@B@B@.       OZ @B@B        @@@@@B@B@B@N     B@B@B@kY:5B@B,\n");
    printw("                             N@B@B@@@B@Bq          B@B@B@BU       LB@B@@@B@7    uB@B@B@B@B@@@B@Br \n");
    printw("                            .NL7r7L7r;.            7XuLYjqG         .rj27,      N0JYLYLjYujuYJjMO \n\n");
    printw("                                                              (( _______ \n");
    printw("                                                   _______     /\\O    O\\ \n");
    printw("                                                  /O     /\\   /  \\      \\ \n");
    printw("                                                 /   O  /O \\ / O  \\O____O\\ )) \n");
    printw("                                              ((/_____O/    \\\\    /O     / \n");
    printw("                                                \\O    O\\    / \\  /   O  / \n");
    printw("                                                 \\O    O\\ O/   \\/_____O/ \n");
    printw("                                                  \\O____O\\/ ))       )) \n");
    printw("                                                 (( \n\n\n\n");
    attroff(COLOR_PAIR(1));
    printw("                                                  PRESS SPACE TO CONTINUE                                               ");


    refresh();			/* Print it on to the real screen */
    spacecontinue();
    clear();


    attron(COLOR_PAIR(5));
    printw("                                                                                                    \n");
    printw("                                                         1111111111                                      \n");
    printw("                                                   1100011111111111000011                                   \n");
    printw("                                                1001111              1111001                                \n");
    printw("                                             10011       1 1 1 1 1 1      11001                             \n");
    printw("                                           1001     1 1 1 1 11111 1 111 1    1101                           \n");
    printw("                                         1001    11111 1 1 1 1111111 111 1 1   1101                         \n");
    printw("                                        101   11111 1 1111111111111 111 111 1 1  101                        \n");
    printw("                                       001   111 111 1111111 11111 1 1111111 1 1   00                       \n");
    printw("                                      01  1111111 1111111 111 111 1 11111 11111 1   10                      \n");
    printw("                                     01  11111 1 1111111 1         1 1111111 11111   10                     \n");
    printw("                                    101 1 111 11111 1 1   11111111    1111111 11111   10                    \n");
    printw("                                   101 11111 111 1 1   11001111110011  1111111 1 111  101                   \n");
    printw("                                   01   1 111 1 111   101          101  1 1 11111 111  10                   \n");
    printw("                                   01  1 1 11111 1   101             01  1 11111 11111 101                  \n");
    printw("                                  101 1111111 111 1 10                01  111111111 1   01                  \n");
    printw("                                  10  111111 111 1 111                101  111 1111111  10                  \n");
    printw("                                  11  11111 111 1  101                 01 1111111 1111  10                  \n");
    printw("                                  10   11111111111 101                101  11111 1 111  10                  \n");
    printw("                                  101 1 111 1 111 1 10                01  111 11111111  01                  \n");
    printw("                                   01  11111 111111  10              01  11111 111 111 101                  \n");
    printw("                                   01  1111 1 1 111   101          101  111 111 1 111  10                   \n");
    printw("                                   101   1 11111 1 1 1 11001     0011  11111111111 1  101                   \n");
    printw("                                    101 1111111111111 1  10      01   1 1 1 111 1 1   10                    \n");
    printw("                                     01  111 1111111 1  101       01   11111 11111   10                     \n");
    printw("                                      01    11111 1 1   01        101 1 111 11111   10                      \n");
    printw("                                       001   1 1 1 11  10          01  1 11111 1   10                       \n");
    printw("                                        101   1 1 111 101           01  11111 1  100                        \n");
    printw("                                         1001  1 1 1 110            101  1 1   1101                  \n");
    printw("                                           1001      10              01      1101                \n");
    printw("                                             10011  101              101  11001                 \n");
    printw("                                                100100                101001                                \n");
    printw("                                                   11                  11                                   \n");
    printw("                                                                                             \n");
    printw("                                                                                             \n");
    printw("                                                                                             \n");
    printw("                    00000   010000    10000   010000       100000   10000   0     01  0 101 000001  10000   \n");
    printw("                   00   00  001  001 00   001 001  001    00    0  00   10  01    00  001  00   01 00   101 \n");
    printw("                  101    01 00    00 00111000 00    00    0011     0     01 0     00  0    0       01111100 \n");
    printw("                  101    01 00    00 00       00    00      11000  0     01 0     00  0   10       01       \n");
    printw("                  100   00  00   101 00   11  00    00          00 01    01 00    00  0    01      01       \n");
    printw("                   1000001  0000001  1000000  00    00    0001100  1000000   0000100  0    1000000  000000  \n");
    printw("                            00                                                                              \n");
    printw("                            00 Source-Code available on: https://github.com/Paradux/liars-dice           \n");
    printw("                            00                                                                              \n");
    printw("                                        \n\n\n\n\n");
    attroff(COLOR_PAIR(5));

    printw("                                                  PRESS SPACE TO CONTINUE                     ");
    spacecontinue();
    clear();


    refresh();





//// MAIN MENU







    attroff(A_BOLD);
    while(1)
    {

        refresh();
        for(int i = 0; i<5; i++)
        {


            if(highlight ==i+1)
            {
                attron(COLOR_PAIR(3));
                mvprintw(20+i,55,menu_options[i]);
                attroff(COLOR_PAIR(3));
            }
            else
            {
                mvprintw(20+i,55,menu_options[i]);

            }

        }
        ch = getch();

        if(ch==KEY_DOWN)
        {
            highlight++;
            if(highlight>5)
            {
                highlight = 1;
            }
            clrtobot();

            // goto menu;

        }
        else if(ch==KEY_UP)
        {
            highlight--;
            if(highlight<1)
            {
                highlight = 5;
            }
            clrtobot();
            //  goto menu;
        }
        else
        {
            clrtobot();
            //  goto menu;
        }


        if(ch==' ')
        {
            break;

        }

        refresh();
    }






//MAIN MENU
    if(highlight==1)
    {
        clear();
        refresh();

    }
    if(highlight==2)
    {
        clear();
        refresh();

    }
    if(highlight==3)
    {
        clear();
        refresh();

    }
    if(highlight==4)
    {
        clear();
        refresh();

    }
    if(highlight==5)
    {
        exit;
    }



}



int main()
{
// PDCURSES/NCURSES INITIALIZING//

    initscr();			/* Start curses mode 		*/
    getmaxyx(stdscr,row,col);
    raw();/* Line buffering disabled	*/
    keypad(stdscr, TRUE);		/* We get key input		*/
    noecho();			/* Don't echo() while we do getch */
    refresh();
    resize_term(50, 125);
    refresh();
//STARTING MENU
    menusplash();

    refresh();
// ENDING APPLICATION
    endwin();			/* End curses mode		  */
    return 0;
}
