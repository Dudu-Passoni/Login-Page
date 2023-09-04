/* 
 * This code was made by Dudu-Passoni
 */

#include <ncurses>
#include <cstring>


int main()
{
 initscr();
 refresh();

 int xMax, yMax;

 getmaxyx(stdscr, yMax, xMax);

 //BORDA DA JANELA
 WINDOW * board_win = newwin(30, 100, 0, 0);
    box(board_win, 0, 0);
        wrefresh(board_win);

 //JANELA DE USUARIO
 WINDOW * username_win = newwin(3, 50, 7, 25);
    box(username_win, 0, 0);
        wrefresh(username_win);
 move(6, 25);
    printw("NOME DE USUARIO");

 //JANELA DE SENHA
 WINDOW * password_win = newwin(3, 50, 13, 25);
    box(password_win, 0, 0);
        wrefresh(password_win);
 move(12, 25);
    printw("SENHA");
 refresh();

 char username[26],
      password[26],
      user1[26] = "user1",
      password1[26] = "1234";

 attron(A_BOLD);
 move(1, 1);
    printw("* * * CONTROLE DE ESTOQUE * * *");
 attroff(A_BOLD);

 username_verify:
    move(8, 26);
 getstr(username);
    move(10, 25);
 if(strcmp(username, user1) != 0)
 {
    printw("USERNAME NOT FOUND");
        move(8, 26);
            printw("\n");
    goto username_verify;
 }
 move(10,25);
 printw("\n");


 password_verify:
    move(14, 26);
 //getstr(password);
 noecho();
 int p=0;
    do{
        password[p] = getch();
        if(password[p] != 127){
            printw("*");
            refresh();
            p++;
        }
    }while(password[p-1] != '\n');
    password[p-1] = '\0';
    move(16, 25);
 if(strcmp(password, password1) != 0)
 {
    printw("INCORECT PASSWORD");
        move(14, 26);
            printw("\n");
    goto password_verify;
 }

 move(16, 25);
 printw("\n");
 move(16, 25);
 attron(A_BLINK);
 printw("PRESS ENTER TO CONTINUE");

 getch();
 endwin();

    return 0;
}
