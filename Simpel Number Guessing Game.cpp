#include <iostream>
#include <windows.h>
#include <random>
#include <map>
#include <time.h>

using namespace std;

int main()
{
    int _SECRET_NUM;
    int guess;
    char emtey;
    int Try= 0;
    char mode;

    int minNum = 0;
    int maxNum = 10;

    HANDLE _color = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(_color, 14);

    cout<<"Hello And Welcome, To The 'Guessing Game'!"<<endl;
    SetConsoleTextAttribute(_color, 12);
    cout<<"Made By Samir Ahmed,"<<endl;
    SetConsoleTextAttribute(_color, 14);
    cout<<"Here You Need To Guess A Nember."<<endl;

    SetConsoleTextAttribute(_color, 3);
    cout<<"If You Want To Edit Anything Then Type 'a', Else Type Anything: ";
    cin>>mode;

    if(mode == 'a')
    {
        cout<<"------Editing Mode Selected------"<<endl;
        do
        {   if(minNum >= maxNum)
            {
                SetConsoleTextAttribute(_color, 4);
                cout<<"Error, 707, Min Cant Be Higher Then Max Nor Equal."<<endl;
                SetConsoleTextAttribute(_color, 7);
            }

            SetConsoleTextAttribute(_color, 14);
            cout<<"Enter Min Number: ";
            cin>>minNum;

            cout<<"Enter Max Number: ";
            cin>>maxNum;
        }while(minNum >= maxNum);
    }
    do{
        emtey = 'o';
        SetConsoleTextAttribute(_color, 3);
        cout<<"Ok Lets Start! Type 's' To Start: ";
        cin>>emtey;

        if(emtey != 's')
        {
            SetConsoleTextAttribute(_color, 4);
            cout<<"Error 704, Unspecified Field XD"<<endl;
            SetConsoleTextAttribute(_color, 7);
        }
    }while(emtey != 's' || sizeof(emtey) > 1);

    //std::random_device rd;
    //std::mt19937 gen(rd());
    //std::uniform_int_distribution<> distr(minNum, maxNum);
    //_SECRET_NUM = distr(gen);

    srand(time(0));
    int range = maxNum - minNum + 1;
    _SECRET_NUM = rand() % range + minNum;

    while(guess != _SECRET_NUM)
    {
        SetConsoleTextAttribute(_color, 9);
        cout<<"Guess The Number Between '"<<minNum<<"', And '"<<maxNum<<"'."<<endl;
        SetConsoleTextAttribute(_color, 14);
        cout<<"What Is The Number: ";

        cin>>guess;
        Try++;

        if(guess != _SECRET_NUM)
        {
            SetConsoleTextAttribute(_color, 4);
            cout<<"Wornge! Try Again,"<<endl;
        }
    }

    if(guess == _SECRET_NUM)
    {
        SetConsoleTextAttribute(_color, 10);

        cout<<"Congrats!, You Guessed Correct Number '"<<_SECRET_NUM<<"',"<<endl;
        cout<<"You Guessed It In '"<<Try<<"' Try...";

        SetConsoleTextAttribute(_color, 7);

    }







    return 0;
}


