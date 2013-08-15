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

char *choices[] =
{
    " New Game",
    "Load Game",
    "  Help   ",
    " Credits ",
    "  Exit   ",
};
int n_choices = sizeof(choices) / sizeof(char *);


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

    printw("                                                 ");
    printw(version);
    printw("\n rBME@@@        P@B@B.     .@@B:      :EB@B@2   @@    ;N@B@@@:       vB@@B@G        :B@B@v     ,MB@B@   .L0B@@@B@k");
    printw(" 7B@U uM       @B@B@      B@B@B     B@@@BF@@B,  @   qB@BUB@@.      M@B@BBB@Bj      i@B@Bi    M@B@B@B8 .B@B@i v@@@ ");
    printw(" .@BM  q       :@B@i:     :@@@@    ,@B@q@r v@B    B@BO  B        uBi,@M  @B@      @@Brr   B@k@0 B@M  iB@B1 q@@X   ");
    printw(" ,@@:  7        r@@v       r@@B.    :@@L5  2@@     O@@B1 ;         Mr@@;  :@BL      B@q   U@B B. @B:   @B u; r   ");
    printw(" ,@B  S,        7@@i    r@BB.2@G    iB@i@7F@@L      :F@B@Bq          B@, u N@B      @@P   @B2 uB@@S    @@O@@i   ");
    printw(" ,B@r   Bi      u@B 1;  @MY@:.B@    i@@ F@B@B      Lu7:.k@B@         @BL   @@@      B@,.X B@X  ;  .J   @Bui@ .5  ");
    printw(" :@B  Pi@B    ,.SB@L8:    @LGB@@v   iB@i r@B@     @@@Bq .B@B         @@  u:B@0   .,i@BOu5 rB@:   5YB   B@:  Mr@ ");
    printw(" iB@X  2B@    B7:@B:  F@7@B P:i@B   :@B:  B@B     B@@    @B@        ,@B5 7B@B    5B @@j.   @B@:: vB@   @BX.  B@ ");
    printw(":B@B@B@B@B    .M@B@Y  @B@BuqE rB@Z  @B@MMjBB@Bi    8@B@B@B8         LB@B@B@B,     EB@B@     ZB@B@B@   MB@B@B@B@B ");
    printw(":u;ir77rrL.    rL77F  .q1  .  irru :2v7J. 7v7Fj      :7v:           Y;:rii         u77ur      iL7.   :5vr7vYL77qi");
    printw("                                                             (( _______ ");
    printw("                                                   _______     /\\O    O\\ ");
    printw("                                                  /O     /\\   /  \\      \\ ");
    printw("                                                 /   O  /O \\ / O  \\O____O\\ )) ");
    printw("                                              ((/_____O/    \\\\    /O     / ");
    printw("                                                \\O    O\\    / \\  /   O  / ");
    printw("                                                        \\O    O\\ O/   \\/_____O/ ");
    printw("                                                  \\O____O\\/ ))       )) ");
    printw("                                                (( ");
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
    printw("                            00 Source-Code available on: https://github.com/Paradux/Loose-Cannons           \n");
    printw("                            00                                                                              \n");
    printw("                                        \n\n\n\n\n");
    attroff(COLOR_PAIR(5));

    printw("                                                  PRESS SPACE TO CONTINUE                     ");
    spacecontinue();
    clear();


    refresh();
//menu:
WINDOW *my_win;
int startx, starty, width, height;


//// MAIN MENU






     printw("   Y.  i:                                                    iL;                 \n");
     printw("   BB@B@BM                                                 q@@B@B                \n");
     printw("    @B@  @,                                               @B@B@B@J                 \n");
     printw("    B@Bi iv                                              @@OBLi@BF                \n");
     printw("    @B@. 7:     ,j5      .u1      .vv:    .rSUv.        LB@ @, B@i    Yr    YriLu2iU 7r:YJ1:5    rXi   Lr:Lj1:F    :jr:  \n");
     printw("    B@Z  u     MB@U@;   O@B5Br   @B@B@u  @B@:MB@        B@r B r@B    @B@v   .@B@;@B7 .B@Br@@7  iB@L@@  .B@BrB@v  .B@B@@.  \n");
     printw("    @BO S7r   uBEZ E@  Y@0O GB  .B@,.O   @@B Y@B        @Bi rB@Bi    L@B8    7@B  @   7B@  B   B@B  @2  7@@  B   X@B 2;   \n");
     printw("    B@B   B@  @@   YBL @B   L@j  @B@.    J@:v,.         B@r  .  i7    O@@    :@@L B   :@BY @  v@:   B@  :@BJ @   iB@u,    \n");
     printw("    @BO ;vY@  @B   v@F B@   LBZ   JB@B:  u@B@,          8BB . .ur@  @Buv@    ruv@j@   rYL@uB  0B.  ,@B  rJLBuB    ,k@@@   \n");
     printw("    B@B  1B@  B@   iBu @B   i@5 ,@E :@B  2B:Li7         .@BO   JB@  7GMv@r   vX @@B   7X @B@  U@,   @@  7P @@@   5M5 OBE  \n");
     printw("    @B@M  @@  0@r  B@  P@r  @B  @Bv  B@  u@  i@.         P@@@Grq@.  :@iB@O  7B@  B@  7@B  @B   B@  v@P ;@B  @B   B@: :@B  \n");
     printw("   O@@B@B@B@0  @@Gj@X   B@EuBN  j@0Fk@S  8B@jrBO          u@B@B@7 @@BGj M@ :B@Eu.YB :@B8j,L@.  FBO1@B :@B8j,v@.  @BU2@B,  \n");
     printw("   uriiiriirr   5@@i     1@@i    :M@@i  ,B@B@@@B.           ivi   7BF i PBu B5 7. X  MF v. k    iB@F   MS 7. k    L@@E \n");
    attroff(A_BOLD);
    while(1)
    {

        refresh();
        for(int i = 0; i<5; i++)
        {


            if(highlight ==i+1)
            {
                attron(COLOR_PAIR(3));
             mvprintw(20+i,55,choices[i]);
                attroff(COLOR_PAIR(3));
            }
            else
            {
                  mvprintw(20+i,55,choices[i]);

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
if(highlight==1){
clear();
refresh();

}
if(highlight==2){
clear();
refresh();

}
if(highlight==3){
clear();
refresh();

}
if(highlight==4){
clear();
refresh();

}
if(highlight==5){
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
