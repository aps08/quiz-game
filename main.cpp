#include <iostream>
#include<Windows.h>
#include<conio.h>
#include"game.h"  //USER DEFINED HEADER

using namespace std;
int main()
{
    int b, c, attempts = 0;
    char n, ch = 'Y';
    system("Color 60");
    
start:
    do {
        system("cls");
        cout << "\n\n\n\n\t\t\t\t\tWELCOME TO THE QUIZ!\n\t\t\t\t\tCREATED BY ANOOP PRATAP SINGH";   //FOR MENU
        cout << "\n\n\t\t\t\t1.LOGIN\n\t\t\t\t2.SIGNUP\n\t\t\t\t3.DETAILS\n\t\t\t\t4.EXIT";
        cout << "\n\t\t\t\tENTER YOUR CHOICE"; 
        n = _getch();
        switch (n)
        {
        case '1': //LOGIN
        {
            system("cls");
            select:
            b =login();
            if (b != 0)
            {
                system("cls");
                cout << "\n\n\n\t\t\t\tLOGIN SUCCESSFUL!\n\t\t\t\tSELECT TOPIC FOR THE QUIZ!";
                Sleep(1000);
                playagain:
                c=topic();
                if (c == 1)
                    goto start;
                else
                {
                    char ch;
                    cout << "\n\n\n\n\t\t\t\tYOUR TOTAL SCORE IS:" << c;
                    cout << "\n\t\t\t\tWANT TO PLAY AGAIN!(Y/N)?";
                    ch = _getch();
                    if (toupper(ch) == 'Y')
                        goto playagain;
                    else
                        break;
                }
            }
            else
            {
                char aa = 'A';
                cout << "\n\t\t\t\tLOGIN UNSUCCESSFUL!TRY AGAIN!";
                Sleep(500);
                cout << "\n\t\t\t\tPRESS Y TO TRY AGAIN\n\t\t\t\tPRESS B TO GO BACK";
                aa = _getch();
                if(toupper(aa)=='B')
                    goto start;
                attempts++;
                if (attempts == 3)
                {
                    cout << "\nMAXIMUM ATTEMPTS EXPIRED!\nTRY SIGNING UP!";
                    cout << "*************"; Sleep(1000);
                    cout << "***************"; Sleep(800);
                    cout << "******************";
                    goto start;
                }
                goto select;
                
            }
            break;
        }
        case '2': //SIGNUP
        {
            system("cls");
            b = signup();
            if (b == 1)
            {
                cout << "\n\n\n\n\t\t\t\t SIGNUP SUCCESSFUL\n\t\t\t\tLOGIN NOW"; Sleep(1500);
                goto start;
            }
            else
            {
                cout << "\n\n\n\n\t\t\t\t\tSIGNUP UNSUCCESSFUL!TRY AGAIN!\nEITHER USERNAME EXIST OR THE PASSWORD DIDN'T MATCH";
                Sleep(500);
                cout << "*************"; Sleep(800);
                cout << "***************"; Sleep(800);
                cout << "******************";
                goto start;
            }
            break;
        }
        case '3': //DETAILS ABOUT THE PROJECT
        {
            system("cls");
            cout << "\n\n\n\t\t This quiz game mini c++ project is coded ANOOP PRATAP SINGH. The main objective of the\n\t\t";
            cout << "project to learn how .exe is created and applications works. This project also shows how \n\t\t";
            cout << "header files and source files can be separated in order to make the program more familiar for\n\t\t";
            cout << "coder to understands what's going at the back-end of the application. This multi-file execution\n\t\t";
            cout << "can help us secure the code from vandalism or any attack.\n\t\tDATE OF CREATION OF THIS PROJECT 1st JULY 2020.\n\t\t";
            cout << "PLEASE HELP ME MAKE IT MORE SHORT IF YOU HAVE ANY IDEA.\n";
            cout << "\n\t\t GO BACK!(Y/N)";
            cout << "\n\t\t\tY to go back\n\t\t\t N to exit";
            ch = _getch();
            if (toupper(ch) == 'Y')
                goto start;
            else
                exit(0);
        }
        case '4': //FOR EXITING THE GAME
        {
            system("cls");
            cout << "\n\n\n\n\t\t\t\tARE YOUR SURE!YOU WANT TO EXIT THE GAME?(Y/N)"; //FOR CONFIRMATION
            ch = _getch();
            if (toupper(ch) == 'Y')
            {
                cout << "\n\t\t\t\tEXITING THE GAME!\n";
                cout << "\t\t\t\t**************";
                Sleep(1200);
                cout << "***************";
                Sleep(1000);
                cout << "***************";
                Sleep(800);
                exit(0);
            }
            else
                goto start; //JUMP TO MENU
        }
        default:
            goto start; //JUMP TO MENU
        }
    } while (1); //INFINITE LOOP UNTIL USER EXITS
    return 0;
}