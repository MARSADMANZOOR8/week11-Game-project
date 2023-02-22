#include <iostream>
#include <windows.h>
#include<conio.h>
using namespace std ;
// to clean the screen 
void clear();
// to print the logo
void logo();
// to print the header
void header();
// to print the main menu
string menu();
// to print the submenu
string submenu();
// to print the keys 
void keys();
// to print the instructions
void instructions();
// To print the maze
void printMaze();
// To print the tanks
void printtomTank();
void printshawTank();
void printrockTank();
void printjohnTank();
// To move the tank up down left right
void movetomTankleft();
void movetomTankright();
void movetomTankup();
void movetomTankdown();
void moveshawTank();
void movejohnTank();
void moverockTank();
// to erase the tanks
void eraseshawTank();
void eraserockTank();
void erasejohnTank();
void erasetomTank();
// to print the bullets 
void printBullet(int x, int y);
// to erase the bullets
void eraseBullet(int x,int y);
void makeBulletinactive(int index);
// Collision detection with enemies
void bulletCollisionwithshawTank();
void bulletCollisionwithjohnTank();
void bulletCollisionwithrockTank();
// to add the score 
void addScore();
// to print the score 
void printScore();

// Shaw Tank Bullets funtions
int SBulletx[1000];
int SBullety[1000];
bool shawBulletActive[10000];
int shawBulletCount = 0;

void generateShawBullet();
void moveshawBullet();
void shawCollisionCheck();
void printshawBullet(int x,int y);
void eraseshawBullet(int x,int y);
// John Tank Bullets Functions
int johnbulletsX[1000];
int johnbulletsY[1000];
bool johnBulletActive[10000];
int johnbulletCount = 0;

void generatejohnBullet();
void movejohnBullet();
void johnCollisionCheck();
void printjohnBullet(int x,int y);
void erasejohnBullet(int x,int y);


// get character 
char getCharAtxy(short int x , short int y);
void gotoxy(int x, int y);
int score;
void tankHealth();
int Tank_health = 200;
//TOM tank character
char box = 219;
char tank1[13] = {'[','[','[',box,box,box,box,box,box,'=','=','~','>'};
char tank2[13] = {' ',' ',' ',' ','*',box,box,box,'*',' ',' ',' ',' '};
char tank3[13] = {' ',box,box,box,box,box,box,box,box,box,box,box,']'};
char tank4[13] = {' ','\\','_','@','_','@','_','@','_','@','_','@',' '};
//enemies john and shaw character
char enemy1[14] = {' ',' ',' ',' ',' ','_','_','_','_','_','_','_',' '};
char enemy2[14] = {'<','=','=','=','(','`','`','`','`','`','`',' ',')'};
char enemy3[14] = {' ',' ',' ',' ',' ','\\','(','@',')','(','@',')','/'};
char enemy4[14] = {' ',' ',' ',' ',' ',' ','*','*','*','*','*','*',' ',' '};
//rock tank character
char rock1[14] = {' ','_','_','_','_','_','_','_',' ',' ',' ',' ',' ',' '};
char rock2[14] = {'(',' ','`','`','`','`','`','`','`',')','=','=','=','>'};
char rock3[14] = {' ','\\','(','@',')','(','@',')','/',' ',' ',' ',' ',' '};
char rock4[14] = {' ',' ','*','*','*','*','*','*',' ',' ',' ',' ',' ',' '};
// Player Coordinate
int tankX = 35;
int tankY = 8;

// Shaw tank coordinate
int enemyX = 87;
int enemyY = 10;
// Rock tank coordinate
int enemy1X = 5;
int enemy1Y = 5;
// JOHN tank coordinate
int enemy2X = 87;
int enemy2Y = 17;
// SHAW  Tank FIRST direction
string shawtankDirection = "Up";
// JOHN tank first direction
string johntankDirection = "Left";
// ROCK tank first direction
string rocktankDirection = "Up";
// hero's Bulllets towards right side 
int bulletX[1000];
int bulletY[1000];
void generateBullet();
void moveBullet();
bool isBulletActive[10000];
int bulletCount = 0;
// hero's Bulllets towards left side
int BxLeft[1000];
int ByLeft[1000];
int bulletCountleft = 0;
void generateBulletL();
void moveBulletL(); 
bool isBulletActiveL[10000];
main()
{
    string choice1;
    string choice2;
    int timer;
    system("cls");
    logo();
    clear();
    
    
    header();
   clear();

    while(choice1<"3")
    {
        system("cls");
         
         
        choice1 = menu();
        system("cls");
        if(choice1=="1")
        { 
            
            printMaze();
            printtomTank();
            printshawTank();
            printjohnTank();
            printrockTank();
            while (true)
            {
                printScore();
                tankHealth();
                if (GetAsyncKeyState(VK_LEFT))
                {
                 movetomTankleft();
                }
                if (GetAsyncKeyState(VK_RIGHT))
                {
                 movetomTankright();
                }
                if (GetAsyncKeyState(VK_UP))
                {
                  movetomTankup();
                }
                 if (GetAsyncKeyState(VK_DOWN))
                {
                movetomTankdown();
                }
                 if (GetAsyncKeyState(VK_SPACE))
                {
                generateBullet();
                }
                if (GetAsyncKeyState(VK_TAB))
                {
                generateBulletL();
                }

        
                // to move the tanks         
                moveshawTank();
                moverockTank();
                movejohnTank();
                // to move the bullets left and right 
                moveBullet();
                moveBulletL();
                generateShawBullet();
                generatejohnBullet();
                moveshawBullet();
                movejohnBullet();
                // collision of the bullets with enemies tanks
                bulletCollisionwithshawTank();
                bulletCollisionwithjohnTank();
                bulletCollisionwithrockTank();
                // Enemies collision detector 
                shawCollisionCheck();
                johnCollisionCheck();
                Sleep(50);
            }
        }
        if (choice1=="2")
        {
            
            while(choice2<"3")
            {
               choice2 = submenu();
               if(choice2=="1")
               {
                keys();
               }
               if(choice2=="2")
               {
                instructions();
               }
               if(choice2=="3")
               {
                break;
               }
            }
        }
        if (choice1=="3")
        {
            break;
        }
    }
}
// logo function
void logo()
{
    
    cout <<"                                                                                  " << endl;
    cout <<"                                                                                  " << endl;
    cout <<"                                                                                  " << endl;
    cout <<"                                                                                  " << endl;
    cout <<"                __________________________________________|||     ___ FIRE        " << endl;
    cout <<"                __________________________________________ ------|___ >>>>>>>>    " << endl;
    cout <<"                    _________________|||_______________   |||                     " << endl;
    cout <<"                   |                                   |                          " << endl;
    cout <<"                   |___________________________________|                          " << endl;
    cout <<"                      |||                         |||                             " << endl;
    cout <<"          ========================================================                " << endl;
    cout <<"         |   @@           @@          @@          @@         @@   |               " << endl;
    cout <<"         | @@  @@       @@  @@      @@  @@      @@  @@     @@  @@ |               " << endl;
    cout <<"         |   @@           @@          @@          @@         @@   |               " << endl;
    cout <<"          ========================================================                " << endl;
    cout <<"                                                                                  " << endl;
    cout <<"______________________________FAST AND FURIOUS____________________________________" << endl;
    cout <<"                                                                                  " << endl;
}

// header of the game
void header()
{
    cout <<"                                                                                             " << endl;
    cout <<"                                                                                             " << endl;
    cout <<"              #########       ##       #####    ############                                 " << endl;
    cout <<"              ##            ##  ##    #             ##                                       " << endl;
    cout <<"              #########    ##    ##    ##           ##        ##   ##      ## ######         " << endl;
    cout <<"              ##          ##########     ##         ##      ##  ## ## ##   ## ##    ##       " << endl;
    cout <<"              ##          ##      ##       ##       ##      ###### ##   ## ## ##    ##       " << endl;
    cout <<"              ##          ##      ##   #####        ##      ##  ## ##      ## ######         " << endl;
    cout <<"                                                                                             " << endl;
    cout <<"       ############     ####     ####    ########    ###      ####     ####    ####   ###### " << endl;
    cout <<"       ###              ####     ####    ##    ##    ###    ##    ##   ####    ####  #       " << endl;
    cout <<"       ############     ####     ####    ########    ###   ##      ##  ####    ####   ##     " << endl;
    cout <<"       ###              ####     ####    ##   #      ###   ##      ##  ####    ####     ##   " << endl;
    cout <<"       ###              ####     ####    ##    #     ###    ##    ##   ####    ####       ## " << endl;
    cout <<"       ###              #############    ##     #    ###      ####     ############   ###### " << endl;
    cout <<"                                                                                             " << endl; 

}
// main menu function
string menu()
{
    string option;
    cout << "                          " << endl;
    cout << "__________________________" << endl;
    cout << "1.  Start                 " << endl;
    cout << "2.  Option                " << endl;
    cout << "3.  Exit                  " << endl;
    cout <<"ENTER ONE OPTION  :        " << endl;
    cin>>option;
    return option;

}
// submenu function after the main menu function
string submenu()
{
    string option1;
    cout << "                   " << endl;
    cout << "1.  Keys.          " << endl;
    cout << "2.  Instructions.  " << endl;
    cout << "3.  Exit           " << endl;
    cout << "Enter any option : " << endl;
    cin >> option1;
    return option1;
}
// important keys function description
void keys()
{
    cout <<"KEYS.                            "<<endl;
    cout <<"________________________________ "<<endl;
    cout <<"1. UP                     GO UP  "<<endl;
    cout <<"2. DOWN                   GO DOWN"<<endl;
    cout <<"3. LEFT                   GO LEFT"<<endl;
    cout <<"4. RIGHT                  GO RIGHT"<<endl;
    cout <<"5. FIRE Right             SPACE   "<<endl;
    cout <<"6. Fire Left              TAB     "<<endl;
    cout <<"Press any key to continue ........"<<endl;
    getch();
}
// the insrtuction function for the users
void instructions()
{
 cout << "Please do not press any invalid key and follow the keys menu given below.  " << endl;
}
// clear function
void clear()
{
    cout << "Press any key to continue....";
    getch();
    system("cls");
}
// to print the maze
void printMaze()
{
  
cout << " ##########################################################################################################" << endl ;
cout << " #                                             BATTLEGROUND                                               #" << endl ;
cout << " #                                                                                                        #" << endl ;
cout << " #                                                                                                        #" << endl ;
cout << " #                                                                                                        #" << endl ;
cout << " #                                                                                                        #" << endl ;
cout << " #                                                                                                        #" << endl ;
cout << " #                                                                                                        #" << endl ;
cout << " #                                                                                                        #" << endl ;
cout << " #                                                                                                        #" << endl ;
cout << " #                                                                                                        #" << endl ;
cout << " #                                                                                                        #" << endl ;
cout << " #                                                                                                        #" << endl ;
cout << " #                                                                                                        #" << endl ;
cout << " #                                                                                                        #" << endl ;
cout << " #                                                                                                        #" << endl ;
cout << " #                                                                                                        #" << endl ;
cout << " #                                                                                                        #" << endl ;
cout << " #                                                                                                        #" << endl ;
cout << " #                                                                                                        #" << endl ;
cout << " #                                                                                                        #" << endl ;
cout << " #                                                                                                        #" << endl ;
cout << " ##########################################################################################################" << endl ;
}

// To print the Tom tank
void printtomTank()
{
    gotoxy(tankX, tankY);
    for (int index = 0; index<13 ;index++)
    {
        cout << tank1[index];
    }
    gotoxy(tankX,tankY+ 1);
    for (int index = 0; index<13;index++)
    {
        cout << tank2[index];
    }
     gotoxy(tankX,tankY+ 2);
    for (int index = 0; index<13;index++)
    {
        cout << tank3[index];
    }
    gotoxy(tankX,tankY+ 3);
    for (int index = 0; index<13;index++)
    {
        cout << tank4[index];
    }
}
// To print shaw tank
void printshawTank()
{
    gotoxy(enemyX, enemyY);
    for (int index = 0; index < 14;index++ )
    {
        cout << enemy1[index];
    }
    gotoxy(enemyX, enemyY+1);
    for (int index = 0; index < 14;index++ )
    {
        cout << enemy2[index];
    }
    gotoxy(enemyX, enemyY+2);
    for (int index = 0; index < 14;index++ )
    {
        cout << enemy3[index];
    }
    gotoxy(enemyX, enemyY+3);
    for (int index = 0; index < 14;index++ )
    {
        cout << enemy4[index];
    }

}
// To print the rock tank
void printrockTank()
{
    gotoxy(enemy1X, enemy1Y);
    for (int index = 0; index < 14;index++ )
    {
        cout << rock1[index];
    }
    gotoxy(enemy1X, enemy1Y+1);
    for (int index = 0; index < 14;index++ )
    {
        cout << rock2[index];
    }
    gotoxy(enemy1X, enemy1Y+2);
    for (int index = 0; index < 14;index++ )
    {
        cout << rock3[index];
    }
    gotoxy(enemy1X, enemy1Y+3);
    for (int index = 0; index < 14;index++ )
    {
        cout << rock4[index];
    }

}
// To print the john tank
void printjohnTank()
{
    gotoxy(enemy2X, enemy2Y);
    for (int index = 0; index < 14;index++ )
    {
        cout << enemy1[index];
    }
    gotoxy(enemy2X, enemy2Y+1);
    for (int index = 0; index < 14;index++ )
    {
        cout << enemy2[index];
    }
    gotoxy(enemy2X, enemy2Y+2);
    for (int index = 0; index < 14;index++ )
    {
        cout << enemy3[index];
    }
    gotoxy(enemy2X, enemy2Y+3);
    for (int index = 0; index < 14;index++ )
    {
        cout << enemy4[index];
    }

}
// to move the tank left
void movetomTankleft()
{
    char next = getCharAtxy(tankX - 1, tankY);
    if (next == ' ')
    {
        erasetomTank();
        tankX = tankX - 1;
        printtomTank();
    }
}
// to move the tank right 
void movetomTankright()
{

    char next = getCharAtxy(tankX + 13, tankY);
    if (next == ' ')
    {
        erasetomTank();
        tankX = tankX + 1;
        printtomTank();
    }
}
// to move the tank up
void movetomTankup()
{


    char next = getCharAtxy(tankX , tankY - 1);
    if (next == ' ')
    {
        erasetomTank();
        tankY = tankY - 1;
        printtomTank();
    }
}
// to move the tank down
void movetomTankdown()
{


    char next = getCharAtxy(tankX , tankY + 4 );
    if (next == ' ')
    {
        erasetomTank();
        tankY = tankY + 1;
        printtomTank();
    }
    
}
// To move the shaw tank
void moveshawTank()
{
    
    if (shawtankDirection == "Up")
    {
        char next = getCharAtxy(enemyX,enemyY - 1);
        if(next == ' ' || next == '.')
        {
            eraseshawTank();
            enemyY--;
            printshawTank();
        }
        if (enemyY<=1)
        {
           shawtankDirection = "Down";
        }
        
    }
    if (shawtankDirection == "Down")
    {
        char next = getCharAtxy(enemyX,enemyY + 4);
        if(next == ' ' || next == '.')
        {
            eraseshawTank();
            enemyY++;
            printshawTank();
        }
        if (enemyY>=13)
        {
           shawtankDirection = "Up";
        }
    
    }
}
// to move the rock tank
void moverockTank()
{
    
    if (rocktankDirection == "Up")
    {
        char next = getCharAtxy(enemy1X,enemy1Y - 1);
        if(next == ' ' || next == '.')
        {
            eraserockTank();
            enemy1Y--;
            printrockTank();
        }
        if (enemy1Y<=1)
        {
           rocktankDirection = "Down";
        }
        
    }
    if (rocktankDirection == "Down")
    {
        char next = getCharAtxy(enemy1X,enemy1Y + 4);
        if(next == ' ' || next == '.')
        {
            eraserockTank();
            enemy1Y++;
            printrockTank();
        }
        if (enemy1Y>=17)
        {
           rocktankDirection = "Up";
        }
    
    }
}
// to move the john tank 
void movejohnTank()
{
    if (johntankDirection == "Left")
    {
        char next = getCharAtxy(enemy2X-1,enemy2Y);
        if(next == ' ' || next == '.')
        {
            erasejohnTank();
            enemy2X--;
            printjohnTank();
        }
        if (enemy2X<=65)
        {
           johntankDirection = "Right";
        }
        
    }
    if (johntankDirection == "Right")
    {
        char next = getCharAtxy(enemy2X + 14,enemy2Y);
        if(next == ' ' || next == '.')
        {
            erasejohnTank();
            enemy2X++;
            printjohnTank();
        }
        if (enemy2X>=85)
        {
           johntankDirection = "Left";
        }
    
    }

}
// To erase the shaw tank
void eraseshawTank()
{
    gotoxy(enemyX,enemyY);
    for (int index = 0; index < 14;index++)
    {

        cout << " ";
    }
    gotoxy(enemyX,enemyY + 1);
    for (int index = 0; index < 14;index++)
    {

        cout << " ";
    }
    gotoxy(enemyX,enemyY + 2);
    for (int index = 0; index < 14;index++)
    {

        cout << " ";
    }
    gotoxy(enemyX,enemyY + 3);
    for (int index = 0; index < 14;index++)
    {

        cout << " ";
    }
}
// To erase the john tank
void erasejohnTank()
{
    gotoxy(enemy2X,enemy2Y);
    for (int index = 0; index < 14;index++)
    {

        cout << " ";
    }
    gotoxy(enemy2X,enemy2Y + 1);
    for (int index = 0; index < 14;index++)
    {

        cout << " ";
    }
    gotoxy(enemy2X,enemy2Y + 2);
    for (int index = 0; index < 14;index++)
    {

        cout << " ";
    }
    gotoxy(enemy2X,enemy2Y + 3);
    for (int index = 0; index < 14;index++)
    {

        cout << " ";
    }
}
// To erase the rock tank
void eraserockTank()
{
    gotoxy(enemy1X,enemy1Y);
    for (int index = 0; index < 14;index++)
    {

        cout << " ";
    }
    gotoxy(enemy1X,enemy1Y + 1);
    for (int index = 0; index < 14;index++)
    {

        cout << " ";
    }
    gotoxy(enemy1X,enemy1Y + 2);
    for (int index = 0; index < 14;index++)
    {

        cout << " ";
    }
    gotoxy(enemy1X,enemy1Y + 3);
    for (int index = 0; index < 14;index++)
    {

        cout << " ";
    }
}
// To erase the tom Tank
void erasetomTank()
{
    gotoxy(tankX, tankY);
    for (int index = 0;index<13;index++)
    {
        cout << " ";
    }
    gotoxy(tankX, tankY + 1);
    for (int index = 0;index<13;index++)
    {
        cout << " ";
    }
    gotoxy(tankX, tankY + 2);
    for (int index = 0;index<13;index++)
    {
        cout << " ";
    }
    gotoxy(tankX,tankY + 3);
     for (int index = 0;index<13;index++)
    {
        cout << " ";
    }

}


//generate bullet from the hero tanks towadrs right side
void generateBullet()
{
    bulletX[bulletCount] = tankX + 13;
    bulletY[bulletCount] = tankY;
    isBulletActive[bulletCount] = true;
    gotoxy(tankX + 13,tankY);
    cout << ".";
    bulletCount++;
}
// to generate the bullets in the left side direction
void generateBulletL()
{
    BxLeft[bulletCount] = tankX - 1;
    ByLeft[bulletCount] = tankY;
    isBulletActiveL[bulletCount] = true;
    gotoxy(tankX-1,tankY);
    cout<<".";
    bulletCount++;
}
//move bullet towards the enemy 
void moveBullet()
{
    for(int x = 0;x < bulletCount ;x++)
    {
        if(isBulletActive[x] == true)
        {
            char next = getCharAtxy(bulletX[x] + 1,bulletY[x]);
            if (next != ' ')
            {
                eraseBullet(bulletX[x],bulletY[x]);
                makeBulletinactive(x);
            }
            else
            {
               eraseBullet(bulletX[x],bulletY[x]);
               bulletX[x] = bulletX[x] + 1;
               printBullet(bulletX[x],bulletY[x]);
            }
        }
    }
}
// to move the bullet in left direction towards the rock tank 
void moveBulletL()
{
    for(int x = 0;x < bulletCount ;x++)
    {
        if(isBulletActiveL[x] == true)
        {
            char next = getCharAtxy(BxLeft[x] - 1,ByLeft[x]);
            if (next != ' ')
            {
                eraseBullet(BxLeft[x],ByLeft[x]);
                isBulletActiveL[x] = false;
            }
            else
            {
               eraseBullet(BxLeft[x],ByLeft[x]);
               BxLeft[x] = BxLeft[x] - 1;
               printBullet(BxLeft[x],ByLeft[x]);
            }
        }
    }
}    

//supporting functions of the enemy
void printBullet(int x, int y)
{
    gotoxy(x, y);
    cout << ".";

}
void eraseBullet(int x, int y)
{
    gotoxy(x, y);
    cout << " ";
}
void makeBulletinactive(int index)
{
    isBulletActive[index] = false;
}


// collision detection tom tank bullets with the rock tank

void bulletCollisionwithrockTank()
{
    for (int x = 0;x<bulletCount;x++)
    {
        if (isBulletActiveL[x]==true)
        {
            if(BxLeft[x] - 1 == enemy1X && (ByLeft[x] == enemy1Y || ByLeft[x] == enemy1Y + 2 || ByLeft[x] == enemy1Y + 3))
            {
                addScore();
            }

            if(enemy1X + 14 == BxLeft[x] && enemy1Y + 1 == ByLeft[x])
            {
                addScore();
            }
        }
    }
} 

// collision detection tom tank bullets with the shaw tank

void bulletCollisionwithshawTank()
{
    for (int x = 0;x<bulletCount;x++)
    {
        if (isBulletActive[x]==true)
        {
            if(bulletX[x] + 1 == enemyX && (bulletY[x] == enemyY || bulletY[x] == enemyY + 2 || bulletY[x] == enemyY + 3))
            {
                addScore();
            }
            if(enemyX - 1 == bulletX[x] && enemyY + 1 == bulletY[x])

            {
                addScore();
            }
        }
    }
}

// collision detection tom tank bullets with the john tank

void bulletCollisionwithjohnTank()
{
    for (int x = 0;x<bulletCount;x++)
    {
        if (isBulletActive[x]==true)
        {
            if(bulletX[x] + 1 == enemy2X && (bulletY[x] == enemy2Y || bulletY[x] == enemy2Y + 2 || bulletY[x] == enemy2Y + 3))
            {
                addScore();
            }
            if(enemy2X - 1 == bulletX[x] && enemy2Y + 1 == bulletY[x])

            {
                addScore();
            }
        }
    }
} 
// score of the player
void addScore()
{
   
    score = score + 1;
}
// to print the score of the player
void printScore()
{
    
    gotoxy(140 , 8);
    cout << "Score" << score;
}
// to generate the shaw tank bullets

void generateShawBullet()
{
     SBulletx[shawBulletCount] = enemyX - 1;
     SBullety[shawBulletCount] = enemyY;
     shawBulletActive[shawBulletCount] = true;
     gotoxy(enemyX-1,enemyY);
     cout<<"-";
     shawBulletCount++;
}
// to move the shaw tank bullets
void moveshawBullet()
{
    for(int x = 0;x < shawBulletCount ;x++)
    {
        if(shawBulletActive[x] == true)
        {
            char next = getCharAtxy(SBulletx[x] - 1,SBullety[x]);
            if (next != ' ')
            {
                eraseshawBullet(SBulletx[x],SBullety[x]);
                shawBulletActive[x] = false;
            }
            else
            {
               eraseshawBullet(SBulletx[x],SBullety[x]);
               SBulletx[x] = SBulletx[x] - 1;
               printshawBullet(SBulletx[x],SBullety[x]);
            }
        }
    }
}    
// to print the shaw tank bullets
void printshawBullet(int x,int y)
{
    gotoxy(x,y);
    cout<<"-";
}
// to erase the shaw tank bullets
void eraseshawBullet(int x,int y)
{
    gotoxy(x,y);
    cout<<" ";
}
// to check the collision shaw tank bullets with the tom tank
void shawCollisionCheck()
{
    for (int x = 0;x<shawBulletCount;x++)
    {
        if (shawBulletActive[x]==true)
        {
            if(SBulletx[x] - 1 == tankX && (SBullety[x] == tankY || SBullety[x] == tankY + 2 || SBullety[x] == tankY + 3))
            {
                Tank_health = Tank_health - 2;
            }

            if(tankX + 13 == SBulletx[x] && tankY + 1 == SBullety[x])
            {
                Tank_health = Tank_health - 2;
            }
        }
    }
 
}
// to generate the john tank bullet
void generatejohnBullet()
{
    johnbulletsX[johnbulletCount] = enemy2X - 1;
    johnbulletsY[johnbulletCount] = enemy2Y+1;
    johnBulletActive[johnbulletCount] = true;
    gotoxy(enemy2X-1,enemy2Y+1);
    cout << "-";
    johnbulletCount++;
}
// to move the john tank bullet
void movejohnBullet()
{
    for(int x = 0;x < johnbulletCount;x++)
    {
        if(johnBulletActive[x] == true)
        {
            char next = getCharAtxy(johnbulletsX[x] - 1,johnbulletsY[x]);
            if (next != ' ')
            {
                erasejohnBullet(johnbulletsX[x],johnbulletsY[x]);
                johnBulletActive[x] = false;
            }
            else
            {
                erasejohnBullet(johnbulletsX[x],johnbulletsY[x]);
                johnbulletsX[x] = johnbulletsX[x] - 1;
                printjohnBullet(johnbulletsX[x],johnbulletsY[x]);
            }
        }
    }
}
// to print the john bullet
void printjohnBullet(int x,int y)
{
    gotoxy(x,y);
    cout<<"-";
}
// to erase the john tank bullet
void erasejohnBullet(int x,int y)
{
    gotoxy(x,y);
    cout<<" ";
}
// to check the collision of the john tank with the tom tank
void johnCollisionCheck()
{
    for (int x = 0;x<johnbulletCount;x++)
    {
        if (johnBulletActive[x]==true)
        {
            if(johnbulletsX[x] - 1 == tankX && (johnbulletsX[x] == tankY || johnbulletsY[x] == tankY + 2 || johnbulletsY[x] == tankY + 3))
            {
                Tank_health = Tank_health - 2;
            }

            if(tankX + 13 == johnbulletsX[x] && tankY + 1 == johnbulletsY[x])
            {
                Tank_health = Tank_health - 2;
            }
        }
    }
 
}
// health of the hero 
void tankHealth()
{
    gotoxy(5,30);
    cout<<"Tank Health : "<<Tank_health;
}
// to move the cursor at desired place
void gotoxy(int x , int y)
{
COORD coordinates;
coordinates.X = x;
coordinates.Y = y;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}
char getCharAtxy(short int x, short int y)
{
CHAR_INFO ci;
COORD xy = {0 ,0};
SMALL_RECT rect = {x , y, x, y};
COORD coorsBufSize;
coorsBufSize.X = 1;
coorsBufSize.Y = 1;
return ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, coorsBufSize , xy ,&rect) ? ci.Char.AsciiChar : ' ';
}