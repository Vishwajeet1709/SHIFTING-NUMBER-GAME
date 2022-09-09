#include<stdio.h>
#include<conio.h>
#include<windows.h>
void MoveElementLeft(char a[4][4]);
void MoveElementRight(char a[4][4]);
void MoveElementUp(char a[4][4]);
void MoveElementDown(char a[4][4]);
int CompairArr(char a[4][4],char b[4][4]);
void ShortArr(char b[4][4]);
int main()
{
    HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
    int i,j,n=20;
    char ch,name[20],line=179,a[4][4],b[4][4];

    SetConsoleTextAttribute(h,3); //this is to color the text

    printf("\nEnter your name : ");
    gets(name);

    system("cls"); //to clear screen

    SetConsoleTextAttribute(h,7);
    printf("\n\n");
    printf("\t\t\t   Welcome %s",name);
    printf("\n\t\t\tRULES OF THIS GAME");

    SetConsoleTextAttribute(h,2);

    printf("\n RULE 1 : You can move 1 step at a time with arrow key.");
    printf("\n\t => Move Up    : Press W key");
    printf("\n\t => Move Down  : Press S key");
    printf("\n\t => Move Left  : Press A key");
    printf("\n\t => Move Right : Press D Key");
    printf("\n RULE 2 : You can move numbers in empty places only.");
    printf("\n RULE 3 : You have only %d moves, as you shift numbers your moves will decreased by 1.",n);
    printf("\n RULE 4 : Wining situation,\"If you arrange all elements in %d moves or earlier you are win!!!\"",n);

    printf("\n\n");
    SetConsoleTextAttribute(h,3);

    for(i=0;i<4;i++) //initializing array with random values
    {
        printf("\t\t%c",line);
        for(j=0;j<4;j++)
        {
            if(i==3 && j==3)
            {
                a[i][j]=' ';
                b[i][j]=a[i][j];
                printf(" %c ",a[i][j]);
                continue;
            }

            a[i][j]=rand()%10; //random function for one digit numbers
            b[i][j]=a[i][j];
            printf(" %d ",a[i][j]);
        }
        printf("%c",line);
        printf("\n");
    }
    SetConsoleTextAttribute(h,2);

    printf("\nPress enter (any key) to start the game.");
    getch(); //getch() to hold screen

    system("cls");
    SetConsoleTextAttribute(h,4);
    printf("\n\n\tYOU HAVE %d MOVES.",n);
    printf("\n\n");
    SetConsoleTextAttribute(h,3);

    for(i=0;i<4;i++) //printing array
    {
        printf("\t | ");
        for(j=0;j<4;j++)
        {
            if(a[i][j]==' ')
                printf(" %c ",a[i][j]);
            else
                printf(" %d ",a[i][j]);
        }
        printf(" | \n");
    }
    SetConsoleTextAttribute(h,4);
    printf("\n\tPRESS ESC KEY TO EXIT\n");
    printf("\n\tMOVE ELEMENTS BY A(LEFT),W(UP),S(DOWN), & D(RIGHT)\n");

    ShortArr(b); //calling short function to compare with result

    i=1;
    while(i)
    {

        ch=getch();
        if(i>n)     //
            break;
        else if(CompairArr(a,b)) //winning situation
        {
            system("cls");
            SetConsoleTextAttribute(h,2);
            printf("\n\tCONGRATULATIONS YOU WON THE GAME\n\n");
        }
        switch(ch)
        {
            case 'a' :  system("cls");
                        SetConsoleTextAttribute(h,4);
                        printf("\n\n\tYOU HAVE %d MOVES.",n-i+1);
                        SetConsoleTextAttribute(h,3);

                        MoveElementLeft(a);

                        SetConsoleTextAttribute(h,4);
                        printf("\n\tPRESS ESC KEY TO EXIT\n");
                        printf("\n\tMOVE ELEMENTS BY A(LEFT),W(UP),S(DOWN), AND D(RIGHT)\n");
                        break;

            case 'w' :  system("cls");
                        printf("\n\n\tYOU HAVE %d MOVES.",n-i+1);
                        SetConsoleTextAttribute(h,3);

                        MoveElementUp(a);

                        SetConsoleTextAttribute(h,4);
                        printf("\n\tPRESS ESC KEY TO EXIT\n");
                        printf("\n\tMOVE ELEMENTS BY A(LEFT),W(UP),S(DOWN), AND D(RIGHT)\n");
                        break;

            case 'd' :  system("cls");
                        printf("\n\n\tYOU HAVE %d MOVES.",n-i+1);
                        SetConsoleTextAttribute(h,3);

                        MoveElementLeft(a);

                        SetConsoleTextAttribute(h,4);
                        printf("\n\tPRESS ESC KEY TO EXIT\n");
                        printf("\n\tMOVE ELEMENTS BY A(LEFT),W(UP),S(DOWN), AND D(RIGHT)\n");
                        break;

            case 's' :  system("cls");
                        printf("\n\n\tYOU HAVE %d MOVES.",n-i+1);
                        SetConsoleTextAttribute(h,3);

                        MoveElementDown(a);

                        SetConsoleTextAttribute(h,4);
                        printf("\n\tPRESS ESC KEY TO EXIT\n");
                        printf("\n\tMOVE ELEMENTS BY A(LEFT),W(UP),S(DOWN), AND D(RIGHT)\n");
                        break;

            case 27  : exit(0);
        }
        i++;
    }
    if(CompairArr(a,b)==0)
    {
        system("cls");
        printf("\n\n\tBETTER LUCK NEXT TIME");
        SetConsoleTextAttribute(h,2);
        printf("\n\tTHANKS FOR PLAYING WITH US");
    }
    printf("\n\n");
    return 0;
}
void MoveElementUp(char a[4][4])
{
    int i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(a[i][j]==' ')
            {
                if(i==0)
                {
                    a[i][j]=a[3][j];
                    a[3][j]=' ';
                }
                else
                {
                    a[i][j]=a[i-1][j];
                    a[i-1][j]=' ';
                }
            }
        }
    }
//    Printing elements after shifting element up
    printf("\n\n");
    for(i=0;i<4;i++)
    {
        printf("\t | ");
        for(j=0;j<4;j++)
        {
            if(a[i][j]==' ')
                printf(" %c ",a[i][j]);
            else
                printf(" %d ",a[i][j]);
        }
        printf(" | \n");
    }
}
void MoveElementDown(char a[4][4])
{
    int i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(a[i][j]==' ')
            {
                a[i][j]=a[(i+1)/4][j];
                a[(i+1)/4][j]=' ';
            }
        }
    }
//    Printing elements after shifting element down
    printf("\n\n");
    for(i=0;i<4;i++)
    {
        printf("\t | ");
        for(j=0;j<4;j++)
        {
            if(a[i][j]==' ')
                printf(" %c ",a[i][j]);
            else
                printf(" %d ",a[i][j]);
        }
        printf(" | \n");
    }
}

void MoveElementLeft(char a[4][4])
{
    int i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(a[i][j]==' ')
            {
                if(j==0)
                {
                    a[i][j]=a[i][3];
                    a[i][3]=' ';
                }
                else
                {
                    a[i][j]=a[i][j-1];
                    a[i][j-1]=' ';
                }
            }
        }
    }
//    Printing elements after shifting element left
    printf("\n\n");
    for(i=0;i<4;i++)
    {
        printf("\t | ");
        for(j=0;j<4;j++)
        {
            if(a[i][j]==' ')
                printf(" %c ",a[i][j]);
            else
                printf(" %d ",a[i][j]);
        }
        printf(" | \n");
    }
}
void MoveElementRight(char a[4][4])
{
    int i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(a[i][j]==' ')
            {
                a[i][j]=a[i][(j+1)/4];
                a[i][(j+1)/4]=' ';
            }
        }
    }
//    Printing elements after shifting element right
    printf("\n\n");
    for(i=0;i<4;i++)
    {
        printf("\t | ");
        for(j=0;j<4;j++)
        {
            if(a[i][j]==' ')
                printf(" %c ",a[i][j]);
            else
                printf(" %d ",a[i][j]);
        }
        printf(" | \n");
    }
}

int CompairArr(char a[4][4],char b[4][4])
{
    int i,j;
    ShortArr(b);
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(a[i][j]!=b[i][j])
                return 0;
        }
    }
    return 1;
}
void ShortArr(char b[4][4]) //Shorting 2D array to compair winning result
{
    int i,j,k,l;
    char m;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(b[i][j]==' ')
                continue;
            else
            {
                for(k=0;k<4;k++)
                {

                    for(l=0;l<4;l++)
                    {
                        if(i==k && j==l)
                            continue;
                        else if(b[i][j]<b[k][l])
                        {
                            m=b[i][j];
                            b[i][j]=b[k][l];
                            b[k][l]=m;
                        }
                    }
                }
            }
        }
    }
}
