/* C++ project to make a calculator.
Made by Raghav Khanna */

#include <iostream>
#include <math.h>
#include <iomanip>
#define pi 3.14151
#define e 2.71828
using namespace std;
class calculator
{
 public:
 void add()
 {
    //function to add 2 or more numbers.
    int no;
    double sum = 0, num;
    cout<<"\nHow many numbers do you want to add? ";
    cin>>no;
    if (no == 1 || no == 0)
    {
     cout<<"\nEnter two or more numbers to add.\n";
    }
    else if (no < 0)
    {
     cout<<"\nThe number of numbers to be added can only be positive.\n"; 
    }
    else
    {
     for (int i = 1; i <= no; i++)
     {
      cout<<"Enter number "<<i<<": ";
      cin>>num;
      sum = sum + num;
     }
     cout<<"\nThe sum is "<<sum<<".\n";
    }
 }
 void multiply()
 {
    //function to multiply 2 or more numbers.
    int no;
    double prod = 1, num;
    cout<<"\nHow many numbers do you want to multiply? ";
    cin>>no;
    if (no == 1 || no == 0)
    {
     cout<<"\nEnter two or more numbers to multiply.\n";
    }
    else if (no < 0)
    {
     cout<<"\nThe number of numbers to be multiplied can only be positive.\n";
    }
    else
    {
     for (int i = 1; i <= no; i++)
     {
      cout<<"Enter number "<<i<<": ";
      cin>>num;
      prod = prod * num;
     }
     cout<<"\nThe product is "<<prod<<".\n";
    }
 }
 void subtract()
 {
    //function to subract 1 or more number(s) from a number.
    int no;
    double diff, num, num1;
    cout<<"\nHow many numbers do you want to subtract from the first number? ";
    cin>>no;
    if (no == 0)
    {
     cout<<"\nEnter one or more number(s) to be subtracted.\n";
    }
    else if (no < 0)
    {
     cout<<"\nThe number of numbers to be subtracted can only be positive.\n";
    }
    else
    {
     cout<<"\nEnter first number: ";
     cin>>num1;
     diff = num1;
     for (int i = 1; i <= no; i++)
     {
      cout<<"Enter number "<<i<<" to be subtracted: ";
      cin>>num;
      diff = diff - num;
     }
     cout<<"\nThe difference is "<<diff<<".\n";
    }
 }
 void divide()
 {
    //function to divide a number by 1 or more number(s).
    int no, flag = 1;
    double quo, num, num1;
    cout<<"\nHow many numbers do you want the first number to be divided by? ";
    cin>>no;
    if (no == 0)
    {
     cout<<"\nEnter one or more number(s) to divide the first number by.\n";
    }
    else if (no < 0)
    {
     cout<<"\nThe number of numbers to divide the first number by can only be positive.\n";
    }
    else
    {
     cout<<"\nEnter first number: ";
     cin>>num1;
     quo = num1;
     for (int i = 1; i <= no; i++)
     {
      cout<<"Enter number "<<i<<" to divide the first number by: ";
      cin>>num;
      if (num == 0)
      {
        cout<<"\nDivision by 0 is not possible.\n";
        flag = 0;
        break;
      }
      quo = quo/num;
     }
     if (flag == 1)
     {
     cout<<"\nThe quotient is "<<quo<<".\n";
     }
    }
 }
 void factorial()
 {
   //function to find the factorial of a number.
   int fact = 1, num;
   cout<<"\nEnter number: ";
   cin>>num;
   if (num < 0)
   {
      cout<<"\nThe factorial of a negative number doesn't exist.\n";
   }
   else if (num == 0)
   {
      cout<<"\nThe factorial of 0 is 1.\n";
   }
   else
   {
      for (int i = 1; i <= num; i++)
      {
        fact = fact * i;
      }
      cout<<"\nThe factorial of "<<num<<" is "<<fact<<".\n";
   }
 }
 void square()
 {
   //function to find the square of a number.
   double num;
   cout<<"\nEnter number: ";
   cin>>num;
   cout<<"\nThe square of "<<num<<" is "<<num * num<<".\n";
 }
 void cube()
 {
   //function to find the cube of a number.
   double num;
   cout<<"\nEnter number: ";
   cin>>num;
   cout<<"\nThe cube of "<<num<<" is "<<num * num * num<<".\n";
 }
 void square_root()
 {
   //function to find the square root of a number.
   double num;
   cout<<"\nEnter number: ";
   cin>>num;
   cout<<"\nThe square root of "<<num<<" is "<<sqrt(num)<<".\n";
 }
 void cube_root()
 {
   //function to find the cube root of a number.
   double num;
   cout<<"\nEnter number: ";
   cin>>num;
   cout<<"\nThe cube root of "<<num<<" is "<<cbrt(num)<<".\n";
 }
 void expon()
 {
   //function to find the value of power of a number.
   double base, power;
   cout<<"\nEnter base: ";
   cin>>base;
   cout<<"\nEnter power: ";
   cin>>power;
   if (power == 2)
   {
      cout<<"\nThe square of "<<base<<" is "<<base * base<<".\n";
   }
   else if (power == 3)
   {
      cout<<"\nThe cube of "<<base<<" is "<<base * base * base<<".\n";
   }
   else
   {
      cout<<base<<" to the power "<<power<<" is "<<pow(base, power)<<".\n";
   }
 }
 void nth_root()
 {
   //function to find the nth root of a number.
   double num, nroot;
   cout<<"\nEnter number: ";
   cin>>num;
   cout<<"\nEnter root number: ";
   cin>>nroot;
   if (num == 2)
   {
      cout<<"\nThe square root of "<<num<<" is "<<sqrt(num)<<".\n";
   }
   else if (num == 3)
   {
      cout<<"\nThe cube root of "<<num<<" is "<<cbrt(num)<<".\n";
   }
   else
   {
      cout<<"The "<<nroot<<"th root of "<<num<<" is "<<pow(num, (1*nroot))<<".\n";
   }
 }
 void percentage()
 {
   //function to find the percentage of a number.
   double num, percent, ans;
   cout<<"\nEnter number: ";
   cin>>num;
   cout<<"\nEnter percentage: ";
   cin>>percent;
   cout<<endl<<percent<<"% of "<<num<<" is "<<(num * percent)/100<<".\n";
 }
 void d_r()
 {
   //function to convert degree(s) to radian(s).
   double deg, rad;
   cout<<"\nEnter angle in degree(s): ";
   cin>>deg;
   cout<<deg<<" degrees is equal to "<<(deg * pi)/180<<" radian(s).\n";
 }
 void r_d()
 {
   //function to convert radian(s) to degree(s).
   double deg, rad;
   cout<<"\nEnter angle in radian(s): ";
   cin>>rad;                                                                 //It's going good.
   cout<<rad<<" radians is equal to "<<(rad * 180)/pi<<" degree(s).\n";
 }
 void sinf()
 {
   //function to find the values of sine function.
   double deg, rad;
   int dor;
   cout<<"\nIs your angle in degrees or radians?\n";
   cout<<"Enter 1 for degrees.\n";
   cout<<"Enter 2 for radians.";
   cout<<"\nEnter the required number: ";
   cin>>dor;
   switch(dor)
   {
      case 1:                                                            
      cout<<"\nEnter angle in degrees: ";
      cin>>deg;
      cout<<"\nThe sine of "<<deg<<" degrees is "<<sin((deg * pi)/180)<<".\n";
      break;

      case 2:
      cout<<"\nEnter angle in radians: ";
      cin>>rad;
      cout<<"\nThe sine of "<<rad<<" radians is "<<sin(rad)<<".\n";
      break;

      default:
      cout<<"\nInvalid choice.";
   }
 }
 void cosf()
 {
   //function to find the values of cosine function.
   double deg, rad;
   int dor;
   cout<<"\nIs your angle in degrees or radians?\n";
   cout<<"Enter 1 for degrees.\n";
   cout<<"Enter 2 for radians.";
   cout<<"\nEnter the required number: ";
   cin>>dor;
   switch(dor)
   {
      case 1:
      cout<<"\nEnter angle in degrees: ";
      cin>>deg;
      cout<<"\nThe cosine of "<<deg<<" degrees is "<<cos((deg * pi)/180)<<".\n";
      break;

      case 2:
      cout<<"\nEnter angle in radians: ";
      cin>>rad;
      cout<<"\nThe cosine of "<<rad<<" radians is "<<cos(rad)<<".\n";
      break;

      default:
      cout<<"\nInvalid choice.";
   }
 }
 void tanf()
  {
   //function to find the values of tangent function.
   double deg, rad;
   int dor;
   cout<<"\nIs your angle in degrees or radians?\n";
   cout<<"Enter 1 for degrees.\n";
   cout<<"Enter 2 for radians.";
   cout<<"\nEnter the required number: ";
   cin>>dor;
   switch(dor)
   {
      case 1:
      cout<<"\nEnter angle in degrees: ";
      cin>>deg;
      cout<<"\nThe tangent of "<<deg<<" degrees is "<<sin((deg * pi)/180)/cos((deg * pi)/180)<<".\n";
      break;

      case 2:
      cout<<"\nEnter angle in radians: ";
      cin>>rad;
      cout<<"\nThe tangent of "<<rad<<" radians is "<<sin(rad)/cos(rad)<<".\n";
      break;

      default:
      cout<<"\nInvalid choice.";
   }
 }
 void cotf()
  { 
   //function to find the values of cotangent function.
   double deg, rad;
   int dor;
   cout<<"\nIs your angle in degrees or radians?\n";
   cout<<"Enter 1 for degrees.\n";
   cout<<"Enter 2 for radians.";
   cout<<"\nEnter the required number: ";
   cin>>dor;
   switch(dor)
   {
      case 1:
      cout<<"\nEnter angle in degrees: ";
      cin>>deg;
      cout<<"\nThe cotangent of "<<deg<<" degrees is "<<cos((deg * pi)/180)/sin((deg * pi)/180)<<".\n";
      break;

      case 2:
      cout<<"\nEnter angle in radians: ";
      cin>>rad;
      cout<<"\nThe cotangent of "<<rad<<" radians is "<<cos(rad)/sin(rad)<<".\n";
      break;

      default:
      cout<<"\nInvalid choice.";
   }
 }
void secf()
 {
   //function to find the values of secant function.
   double deg, rad;
   int dor;
   cout<<"\nIs your angle in degrees or radians?\n";
   cout<<"Enter 1 for degrees.\n";
   cout<<"Enter 2 for radians.";
   cout<<"\nEnter the required number: ";
   cin>>dor;
   switch(dor)
   {
      case 1:
      cout<<"\nEnter angle in degrees: ";
      cin>>deg;
      cout<<"\nThe secant of "<<deg<<" degrees is "<<1/cos((deg * pi)/180)<<".\n";
      break;

      case 2:
      cout<<"\nEnter angle in radians: ";
      cin>>rad;
      cout<<"\nThe secant of "<<rad<<" radians is "<<1/cos(rad)<<".\n";
      break;

      default:
      cout<<"\nInvalid choice.";
   }
 }
 void cosecf()
  {
   //function to find the values of cosecant function.
   double deg, rad;
   int dor;
   cout<<"\nIs your angle in degrees or radians?\n";
   cout<<"Enter 1 for degrees.\n";
   cout<<"Enter 2 for radians.";
   cout<<"\nEnter the required number: ";
   cin>>dor;
   switch(dor)
   {
      case 1:
      cout<<"\nEnter angle in degrees: ";
      cin>>deg;
      cout<<"\nThe cosecant of "<<deg<<" degrees is "<<1/sin((deg * pi)/180)<<".\n";
      break;

      case 2:
      cout<<"\nEnter angle in radians: ";
      cin>>rad;
      cout<<"\nThe cosecant of "<<rad<<" radians is "<<1/sin(rad)<<".\n";
      break;

      default:
      cout<<"\nInvalid choice.";
   }
 }
 void reciprocal()
 {
   //function to find the reciprocal of a number.
   double num;
   cout<<"\nEnter number: ";
   cin>>num;
   cout<<"\nThe reciprocal of "<<num<<" is "<<1/num<<".\n";
 }
 void logf()
 {
   //function to find the log of a number.
   double num;
   int base, eon;
   cout<<"\nEnter 1 for natural log (to the base e).\n";
   cout<<"Enter 2 for log to the base 10.\n";
   cout<<"Enter 3 for log to some integral base other than e and 10.\n";
   cout<<"Enter the required number: ";
   cin>>eon;
   cout<<"\nEnter number: ";
   cin>>num;
   switch(eon)
   {
      case 1:
      cout<<"\nThe natural log (to the base e) of "<<num<<" is "<<log(num)<<".\n";
      break;

      case 2:
      cout<<"\nThe log of "<<num<<" to the base 10 is "<<log(num)/log(10)<<".\n";
      break;

      case 3:
      cout<<"\nEnter base: ";
      cin>>base;
      cout<<"\nThe log of "<<num<<" to the base "<<base<<" is "<<log(num)/log(base)<<".\n";
      break;

      default:
      cout<<"\nInvalid choice.";
   }
 }
 void antilogf()
 {
   //function to find the anti-log of a number.
   double num;
   int base, eon;
   cout<<"\nEnter 1 for natural anti-log (base e).\n";
   cout<<"Enter 2 for anti-log to the base 10.\n";
   cout<<"Enter 3 for anti-log to some integral base other than e and 10.\n";
   cout<<"Enter the required number: ";
   cin>>eon;
   cout<<"\nEnter number: ";
   cin>>num;
   switch(eon)
   {
      case 1:
      cout<<"\nThe natural anti-log (base e) of "<<num<<" is "<<exp(num)<<".\n";
      break;

      case 2:
      cout<<"\nThe anti-log of "<<num<<" to the base 10 is "<<pow(10, num)<<".\n";
      break;

      case 3:
      cout<<"\nEnter base: ";
      cin>>base;
      cout<<"\nThe anti-log of "<<num<<" to the base "<<base<<" is "<<pow(base, num)<<".\n";
      break;

      default:
      cout<<"\nInvalid choice.";
   }
 }
void exi()
{
   //function to find the value of power of e.                                          //Keep going.
   double power;
   cout<<"\nEnter power of e: ";
   cin>>power;
   cout<<"e to the power "<<power<<" is "<<exp(power);
}
void invsin()
{
   //function to find the values of inverse sine function.
   double num;
   cout<<"\nEnter number: ";
   cin>>num;
   cout<<"\nThe inverse sine of "<<num<<" is "<<asin(num)<<" radians or "<<(asin(num) * 180)/pi<<" degrees.\n";
}
void invcos()
{          
   //function to find the values of inverse cosine function.                                                          
   double num;
   cout<<"\nEnter number: ";
   cin>>num;
   cout<<"\nThe inverse cosine of "<<num<<" is "<<acos(num)<<" radians or "<<(acos(num) * 180)/pi<<" degrees.\n";
}
void invtan()
{
   //function to find the values of inverse tangent function.
   double num;
   cout<<"\nEnter number: ";
   cin>>num;
   cout<<"\nThe inverse tangent of "<<num<<" is "<<atan(num)<<" radians or "<<(atan(num) * 180)/pi<<" degrees.\n";
}
void invcot()
{
   //function to find the values of inverse cotangent function.
   double num;
   cout<<"\nEnter number: ";
   cin>>num;
   cout<<"\nThe inverse cotangent of "<<num<<" is "<<atan(1/num)<<" radians or "<<(atan(1/num) * 180)/pi<<" degrees.\n";
}
void invsec()
{
   //function to find the values of inverse secant function.
   double num;
   cout<<"\nEnter number: ";
   cin>>num;
   cout<<"\nThe inverse secant of "<<num<<" is "<<acos(1/num)<<" radians or "<<(acos(1/num) * 180)/pi<<" degrees.\n";
}
void invcosec()
{
   //function to find the values of inverse cosecant function.
   double num;
   cout<<"\nEnter number: ";
   cin>>num;
   cout<<"\nThe inverse cosecant of "<<num<<" is "<<asin(1/num)<<" radians or "<<(asin(1/num) * 180)/pi<<" degrees.\n";
}
void operation()
 {
   //menu-driven application of functions using switch-case.
   int op;
   cout<<"\nEnter 1 for arithmetic operations.";
   cout<<"\nEnter 2 for trigonometric operations.";
   cout<<"\nEnter 3 for inverse trigonometric operations.";
   cout<<"\nEnter 4 for square and/or square root operation(s).";
   cout<<"\nEnter 5 for cube and/or cube root operation(s).";
   cout<<"\nEnter 6 for nth power and/or nth root operation(s).";
   cout<<"\nEnter 7 for reciprocation.";
   cout<<"\nEnter 8 for logarithmic and/or anti-logarithmic operation(s).";
   cout<<"\nEnter 9 for exponential operation.";
   cout<<"\nEnter 10 for percentage operation.";
   cout<<"\nEnter 11 for factorial.";
   cout<<"\nEnter 12 for degree-radian interconversions.";
   cout<<"\nEnter 13 to exit.";
   cout<<"\nEnter the required number: ";
   cin>>op;
   switch(op)
   {
    case 1:
    {
      char O;
      cout<<"\nEnter + for addition.";
      cout<<"\nEnter - for subtraction.";
      cout<<"\nEnter * for multiplication.";
      cout<<"\nEnter / for division.";
      cout<<"\nEnter the required symbol: ";
      cin>>O;
      switch(O)
      {
         case '+':
         add();
         break;

         case '-':
         subtract();
         break;

         case '*':
         multiply();
         break;

         case '/':
         divide();
         break;

         default:
         cout<<"\nInvalid choice.";
      }
      break;
    }

    case 2:
    {
      int tr;
      cout<<"\nEnter 1 for sine.";
      cout<<"\nEnter 2 for cosine.";
      cout<<"\nEnter 3 for tangent.";
      cout<<"\nEnter 4 for cotangent.";
      cout<<"\nEnter 5 for secant.";
      cout<<"\nEnter 6 for cosecant.";
      cout<<"\nEnter the required number: ";
      cin>>tr;
      switch(tr)
      {
         case 1:
         sinf();
         break;

         case 2:
         cosf();
         break;

         case 3:
         tanf();
         break;

         case 4:
         cotf();
         break;

         case 5:
         secf();
         break;

         case 6:
         cosecf();
         break;

         default:
         cout<<"\nInvalid choice.";      
      }
      break;
    }
   
    case 3:
    {
      int atr;
      cout<<"\nEnter 1 for inverse sine.";
      cout<<"\nEnter 2 for inverse cosine.";
      cout<<"\nEnter 3 for inverse tangent.";
      cout<<"\nEnter 4 for inverse cotangent.";
      cout<<"\nEnter 5 for inverse secant.";
      cout<<"\nEnter 6 for inverse cosecant.";
      cout<<"\nEnter the required number: ";
      cin>>atr;
      switch(atr)
      {
         case 1:
         invsin();    
         break;

         case 2:
         invcos();
         break;

         case 3:
         invtan();
         break;

         case 4:
         invcot();
         break;

         case 5:
         invsec();
         break;

         case 6:
         invcosec();
         break;

         default:
         cout<<"\nInvalid choice.";      
      }
      break;
    }

    case 4:
    {
      int sq;
      cout<<"\nEnter 1 for square operation.";
      cout<<"\nEnter 2 for square root operation.";
      cout<<"\nEnter the required number: ";
      cin>>sq;
      switch(sq)
      {
         case 1:
         square();
         break;

         case 2:
         square_root();
         break;

         default:
         cout<<"\nInvalid choice.";
      }
      break;
    }

    case 5:
    {
      int cb;
      cout<<"\nEnter 1 for cube operation.";
      cout<<"\nEnter 2 for cube root operation.";
      cout<<"\nEnter the required number: ";
      cin>>cb;
      switch(cb)
      {
         case 1:
         cube();
         break;

         case 2:
         cube_root();
         break;

         default:
         cout<<"\nInvalid choice.";
      }
      break;
    }

    case 6:
    {
      int n;
      cout<<"\nEnter 1 for nth power operation.";
      cout<<"\nEnter 2 for nth root operation.";
      cout<<"\nEnter the required number: ";
      cin>>n;
      switch (n)
      {
         case 1:
         expon();
         break;

         case 2:
         nth_root();
         break;

         default:
         cout<<"\nInvalid choice.";
      }
      break;
    }

    case 7:
    reciprocal();
    break;

    case 8:
    {
      int l;
      cout<<"\nEnter 1 for logarithmic operation.";
      cout<<"\nEnter 2 for anti-logarithmic operation.";
      cout<<"\nEnter the required number: ";
      cin>>l;
      switch (l)
      {
         case 1:
         logf();
         break;

         case 2:
         antilogf();
         break;

         default:
         cout<<"\nInvalid choice.";
      }
      break;
    }

    case 9:
    exi();
    break;

    case 10:
    percentage();
    break;

    case 11:
    factorial();
    break;

    case 12:
    {
      int n;
      cout<<"\nEnter 1 for degree to radian conversion.";
      cout<<"\nEnter 2 for radian to degree conversion.";
      cout<<"\nEnter the required number: ";
      cin>>n;
      switch (n)
      {
         case 1:
         d_r();
         break;

         case 2:
         r_d();
         break;

         default:
         cout<<"\nInvalid choice.";
      }
      break;
    }

    case 13:
    break;

    default:
    cout<<"\nInvalid choice.";
   }
 }
};
calculator obj;
int main()
{
   obj.operation();
}
//The end