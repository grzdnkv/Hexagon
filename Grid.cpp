#include "Grid.h"

Grid::Grid() {
    int counteri = 0;
    int counterj = 0;
    for (auto & i : field) {
        counterj = 0;
        for (auto & j : i) {
            j.q = counterj;
            j.r = counteri;
            counterj++;
        }
        counteri++;
    }
}

//void Grid::View() {
//    std::cout << '\n';
//    std::cout << "   ";
//    int j = 7; // !
//    for (int i = 3; i != j; i++){
//        std::cout << field[0][i].status << " ";
//    }
//    std::cout << '\n';
//    std::cout << "  ";
//    for (int i = 2; i != j; i++){
//        std::cout << field[1][i].status << " ";
//    }
//    std::cout << '\n';
//    std::cout << " ";
//    for (int i = 1; i != j; i++){
//        std::cout << field[2][i].status << " ";
//    }
//    std::cout << '\n';
//    for (int i = 0; i != j; i++){
//        std::cout << field[3][i].status << " ";
//    }
//    std::cout << '\n';
//    std::cout << " ";
//    j = 6;
//    for (int i = 0; i != j; i++){
//        std::cout << field[4][i].status << " ";
//    }
//    std::cout << '\n';
//    std::cout << "  ";
//    j = 5;
//    for (int i = 0; i != j; i++){
//        std::cout << field[5][i].status << " ";
//    }
//    std::cout << '\n';
//    std::cout << "   ";
//    j = 4;
//    for (int i = 0; i != j; i++){
//        std::cout << field[6][i].status << " ";
//    }
//    std::cout << '\n';
//}

void Grid::ViewNcur() {
    initscr();
    init_pair(4, COLOR_CYAN, COLOR_BLACK);
    init_pair(5, COLOR_GREEN, COLOR_BLACK);
    chtype ch;
    int x, y;
    x = 30;
    y = 11;
    move(y, x);
    int j = 7; // !
    for (int i = 3; i != j; i++){
        if (field[0][i].status == '1') {
            ch = '1' | COLOR_PAIR(4);
            addch(ch);
        }
        if (field[0][i].status == '2'){
            ch = '2' | COLOR_PAIR(5);
            addch(ch);
        }
        if (field[0][i].status == '0'){
            addch(field[0][i].status);
        }
            printw(" ");
    }
    printw("                                                        ");
    move(11, 0);
    printw("                              ");
    y++;
    x--;
    move(y, x);
    for (int i = 2; i != j; i++){
        if (field[1][i].status == '1') {
            ch = '1' | COLOR_PAIR(4);
            addch(ch);
        }
        if (field[1][i].status == '2'){
            ch = '2' | COLOR_PAIR(5);
            addch(ch);
        }
        if (field[1][i].status == '0') {
            addch(field[1][i].status);
        }
        printw(" ");
    }
    printw("                                                        ");
    move(12, 0);
    printw("                             ");
    y++;
    x--;
    move(y, x);
    for (int i = 1; i != j; i++){
        if (field[2][i].status == '1') {
            ch = '1' | COLOR_PAIR(4);
            addch(ch);
        }
        if (field[2][i].status == '2'){
            ch = '2' | COLOR_PAIR(5);
            addch(ch);
        }
        if (field[2][i].status == '0') {
            addch(field[2][i].status);
        }
        printw(" ");
    }
    printw("                                                        ");
    move(13, 0);
    printw("                            ");
    y++;
    x--;
    move(y, x);
    for (int i = 0; i != j; i++){
        if (field[3][i].status == '1') {
            ch = '1' | COLOR_PAIR(4);
            addch(ch);
        }
        if (field[3][i].status == '2'){
            ch = '2' | COLOR_PAIR(5);
            addch(ch);
        }
        if (field[3][i].status == '0') {
            addch(field[3][i].status);
        }
        printw(" ");
    }
    printw("                                                        ");
    move(14, 0);
    printw("                           ");
    y++;
    x++;
    move(y, x);
    j = 6;
    for (int i = 0; i != j; i++){
        if (field[4][i].status == '1') {
            ch = '1' | COLOR_PAIR(4);
            addch(ch);
        }
        if (field[4][i].status == '2'){
            ch = '2' | COLOR_PAIR(5);
            addch(ch);
        }
        if (field[4][i].status == '0') {
            addch(field[4][i].status);
        }
        printw(" ");
    }
    printw("                                                        ");
    move(15, 0);
    printw("                           ");
    y++;
    x++;
    move(y, x);
    j = 5;
    for (int i = 0; i != j; i++){
        if (field[5][i].status == '1') {
            ch = '1' | COLOR_PAIR(4);
            addch(ch);
        }
        if (field[5][i].status == '2'){
            ch = '2' | COLOR_PAIR(5);
            addch(ch);
        }
        if (field[5][i].status == '0') {
            addch(field[5][i].status);
        }
        printw(" ");
    }
    printw("                                                        ");
    move(16, 0);
    printw("                           ");
    y++;
    x++;
    move(y, x);
    j = 4;
    for (int i = 0; i != j; i++){
        if (field[6][i].status == '1') {
            ch = '1' | COLOR_PAIR(4);
            addch(ch);
        }
        if (field[6][i].status == '2'){
            ch = '2' | COLOR_PAIR(5);
            addch(ch);
        }
        if (field[6][i].status == '0') {
            addch(field[6][i].status);
        }
        printw(" ");
    }
    printw("                                                        ");
    move(17, 0);
    printw("                            ");
    endwin();
}

bool Grid::IsFilled() {
    int counter = 0;
    if(field[0][3].status != '0' && field[0][4].status != '0' && field[0][5].status != '0' && field[0][6].status != '0')
        counter++;
    if(field[1][2].status != '0' && field[1][3].status != '0' && field[1][4].status != '0' && field[1][5].status != '0' && field[1][6].status != '0')
        counter++;
    if(field[2][1].status != '0' && field[2][2].status != '0' && field[2][3].status != '0' && field[2][4].status != '0' && field[2][5].status != '0' && field[2][6].status != '0')
        counter++;
    if(field[3][0].status != '0' && field[3][1].status != '0' && field[3][2].status != '0' && field[3][3].status != '0' && field[3][4].status != '0' && field[3][5].status != '0' && field[3][6].status != '0')
        counter++;
    if(field[4][0].status != '0' && field[4][1].status != '0' && field[4][2].status != '0' && field[4][3].status != '0' && field[4][4].status != '0' && field[4][5].status != '0')
        counter++;
    if(field[5][0].status != '0' && field[5][1].status != '0' && field[5][2].status != '0' && field[5][3].status != '0' && field[5][4].status != '0')
        counter++;
    if(field[6][0].status != '0' && field[6][1].status != '0' && field[6][2].status != '0' && field[6][3].status != '0')
        counter++;

    return counter == 7;
}

int Grid::Distance(Grid::Hex a, Grid::Hex b) {
    return (abs(a.q - b.q)
            + abs(a.q + a.r - b.q - b.r)
            + abs(a.r - b.r)) / 2;
}

void Grid::DistanceMarker(Grid::Hex hex, int xb, int yb) {
    move(yb, xb);
    int i = hex.r;
    int j = hex.q;
    int x = 30;
    int y = 11;
    int jj =0;
    int ii =0;
    start_color();
    init_pair(2, COLOR_BLUE, COLOR_BLACK);
    chtype colorpointer;
    jj = 7;
        for (ii = 3; ii != jj; ii++) {
            move(y, x);
            if (Grid::Distance(field[i][j], field[0][ii]) == 1 && field[0][ii].status == '0') {
                colorpointer = field[0][ii].status | COLOR_PAIR(2);
                addch(colorpointer);
            }
            if (Distance(field[i][j], field[0][ii]) == 2 && field[0][ii].status == '0') {
                colorpointer = field[0][ii].status | A_BOLD | COLOR_PAIR(2);
                addch(colorpointer);
            }
            x = x + 2;
        }
        x = 29;
        y++;
        for (ii = 2; ii != jj; ii++) {
            move(y, x);
            if (Distance(field[i][j], field[1][ii]) == 1 && field[1][ii].status == '0') {
                colorpointer = field[1][ii].status | COLOR_PAIR(2);
                addch(colorpointer);
            }
            if (Distance(field[i][j], field[1][ii]) == 2 && field[1][ii].status == '0') {
                colorpointer = field[1][ii].status | A_BOLD | COLOR_PAIR(2);
                addch(colorpointer);
            }
            x = x + 2;
        }
        y++;
        x = 28;
        for (ii = 1; ii != jj; ii++) {
            move(y, x);
            if (Distance(field[i][j], field[2][ii]) == 1 && field[2][ii].status == '0') {
                colorpointer = field[2][ii].status | COLOR_PAIR(2);
                addch(colorpointer);
            }
            if (Distance(field[i][j], field[2][ii]) == 2 && field[2][ii].status == '0') {
                colorpointer = field[2][ii].status | A_BOLD | COLOR_PAIR(2);
                addch(colorpointer);
            }
            x = x + 2;
        }
        y++;
        x = 27;
        for (ii = 0; ii != jj; ii++) {
            move(y, x);
            if (Distance(field[i][j], field[3][ii]) == 1 && field[3][ii].status == '0') {
                colorpointer = field[3][ii].status | COLOR_PAIR(2);
                addch(colorpointer);
            }
            if (Distance(field[i][j], field[3][ii]) == 2 && field[3][ii].status == '0') {
                colorpointer = field[3][ii].status | A_BOLD | COLOR_PAIR(2);
                addch(colorpointer);
            }
            x = x + 2;
        }
        y++;
        x = 28;
        jj = 6;
        for (ii = 0; ii != jj; ii++) {
            move(y, x);
            if (Distance(field[i][j], field[4][ii]) == 1 && field[4][ii].status == '0') {
                colorpointer = field[4][ii].status | COLOR_PAIR(2);
                addch(colorpointer);
            }
            if (Distance(field[i][j], field[4][ii]) == 2 && field[4][ii].status == '0') {
                colorpointer = field[4][ii].status | A_BOLD | COLOR_PAIR(2);
                addch(colorpointer);
            }
            x = x + 2;
        }
        y++;
        x = 29;
        jj = 5;
        for (ii = 0; ii != jj; ii++) {
            move(y, x);
            if (Distance(field[i][j], field[5][ii]) == 1 && field[5][ii].status == '0') {
                colorpointer = field[5][ii].status | COLOR_PAIR(2);
                addch(colorpointer);
            }
            if (Distance(field[i][j], field[5][ii]) == 2 && field[5][ii].status == '0') {
                colorpointer = field[5][ii].status | A_BOLD | COLOR_PAIR(2);
                addch(colorpointer);
            }
            x = x + 2;
        }
        y++;
        x = 30;
        jj = 4;
        for (ii = 0; ii != jj; ii++) {
            move(y, x);
            if (Distance(field[i][j], field[6][ii]) == 1 && field[6][ii].status == '0') {
                colorpointer = field[6][ii].status | COLOR_PAIR(2);
                addch(colorpointer);
            }
            if (Distance(field[i][j], field[6][ii]) == 2 && field[6][ii].status == '0') {
                colorpointer = field[6][ii].status | A_BOLD | COLOR_PAIR(2);

                addch(colorpointer);
            }
            x = x + 2;
        }
        move(yb, xb);
}

void Grid::Invader(Grid::Hex a, char playernumber) {
    int j = 7; // !
    for (int i = 3; i != j; i++){
        if (Distance(field[a.r][a.q], field[0][i]) == 1 && field[0][i].status != '0')
            field[0][i].status = playernumber;
    }
    for (int i = 2; i != j; i++){
        if (Distance(field[a.r][a.q], field[1][i]) == 1 && field[1][i].status != '0')
            field[1][i].status = playernumber;
    }
    for (int i = 1; i != j; i++){
        if (Distance(field[a.r][a.q], field[2][i]) == 1 && field[2][i].status != '0')
            field[2][i].status = playernumber;
    }

    for (int i = 0; i != j; i++){
        if (Distance(field[a.r][a.q], field[3][i]) == 1 && field[3][i].status != '0')
            field[3][i].status = playernumber;
    }

    j = 6;
    for (int i = 0; i != j; i++){
        if (Distance(field[a.r][a.q], field[4][i]) == 1 && field[4][i].status != '0')
            field[4][i].status = playernumber;
    }
    j = 5;
    for (int i = 0; i != j; i++){
        if (Distance(field[a.r][a.q], field[5][i]) == 1 && field[5][i].status != '0')
            field[5][i].status = playernumber;
    }
    j = 4;
    for (int i = 0; i != j; i++){
        if (Distance(field[a.r][a.q], field[6][i]) == 1 && field[6][i].status != '0')
            field[6][i].status = playernumber;
    }
}

bool Grid::IsOnePlayer() {
    int playernumber1 = 0;
    int playernumber2 = 0;
    if(field[0][3].status == '1' || field[0][4].status == '1' || field[0][5].status == '1' || field[0][6].status == '1')
        playernumber1 = 1;
    if(field[0][3].status == '2' || field[0][4].status == '2' || field[0][5].status == '2' || field[0][6].status == '2')
        playernumber2 = 2;

    if(field[1][2].status == '1' || field[1][3].status == '1' || field[1][4].status == '1' || field[1][5].status == '1' || field[1][6].status == '1')
        playernumber1 = 1;
    if(field[1][2].status == '2' || field[1][3].status == '2' || field[1][4].status == '2' || field[1][5].status == '2' || field[1][6].status == '2')
        playernumber2 = 2;

    if(field[2][1].status == '1' || field[2][2].status == '1' || field[2][3].status == '1' || field[2][4].status == '1' || field[2][5].status == '1' || field[2][6].status == '1')
        playernumber1 = 1;
    if(field[2][1].status == '2' || field[2][2].status == '2' || field[2][3].status == '2' || field[2][4].status == '2' || field[2][5].status == '2' || field[2][6].status == '2')
        playernumber2 = 2;

    if(field[3][0].status == '1' || field[3][1].status == '1' || field[3][2].status == '1' || field[3][3].status == '1' || field[3][4].status == '1' || field[3][5].status == '1' || field[3][6].status == '1')
        playernumber1 = 1;
    if(field[3][0].status == '2' || field[3][1].status == '2' || field[3][2].status == '2' || field[3][3].status == '2' || field[3][4].status == '2' || field[3][5].status == '2' || field[3][6].status == '2')
        playernumber2 = 2;

    if(field[4][0].status == '1' || field[4][1].status == '1' || field[4][2].status == '1' || field[4][3].status == '1' || field[4][4].status == '1' || field[4][5].status == '1')
        playernumber1 = 1;
    if(field[4][0].status == '2' || field[4][1].status == '2' || field[4][2].status == '2' || field[4][3].status == '2' || field[4][4].status == '2' || field[4][5].status == '2')
        playernumber2 = 2;

    if(field[5][0].status == '1' || field[5][1].status == '1' || field[5][2].status == '1' || field[5][3].status == '1' || field[5][4].status == '1')
        playernumber1 = 1;
    if(field[5][0].status == '2' || field[5][1].status == '2' || field[5][2].status == '2' || field[5][3].status == '2' || field[5][4].status == '2')
        playernumber2 = 2;

    if(field[6][0].status == '1' || field[6][1].status == '1' || field[6][2].status == '1' || field[6][3].status == '1')
        playernumber1 = 1;
    if(field[6][0].status == '2' || field[6][1].status == '2' || field[6][2].status == '2' || field[6][3].status == '2')
        playernumber2 = 2;

    return !(playernumber1 == 1 && playernumber2 == 2);
}
