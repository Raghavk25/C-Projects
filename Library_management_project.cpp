/* C++ project to make a book library management system.
Made by Raghav Khanna */

#include <iostream>
#include <fstream>
#include <string.h>
#include <iomanip>
using namespace std;

class book
{
 int bookid, edition, issued_to;
 char bookname[50], author[40], publisher[40], isbn[20];
 public:
 friend void search_id();
 friend void search_name();
 friend void search_author();
 friend void search_edition();
 friend void search_publisher();
 friend void search_isbn();
 friend void remove_bookid();
 friend void remove_name();
 friend void remove_author();
 friend void remove_edition();
 friend void remove_publisher();
 friend void remove_isbn();
 friend void issue_book();
 friend void return_book();
 friend void edit_bookname();
 friend void edit_bookid();
 friend void edit_isbn();
 friend void clear_entire_record();
 void accept();
 void display()
 { 
   cout<<endl<<bookid<<"\t\t";
   cout<<setw(30)<<left<<bookname<<"\t";
   cout<<setw(20)<<left<<author<<"\t";
   cout<<edition<<"\t\t";
   cout<<setw(20)<<left<<publisher<<"\t";
   cout<<setw(13)<<left<<isbn<<"\t"<<issued_to;
 }
};
book obj_bk;
int flag1;
void book::accept()
{ 
   int samp;
   flag1 = 1;
   cout<<endl<<"Enter book ID: ";
   cin>>samp;
   fstream rd, wr;
   rd.open("data.txt", ios::in);
   rd.seekg(0, ios::end);
   int s = rd.tellg();
   int n = (s/sizeof(obj_bk));
   rd.seekg(0, ios::beg);
   for (int i = 1; i <= n; i++)
   {
     rd.read((char*)&obj_bk, sizeof(obj_bk));
     if (samp == obj_bk.bookid)
     {
      flag1 = 0;
      return;
     }
   }
   if (flag1 == 0)
   {
    cout<<endl<<"Book ID already in use.";
    return;
   }
   else if (flag1 == 1)
   {
   bookid = samp;
   cout<<endl<<"Enter book's name: ";
   cin>>bookname;
   cout<<endl<<"Enter author's name: ";
   cin>>author;
   cout<<endl<<"Enter edition: ";
   cin>>edition;
   cout<<endl<<"Enter publisher's name: ";
   cin>>publisher;
   cout<<endl<<"Enter ISBN: ";
   cin>>isbn;
   issued_to = 0;
   }
 }
void add_book()
{
  //function to add a book.
   obj_bk.accept();
   fstream wr;
   if (flag1 == 1)
   {
   wr.open("data.txt", ios::app);
   wr.write((char*)&obj_bk, sizeof(obj_bk));
   wr.close();
   cout<<endl<<"Book added successfully."<<endl;
   }
}
void view_all()
{
  //function to view the entire record
  fstream rd;
  rd.open("data.txt", ios::in);
  rd.seekg(0, ios::end);
  int s = rd.tellg();
  int n = s/sizeof(obj_bk);
  rd.seekg(0, ios::beg);
  if (n == 0)
  {
    cout<<"\nThe library is empty.\n";
    return;
  }
  cout<<"\t\t\t\t\t\t\t\tLibrary"<<endl;
  cout<<endl<<"---------------------------------------------------------------------------------------------------------------------------------------------";
  cout<<endl<<"Book ID"<<"\t\t"<<setw(30)<<left<<"Book name"<<"\t"<<setw(20)<<left<<"Author"<<"\t"<<"Edition"<<"\t\t"<<setw(20)<<left<<"Publisher"<<"\t"<<setw(13)<<left<<"ISBN"<<"\t"<<"Issued to";
  cout<<endl<<"---------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
  for (int i = 1; i <= n; i++)
  { 
    rd.read((char*)&obj_bk, sizeof(obj_bk));
    obj_bk.display();
    cout<<endl;
  }
  cout<<endl<<"---------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
}
void search_id()
{
  //function to search a book by its book ID.
  int sr;
  int flag = 0;
  fstream rd;
  rd.open("data.txt", ios::in);
  rd.seekg(0, ios::end);
  int s = rd.tellg();
  int n = s/sizeof(obj_bk);
  rd.seekg(0, ios::beg);
  if (n == 0)
  {
    cout<<"\nThe library is empty.\n";
    return;
  }
  cout<<endl<<"Enter book ID: ";
  cin>>sr;
  cout<<endl<<"Book ID"<<"\t\t"<<setw(30)<<left<<"Book name"<<"\t"<<setw(20)<<left<<"Author"<<"\t"<<"Edition"<<"\t\t"<<setw(20)<<left<<"Publisher"<<"\t"<<setw(13)<<left<<"ISBN"<<"\t"<<"Issued to\n";
  for (int i = 1; i <= n; i++)
  {
    rd.read((char*)&obj_bk, sizeof(obj_bk));
    if (obj_bk.bookid == sr)
    {
    obj_bk.display();
    flag = 1;
    }
  }
  if (flag == 0)
  {
    cout<<"\nBook not found.\n";
  }
}
void search_name()
{
  //function to search a book by its name.
  char sr_name[50];
  int flag = 0;
  fstream rd;
  rd.open("data.txt", ios::in);
  rd.seekg(0, ios::end);
  int s = rd.tellg();
  int n = s/sizeof(obj_bk);
  rd.seekg(0, ios::beg);
  if (n == 0)
  {
    cout<<"\nThe library is empty.\n";
    return;
  }
  cout<<endl<<"Enter book's name: ";
  cin>>sr_name;
  for (int i = 1; i <= n; i++)
  {
    rd.read((char*)&obj_bk, sizeof(obj_bk));
    if (strcmp(obj_bk.bookname, sr_name)==0)
    {
    cout<<endl<<"Book ID"<<"\t\t"<<setw(30)<<left<<"Book name"<<"\t"<<setw(20)<<left<<"Author"<<"\t"<<"Edition"<<"\t\t"<<setw(20)<<left<<"Publisher"<<"\t"<<setw(13)<<left<<"ISBN"<<"\t"<<"Issued to\n";
    obj_bk.display();
    flag = 1;
    }
  }
  if (flag == 0)
  {
    cout<<"\nBook not found.\n";
  }
}
void search_author()
{
  //function to search a book by its author.
  char sr_author[40];
  int flag = 0;
  fstream rd;
  rd.open("data.txt", ios::in);
  rd.seekg(0, ios::end);
  int s = rd.tellg();
  int n = s/sizeof(obj_bk);
  rd.seekg(0, ios::beg);
  if (n == 0)
  {
    cout<<"\nThe library is empty.\n";
    return;
  }
  cout<<endl<<"Enter author's name: ";
  cin>>sr_author;
  cout<<endl<<"Book ID"<<"\t\t"<<setw(30)<<left<<"Book name"<<"\t"<<setw(20)<<left<<"Author"<<"\t"<<"Edition"<<"\t\t"<<setw(20)<<left<<"Publisher"<<"\t"<<setw(13)<<left<<"ISBN"<<"\t"<<"Issued to\n";
  for (int i = 1; i <= n; i++)
  {
    rd.read((char*)&obj_bk, sizeof(obj_bk));
    if (strcmp(obj_bk.author, sr_author)==0)
    {
    obj_bk.display();
    flag = 1;
    }
  }
  if (flag == 0)
  {
    cout<<"\nBook not found.\n";
  }
}
void search_edition()
{
  //function to search a book by its edition.
  int sr;
  int flag = 0;
  fstream rd;
  rd.open("data.txt", ios::in);
  rd.seekg(0, ios::end);
  int s = rd.tellg();                                              
  int n = s/sizeof(obj_bk);                                                   //It's going good.
  rd.seekg(0, ios::beg); 
  if (n == 0)
  {
    cout<<"\nThe library is empty.\n";
    return;
  }
  cout<<endl<<"Enter book's edition: ";
  cin>>sr;
  cout<<endl<<"Book ID"<<"\t\t"<<setw(30)<<left<<"Book name"<<"\t"<<setw(20)<<left<<"Author"<<"\t"<<"Edition"<<"\t\t"<<setw(20)<<left<<"Publisher"<<"\t"<<setw(13)<<left<<"ISBN"<<"\t"<<"Issued to\n";
  for (int i = 1; i <= n; i++)
  {
    rd.read((char*)&obj_bk, sizeof(obj_bk));
    if (obj_bk.edition == sr)
    {
    obj_bk.display();
    flag = 1;
    }
  }
  if (flag == 0)
  {
    cout<<"\nBook not found.\n";
  }
}
void search_publisher()
{
  //function to search a book by its publisher.
  char sr_publisher[40];
  int flag = 0;
  fstream rd;
  rd.open("data.txt", ios::in);
  rd.seekg(0, ios::end);
  int s = rd.tellg();
  int n = s/sizeof(obj_bk);
  rd.seekg(0, ios::beg);
  if (n == 0)
  {
    cout<<"\nThe library is empty.\n";
    return;
  }
  cout<<endl<<"Enter publisher's name: ";
  cin>>sr_publisher;
  cout<<endl<<"Book ID"<<"\t\t"<<setw(30)<<left<<"Book name"<<"\t"<<setw(20)<<left<<"Author"<<"\t"<<"Edition"<<"\t\t"<<setw(20)<<left<<"Publisher"<<"\t"<<setw(13)<<left<<"ISBN"<<"\t"<<"Issued to\n";
  for (int i = 1; i <= n; i++)
  {
    rd.read((char*)&obj_bk, sizeof(obj_bk));
    if (strcmp(obj_bk.publisher, sr_publisher)==0)
    {
    obj_bk.display();
    flag = 1;
    }
  }
  if (flag == 0)
  {
    cout<<"\nBook not found.\n";
  }
}
void search_isbn()
{
  //function to search a book by its ISBN.
  char sr_isbn[20];
  int flag = 0;
  fstream rd;
  rd.open("data.txt", ios::in);
  rd.seekg(0, ios::end);
  int s = rd.tellg();
  int n = s/sizeof(obj_bk);
  rd.seekg(0, ios::beg);
  if (n == 0)
  {
    cout<<"\nThe library is empty.\n";
    return;
  }
  cout<<endl<<"Enter book's ISBN: ";
  cin>>sr_isbn;
  cout<<endl<<"Book ID"<<"\t\t"<<setw(30)<<left<<"Book name"<<"\t"<<setw(20)<<left<<"Author"<<"\t"<<"Edition"<<"\t\t"<<setw(20)<<left<<"Publisher"<<"\t"<<setw(13)<<left<<"ISBN"<<"\t"<<"Issued to\n";
  for (int i = 1; i <= n; i++)
  {
    rd.read((char*)&obj_bk, sizeof(obj_bk));
    if (strcmp(obj_bk.isbn, sr_isbn)==0)
    {
    obj_bk.display();
    flag = 1;
    }
  }
  if (flag == 0)
  {
    cout<<"\nBook not found.\n";
  }
}
void edit_bookid()
{
  //function to edit a book ID.
    int n_id, l_id;
    int flag = 0;
    int flag1 = 0;
    fstream rd, r;
    rd.open("data.txt", ios::in);
    r.open("temp.txt", ios::out);
    rd.seekg(0, ios::end);
    int s = rd.tellg();
    int n = (s/sizeof(obj_bk));
    rd.seekg(0, ios::beg);
    if (n == 0)
  {
    cout<<"\nThe library is empty.\n";
    return;
  }
    cout<<"\nEnter the book ID you want to edit: ";
    cin>>l_id;
    for (int i = 1; i <= n; i++)
    {
      rd.read((char*)&obj_bk, sizeof(obj_bk));
      if (l_id == obj_bk.bookid)
      {
        flag = 1;
        cout<<"\nEnter new book ID: ";
        cin>>n_id;
        static book nf = obj_bk;
        fstream r1;
        r1.open("data.txt", ios::in);
        r1.seekg(0, ios::end);
        int n1 = (r1.tellg()/sizeof(obj_bk));
        r1.seekg(0, ios::beg);
        for (int i = 1; i <= n; i++)
        {
         r1.read((char*)&obj_bk, sizeof(obj_bk));
         if (n_id == obj_bk.bookid)
          {
            if (n_id == l_id)
            {
              cout<<"\nNo change.";
            }
           cout<<endl<<"Book ID already in use.";
           obj_bk = nf;
           r.write((char*)&obj_bk, sizeof(obj_bk));
           flag1 = 1;
           break;
          }
        }
      if (flag1 == 0)
      {
        obj_bk.bookid = n_id;
        r.write((char*)&obj_bk, sizeof(obj_bk));
        cout<<"\nBook ID edited successfully!";
      }
      }
      else
      {
        r.write((char*)&obj_bk, sizeof(obj_bk));
      }
    }
    if (flag == 0)
    {
      cout<<"\nBook not found.";
    }
    rd.close();
    r.close();
    remove("data.txt");
    rename("temp.txt", "data.txt");
}
void edit_bookname()
{
  //function to edit a book's name.
    char n_name[50], name[50];
    int flag = 0;
    fstream rd, r;
    rd.open("data.txt", ios::in);
    r.open("temp.txt", ios::out);
    rd.seekg(0, ios::end);
    int s = rd.tellg();
    int n = (s/sizeof(obj_bk));
    rd.seekg(0, ios::beg);
    if (n == 0)
  {
    cout<<"\nThe library is empty.\n";
    return;
  }
    cout<<"\nEnter the book's name you want to edit: ";
    cin>>name;
    for (int i = 1; i <= n; i++)
    {
      rd.read((char*)&obj_bk, sizeof(obj_bk));
      if (strcmp(obj_bk.bookname, name) == 0)
      {
        cout<<"\nEnter new name: ";
        cin>>n_name;
        for (int i = 0; i <= 49; i++)
        {
            obj_bk.bookname[i] = n_name[i];
        }
        r.write((char*)&obj_bk, sizeof(obj_bk));
        cout<<"\nBook's name edited successfully!";
        flag = 1;
      }
      else
      {
        r.write((char*)&obj_bk, sizeof(obj_bk));
      }
    }
    if (flag == 0)
    {
      cout<<"\nBook not found.";
    }
    rd.close();
    r.close();
    remove("data.txt");
    rename("temp.txt", "data.txt");
}
void edit_isbn()
{
  //function to edit a book's ISBN.
    char n_isbn[20], l_isbn[20];
    int flag = 0;
    fstream rd, r;
    rd.open("data.txt", ios::in);
    r.open("temp.txt", ios::out);
    rd.seekg(0, ios::end);
    int s = rd.tellg();
    int n = (s/sizeof(obj_bk));
    rd.seekg(0, ios::beg);
    if (n == 0)
  {
    cout<<"\nThe library is empty.\n";
    return;
  }
    cout<<"\nEnter the book's ISBN you want to edit: ";
    cin>>l_isbn;
    for (int i = 1; i <= n; i++)
    {
      rd.read((char*)&obj_bk, sizeof(obj_bk));                                    //Keep going.
      if (strcmp(obj_bk.isbn, l_isbn) == 0)
      {
        cout<<"\nEnter new ISBN: ";
        cin>>n_isbn;
        for (int i = 0; i <= 19; i++)
        {
            obj_bk.isbn[i] = n_isbn[i];
        }
        r.write((char*)&obj_bk, sizeof(obj_bk));
        cout<<"\nBook's ISBN edited successfully!";
        flag = 1;
      }
      else
      {
        r.write((char*)&obj_bk, sizeof(obj_bk));
      }
    }
    if (flag == 0)
    {
      cout<<"\nBook not found.";
    }
    rd.close();
    r.close();
    remove("data.txt");
    rename("temp.txt", "data.txt");
}
void remove_bookid()
{
  //function to remove a book by its book ID.
  fstream wr, rd;
  int flag = 0;
  rd.open("data.txt", ios::in);
  wr.open("temp.txt", ios::out);
  int id;
  rd.seekg(0, ios::end);
  int s = rd.tellg()/sizeof(obj_bk);
  rd.seekg(0, ios::beg);
  if (s == 0)
    {
      cout<<"\nThe library is empty.\n";
      return;
    }
  cout<<endl<<"Enter book ID: ";
  cin>>id;
  for (int i = 1; i <= s; i++)
  {                                                                                   
    rd.read((char*)&obj_bk, sizeof(obj_bk));
    if (obj_bk.bookid == id)
    {
      flag = 1;
    }
    else
    {
      wr.write((char*)&obj_bk, sizeof(obj_bk));
    }
  }
  if (flag == 0)
  {
    cout<<endl<<"Book not found.";
  }
  else
  {
    cout<<endl<<"Book removed successfully.";
  }
  wr.close();
  rd.close();
  remove("data.txt");
  rename("temp.txt", "data.txt");
}
void remove_name()
{
  //function to remove a book by its name.
  fstream wr, rd;
  int flag = 0;
  rd.open("data.txt", ios::in);
  wr.open("temp.txt", ios::out);
  char name[50];
  rd.seekg(0, ios::end);
  int s = rd.tellg()/sizeof(obj_bk);
  rd.seekg(0, ios::beg);
  if (s == 0)
    {
      cout<<"\nThe library is empty.\n";
      return;
    }
  cout<<endl<<"Enter book's name: ";
  cin>>name;
  for (int i = 1; i <= s; i++)
  {
    rd.read((char*)&obj_bk, sizeof(obj_bk));
    if (strcmp(obj_bk.bookname, name) == 0)
    {
      flag = 1;
    }
    else
    {
      wr.write((char*)&obj_bk, sizeof(obj_bk));
    }
  }
  if (flag == 0)
  {
    cout<<endl<<"Book not found.";
  }
  else
  {
    cout<<endl<<"Book(s) removed successfully.";
  }
  wr.close();
  rd.close();
  remove("data.txt");
  rename("temp.txt", "data.txt");
}
void remove_author()
{
  //function to remove a book by its author.
  fstream wr, rd;
  int flag = 0;
  rd.open("data.txt", ios::in);
  wr.open("temp.txt", ios::out);
  char auth[40];
  rd.seekg(0, ios::end);
  int s = rd.tellg()/sizeof(obj_bk);
  rd.seekg(0, ios::beg);
  if (s == 0)
    {
      cout<<"\nThe library is empty.\n";
      return;
    }
  cout<<endl<<"Enter book's author: ";
  cin>>auth;
  for (int i = 1; i <= s; i++)
  {
    rd.read((char*)&obj_bk, sizeof(obj_bk));
    if (strcmp(obj_bk.author, auth) == 0)
    {
      flag = 1;
    }
    else
    {
      wr.write((char*)&obj_bk, sizeof(obj_bk));
    }
  }
  if (flag == 0)
  {
    cout<<endl<<"Book not found.";
  }
  else
  {
    cout<<endl<<"Book(s) removed successfully.";
  }
  wr.close();
  rd.close();
  remove("data.txt");
  rename("temp.txt", "data.txt");
}
void remove_edition()
{
  //function to remove a book by its edition.
  fstream wr, rd;
  int flag = 0;
  rd.open("data.txt", ios::in);
  wr.open("temp.txt", ios::out);
  int ed;
  rd.seekg(0, ios::end);
  int s = rd.tellg()/sizeof(obj_bk);
  rd.seekg(0, ios::beg);
  if (s == 0)
    {
      cout<<"\nThe library is empty.\n";
      return;
    }
  cout<<endl<<"Enter book's edition: ";
  cin>>ed;
  for (int i = 1; i <= s; i++)
  {
    rd.read((char*)&obj_bk, sizeof(obj_bk));
    if (obj_bk.edition == ed)
    {
      flag = 1;
    }
    else
    {
      wr.write((char*)&obj_bk, sizeof(obj_bk));
    }
  }
  if (flag == 0)
  {
    cout<<endl<<"Book not found.";
  }
  else
  {
    cout<<endl<<"Book(s) removed successfully.";
  }
  wr.close();
  rd.close();
  remove("data.txt");
  rename("temp.txt", "data.txt");
}
void remove_publisher()
{
  //function to remove a book by its publisher.
  fstream wr, rd;
  int flag = 0;
  rd.open("data.txt", ios::in);
  wr.open("temp.txt", ios::out);
  char pub[40];
  rd.seekg(0, ios::end);
  int s = rd.tellg()/sizeof(obj_bk);
  rd.seekg(0, ios::beg);
  if (s == 0)
    {
      cout<<"\nThe library is empty.\n";
      return;
    }
  cout<<endl<<"Enter book's publisher: ";
  cin>>pub;
  for (int i = 1; i <= s; i++)
  {
    rd.read((char*)&obj_bk, sizeof(obj_bk));
    if (strcmp(obj_bk.publisher, pub) == 0)
    {
      flag = 1;
    }
    else
    {
      wr.write((char*)&obj_bk, sizeof(obj_bk));
    }
  }
  if (flag == 0)
  {
    cout<<endl<<"Book not found.";
  }
  else
  {
    cout<<endl<<"Book(s) removed successfully.";
  }
  wr.close();
  rd.close();
  remove("data.txt");
  rename("temp.txt", "data.txt");
}
void remove_isbn()
{
  //function to remove a book by its ISBN.
  fstream wr, rd;
  int flag = 0;
  rd.open("data.txt", ios::in);
  wr.open("temp.txt", ios::out);
  char id[13];
  rd.seekg(0, ios::end);
  int s = rd.tellg()/sizeof(obj_bk);
  rd.seekg(0, ios::beg);
  if (s == 0)
    {
      cout<<"\nThe library is empty.\n";
      return;
    }
  cout<<endl<<"Enter book ISBN: ";
  cin>>id;
  for (int i = 1; i <= s; i++)
  {
    rd.read((char*)&obj_bk, sizeof(obj_bk));
    if (strcmp(obj_bk.isbn, id) == 0)
    {
      flag = 1;
    }
    else
    {
      wr.write((char*)&obj_bk, sizeof(obj_bk));
    }
  }
  if (flag == 0)
  {
    cout<<endl<<"Book not found.";
  }
  else
  {
    cout<<endl<<"Book removed successfully.";
  }
  wr.close();
  rd.close();
  remove("data.txt");
  rename("temp.txt", "data.txt");
}
void issue_book()
{
  //function to issue a book.
  fstream wr, rd;
  int flag = 0;
  rd.open("data.txt", ios::in);
  wr.open("temp.txt", ios::out);
  int id;
  rd.seekg(0, ios::end);
  int s = rd.tellg()/sizeof(obj_bk);
  rd.seekg(0, ios::beg);
  if (s == 0)
    {
      cout<<"\nThe library is empty.\n";
      return;
    }
  cout<<endl<<"Enter book ID: ";
  cin>>id;
  for (int i = 1; i <= s; i++)
  {
    rd.read((char*)&obj_bk, sizeof(obj_bk));
    if (obj_bk.bookid == id)
    {
      flag = 1;
      if (obj_bk.issued_to == 0)
      {
        int member_id;
        cout<<endl<<"Enter membership ID: ";
        cin>>member_id;
        obj_bk.issued_to = member_id;
        wr.write((char*)&obj_bk, sizeof(obj_bk));
        cout<<endl<<"Book issued successfully.";
      }
      else
      {
        cout<<endl<<"Book not available.";
        wr.write((char*)&obj_bk, sizeof(obj_bk));
      }
    }
    else
    {
      wr.write((char*)&obj_bk, sizeof(obj_bk));
    }
  }
  if (flag == 0)
  {
    cout<<"\nBook not found.\n";
  }
  wr.close();
  rd.close();
  remove("data.txt");
  rename("temp.txt", "data.txt");
}
void return_book()
{
  //function to return a book.
  fstream wr, rd;
  int flag = 0;
  rd.open("data.txt", ios::in);
  wr.open("temp.txt", ios::out);
  int id;
  rd.seekg(0, ios::end);
  int s = rd.tellg()/sizeof(obj_bk);
  rd.seekg(0, ios::beg);
  if (s == 0)
    {
      cout<<"\nThe library is empty.\n";
      return;
    }
  cout<<endl<<"Enter book ID: ";
  cin>>id;
  for (int i = 1; i <= s; i++)
  {
    rd.read((char*)&obj_bk, sizeof(obj_bk));
    if (obj_bk.bookid == id)
    {
      flag = 1;
      if (obj_bk.issued_to != 0)
      {
        obj_bk.issued_to = 0;
        wr.write((char*)&obj_bk, sizeof(obj_bk));
        cout<<endl<<"Book returned successfully.";
      }
      else
      {
        cout<<endl<<"Book was not issued.";
        wr.write((char*)&obj_bk, sizeof(obj_bk));
      }
    }
    else
    {
      wr.write((char*)&obj_bk, sizeof(obj_bk));
    }
  }
  if (flag == 0)
  {
    cout<<"\nBook not found.\n";
  }
  wr.close();
  rd.close();
  remove("data.txt");
  rename("temp.txt", "data.txt");                                             
}
void clear_entire_record()
{
  //function to clear the entire library
  fstream clear;
  clear.open("data.txt", ios::out | ios::trunc);
  clear.close();
  cout<<endl<<"The contents of the library are entirely deleted.";
}
void menu()
{
  //menu-driven application of all functions using switch-case.
  int num;
  cout<<endl<<"Welcome to Raghav's library!\n";
  cout<<endl<<"Enter 1 to add a book.";
  cout<<endl<<"Enter 2 to view all books.";
  cout<<endl<<"Enter 3 to search a book.";
  cout<<endl<<"Enter 4 to edit a book's data.";
  cout<<endl<<"Enter 5 to remove a book from record.";
  cout<<endl<<"Enter 6 to issue a book.";
  cout<<endl<<"Enter 7 to return a book.";
  cout<<endl<<"Enter 8 to clear the entire library.";
  cout<<endl<<"Enter 9 to exit.";
  cout<<endl<<"\nEnter the required number: ";
  cin>>num;
  switch (num)
  {
    case 1:
    add_book();
    break;

    case 2:
    view_all();
    break;

    case 3:
    {
      int num2;
      cout<<endl<<"Enter 1 to search a book by its book ID.";
      cout<<endl<<"Enter 2 to search a book by its name.";
      cout<<endl<<"Enter 3 to search a book by its author.";
      cout<<endl<<"Enter 4 to search a book by its edition.";
      cout<<endl<<"Enter 5 to search a book by its publisher.";
      cout<<endl<<"Enter 6 to search a book by its ISBN.";
      cout<<endl<<"\nEnter the required number: ";
      cin>>num2;
      switch(num2)
      {
        case 1:
        search_id();
        break;

        case 2:
        search_name();
        break;

        case 3:
        search_author();
        break;

        case 4:
        search_edition();
        break;

        case 5:
        search_publisher();
        break;

        case 6:
        search_isbn();
        break;

        default:
        cout<<"\nInvalid choice.";
      }
      break;
    }

    case 4:
    {
      int num3;
      cout<<endl<<"Enter 1 to edit a book ID.";
      cout<<endl<<"Enter 2 to edit a book's name.";
      cout<<endl<<"Enter 3 to edit a book's ISBN.";
      cout<<endl<<"\nEnter the required number: ";
      cin>>num3;
      switch(num3)
      {
        case 1:
        edit_bookid();
        break;

        case 2:
        edit_bookname();
        break;

        case 3:
        edit_isbn();
        break;

        default:
        cout<<"\nInvalid choice.";
      }
    break;
    }

    case 5:
    {
      int num4;
      cout<<endl<<"Enter 1 to remove a book from record by its book ID.";
      cout<<endl<<"Enter 2 to remove a book from record by its name.";
      cout<<endl<<"Enter 3 to remove a book from record by its author.";
      cout<<endl<<"Enter 4 to remove a book from record by its edition.";
      cout<<endl<<"Enter 5 to remove a book from record by its publisher.";
      cout<<endl<<"Enter 6 to remove a book from record by its ISBN.";
      cout<<endl<<"\nEnter the required number: ";
      cin>>num4;
      switch(num4)
      {
        case 1:
        remove_bookid();
        break;

        case 2:
        remove_name();
        break;

        case 3:
        remove_author();
        break;

        case 4:
        remove_edition();
        break;

        case 5:
        remove_publisher();
        break;

        case 6:
        remove_isbn();
        break;

        default:
        cout<<"\nInvalid choice.";
      }
    break;
    }

    case 6:
    issue_book();
    break;

    case 7:
    return_book();
    break;

    case 8:
    clear_entire_record();
    break;

    case 9:
    break;

    default:
    cout<<"\nInvalid choice.";
  }
}
int main()
{
  //Run the menu() function only that will run the required function based on the number entered.
  menu();
}
//The end