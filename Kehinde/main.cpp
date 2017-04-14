//
//Kehinde Project
//This program will write to a .csv file which can directly be opened up in excel
//Save both this file and the .csv file in the same folder

#include <iostream>
#include <iostream>
#include <fstream>

using namespace std;

int Gender;
float Height_Feet;
float Height_Inches;
float Total_Height;
float Weight;
float BMR;
float Calculations;

int Age;
int HB;

ofstream myfile;

int main ()
{
    
    myfile.open ("HEART.csv");
    myfile << "Gender" << "," <<  "Height_Feet" << "," << "Height_Inches"<< "," << "Weight" << "," << "Age" << endl;
    
    cout << "Welcome, Let's Calculate your BMR" << endl;
    
    cout << "Sex? (Male = 0 or Female = 1)" << endl;
    cin >> Gender;
    
    
    cout << "How tall are you? (feet)" << endl;
    cin >> Height_Feet;
   
    
    cout << "How tall are you? (inches)" << endl;
    cin >> Height_Inches;
    
    
    cout << "How much do you weigh in pounds" << endl;
    cin >> Weight;
 
    
    cout << "How old are you?" << endl;
    cin >> Age;
    
    myfile << Gender << "," << Height_Feet << "," << Height_Inches << "," << Weight << "," << Age << endl ; //write to file
    
    // Since there is no file existing at this moment to get the HB value from, we prompted the user to enter that value
    cout << "How many heartbeats do you have per minute (value should be between 60 - 250)" << endl;
    cin >> HB;
    myfile << HB;
    
    Total_Height =  (Height_Feet * 12) + Height_Inches;
    
    if (Gender == 0)
    {
        BMR = 66 + (6.2 * Weight) + (12.7 * Total_Height) - (6.67 * Age);
    }
    else if (Gender == 1)
    {
        BMR = 655.1 + (4.35 * Weight) + (4.7 * Total_Height) - (4.7 * Age);
    }
    //To calculate BMR
    if (HB > 60 || HB < 100)
    {
        Calculations = BMR * 1.2;
    }
    else if (HB == 150 && HB > 100 && HB < 150)
    {
        Calculations = BMR * 1.375;
    }
    else if (HB == 200 && HB > 150 && HB < 200)
    {
        Calculations = BMR * 1.55;
    }
    else (HB = 250 && HB > 200 &&  HB < 250);
    {
        Calculations = BMR * 1.725;
    }
    
    myfile.close ();
    cout << "The amount of calories you may eat for the day is: " << Calculations << endl;
    return 0;
}

