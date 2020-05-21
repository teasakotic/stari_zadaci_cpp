#include <iostream>
using namespace std;

#define clrscr() printf("\033[H\033[J")

void gotoxy(int x,int y)
{
    printf("%c[%d;%df",0x1B,y,x);
}

int border(){
    gotoxy(1,1);
    std::cout<<"+---------+";
    for(int i=2; i<7; i++){
        gotoxy(0,i);
        std::cout<<"|";
        gotoxy(11,i);
        std::cout<<"|";
    }
    gotoxy(1,7);
    std::cout<<"+---------+";
}

int main()
{
    char ekran[10][10];
    for(int i=0; i<10; i++)
        for(int j=0; j<10; j++)
            ekran[i][j] = ' ';

    ekran[5][5] = 'x';
    char c;
    char tabla[3][3];
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            tabla[i][j] = ' ';
    int player = 1;
    do{
        clrscr();
        // // nacrtati tablu
        // gotoxy(1,2);
        // std::cout<<" "<<tabla[0][0]<<" | "<<tabla[0][1]<<" | "<<tabla[0][2]<<" \n";
        // std::cout<<"---+---+---\n";
        // std::cout<<" "<<tabla[1][0]<<" | "<<tabla[1][1]<<" | "<<tabla[1][2]<<" \n";
        // std::cout<<"---+---+---\n";
        // std::cout<<" "<<tabla[2][0]<<" | "<<tabla[2][1]<<" | "<<tabla[2][2]<<" \n";
        // border();

        // gotoxy(1,1);
        for(int i=0; i<10; i++){
            for(int j=0; j<10; j++)
                std::cout << ekran[i][j];
            std::cout << "\n";
        }

        // gotoxy(10, 10);
        std::cout<<"igrac "<<player<<": ";
        std::cin >> c;
        if(c=='1')
            tabla[0][0] = 'O';

        player++;
        player = player%2;
    }while(c != 'q');
    return 0;
}
