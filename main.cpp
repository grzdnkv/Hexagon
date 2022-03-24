#include "Grid.h"

int main() {
    Grid a; //37
    initscr();

    mvprintw(10, 20, "Welcome to Hexagon Game!");
    getch();
//    mvprintw(11, 20, "Choose your game number(1, 2): ");
    char playernumber = '1';
    mvprintw(10, 20, "                        ");
    mvprintw(11, 20, "                                ");
//    mvprintw(10, 19, "player: ");
    start_color();
    init_pair(1, COLOR_YELLOW, COLOR_BLACK);
    init_pair(2, COLOR_BLUE, COLOR_BLACK);
    chtype ch1;
//    addch(ch1);

    a.ViewNcur();

    int x = 33;
    int y = 14;
    int i = 3;
    int j = 3;
    int s = 1;

    int xbuf = 0;
    int ybuf = 0;
    int jbuf = 0;
    int ibuf = 0;
    move(y, x); // 14, 33 = 3,3

    a.field[0][3].status = '1';
    a.field[6][3].status = '2';
    a.ViewNcur();

    chtype colorpointer = a.field[i][j].status | COLOR_PAIR(1);
    move(y, x);
    addch(colorpointer);
    keypad (stdscr, true);

    int pp = 0;
    int p = 0;
    bool sig = false;
    bool sig2 = false;
    while (!sig){
        if (playernumber == '1'){
            mvprintw(10, 15, "player:    ");
            move(10, 23);
            ch1 = playernumber | A_UNDERLINE;
            addch(ch1);
        }
        if (playernumber == '2'){
            mvprintw(10, 15, "player:    ");
            move(10, 25);
            ch1 = playernumber | A_UNDERLINE;
            addch(ch1);
        }
        if (a.IsOnePlayer())
            sig = true;
        if (a.IsFilled())
            sig = true;
        p = getch();
        switch (p) {

            case '\n':
                if (a.field[i][j].status == playernumber) {
                    move(y, x);
                    colorpointer = a.field[i][j].status | A_UNDERLINE | COLOR_PAIR(1);
                    addch(colorpointer);
                    a.DistanceMarker(a.field[i][j], x, y);
                    xbuf = x;
                    ybuf = y;
                    ibuf = i;
                    jbuf = j;

                    while (!sig2){
//                        move(19, 0);
//                        printw("ibuf= %d ", ibuf);
//                        printw("jbuf= %d ", jbuf);
                        pp = getch();
                        switch (pp){
                            case '\n':
                                if (a.field[ibuf][jbuf].status == '0' && a.Distance(a.field[i][j], a.field[ibuf][jbuf]) == 1) {
                                    a.field[ibuf][jbuf].status = playernumber;
                                    a.Invader(a.field[ibuf][jbuf], playernumber);
                                    a.ViewNcur();
                                    move(y, x);
                                    sig2 = true;
                                    switch (playernumber) {
                                        case '1': playernumber = '2';
                                            break;
                                        case '2': playernumber = '1';
                                            break;
                                    }
                                    break;
                                } else {
                                    move(ybuf, xbuf); colorpointer = a.field[ibuf][jbuf].status | COLOR_PAIR(1); addch(colorpointer);
                                }
                                if (a.field[ibuf][jbuf].status == '0' && a.Distance(a.field[i][j], a.field[ibuf][jbuf]) == 2) {
                                    a.field[ibuf][jbuf].status = playernumber;
                                    a.Invader(a.field[ibuf][jbuf], playernumber);
                                    a.ViewNcur();
                                    move(y, x);
                                    a.field[i][j].status = '0';
                                    sig2 = true;
                                    switch (playernumber) {
                                        case '1':
                                            playernumber = '2';
                                            break;
                                        case '2':
                                            playernumber = '1';
                                            break;
                                    }
                                    break;
                                }
                                else {
                                    move(ybuf, xbuf); colorpointer = a.field[ibuf][jbuf].status | COLOR_PAIR(1); addch(colorpointer);
                                }
                                break;
                            case KEY_RIGHT:
                                    a.DistanceMarker(a.field[i][j], x, y);
                                    xbuf = xbuf + 2;
                                    jbuf++;
                                    if (a.Distance(a.field[i][j], a.field[ibuf][jbuf]) > 2){
                                        xbuf = xbuf - 2;
                                        jbuf--;
                                    }
                                    move(ybuf, xbuf);
                                    colorpointer = a.field[ibuf][jbuf].status | COLOR_PAIR(1);
                                    if (a.field[ibuf][jbuf].status == '0')
                                        addch(colorpointer);

                                    break;
                            case KEY_LEFT:
                                a.DistanceMarker(a.field[i][j], x, y);
                                xbuf = xbuf-2;
                                jbuf--;
                                if (a.Distance(a.field[i][j], a.field[ibuf][jbuf]) > 2){
                                    xbuf = xbuf + 2;
                                    jbuf++;
                                }
                                move(ybuf, xbuf);
                                colorpointer = a.field[ibuf][jbuf].status | COLOR_PAIR(1);
                                if (a.field[ibuf][jbuf].status == '0')
                                    addch(colorpointer);
                                break;
                            case KEY_UP: a.DistanceMarker(a.field[i][j], x, y); xbuf--; ybuf--; ibuf--;
                                if (a.Distance(a.field[i][j], a.field[ibuf][jbuf]) > 2){
                                    xbuf++;
                                    ybuf++;
                                    ibuf++;
                                }
                            move(ybuf, xbuf); colorpointer = a.field[ibuf][jbuf].status | COLOR_PAIR(1);
                                if (a.field[ibuf][jbuf].status == '0')
                                    addch(colorpointer);
                                break;
                            case KEY_DOWN: a.DistanceMarker(a.field[i][j], x, y); xbuf++; ybuf++; ibuf++;
                                if (a.Distance(a.field[i][j], a.field[ibuf][jbuf]) > 2){
                                    xbuf--;
                                    ybuf--;
                                    ibuf--;
                                }
                                move(ybuf, xbuf); colorpointer = a.field[ibuf][jbuf].status | COLOR_PAIR(1);
                                if (a.field[ibuf][jbuf].status == '0')
                                    addch(colorpointer);
                                break;
                            case KEY_BACKSPACE: sig2 = true;
                                break;
                        }
//                        move(19, 0);
//                        printw("ibuf= %d ", ibuf);
//                        printw("jbuf= %d ", jbuf);
                        pp = 0;
                    }
                    sig2 = false;

                    a.ViewNcur();
                    move(y, x);
                    colorpointer = a.field[i][j].status | COLOR_PAIR(1);
                    addch(colorpointer);
                } else {
                    pp = 0;
                    sig2 = false;
                    a.ViewNcur();
                    move(y, x);
                    colorpointer = a.field[i][j].status | COLOR_PAIR(1);
                    addch(colorpointer);
                }
                break;
            case KEY_RIGHT:
                a.ViewNcur();
                x = x+2;
                j++;
                if (a.Distance(a.field[3][3], a.field[i][j]) > 3){
                    x = x-2;
                    j--;
                    move(y, x);
                }
                move(y, x); colorpointer = a.field[i][j].status | COLOR_PAIR(1); addch(colorpointer);
                break;
            case KEY_LEFT: a.ViewNcur(); x = x-2; j--;
                if (a.Distance(a.field[3][3], a.field[i][j]) > 3){
                    x = x+2;
                    j++;
                }
                move(y, x); colorpointer = a.field[i][j].status | COLOR_PAIR(1); addch(colorpointer);
                break;
            case KEY_UP: a.ViewNcur(); x--; y--; i--;
                if (a.Distance(a.field[3][3], a.field[i][j]) > 3){
                    x++;
                    y++;
                    i++;
                }
                move(y, x); colorpointer = a.field[i][j].status | COLOR_PAIR(1); addch(colorpointer);
                break;
            case KEY_DOWN: a.ViewNcur(); x++; y++; i++;
                if (a.Distance(a.field[3][3], a.field[i][j]) > 3){
                    x--;
                    y--;
                    i--;
                }
                move(y, x); colorpointer = a.field[i][j].status | COLOR_PAIR(1); addch(colorpointer);
                break;
            case KEY_BACKSPACE: sig = true;
                break;
        }
//        mvprintw(21, 40, "pn= ");
//        addch(playernumber);
        p = 0; // dont touch!!!
        pp = 0;
    }
    mvprintw(21, 40, "Game Over!");

    endwin();
}