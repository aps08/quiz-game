#include "game.h"
#include<iostream>
#include<conio.h>
#include <string>
#include<fstream>
#include<Windows.h>
using namespace std;
char user[20], pass[20]; //FOR READING USER AND PASS FROM FILE
string question, option1, option2, option3, option4;
int abc = 0, score, tscore, option, answer;
int login()
{
    char a;
    system("cls");
    cout << "\n\n\n\n\t\t\t\t\tENTER USERNAME:"; cin >> user;
    cout << "\n\t\t\t\t\tENTER PASSWORD:";
    for (int i = 0;;)
    {
        a = _getch();//STORES CHAR TYPED IN A
        if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9'))
            //CHECKS IF THE ENTERED CHARACTER IS ALPHABET OR NUMBER
        {
            pass[i] = a;//STORES THE CHARACTER IN A IN PASS
            ++i;
            cout << "*"; //SHOW * AS INPUT FOR SECURITY
        }
        if (a == '\b' && i >= 1)//IF USER TYPED BACKSPACE
        {
            cout << "\b \b";//RUB THE CHARACTER BEHIND THE CURSOR
            --i;
        }
        if (a == '\r')//IF ENTER IS PRESSED
        {
            pass[i] = '\0';//END OF STRING
            break;//BREAKS THE LOOP
        }
    }
    ifstream f;
    char username[20], password[20]; //FOR STORING USER ENTERED USERNAME AND PASSWORD
    int n = 0;
    f.open("users.txt",ios::in);
    if (f.is_open()) //IF FILE OPENS
    {
        while (!f.eof()) //READING FILE TILL THE END OF LINE
        {
            f >> username >> password;
            n++;
            if (strcmp(user, username) == 0 && strcmp(pass, password) == 0) //COMPARING EACH USERNAME AND PASSWORD
            {
                f.close();
                return n;
            }
        }
    }
    else
    {
        cout << "FILE DIDN'T OPEN.\n\n\t\t\t\tEXITING GAME";
        Sleep(1500);
        exit(0);
    }
    f.close();
	return 0;
}   
int signup()
{
    int alpha = 0;
    ifstream file; //FOR READING FROM THE FILE
    ofstream newuser; //FOR WRITING INTO THE FILE
    char username[20], password[20], passwordconfirm[20]; //FOR USER ENTERED USERNAME AND PASSWORD AND FOR PASSWORD CONFIRMATION
    file.open("users.txt", ifstream::in);
    newuser.open("users.txt", ofstream::out||ofstream::app);
    bool uservalid = false;
    char a;
    int i, j;
    while (!uservalid)
    {
    user:
        system("cls");
        cout << "\n\n\n\n\t\t\t\tSIGNUP FORUM!!"; //TO MAKE A DIFFERENCE IN LOGIN AND SIGNUP SCREEN
        cout << "\n\n\t\t\t\tUsername: ";
        cin >> username;
        pass:
        cout << "\n\t\t\t\tPassword: ";
        for (i = 0;;)
        {
            a = _getch();//STORES CHARACTER IN A
            if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9'))
                //CHECK IF THE ENTERED CHARACTER IS ALPHABET OR NUMBER
            {
                password[i] = a;//STORES THE CHEARACTER IN A INTO PASSWORD
                ++i;
                cout << "*";
            }
            if (a == '\b' && i >= 1)//IF USER ENTERS BACKSPACE
            {
                cout << "\b \b";//RUB THE CHARACTER BEHIND THE CURSOR
                --i;
            }
            if (a == '\r')//IF ENTERED IS PRESSED
            {
                password[i] = '\0';//END OF STRING
                break;
            }
        }
        cout << "\n\n\t\t\t\tConfirm password: ";
        for (j = 0;;)
        {
            a = _getch();//STORES CHARACTER IN A
            if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9'))
                //CHECK IF THE ENTERED CHARACTER IS ALPHABET OR NUMBER
            {
                passwordconfirm[j] = a;//STORES THE CHEARACTER IN A INTO PASSWORDCONFIRM
                ++j;
                cout << "*";
            }
            if (a == '\b' && i >= 1)////IF USER ENTERED BACKSPACE
            {
                cout << "\b \b";//RUB THE CHARACTER BEHIND THE CURSOR
                --j;
            }
            if (a == '\r')//IF ENTERED IS PRESSED
            {
                passwordconfirm[j] = '\0';//END OF STRING
                break;
            }
        }
        if (strcmp(password,passwordconfirm)!=0) //COMPARING ENTERED PASSWORD AND CONFIRMED PASSWORD
        {
            cout << "\n\t\t\t\t PASSWORD DO NOT MATCH! TRY AGAIN!";
            cout << "\n\t\t\t\tENTER THE PASSWORD AGAIN!";
            goto pass; //JUMP TO PASSWORD LINE IF ENTERED WRONG PASSWORD
        }
        int m = 0;
        while (!file.eof()) //IF FILE OPENS
        {
            file >> user >> pass;  //READING TILL THE END OF LINE IN FILE
            if (strcmp(username,user)==0) //COMPRING ENTERED USER AND EXISTING USER
                m = 1;
        }
        if (m == 0)
        {
            //IF USER DOESN'T EXIST
            uservalid = true;
            alpha++;
            cout << "\n\t\t\t\tSIGNUP SUCCESSFUL";
            cout << "\n\t\t\t\t KINDLY LOGIN TO VERIFY";
            newuser.seekp(0, ios::end);
            newuser << username << " " << password<<"\n";
            file.close();
            newuser.close();
        }
        else
        {
            //IF USER EXIST
            cout << "\n\t\t\t\tUSER ALREADY EXIST!TRY A DIFFERENT USER NAME.";
            Sleep(500);
            cout << "\n\t\t\t\t TRY TO LOGIN OR TRY A NEW USER NAME!";
            goto user;
        }
    }
    return alpha;
}
int topic()
{ 
    system("cls");
    //FOR CHOOSING YOUR FAVORITE TOPIC FOR THE QUIZ
    abc = 0; //FOR STORING THE RESULT
    score=0; //FOR RETURNING THE RESULT TO THE MAIN.CPP
    cout << "\n\n\t\t\t\tSELECT A TOPIC:";
    char a;
    do {
        st:
        cout << "\n\n\t\t\t\t1.SCIENCE\n\t\t\t\t2.SPORTS\n\t\t\t\t3.CPP\n\t\t\t\t4.MATHS\n\n\t\t\t\t5.BACK";
        a = _getch();
        switch (a)
        {
        case '1':
        {
            score=science();
            return score;
            break;
        }
        case '2':
        {
            score=sports();
            return score;
            break;
        }
        case '3':
        {
            score=cpp();
            return score;
            break;
        }
        case '4':
        {
            score=maths();
            return score;
            break;
        }
        case '5':
        {
            return 1;
        } 
        default:
            goto st;
        }
    } while (a != '5');
}
int sports()
{   
    //SPORTS QUESTION
    rules();  //RULES
    system("cls");
    abc = 0;
    trueorfalse("IN WHICH SPORT AMONG THE FOLLOWING, 22 PLAYERS PLAY AT THE SAME TIME ON THE FIELD ?", "CRICKET", "VOLLEYBALL", " HOCKEY", "BASKETBALL", '3');
    trueorfalse("WHAT IS NATIONAL GAME OF INDIA ?","CRICKET","VOLLEYBALL","HOCKEY","BASKETBALL",'3');
    trueorfalse("RONALDO IS A", "CRICKET PLAYER", "VOLLEYBALL PLAYER", "HOCKEY PLAYER", "FOOTBALL PLAYER", '4');
    trueorfalse("WHICH SPORT AMONG THE FOLLOWING IS PLAYED BY 6 MEMBERS IN A TEAM ?", "CRICKET", "VOLLEYBALL", " HOCKEY", " BASKETBALL", '2');
    trueorfalse(" WHEN WAS FIRST COMMONWEALTH GAME HELD ?", "1938", "1930", "1920", "1921", '2');
    trueorfalse("WHO WAS THE FIRST CAPTAIN  OF INDIAN CRICKET TEAM ?", "C K NAYADU", "MS DHONI", "VIRAT KHOLI", "NONE OF THESE", '1');
    trueorfalse("WHO IS NICKNAMED DHING EXPRESS ?", "MS DHONI", " HIMA DAS", " SUNIL CHETRI", "NONE OF THESE", '2');
    trueorfalse("INDIA WON THE FIRST OLYMPIC HOCKEY GOLD IN ?", "2012", "1920", "1928", " 1941", '3');
    trueorfalse("IN WHICH SPORTS IS THE PARTICIPANT CALLED PUGILIST ?", "CRICKET", "VOLLEYBALL", "SWIMMING", "BOXING", '4');
    trueorfalse(" THE TERM 'BUTTERFLY' STROKE IS REFERRED TO IN WHICH SPORTS ?", " SWIMMING", "VOLLEYBALL", "HOCKEY", "BASKETBALL", '1');
    return abc;
}
int cpp()
{
    //C++ QUESTIONS
    rules(); //RULES
    system("cls");
    trueorfalse("\n 'cin' IS AN __", "CLASS", "CODE", "FUNCTION", "OBJECT", '4');
    trueorfalse("WHICH HEADER FILE INCLUDE THE SLEEP() FUNCTION ?", "IOSTREAM", " WINDOWS.h", "CONIO.H", "STDLIB.H", '3');
    trueorfalse("HOW MANY NUMBER OF ARGUMENTS CAN A DESTRUCTOR HAVE ?", "1", "0", "INFINITE", "NONE OF THESE", '2');
    trueorfalse("WHAT IS THE OUPUT?\n\t\t\t #include<iostream> \n\t\t\t using namespace std;\nint main()\n\t\t\t {  cout<<hello world; }", " ERROR", " HELLO WORLD", "hello world", " hello", '1');
    trueorfalse("NAME THE HEADER FILE USE FOR FILE HANDLING ?", "IOSTREAM", "FSTREAM", " FILE.H", "WINDOWS.H", '2');
    trueorfalse("COLLECTION OF DATA MEMEBER AND MEMEBER FUNCTION IS CALLED ?", "OBJECT", "FUNCTION", "CLASS", "NONE OF THESE", '3');
    trueorfalse("IF A=20,WHAT WOULD BE THE VALUE of \n cout<<A<<++A<<A++;", "20,21,20", "21,21,21", " 20,20,20", "20,21,21", '4');
    trueorfalse("for(int i=0;i<1 ;i-- ) is a ?", "WILL NOT RUN", " RUN 1 TIME", "RUN  2 TIMES", "INFINITE LOOP", '4');
    trueorfalse(" WHICH ONE OF THE FOLLOWING IS NOT A CONTROL STATEMENT", "IF", "DO WHILE", "IF ELSE LADDER", "IF ELSE", '2');
    trueorfalse("C++ was developed by ?", "BILL GATES", " ELON MUSK", "BJARNE STROUSTRUP", "CHARLES BABBAGE", '3');

    return abc;
}
int science()
{
   // SCIENCE QUESTIONS
    rules(); //RULES
    system("cls");
    abc = 0;
    trueorfalse(" WHAT IS THE PH LEVEL OF PURE WATER ?", "0.7", "7", "7.7", "1.7", '2');
    trueorfalse(" WHEN IS SCIENCE DAY CELEBRATED ? ", "28th FEB", "20th FEB", "8th MARCH", "28th JAN", '1');
    trueorfalse(" WHAT IS THE BIGGEST PLANET IN OUR SOLAR SYSTEM? ", "MARS...", "PLUTO", "SATURN", "JUPITER", '4');
    trueorfalse(" WHAT IS THE  NAME OF THE ELEMENT WITH THE CHEMICAL SYMBOL He ?", "HYDROGEN", "HELIUM", "HOLMIUM", "XENON", '2');
    trueorfalse(" WHAT IS THE CHEMICAL SYMBOL FOR THE ELEMENT OXYGEN ?", "X", "Y", "O", "G", '3');
    trueorfalse(" WHAT IS THE NAME OF THE CLOSEST STAR TO THE EARTH ?", "NEBULA", "SUN", "P7...", "DWARF", '2');
    trueorfalse(" WHICH AMONG THE FOLLOWING IS USED IN PENCILS ?", "BROMINE", "WOOD", "GRAPHITE", "BOTH 2 and 3", '4');
    trueorfalse(" WHICH GAS IS USUALLY FILLED IN ELECTRIC BULB ?", "HELIUM", "HYDROGEN", "NITROGEN", "NONE OF THESE", '3');
    trueorfalse(" BALLONS ARE FILLED WITH WHICH GAS TO FLOAT IN AIR ?", "HELIUM", "NITROGEN", "OXYGEN", "CARBON", '1');
    trueorfalse(" WHICH AMONG THE FOLLOWING IS AN ELEMENT ?", "CARBONDIOXIDE", "DIAMOND", "HYDROCHLORIC ACID", "NONE OF THESE", '2');
    return abc;
}
int maths()
{
    //MATHS QUESTION
    rules();//RULES
    system("cls");
    trueorfalse(" WHICH AMONG THE FOLLOWING IS A MATHEMATICIAN ?", "RAMANUJAN", "NEIL ARMSTRONG", "BOROS", "PREMCHAND", '1');
    trueorfalse(" WHAT IS THE VALUE OF 2 TO THE POWER 10 ?", "20", "100", "1024", "NONE OF THESE", '3');
    trueorfalse(" WHAT IS THE VALUE OF ZERO FACTORIAL ?", "0", "1", "NOT POSSIBLE", "NONE OF THESE", '2');
    trueorfalse(" IF DAVID'S AGE IS 27 YEARS OLD IN 2011.WHAT WAS HIS AGE IN 2003 ?", "27", "20", "21", "19", '4');
    trueorfalse(" WHAT IS THE REMAINDER IF WE DIVIDE 546 BY 24 ?", "8", "23", "80", "18", '4');
    trueorfalse(" WHAT IS THE CUBE OF 23 ?", "592", "23", "529", "12,167", '3');
    trueorfalse(" 2,4,16,256..WHAT WILL BE THE NEXT TERM IN THE PATTERN ?", "65536", "1024", "512", "NONE OF THESE", '1');
    trueorfalse(" WHAT IS THE PROBABILITY OF GETTING A SUM OF 10 WHEN 2 DICE ARE THROWN SIMULTANEOUSLY ?", "4/36", "1/12", "3", "5/26", '2');
    trueorfalse("  WHAT IS THE VALUE OF 11111*11111 ?", "11111111111", "1234554321", "123454321", "123456789", '3');
    trueorfalse("  WHAT IS VOLUME OF CUBOID WITH DIMENSIONS 45,2,2 ?", "90", "120", "180", "360", '3');

    return abc;
}
void rules()
{
    system("cls");
    cout << "\n\n\n\n\t\t\t\t1.EACH QUESTION CARRIES 10 Points";
    cout << "\n\t\t\t\t2.EACH TOPIC CONTAINS 10 QUESTIONS ";
    cout << "\n\t\t\t\t3.EACH CORRECT ANSWER ADDS 10 POINTS AND EACH WRONG ANSWER SUBSTRACTS 5 POINTS";
    cout << "\n\t\t\t\t4.YOU REQUIRE 40 POINTS TO PASS THE QUIZ";
    cout << "\n\t\t\t\tPRESS ANY KEY TO START THE QUIZ";
    system("pause");
}
int correct(int aaa)
{ 
    // IF ANSWER IS CORRECT
    cout << "\n\n\t\t\t\tCORRECT ANSWER.";
    Sleep(500);
    aaa += 10;
    system("cls");
    return aaa;
}
int wrong(int bbb)
{
    //IF ANSWER IS WRONG
    cout << "\n\n\t\t\t\tWRONG ANSWER";
    Sleep(500);
    bbb -= 5;
    system("cls");
    return bbb;
}
void invalid()
{
    //IF INVALID KEY IS PRESSED DURING THE QUIZ GAME
    cout << "\nINVALID INPUT\nLOADING\nEXITING GAME!\n*********"; Sleep(2000);
    cout << "***********"; Sleep(1500); cout << "*****"; Sleep(1000);cout<<"******";
    exit(0);
}
void trueorfalse(string question, string option1, string option2, string option3, string option4, char answer)
{
    system("cls");
    cout << "\n\n\n\n\t\t\t\t" << question << "\n\n\t\t\t\t1. " << option1 << "\t\t2. " << option2 << "\n\t\t\t\t3. " << option3 << "\t\t4. " << option4;
    option = _getch();
    if (option > '0' && option < '5')
        if (option == answer)
            abc = correct(abc);
        else
            abc = wrong(abc);
    else
        invalid();
}





