// MIT License
// Copyright (c) 2024 Raghav Khanna
// See the LICENSE file in the root of the repository for full license details. 

#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
using namespace std;

class casino
{
  float amt, balance, bet_mon;
  int bet_no, rand_num;
  int flag = 0;
  char yon, yon1;
  char name[32];
  public:
  void get_amt()
  {
    //function to get amount from user.
    cout<<"\nEnter the amount you wish to deposit to play the game: ";
    cin>>amt;
    balance = amt;
  }
  void bet()
  {
    //function to input the amount to bet and the number to bet on.
    cout<<"\nEnter the amount you want to bet: ";
    cin>>bet_mon;
    if (balance < bet_mon)
    {
        cout<<"\nYour betting money cannot be more than your deposited money.";
        flag = 1;
    }
    else
    {
    balance = balance - bet_mon;
    cout<<"\nChoose the number from 1 to 10 you want to bet on: ";
    cin>>bet_no;
    }
  }
  void rand_no()
  {
    //function to generate a random number.
    srand(time(0));
    rand_num = (rand()%10) + 1;
  }
  void result()
  {
    //function to display the results of the bet.
    if (flag == 0)
    {
    rand_no();
    if (rand_num == bet_no)
    {
      cout<<"\nCongratulations! You won "<<(bet_mon * 10)<<" bucks.";
      balance = balance + (bet_mon * 10);
      cout<<"\nYour balance is "<<balance<<" bucks.";
    }
    else
    {
      cout<<"\nBad luck! You lost "<<bet_mon<<" bucks.";
      cout<<"\nYour balance is "<<balance<<" bucks.";
    }
    if (balance == 0)
    {
        cout<<"\n\nOops, you don't have any money to play further. Have a nice day!";
    }
    else
    {
        cout<<"\n\nDo you wish to play further?";
        cout<<"\nEnter Y for yes.";
        cout<<"\nEnter N for no.";
        cout<<"\nEnter your answer: ";
        cin>>yon;
        if (yon == 'Y' || yon == 'y')
        {
            bet();
            result();
        }
        else if (yon == 'N' || yon == 'n')
        {
            cout<<"\nThanks for playing!\nYour balance is "<<balance<<" bucks. Have a nice day!";
        }
        else
        {
            cout<<"\nInvalid choice.";
        }
    }
    }
  }
  void play()
  {
    //function to make it menu-driven and to display the rules.
    cout<<"\nWelcome to the casino number-guessing game!";
    cout<<"\nHere are the rules for playing: ";
    cout<<"\nEnter the amount you wish to deposit to play the game.";
    cout<<"\nEnter the amount you want to bet.";
    cout<<"\nChoose a number from 1 to 10 to bet on.";
    cout<<"\nIf you win, you will get 10 times the amount you bet on.";
    cout<<"\nIf you lose, you will lose the amount you bet.";
    cout<<"\n\nEnter Y if you wish to play further.";
    cout<<"\nEnter N if you wish to abort.";
    cout<<"\n\nEnter your answer: ";
    cin>>yon1;
    if (yon1 == 'Y' || yon1 == 'y')
    {
        get_amt();
        bet();
        result();
    }
    else if (yon1 == 'N' || yon1 == 'n')
    {
        cout<<"\nGame aborted.\nHave a nice day!";
    }
    else
    {
        cout<<"\nInvalid choice.";
    }
  }
};
int main()
{
   casino obj;
   obj.play();
}
