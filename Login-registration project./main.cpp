// MIT License
// Copyright (c) 2024 Raghav Khanna
// See the LICENSE file in the root of the repository for full license details. 

#include <iostream>
#include <string.h>
#include <iomanip>
#include <fstream>
using namespace std;

class log_reg
{
   char user[20], pass[20], name[25], gender, nat[15], email[35];
   int age, dd, mm, yyyy;
   public:
   void display()
   {
    cout<<"\n\t\t\t\t\t\t\tPersonal information\n";
    cout<<"-----------------------------------------------------------------------------------------------------------------------------------------";
    cout<<"\nName                                                            : "<<name;
    cout<<"\nAge                                                             : "<<age;
    cout<<"\nGender                                                          : "<<gender;
    cout<<"\nNationality                                                     : "<<nat;
    cout<<"\nDate of birth                                                   : "<<dd<<"/"<<mm<<"/"<<yyyy;
    cout<<"\nE-mail ID                                                       : "<<email;
    cout<<"\n-----------------------------------------------------------------------------------------------------------------------------------------";
   }
   void rec_display_d()
   {
    cout<<endl<<setw(25)<<left<<name<<"   "<<age<<"\t     "<<gender<<"\t\t\t"<<setw(19)<<left<<nat<<"    "<<dd<<"/"<<mm<<"/"<<yyyy<<"\t\t"<<setw(35)<<left<<email<<"\n";
   }
   void accept();
   friend void reg();
   friend void view_all();
   friend void rec_display();
   friend void login();
   friend void edit_name();
   friend void edit_age();
   friend void edit_gender();
   friend void edit_nat();
   friend void edit_email();
   friend void edit_dob();
   friend void change_pass();
   friend void change_user();
   friend void delete_acc();
   friend void clear_entire_record();
   friend void menu();
};
log_reg obj;
char pass_off[20] = "Kaffeeland";
int flag1;
void log_reg::accept()
{ 
   char f_user[20], f_pass[20], f_pass1[20], f_name[25], f_email[35], f_nat[15], f_gender;
   int flagf = 0;
   int f_age, f_dd, f_mm, f_yyyy;
   char userl[20];
   flag1 = 1;
   cout<<endl<<"Create username: ";
   cin>>userl;
   fstream rd;
   rd.open("data1.txt", ios::in);
   rd.seekg(0, ios::end);
   int s = rd.tellg();
   int n = (s/sizeof(obj));
   rd.seekg(0, ios::beg);
   for (int i = 1; i <= n; i++)
   {
     rd.read((char*)&obj, sizeof(obj));
     if (strcmp(obj.user, userl) == 0)
     {
      flag1 = 0;
      break;
     }
   }
   if (flag1 == 0)
   {
    cout<<endl<<"Username already taken.";
    return;
   }
   cout<<endl<<"Create password: ";
   cin>>f_pass;
   cout<<endl<<"Re-enter password: ";
   cin>>f_pass1;
   if (strcmp(f_pass, f_pass1) != 0)
   {
    cout<<"\nPasswords do not match.";
    flag1 = 0;
    return;
   }
   else if (flag1 == 1)
   {
   for (int i = 0; i <= 19; i++)
   {
    f_user[i] = userl[i];
   }
   cout<<"\n\t\t\t\t\t\tPersonal information\n";
   cout<<"-----------------------------------------------------------------------------------------------------------------------------";
   cout<<endl<<"Enter name: ";
   cin>>f_name;
   cout<<endl<<"Enter age: ";
   cin>>f_age;
   cout<<endl<<"Enter gender (M/F): ";
   cin>>f_gender;
   cout<<endl<<"Enter nationality: ";
   cin>>f_nat;
   cout<<endl<<"Enter date of birth (DD/MM/YYYY; enter space between dd, mm, and yyyy): ";
   cin>>f_dd>>f_mm>>f_yyyy;
   cout<<endl<<"Enter e-mail ID: ";
   cin>>f_email;
   cout<<"\n-----------------------------------------------------------------------------------------------------------------------------";
   if (f_yyyy < 1890 || f_yyyy > 2024)
   {
    cout<<"\nInvalid date of birth.";
    flagf = 1;
    return;
   }
   switch(f_mm)
   {
    case 1:
    {
      if (f_dd > 31)
      {
        cout<<"\nInvalid date of birth.";
        flagf = 1;
      }
      break;
    }

    case 2:
    {
      if (f_yyyy % 4 == 0)
      {
        if (f_dd > 29)
        {
          cout<<"\nInvalid date of birth.";
          flagf = 1;
        }
      }
      else
      {
        if (f_dd > 28)
        {
          cout<<"\nInvalid date of birth.";
          flagf = 1;
        }
      }
      break;
    }

    case 3:
    {
      if (f_dd > 31)
      {
        cout<<"\nInvalid date of birth.";
        flagf = 1;
      }
    break;
    }

    case 4:
    {
      if (f_dd > 30)
      {
        cout<<"\nInvalid date of birth.";
        flagf = 1;
      }
      break;
    }

    case 5:
    {
      if (f_dd > 31)
      {
        cout<<"\nInvalid date of birth.";
        flagf = 1;
      }
    break;
    }

    case 6:
    {
      if (f_dd > 30)
      {
        cout<<"\nInvalid date of birth.";
        flagf = 1;
      }
      break;
    }

    case 7:
    {
      if (f_dd > 31)
      {
        cout<<"\nInvalid date of birth.";
        flagf = 1;
      }
    break;
    }

    case 8:
    {
      if (f_dd > 31)
      {
        cout<<"\nInvalid date of birth.";
        flagf = 1;
      }
    break;
    }

    case 9:
    {
      if (f_dd > 30)
      {
        cout<<"\nInvalid date of birth.";
        flagf = 1;
      }
      break;
    }

    case 10:
    {
      if (f_dd > 31)
      {
        cout<<"\nInvalid date of birth.";
        flagf = 1;
      }
    break;
    }

    case 11:
    {
      if (f_dd > 30)
      {
        cout<<"\nInvalid date of birth.";
        flagf = 1;
      }
      break;
    }

    case 12:
    {
      if (f_dd > 31)
      {
        cout<<"\nInvalid date of birth.";
        flagf = 1;
      }
    break;
    }

    default:
    {
      cout<<"\nInvalid date of birth.";
      flagf = 1;                                                      //It's going good.
    }
    
   }
   if (flagf == 0)
   {
    for (int i = 0; i <= 19; i++)
    {
      user[i] = f_user[i];
      pass[i] = f_pass[i];
    }
    for (int i = 0; i <= 24; i++)
    {
      name[i] = f_name[i];
      email[i] = f_email[i];
    }
    for (int i = 0; i <= 14; i++)
    {
      nat[i] = f_nat[i];
    }
    for (int i = 0; i <= 34; i++)
    {
      email[i] = f_email[i];
    }
    gender = f_gender;
    age = f_age;
    mm = f_mm;
    dd = f_dd;
    yyyy = f_yyyy;
   }
   }
 }
void reg()
{
   obj.accept();
   fstream wr;
   if (flag1 == 1)
   {
   wr.open("data1.txt", ios::app);
   wr.write((char*)&obj, sizeof(obj));
   wr.close();
   cout<<endl<<"Registered successfully!"<<endl;
   }
}
void login()
{
    char userl2[20], passl2[20];
    int no = 0;
    cout<<"\nEnter username: ";
    cin>>userl2;
    cout<<"\nEnter password: ";
    cin>>passl2;
    fstream rd;
    rd.open("data1.txt", ios::in);
    rd.seekg(0, ios::end);
    int s = rd.tellg();
    int n = (s/sizeof(obj));
    rd.seekg(0, ios::beg);
    for (int i = 1; i <= n; i++)
    {
      rd.read((char*)&obj, sizeof(obj));
      if (strcmp(obj.user, userl2) == 0 && strcmp(obj.pass, passl2) == 0)
      {
        cout<<"\nLogged in!\n";
        obj.display();
        no = 1;
        break;
      } 
    }
    if (no == 0)
    {
        cout<<"\nIncorrect username or password.";
    }
}
void rec_display()
{
  char po[20];
  cout<<"\nEnter office password: ";
  cin>>po;
  if (strcmp(po, pass_off) == 0)
  {
     fstream rd;
  rd.open("data1.txt", ios::in);
  rd.seekg(0, ios::end);
  int s = rd.tellg();
  int n = s/sizeof(obj);
  rd.seekg(0, ios::beg);
  if (n == 0)
  {
    cout<<"\nThe record is empty.\n";
    return;
  }
  cout<<"\t\t\t\t\t\t\tRecord"<<endl;
  cout<<endl<<"-----------------------------------------------------------------------------------------------------------------------------------------------";
  cout<<endl<<setw(25)<<left<<"Name\t"<<"Age\t     "<<"Gender\t\t"<<setw(19)<<left<<"Nationality\t"<<"Date of birth\t\t"<<setw(35)<<left<<"E-mail ID";
  cout<<"\n-----------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
  for (int i = 1; i <= n; i++)
  { 
    rd.read((char*)&obj, sizeof(obj));
    obj.rec_display_d();
    cout<<"("<<obj.user<<")";
    cout<<endl;
  }
  cout<<"-----------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
  }
  else
  {
    cout<<"\nInvalid office password.";
  }
}
void edit_name()
{
    int flagg = 0;
    char nname[25];
    char userl2[20], passl2[20];
    cout<<"\nEnter username: ";
    cin>>userl2;
    cout<<"\nEnter password: ";
    cin>>passl2;
    fstream rd, r;
    rd.open("data1.txt", ios::in);
    r.open("temp1.txt", ios::out);
    rd.seekg(0, ios::end);
    int s = rd.tellg();
    int n = (s/sizeof(obj));
    rd.seekg(0, ios::beg);
    for (int i = 1; i <= n; i++)
    {
      rd.read((char*)&obj, sizeof(obj));
      if (strcmp(obj.user, userl2) == 0 && strcmp(obj.pass, passl2) == 0)
      {
        cout<<"\nEnter new name: ";
        cin>>nname;
        flagg = 1;
        strcpy(obj.name, nname);
        r.write((char*)&obj, sizeof(obj));
        cout<<"\nName edited successfully!";
      }
      else
      {
        r.write((char*)&obj, sizeof(obj));
      }
    }
    if (flagg == 0)
    {
      cout<<"\nIncorrect username or password.";
    }
    rd.close();
    r.close();
    remove("data1.txt");
    rename("temp1.txt", "data1.txt");
}
void edit_age()
{
    int flagg = 0;
    int n_age;
    char userl2[20], passl2[20];
    cout<<"\nEnter username: ";
    cin>>userl2;
    cout<<"\nEnter password: ";
    cin>>passl2;
    fstream rd, r;
    rd.open("data1.txt", ios::in);
    r.open("temp1.txt", ios::out);
    rd.seekg(0, ios::end);
    int s = rd.tellg();
    int n = (s/sizeof(obj));
    rd.seekg(0, ios::beg);
    for (int i = 1; i <= n; i++)
    {
      rd.read((char*)&obj, sizeof(obj));
      if (strcmp(obj.user, userl2) == 0 && strcmp(obj.pass, passl2) == 0)
      {
        cout<<"\nEnter new age: ";
        cin>>n_age;
        obj.age = n_age;
        flagg = 1;
        r.write((char*)&obj, sizeof(obj));
        cout<<"\nAge edited successfully!";
      }
      else
      {
        r.write((char*)&obj, sizeof(obj));
      }
    }
    if (flagg == 0)
    {
      cout<<"\nIncorrect username or password.";
    }
    rd.close();
    r.close();
    remove("data1.txt");
    rename("temp1.txt", "data1.txt");
}
void edit_gender()
{
    int flagg = 0;
    char n_gender;
    char userl2[20], passl2[20];
    cout<<"\nEnter username: ";
    cin>>userl2;
    cout<<"\nEnter password: ";
    cin>>passl2;
    fstream rd, r;
    rd.open("data1.txt", ios::in);
    r.open("temp1.txt", ios::out);
    rd.seekg(0, ios::end);
    int s = rd.tellg();
    int n = (s/sizeof(obj));
    rd.seekg(0, ios::beg);
    for (int i = 1; i <= n; i++)
    {
      rd.read((char*)&obj, sizeof(obj));
      if (strcmp(obj.user, userl2) == 0 && strcmp(obj.pass, passl2) == 0)
      {
        cout<<"\nEnter new gender: ";
        cin>>n_gender;
        flagg = 1;
        obj.gender = n_gender;
        r.write((char*)&obj, sizeof(obj));
        cout<<"\nGender edited successfully!";
      }
      else
      {
        r.write((char*)&obj, sizeof(obj));
      }
    }
    if (flagg == 0)
    {
      cout<<"\nIncorrect username or password.";
    }
    rd.close();
    r.close();
    remove("data1.txt");
    rename("temp1.txt", "data1.txt");
}
void edit_nat()
{
    int flagg = 0;
    char n_nat[15];
    char userl2[20], passl2[20];
    cout<<"\nEnter username: ";                                            //Keep going.
    cin>>userl2;
    cout<<"\nEnter password: ";
    cin>>passl2;
    fstream rd, r;
    rd.open("data1.txt", ios::in);
    r.open("temp1.txt", ios::out);
    rd.seekg(0, ios::end);
    int s = rd.tellg();
    int n = (s/sizeof(obj));
    rd.seekg(0, ios::beg);
    for (int i = 1; i <= n; i++)
    {
      rd.read((char*)&obj, sizeof(obj));
      if (strcmp(obj.user, userl2) == 0 && strcmp(obj.pass, passl2) == 0)
      {
        cout<<"\nEnter new nationality: ";
        cin>>n_nat;
        flagg = 1;
        strcpy(obj.nat, n_nat);
        r.write((char*)&obj, sizeof(obj));
        cout<<"\nNationality edited successfully!";
      }
      else
      {
        r.write((char*)&obj, sizeof(obj));
      }
    }
    if (flagg == 0)
    {
      cout<<"\nIncorrect username or password.";
    }
    rd.close();
    r.close();
    remove("data1.txt");
    rename("temp1.txt", "data1.txt");
}
void edit_email()
{
    int flagg = 0;
    char n_mail[35];
    char userl2[20], passl2[20];
    cout<<"\nEnter username: ";
    cin>>userl2;
    cout<<"\nEnter password: ";
    cin>>passl2;
    fstream rd, r;
    rd.open("data1.txt", ios::in);
    r.open("temp1.txt", ios::out);
    rd.seekg(0, ios::end);
    int s = rd.tellg();
    int n = (s/sizeof(obj));
    rd.seekg(0, ios::beg);
    for (int i = 1; i <= n; i++)
    {
      rd.read((char*)&obj, sizeof(obj));
      if (strcmp(obj.user, userl2) == 0 && strcmp(obj.pass, passl2) == 0)
      {
        cout<<"\nEnter new e-mail: ";
        cin>>n_mail;
        flagg = 1;
        strcpy(obj.email, n_mail);
        r.write((char*)&obj, sizeof(obj));
        cout<<"\nE-mail edited successfully!";
      }
      else
      {
        r.write((char*)&obj, sizeof(obj));
      }
    }
    if (flagg == 0)
    {
      cout<<"\nIncorrect username or password.";
    }
    rd.close();
    r.close();
    remove("data1.txt");
    rename("temp1.txt", "data1.txt");
}
void edit_dob()
{
    int flagg = 0, flagf = 0;
    int n_d, n_m, n_y;
    char userl2[20], passl2[20];
    cout<<"\nEnter username: ";
    cin>>userl2;
    cout<<"\nEnter password: ";
    cin>>passl2;
    fstream rd, r;
    rd.open("data1.txt", ios::in);
    r.open("temp1.txt", ios::out);
    rd.seekg(0, ios::end);
    int s = rd.tellg();
    int n = (s/sizeof(obj));
    rd.seekg(0, ios::beg);
    for (int i = 1; i <= n; i++)
    {
      rd.read((char*)&obj, sizeof(obj));
      if (strcmp(obj.user, userl2) == 0 && strcmp(obj.pass, passl2) == 0)
      {
        cout<<"\nEnter new date of birth: ";
        cin>>n_d>>n_m>>n_y;
        flagg = 1;
        if (n_y < 1890 || n_y > 2024)
   {
    cout<<"\nInvalid date of birth.";
    flagf = 1;
    r.write((char*)&obj, sizeof(obj));
    continue;
   }
   switch(n_m)
   {
    case 1:
    {
      if (n_d > 31)
      {
        cout<<"\nInvalid date of birth.";
        flagf = 1;
        r.write((char*)&obj, sizeof(obj));
      }
      break;
    }

    case 2:
    {
      if (n_y % 4 == 0)
      {
        if (n_d > 29)
        {
          cout<<"\nInvalid date of birth.";
          flagf = 1;
          r.write((char*)&obj, sizeof(obj));
        }
      }
      else
      {
        if (n_d > 28)
        {
          cout<<"\nInvalid date of birth.";
          flagf = 1;
          r.write((char*)&obj, sizeof(obj));
        }
      }
      break;
    }

    case 3:
    {
      if (n_d > 31)
      {
        cout<<"\nInvalid date of birth.";
        flagf = 1;
        r.write((char*)&obj, sizeof(obj));
      }
    break;
    }

    case 4:
    {
      if (n_d > 30)
      {
        cout<<"\nInvalid date of birth.";
        flagf = 1;
        r.write((char*)&obj, sizeof(obj));
      }
      break;
    }

    case 5:
    {
      if (n_d > 31)
      {
        cout<<"\nInvalid date of birth.";
        flagf = 1;
        r.write((char*)&obj, sizeof(obj));
      }
    break;
    }

    case 6:
    {
      if (n_d > 30)
      {
        cout<<"\nInvalid date of birth.";
        flagf = 1;
        r.write((char*)&obj, sizeof(obj));
      }
      break;
    }

    case 7:
    {
      if (n_d > 31)
      {
        cout<<"\nInvalid date of birth.";
        flagf = 1;
        r.write((char*)&obj, sizeof(obj));
      }
    break;
    }

    case 8:
    {
      if (n_d > 31)
      {
        cout<<"\nInvalid date of birth.";
        flagf = 1;
        r.write((char*)&obj, sizeof(obj));
      }
    break;
    }

    case 9:
    {
      if (n_d > 30)
      {
        cout<<"\nInvalid date of birth.";
        flagf = 1;
        r.write((char*)&obj, sizeof(obj));
      }
      break;
    }

    case 10:
    {
      if (n_d > 31)
      {
        cout<<"\nInvalid date of birth.";
        flagf = 1;
        r.write((char*)&obj, sizeof(obj));
      }
    break;
    }

    case 11:
    {
      if (n_d > 30)
      {
        cout<<"\nInvalid date of birth.";
        flagf = 1;
        r.write((char*)&obj, sizeof(obj));
      }
      break;
    }

    case 12:
    {
      if (n_d > 31)
      {
        cout<<"\nInvalid date of birth.";
        flagf = 1;
        r.write((char*)&obj, sizeof(obj));
      }
    break;
    }

    default:
    {
      cout<<"\nInvalid date of birth.";
      flagf = 1;
      r.write((char*)&obj, sizeof(obj));
    }
   }
        if (flagf == 0)
        {
          obj.dd = n_d;
          obj.mm = n_m;
          obj.yyyy = n_y;
          r.write((char*)&obj, sizeof(obj));
          cout<<"\nDate of birth updated successfully!";
        }
      }
      else
      {
        r.write((char*)&obj, sizeof(obj));
      }
    }
    if (flagg == 0)
    {
      cout<<"\nIncorrect username or password.";
    }
    rd.close();
    r.close();
    remove("data1.txt");
    rename("temp1.txt", "data1.txt");
}
void change_user()
{
    int flagg = 0, flag1 = 0;
    char n_user[20];
    char userl2[20], passl2[20];
    cout<<"\nEnter username: ";
    cin>>userl2;
    cout<<"\nEnter password: ";
    cin>>passl2;
    fstream rd, r;
    rd.open("data1.txt", ios::in);
    r.open("temp1.txt", ios::out);
    rd.seekg(0, ios::end);
    int s = rd.tellg();
    int n = (s/sizeof(obj));
    rd.seekg(0, ios::beg);
    for (int i = 1; i <= n; i++)
    {
      rd.read((char*)&obj, sizeof(obj));
      if (strcmp(obj.user, userl2) == 0 && strcmp(obj.pass, passl2) == 0)
      {
        cout<<"\nEnter new username: ";
        cin>>n_user;
        flagg = 1;
        fstream rd, r;
    rd.open("data1.txt", ios::in);
    r.open("temp1.txt", ios::out);
    rd.seekg(0, ios::end);
    int s = rd.tellg();
    int n = (s/sizeof(obj));
        rd.seekg(0, ios::beg);
        for (int i = 1; i <= n; i++)
        {
        rd.read((char*)&obj, sizeof(obj));
        if (strcmp(obj.user, n_user) == 0)
        {
            flag1 = 1;
        }
        }
      }
    }
    rd.seekg(0, ios::beg);
    for (int i = 1; i <= n; i++)
    {
      rd.read((char*)&obj, sizeof(obj));
      if (flag1 == 0)
      {
      if (strcmp(obj.user, userl2) == 0 && strcmp(obj.pass, passl2) == 0)
      {
        strcpy(obj.user, n_user);
        cout<<"\nUsername is now "<<obj.user<<"\nUsername changed successfully!";
      }
      }
      r.write((char*)&obj, sizeof(obj));
    }
    if (flagg == 0)
    {
      cout<<"\nIncorrect username or password.";
    }
    rd.close();
    r.close();
    remove("data1.txt");
    rename("temp1.txt", "data1.txt");
}
void change_pass()
{
    int flagg = 0;
    char n_pass[20], c_pass[20];
    char userl2[20], passl2[20];
    cout<<"\nEnter username: ";
    cin>>userl2;
    cout<<"\nEnter old password: ";
    cin>>passl2;
    fstream rd, r;
    rd.open("data1.txt", ios::in);
    r.open("temp1.txt", ios::out);
    rd.seekg(0, ios::end);
    int s = rd.tellg();
    int n = (s/sizeof(obj));
    rd.seekg(0, ios::beg);
    for (int i = 1; i <= n; i++)
    {
      rd.read((char*)&obj, sizeof(obj));
      if (strcmp(obj.user, userl2) == 0 && strcmp(obj.pass, passl2) == 0)
      {
        flagg = 1;
        cout<<"\nEnter new password: ";
        cin>>n_pass;
        cout<<"\nConfirm new password: ";
        cin>>c_pass;
        if (strcmp(n_pass, c_pass) == 0)
        {
        for (int i = 0; i <= 19; i++)
        {
            obj.pass[i] = n_pass[i];
        }
        r.write((char*)&obj, sizeof(obj));
        cout<<"\nPassword changed successfully!";
        }
        else
        {
            cout<<"\nPasswords do not match.";
            r.write((char*)&obj, sizeof(obj));
        }
      }
      else
      {
        r.write((char*)&obj, sizeof(obj));
      }
    }
    if (flagg == 0)
    {
      cout<<"\nIncorrect username or password.";
    }
    rd.close();
    r.close();
    remove("data1.txt");
    rename("temp1.txt", "data1.txt");
}
void delete_acc()
{
    char userl2[20], passl2[20];
    int no = 0;
    cout<<"\nEnter username: ";
    cin>>userl2;
    cout<<"\nEnter password: ";
    cin>>passl2;
    fstream rd, wr;
    rd.open("data1.txt", ios::in);
    wr.open("temp1.txt", ios::out);
    rd.seekg(0, ios::end);
    int s = rd.tellg();
    int n = (s/sizeof(obj));
    rd.seekg(0, ios::beg);
    for (int i = 1; i <= n; i++)
    {
      rd.read((char*)&obj, sizeof(obj));
      if (strcmp(obj.user, userl2) == 0 && strcmp(obj.pass, passl2) == 0)
      {
        no = 1;
        cout<<"\nAccount deleted successfully!";
      }
      else
      {
        wr.write((char*)&obj, sizeof(obj));
      } 
    }
    if (no == 0)
    {
        cout<<"\nIncorrect username or password.";
    }
    wr.close();
    rd.close();
    remove("data1.txt");
    rename("temp1.txt", "data1.txt");
}
void clear_entire_record()
{
  //function to clear the entire record.
  char po[20];
  cout<<"\nEnter office password: ";
  cin>>po;
  if (strcmp(po, pass_off) == 0)
  {
  fstream clear;
  clear.open("data1.txt", ios::out | ios::trunc);
  clear.close();
  cout<<endl<<"The contents are entirely deleted.";
  }
  else
  {
    cout<<"\nIncorrect office password.";
  }
}
void menu()
{
  int choice;
  cout<<"\nEnter 1 to register.";
  cout<<"\nEnter 2 to log in.";
  cout<<"\nEnter 3 to edit personal information.";
  cout<<"\nEnter 4 to change username and/or password: ";
  cout<<"\nEnter 5 to delete account.";
  cout<<"\nEnter 6 to view entire record (for office use only).";
  cout<<"\nEnter 7 to clear entire record (for office use only).";
  cout<<"\nEnter 8 to exit.";
  cout<<"\n\nEnter the required number: ";
  cin>>choice;
  switch(choice)
  {
    case 1:
    reg();
    break;

    case 2:
    login();
    break;

    case 3:
    {
      int choice2;
      cout<<"\nEnter 1 to edit name.";
      cout<<"\nEnter 2 to edit age.";
      cout<<"\nEnter 3 to edit gender.";
      cout<<"\nEnter 4 to edit nationality.";
      cout<<"\nEnter 5 to edit date of birth.";
      cout<<"\nEnter 6 to edit e-mail.";
      cout<<"\n\nEnter the required number: ";
      cin>>choice2;
      switch(choice2)
      {
        case 1:
        edit_name();
        break;

        case 2:
        edit_age();
        break;

        case 3:
        edit_gender();
        break;

        case 4:
        edit_nat();
        break;

        case 5:
        edit_dob();
        break;

        case 6:
        edit_email();
        break;

        default:
        cout<<"\nInvalid choice.";
      }
     break;
    }

    case 5:
    delete_acc();
    break;

    case 4:
    {
       int choice3;
       cout<<"\nEnter 1 to change username.";
       cout<<"\nEnter 2 to change password.";
       cout<<"\n\nEnter the required number: ";
       cin>>choice3;
       switch(choice3)
       {
        case 1:
        change_user();
        break;
        
        case 2:
        change_pass();
        break;

        default:
        cout<<"\nInvalid choice.";
       }
      break;
    }

    case 6:
    rec_display();
    break;

    case 7:
    clear_entire_record();
    break;

    case 8:
    break;
  }
}
int main()
{
   menu();
}
//The end.
    
