//#include "../include/myTerm.h"

int mt_clrscrn()
{
    printf("\033[H\033[2J");
    return 0;
}

int mt_gotoXY(int col, int row)
{
    if((col == 0) || (row == 0))
        return -1;
    int *X, *Y;
    if(mt_getscreensize(X,Y) == 1)
        return -1;
    if((*Y < row) || (*X < col))
        return -1;
    printf("\033[%d;%dH", row, col);
    return 0;
}

int mt_getscreensize(int * rows, int * cols)
{
    struct winsize ws;
    if (ioctl(1, TIOCGWINSZ, &ws))
        return -1 ;
    * rows = ws.ws_row ;
    * cols = ws.ws_col ;
    return 0 ;
};

int mt_setfgcolor(enum Colors color)
{
    printf("\033[38;5;%dm", color);
    return 0;
}

int mt_setbgcolor(enum Colors color)
{
    printf("\033[48;5;%dm", color);
    return 0;
}

int mt_setdefaultcolor()
{
    printf("\033[0m");
    return 0;
}

int mt_set_cursorvisible(int value)
{
    if (value == 1)
    {
        printf("\033[?25h");
        return 0;
    }
    else if(value == 0)
    {
        printf("\033[?25l");
        return 0;
    }
    else
        return -1;
}

int mt_delline()
{
    printf("\033[H\033[J");
    return 0;
}

/*int main()
{
    printf("test\n");
    mt_clrscrn();
    printf("test go to random x = 14 Y = 14\n");
    mt_gotoXY(14,14);
    int *x, *y;
    printf("test get screen size ");
    mt_getscreensize(x,y);
    printf("screen size is: %d %d\n", *y, *x);
    printf("test colors f = 5, b = 2\n");
    mt_setfgcolor(5);
    printf("test one\n");
    mt_setbgcolor(2);
    printf("test two\n");
   mt_delline();
    return 0;
}*/