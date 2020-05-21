#include <iostream>
using namespace std;

#define clrscr() printf("\033[H\033[J")

void gotoxy(int x,int y)
{
    printf("%c[%d;%df",0x1B,y,x);
}

int main()
{
    string c;
    char tabla[3][3];
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            tabla[i][j] = ' ';
    int player = 1;
    do{
        clrscr();
        gotoxy(1,2);
        std::cout<<" "<<tabla[0][0]<<" | "<<tabla[0][1]<<" | "<<tabla[0][2]<<" \n";
        std::cout<<"---+---+---\n";
        std::cout<<" "<<tabla[1][0]<<" | "<<tabla[1][1]<<" | "<<tabla[1][2]<<" \n";
        std::cout<<"---+---+---\n";
        std::cout<<" "<<tabla[2][0]<<" | "<<tabla[2][1]<<" | "<<tabla[2][2]<<" \n";

        std::cout<<"igrac "<<player<<": ";
        std::cin >> c;

        if(c=="00")
            tabla[0][0] = 'O';

        player++;
        player = player%2;
    }while(c != "q");
    return 0;
}