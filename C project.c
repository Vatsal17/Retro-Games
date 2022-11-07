#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>
#include<windows.h>
#include<time.h>
#include<process.h>

//Tic Tac Toe Game START

char square[10] = { 'o', '1', '2', '3', '4', '5', '6', '7', '8', '9' };

int checkwin();
void board();

int tictactoe()
{
    int player = 1, i, choice;

    char mark;
    do
    {
        board();
        player = (player % 2) ? 1 : 2;

        printf("Player %d, enter a number:  ", player);
        scanf("%d", &choice);

        mark = (player == 1) ? 'X' : 'O';

        if (choice == 1 && square[1] == '1')
            square[1] = mark;
            
        else if (choice == 2 && square[2] == '2')
            square[2] = mark;
            
        else if (choice == 3 && square[3] == '3')
            square[3] = mark;
            
        else if (choice == 4 && square[4] == '4')
            square[4] = mark;
            
        else if (choice == 5 && square[5] == '5')
            square[5] = mark;
            
        else if (choice == 6 && square[6] == '6')
            square[6] = mark;
            
        else if (choice == 7 && square[7] == '7')
            square[7] = mark;
            
        else if (choice == 8 && square[8] == '8')
            square[8] = mark;
            
        else if (choice == 9 && square[9] == '9')
            square[9] = mark;
            
        else
        {
            printf("Invalid move ");

            player--;
            getch();
        }
        i = checkwin();

        player++;
    }while (i ==  - 1);
    
    board();
    
    if (i == 1)
        printf("==>\aPlayer %d win ", --player);
    else
        printf("==>\aGame draw");

    getch();

    return 0;
}

/*********************************************

FUNCTION TO RETURN GAME STATUS
1 FOR GAME IS OVER WITH RESULT
-1 FOR GAME IS IN PROGRESS
O GAME IS OVER AND NO RESULT
 **********************************************/

int checkwin()
{
    if (square[1] == square[2] && square[2] == square[3])
        return 1;
        
    else if (square[4] == square[5] && square[5] == square[6])
        return 1;
        
    else if (square[7] == square[8] && square[8] == square[9])
        return 1;
        
    else if (square[1] == square[4] && square[4] == square[7])
        return 1;
        
    else if (square[2] == square[5] && square[5] == square[8])
        return 1;
        
    else if (square[3] == square[6] && square[6] == square[9])
        return 1;
        
    else if (square[1] == square[5] && square[5] == square[9])
        return 1;
        
    else if (square[3] == square[5] && square[5] == square[7])
        return 1;
        
    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' &&
        square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7] 
        != '7' && square[8] != '8' && square[9] != '9')

        return 0;
    else
        return  - 1;
}


/*******************************************************************
FUNCTION TO DRAW BOARD OF TIC TAC TOE WITH PLAYERS MARK
 ********************************************************************/


void board()
{
    system("cls");
    printf("\n\n\tTic Tac Toe\n\n");

    printf("Player 1 (X)  -  Player 2 (O)\n\n\n");


    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", square[1], square[2], square[3]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", square[4], square[5], square[6]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", square[7], square[8], square[9]);

    printf("     |     |     \n\n");
}
//END of Tic Tac Toe Game

//Snake Game START

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
int length;
int bend_no;
int len;
char key;
void record();
void load();
int life;
void Delay(long double);
void Move();
void Food();
int Score();
void Print();
void gotoxy(int x, int y);
void GotoXY(int x,int y);
void Bend();
void Boarder();
void Down();
void Left();
void Up();
void Right();
void ExitGame();
int Scoreonly();
struct coordinate
{
    int x;
    int y;
    int direction;
};
typedef struct coordinate coordinate;
coordinate head, bend[500],food,body[30];
void snake()
 {
    char key;
    Print();
    system("cls");
    load();
    length=5;
    head.x=25;
    head.y=20;
    head.direction=RIGHT;
    Boarder();
    Food(); //to generate food coordinates initially
    life=3; //number of extra lives
    bend[0]=head;
    Move();   //initialing initial bend coordinate
    return ;
}
void Move()
{
    int a,i;
    do
    {
        Food();
        fflush(stdin);

        len=0;

        for(i=0; i<30; i++)

        {

            body[i].x=0;

            body[i].y=0;

            if(i==length)

                break;

        }

        Delay(length);

        Boarder();

        if(head.direction==RIGHT)

            Right();

        else if(head.direction==LEFT)

            Left();

        else if(head.direction==DOWN)

            Down();

        else if(head.direction==UP)

            Up();

        ExitGame();

    }
    while(!kbhit());

    a=getch();

    if(a==27)

    {

        system("cls");

        exit(0);

    }
    key=getch();

    if((key==RIGHT&&head.direction!=LEFT&&head.direction!=RIGHT)||(key==LEFT&&head.direction!=RIGHT&&head.direction!=LEFT)||(key==UP&&head.direction!=DOWN&&head.direction!=UP)||(key==DOWN&&head.direction!=UP&&head.direction!=DOWN))

    {

        bend_no++;

        bend[bend_no]=head;

        head.direction=key;

        if(key==UP)

            head.y--;

        if(key==DOWN)

            head.y++;

        if(key==RIGHT)

            head.x++;

        if(key==LEFT)

            head.x--;

        Move();

    }

    else if(key==27)

    {

        system("cls");

        exit(0);

    }

    else

    {

        printf("\a");

        Move();

    }
}

void gotoxy(int x, int y)
{

    COORD coord;

    coord.X = x;

    coord.Y = y;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}
void GotoXY(int x, int y)
{
    HANDLE a;
    COORD b;
    fflush(stdout);
    b.X = x;
    b.Y = y;
    a = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(a,b);
}
void load()
{
    int row,col,r,c,q;
    gotoxy(36,14);
    printf("loading...");
    gotoxy(30,15);
    for(r=1; r<=20; r++)
    {
        for(q=0; q<=100000000; q++); //to display the character slowly
        printf("%c",177);
    }
    getch();
}
void Down()
{
    int i;
    for(i=0; i<=(head.y-bend[bend_no].y)&&len<length; i++)
    {
        GotoXY(head.x,head.y-i);
        {
            if(len==0)
                printf("v");
            else
                printf("*");
        }
        body[len].x=head.x;
        body[len].y=head.y-i;
        len++;
    }
    Bend();
    if(!kbhit())
        head.y++;
}
void Delay(long double k)
{
    Score();
    long double i;
    for(i=0; i<=(10000000); i++);
}
void ExitGame()
{
    int i,check=0;
    for(i=4; i<length; i++) //starts with 4 because it needs minimum 4 element to touch its own body
    {
        if(body[0].x==body[i].x&&body[0].y==body[i].y)
        {
            check++;    //check's value increases as the coordinates of head is equal to any other body coordinate
        }
        if(i==length||check!=0)
            break;
    }
    if(head.x<=10||head.x>=70||head.y<=10||head.y>=30||check!=0)
    {
        life--;
        if(life>=0)
        {
            head.x=25;
            head.y=20;
            bend_no=0;
            head.direction=RIGHT;
            Move();
        }
        else
        {
            system("cls");
            printf("All lives completed\nBetter Luck Next Time!!!\nPress any key to quit the game\n");
            record();
            exit(0);
        }
    }
}
void Food()
{
    if(head.x==food.x&&head.y==food.y)
    {
        length++;
        time_t a;
        a=time(0);
        srand(a);
        food.x=rand()%70;
        if(food.x<=10)
            food.x+=11;
        food.y=rand()%30;
        if(food.y<=10)

            food.y+=11;
    }
    else if(food.x==0)/*to create food for the first time coz global variable are initialized with 0*/
    {
        food.x=rand()%70;
        if(food.x<=10)
            food.x+=11;
        food.y=rand()%30;
        if(food.y<=10)
            food.y+=11;
    }
}
void Left()
{
    int i;
    for(i=0; i<=(bend[bend_no].x-head.x)&&len<length; i++)
    {
        GotoXY((head.x+i),head.y);
        {
            if(len==0)
                printf("<");
            else
                printf("*");
        }
        body[len].x=head.x+i;
        body[len].y=head.y;
        len++;
    }
    Bend();
    if(!kbhit())
        head.x--;

}
void Right()
{
    int i;
    for(i=0; i<=(head.x-bend[bend_no].x)&&len<length; i++)
    {
        //GotoXY((head.x-i),head.y);
        body[len].x=head.x-i;
        body[len].y=head.y;
        GotoXY(body[len].x,body[len].y);
        {
            if(len==0)
                printf(">");
            else
                printf("*");
        }
        /*body[len].x=head.x-i;
        body[len].y=head.y;*/
        len++;
    }
    Bend();
    if(!kbhit())
        head.x++;
}
void Bend()
{
    int i,j,diff;
    for(i=bend_no; i>=0&&len<length; i--)
    {
        if(bend[i].x==bend[i-1].x)
        {
            diff=bend[i].y-bend[i-1].y;
            if(diff<0)
                for(j=1; j<=(-diff); j++)
                {
                    body[len].x=bend[i].x;
                    body[len].y=bend[i].y+j;
                    GotoXY(body[len].x,body[len].y);
                    printf("*");
                    len++;
                    if(len==length)
                        break;
                }
            else if(diff>0)
                for(j=1; j<=diff; j++)
                {
                    /*GotoXY(bend[i].x,(bend[i].y-j));
                    printf("*");*/
                    body[len].x=bend[i].x;
                    body[len].y=bend[i].y-j;
                    GotoXY(body[len].x,body[len].y);
                    printf("*");
                    len++;
                    if(len==length)
                        break;
                }
        }
        else if(bend[i].y==bend[i-1].y)
        {
            diff=bend[i].x-bend[i-1].x;
            if(diff<0)
                for(j=1; j<=(-diff)&&len<length; j++)
                {
                    /*GotoXY((bend[i].x+j),bend[i].y);
                    printf("*");*/
                    body[len].x=bend[i].x+j;
                    body[len].y=bend[i].y;
                    GotoXY(body[len].x,body[len].y);
                    printf("*");
                    len++;
                    if(len==length)
                        break;
                }
            else if(diff>0)
                for(j=1; j<=diff&&len<length; j++)
                {
                    /*GotoXY((bend[i].x-j),bend[i].y);
                    printf("*");*/
                    body[len].x=bend[i].x-j;
                    body[len].y=bend[i].y;
                    GotoXY(body[len].x,body[len].y);
                    printf("*");
                    len++;
                    if(len==length)
                        break;
                }
        }
    }
}
void Boarder()
{
    system("cls");
    int i;
    GotoXY(food.x,food.y);   /*displaying food*/
    printf("F");
    for(i=10; i<71; i++)
    {
        GotoXY(i,10);
        printf("!");
        GotoXY(i,30);
        printf("!");
    }
    for(i=10; i<31; i++)
    {
        GotoXY(10,i);
        printf("!");
        GotoXY(70,i);
        printf("!");
    }
}
void Print()
{
    //GotoXY(10,12);
    printf("\tWelcome to the Snake game.(press any key to continue)\n");
    getch();
    system("cls");
    printf("\tGame instructions:\n");
    printf("\n-> Use arrow keys to move the snake.\n\n-> You will be provided foods at the several coordinates of the screen which you have to eat. Everytime you eat a food the length of the snake will be increased by 1 element and thus the score.\n\n-> Here you are provided with three lives. Your life will decrease as you hit the wall or snake's body.\n\n-> YOu can pause the game in its middle by pressing any key. To continue the paused game press any other key once again\n\n-> If you want to exit press esc. \n");
    printf("\n\nPress any key to play game...");
    if(getch()==27)
        exit(0);
}
void record()
{
    char plname[20],nplname[20],cha,c;
    int i,j,px;
    FILE *info;
    info=fopen("record.txt","a+");
    getch();
    system("cls");
    printf("Enter your name\n");
    scanf("%[^\n]",plname);
    //************************
    for(j=0; plname[j]!='\0'; j++) //to convert the first letter after space to capital
    {
        nplname[0]=toupper(plname[0]);
        if(plname[j-1]==' ')
        {
            nplname[j]=toupper(plname[j]);
            nplname[j-1]=plname[j-1];
        }
        else nplname[j]=plname[j];
    }
    nplname[j]='\0';
    //*****************************
    //sdfprintf(info,"\t\t\tPlayers List\n");
    fprintf(info,"Player Name :%s\n",nplname);
    //for date and time

    time_t mytime;
    mytime = time(NULL);
    fprintf(info,"Played Date:%s",ctime(&mytime));
    //**************************
    fprintf(info,"Score:%d\n",px=Scoreonly());//call score to display score
    //fprintf(info,"\nLevel:%d\n",10);//call level to display level
    for(i=0; i<=50; i++)
        fprintf(info,"%c",'_');
    fprintf(info,"\n");
    fclose(info);
    printf("Wanna see past records press 'y'\n");
    cha=getch();
    system("cls");
    if(cha=='y')
    {
        info=fopen("record.txt","r");
        do
        {
            putchar(c=getc(info));
        }
        while(c!=EOF);
    }
    fclose(info);
}
int Score()
{
    int score;
    GotoXY(20,8);
    score=length-5;
    printf("SCORE : %d",(length-5));
    score=length-5;
    GotoXY(50,8);
    printf("Life : %d",life);
    return score;
}
int Scoreonly()
{
    int score=Score();
    system("cls");
    return score;
}
void Up()
{
    int i;
    for(i=0; i<=(bend[bend_no].y-head.y)&&len<length; i++)
    {
        GotoXY(head.x,head.y+i);
        {
            if(len==0)
                printf("^");
            else
                printf("*");
        }
        body[len].x=head.x;
        body[len].y=head.y+i;
        len++;
    }
    Bend();
    if(!kbhit())
        head.y--;
}



//END Snake Game

//START ASCII Game

char grid[20][41]=                                    ///arena
                      {"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX", /// X: wall
                       "X          c                           X", /// c: cpu
                       "X                                      X", /// u: user
                       "X                                      X", /// b: user's bullet
                       "X                                      X", /// B: cpu's bullet
                       "X                                      X", ///boomerang(array): boomerang
                       "X                                      X", ///wall(array): user's wall
                       "X                                      X",
                       "X                                      X",
                       "X                                      X",
                       "X                                      X",
                       "X                                      X",
                       "X                                      X",
                       "X                                      X",
                       "X                                      X",
                       "X                                      X",
                       "X                                      X",
                       "X                                      X",
                       "X          u                           X",
                       "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"};
///function declarations
void titlescreen(void);
void printbuffer(void);
void win(int);
void printborder(int,int,COORD,int);
void score(int,int,int,int,int,int,int);
void printscoreboard(void);
void screenflash(void);
///main program
void ascii()
{
    int i,j,k,upos=11,cpos=11,cmove,winner=0,uhealth=10,chealth=40,bullets=500,qtyofboomerang=20,qtyofwall=50,boost=0,nofboost=1;
    int boomerang[4]={188,187,201,200},wall[4]={219,178,177,176};
    clock_t start=-1,reloadtime=-1;
    SetConsoleTitle("ASCII Showdown");
    printf("controls:\n'a': left\n'd': right\n'w': fire bullet\n'o': fire homing boomerang\n'p': place a wall\n'i': Engage triple bullet firing mode\n");
    system("pause");
    titlescreen();
    system("cls");
    printbuffer();
    printscoreboard();
    getch();
    srand(time(NULL));         ///seeds random numbers using system time
    while(1)
    {
        ///user's turn
        if(kbhit()) ///listens if user pressed a key
        {
            switch(getch()) ///takes the key input
            {
            case 'w':
                if(bullets>0)
                {
                    if(boost==0)
                    {
                        grid[17][upos]='b';           ///fires a bullet
                        bullets--;
                    }
                    else
                    {
                        if(bullets>2)
                        {
                            for(i=-1;i<=1;i++)
                            {
                                if(upos+i>0 && upos+i<39)
                                {
                                    grid[17][upos+i]='b';          ///fires 3 bullets via weapon boost
                                    bullets--;
                                }
                            }
                        }
                    }
                }
                break;
            case 'a':              ///moves user left
                if(upos>1)
                {
                    grid[18][upos]=' ';
                    upos=upos-1;
                    grid[18][upos]='u';
                }
                break;
            case 'd':             ///moves user right
                if(upos<38)
                {
                    grid[18][upos]=' ';
                    upos=upos+1;
                    grid[18][upos]='u';
                }
                break;
            case 'o':
                if(qtyofboomerang>0)
                {
                    grid[17][upos]=boomerang[0];      ///fires homing boomerang
                    qtyofboomerang--;
                }
                break;
            case 'p':
                if(qtyofwall>0)
                {
                    grid[16][upos]=219;                 ///sets up a wall
                    qtyofwall--;
                }
                break;
            case 'i':
                if(nofboost>0)
                {boost=1;                              ///starts weapon boost
                start=clock();
                nofboost--;
                }
                break;
            }
        }
        ///cpu's turn
        cmove=rand()%4;        ///randomizing cpu's move
        switch(cmove)
        {
        case 0:
            if(chealth>10)
                grid[2][cpos]='B';    ///fires a bullet
            else
                {
                    for(i=-1;i<=1;i++)
                        {
                            if(cpos+i>0 && cpos+i<39)
                                grid[2][cpos+i]='B';          ///fires 3 bullets when health goes 10 or below 10
                        }
                }
            break;
        case 1:
            if(cpos>1)            ///moves left
            {
                grid[1][cpos]=' ';
                cpos=cpos-1;
                grid[1][cpos]='c';
            }
            break;
        case 2:                 ///moves right
            if(cpos<38)
            {
                grid[1][cpos]=' ';
                cpos=cpos+1;
                grid[1][cpos]='c';
            }
            break;
        case 3:                 ///does nothing
            break;
        }
        ///prints the arena
        printbuffer();
        ///prints score
        score(uhealth,chealth,bullets,qtyofboomerang,qtyofwall,boost,nofboost);
        ///time delay
        Sleep(70);
        ///user bullets
        for(i=0;i<20;i++)
        {
            for(j=0;j<40;j++)
            {
                if(grid[i][j]=='b' && i>1 && grid[i-1][j]==' ')
                {
                    grid[i][j]=' ';
                    grid[i-1][j]='b';             ///moves the bullets forward
                }
                if(grid[i][j]=='b' && i==1)
                    grid[i][j]=' ';   ///bullets collision with wall
                if(grid[i][j]=='b' && grid[i-1][j]=='B')
                {
                    grid[i][j]=' ';                      ///bullets collision
                    grid[i-1][j]=' ';
                }
                if(grid[i][j]=='b' && grid[i-1][j]=='c')
                {
                    grid[i][j]=' ';              ///bullet hits cpu
                    chealth--;
                    screenflash();
                }
                for(k=0;k<4;k++)
                {
                    if(grid[i][j]==boomerang[k]-256 && (grid[i-1][j]=='c' || grid[i-1][j-1]=='c' || grid[i-1][j+1]=='c'))
                    {
                        grid[i][j]=' ';              ///boomerang hits cpu
                        chealth-=1;
                        screenflash();
                        screenflash();
                    }
                    if(grid[i][j]==boomerang[k]-256 && i>1 && grid[i-1][j]==' ')
                    {
                        grid[i][j]=' ';
                        if(j>cpos)
                            grid[i-1][j-1]=boomerang[(k+1)%4];         /// boomerang moves forward
                        if(j<cpos)
                            grid[i-1][j+1]=boomerang[(k+1)%4];           ///homing boomerang
                        if(j==cpos)
                            grid[i-1][j]=boomerang[(k+1)%4];
                        break;
                    }
                    if(grid[i][j]==boomerang[k]-256 && grid[i-1][j]=='B')
                    {
                        grid[i][j]=' ';                      ///bullet and boomerang collision
                        grid[i-1][j]=boomerang[(k+1)%4];
                    }
                    if(grid[i][j]==boomerang[k]-256 && i==1)
                        grid[i][j]=' ';                       ///boomerang hits wall
                }
                for(k=0;k<4;k++)
                {
                    if(grid[i][j]=='b' && grid[i-1][j]==wall[k]-256)
                    {
                        grid[i][j]=' ';
                        grid[i-2][j]='b';                                           ///bullets collision with user's wall
                    }
                    if(grid[i][j]==boomerang[0]-256 && grid[i-1][j]==wall[k]-256)
                    {
                        grid[i][j]=' ';
                        grid[i-1][j]=' ';                                       ///boomerang collision with user's wall
                        grid[i-2][j]=boomerang[2];
                    }
                }
            }
        }
        ///cpu bullets
        for(i=19;i>-1;i--)
        {
            for(j=0;j<40;j++)
            {
                if(grid[i][j]=='B' && i<18 && grid[i+1][j]==' ')
                {
                    grid[i][j]=' ';                ///moves the bullets forward
                    grid[i+1][j]='B';
                }
                if(grid[i][j]=='B' && i==18)
                    grid[i][j]=' ';                 ///bullets collision with wall
                if(grid[i][j]=='B' && grid[i+1][j]=='u')
                {
                    grid[i][j]=' ';           ///bullet hits user
                    uhealth--;
                    screenflash();
                }
                for(k=0;k<4;k++)
                {
                    if(grid[i][j]=='B' && grid[i+1][j]==wall[k]-256)
                    {
                        grid[i][j]=' ';                             ///cpu's bullets collision with user's wall
                        if(k<3)
                            grid[i+1][j]=wall[k+1];
                        else
                            grid[i+1][j]=' ';
                    }
                }
            }
        }
        if(clock()-start>5000 && start>0)
        {
            boost=0;                                 ///stops the weapon boost
            start=-1;
            reloadtime=clock();
        }
        if(clock()-reloadtime>10000 && reloadtime>0)
        {
            if(nofboost==0)
                nofboost++;                              ///reloads the weapon boost
            reloadtime=-1;
        }
        if(chealth<=0)
        {
            winner=1;                               ///user wins
            break;
        }
        if(uhealth<=0 || (bullets<=0 && qtyofboomerang==0))
        {
            winner=2;                                            ///cpu wins
            break;
        }
    }
    win(winner);   ///selects the winner. 0 : no winner, 1 : user wins, 2 : cpu wins
    return ; ///end of program
}
/// function definitions
void titlescreen()         ///displays the title screen
{

}
///
void printbuffer()         ///prints the arena
{
    int i,j,ucol=10,ccol=12,color=15;
    CHAR_INFO gridbuffer[800];
    COORD zerozero={0,0},gridsz={40,20};
    SMALL_RECT gridrect={10,2,50,22};
    HANDLE out;
    out=GetStdHandle(STD_OUTPUT_HANDLE);
    for(i=0;i<20;i++)
    {
        for(j=0;j<40;j++)
        {
            gridbuffer[j+40*i].Attributes=color;
            if(grid[i][j]=='X')
                gridbuffer[j+40*i].Char.AsciiChar=219;
            else if(grid[i][j]=='u')
            {
                gridbuffer[j+40*i].Char.AsciiChar=1;
                gridbuffer[j+40*i].Attributes=ucol;
            }
            else if(grid[i][j]==' ')
                gridbuffer[j+40*i].Char.AsciiChar=' ';
            else if(grid[i][j]=='b')
                gridbuffer[j+40*i].Char.AsciiChar=30;
            else if(grid[i][j]=='B')
                gridbuffer[j+40*i].Char.AsciiChar=31;
            else if(grid[i][j]=='c')
            {
                gridbuffer[j+40*i].Char.AsciiChar=2;
                gridbuffer[j+40*i].Attributes=ccol;
            }
            else
            {
                gridbuffer[j+40*i].Char.AsciiChar=grid[i][j];
            }
        }
    }
    WriteConsoleOutput(out,gridbuffer,gridsz,zerozero,&gridrect);
}
///
void win(int winner) ///prints winning message
{
    COORD wintextpos={37,12};
    switch(winner)
    {
    case 1:
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),wintextpos);
        printf("You win!\n");
        Sleep(100);
        break;
    case 2:
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),wintextpos);
        printf("You lose!\n");
        Sleep(100);
        break;
    }
}
///
void printborder(int _length,int _width,COORD _coordinates,int _color)     ///border printing function
{
    int i,j;
    COORD zerozero={0,0},bordersz;
    SMALL_RECT _rect;
    CHAR_INFO _border[_length*_width];
    HANDLE out;
    out=GetStdHandle(STD_OUTPUT_HANDLE);
    bordersz.X=_length;
    bordersz.Y=_width;
    _rect.Left=_coordinates.X;
    _rect.Top=_coordinates.Y;
    _rect.Right=_rect.Left+_length;
    _rect.Bottom=_rect.Top+_width;
    for(i=0;i<_width;i++)
    {
        for(j=0;j<_length;j++)
        {
            if(i==0 || i==_width-1)
            {
                _border[j+_length*i].Char.AsciiChar=205;
                _border[j+_length*i].Attributes=_color;
                continue;
            }
            if(j==0 || j==_length-1)
            {
                _border[j+_length*i].Char.AsciiChar=186;
                _border[j+_length*i].Attributes=_color;
                continue;
            }
            _border[j+_length*i].Char.AsciiChar=' ';
            _border[j+_length*i].Attributes=_color;
        }
    }
    _border[0].Char.AsciiChar=201;
    _border[_length-1].Char.AsciiChar=187;
    _border[_length*_width - 1].Char.AsciiChar=188;
    _border[_length*(_width-1)].Char.AsciiChar=200;
    _border[0].Attributes=_color;
    _border[_length-1].Attributes=_color;
    _border[_length*_width - 1].Attributes=_color;
    _border[_length*(_width-1)].Attributes=_color;
    WriteConsoleOutput(out,_border,bordersz,zerozero,&_rect);
}
///
void score(int uhealth,int chealth,int ubullets,int uboomerang,int uwall,int boost,int nofboost)   ///prints score
{
    HANDLE out;
    out=GetStdHandle(STD_OUTPUT_HANDLE);
    COORD ctext={68,4},utext={68,16},utext1={68,17},utext2={68,18},utext3={68,19},utext4={68,20};
    SetConsoleCursorPosition(out,ctext);
    printf("   ");
    SetConsoleCursorPosition(out,utext);
    printf("   ");
    SetConsoleCursorPosition(out,utext1);
    printf("   ");
    SetConsoleCursorPosition(out,utext2);
    printf("  ");
    SetConsoleCursorPosition(out,utext3);
    printf("  ");
    SetConsoleCursorPosition(out,utext4);
    printf("   ");
    SetConsoleCursorPosition(out,ctext);
    printf("%d",chealth);
    SetConsoleCursorPosition(out,utext);
    printf("%d",uhealth);
    SetConsoleCursorPosition(out,utext1);
    printf("%d",ubullets);
    SetConsoleCursorPosition(out,utext2);
    printf("%d",uboomerang);
    SetConsoleCursorPosition(out,utext3);
    printf("%d",uwall);
    if(nofboost==1 && boost==0)
    {
        SetConsoleCursorPosition(out,utext4);
        SetConsoleTextAttribute(out,12);
        printf("OFF");
        SetConsoleTextAttribute(out,7);
    }
    else if(nofboost==0 && boost==1)
    {
        SetConsoleCursorPosition(out,utext4);
        SetConsoleTextAttribute(out,10);
        printf("ON");
        SetConsoleTextAttribute(out,7);
    }
    else if(nofboost==0 && boost==0)
    {
        SetConsoleCursorPosition(out,utext4);
        SetConsoleTextAttribute(out,14);
        printf("...");
        SetConsoleTextAttribute(out,7);
        exit(0);
    }
}
///
void printscoreboard()    ///prints scoreboard
{
    COORD cpuscoresz={55,3},userscoresz={55,15},ctextpos={56,4},utextpos={56,16};
    HANDLE out;
    out=GetStdHandle(STD_OUTPUT_HANDLE);
    printborder(18,3,cpuscoresz,15);
    printborder(18,7,userscoresz,15);
    SetConsoleCursorPosition(out,ctextpos);
    printf("CPU health: ");
    SetConsoleCursorPosition(out,utextpos);
    printf("USER health: ");
    utextpos.Y++;
    SetConsoleCursorPosition(out,utextpos);
    printf("Bullets: ");
    utextpos.Y++;
    SetConsoleCursorPosition(out,utextpos);
    printf("Boomerang: ");
    utextpos.Y++;
    SetConsoleCursorPosition(out,utextpos);
    printf("Wall: ");
    utextpos.Y++;
    SetConsoleCursorPosition(out,utextpos);
    printf("Boost: ");
}
///
void screenflash()      ///flashes the screen
{
    char str[9]="color   ";
    char sym[17]="0123456789ABCDEF";
    str[6]=sym[rand()%17];
    str[7]=sym[rand()%17];
    system(str);
    Sleep(3);
    str[6]=sym[rand()%17];
    str[7]=sym[rand()%17];
    system(str);
    Sleep(3);
    str[6]=sym[rand()%17];
    str[7]=sym[rand()%17];
    system(str);
    Sleep(3);
    system("color 07");
}
//END ASCII Game

//MAIN Function 
int main()
{
 int ch;
 char op;
do
{
printf("\n\n\n\n\n\n\n\n\n-------:::::Game menu:::::-------\n");
printf("1.TIC TAC TOE game\n");
printf("2. SNAKE game\n");
printf("3. ASCII gmae\n");
printf("4. Exit\n");
printf("Enter your choice: \n");
scanf("%d",&ch);
switch(ch)
{
 case 1:
	tictactoe();
	break;
 case 2:
	snake();
	break;
 case 3:
	ascii();
	break;
	case 4:
	  break;	
default: printf("--------WRONG OPTION OPTED--------");
	 break;
return 0;
}
}
while(ch<4);
ch--;
 }
