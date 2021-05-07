/*
Week07_Q3.cpp
Duarte, Cameryn
CSC119-142 Introduction to Programming C++ Spring 2021
03/09/2021
This program finds the highest grossing division in a quarter
*/
#include<iostream>
#include<string>//allows use of string variables
#include<iomanip>
using namespace std;
//function prototypes
double getSales(string division);
void findHighest(double& northE, double& southE, double& northW, double& southW, string& one,
string& two, string& three, string& four);

int main()
{
    double northEast, southEast, northWest, southWest;//declaring variables
    string divisionOne = "Northeast", divisionTwo = "Southeast", divisionThree = "Northwest",
           divisionFour = "Southwest";//declaring and setting the value of string variables

    cout << "This program will calculate which division had the greatest sales for a quarter.";//explaining program
    cout << endl << endl;
    //assigning value of getSales to a new valiable each time the function is called and passing string variables
    //that name the division as arguments to make it easier for the user to know what input to enter
    northEast = getSales(divisionOne);
    southEast = getSales(divisionTwo);
    northWest = getSales(divisionThree);
    southWest = getSales(divisionFour);
    cout << endl;

    findHighest(northEast, southEast, northWest, southWest, divisionOne, divisionTwo, divisionThree,
    divisionFour);//function to find which value is highest and display results

    return 0;
}

double getSales(string division)//user input function, "division" displays whichever string value is being passed 
//as an argument when the function is called
{
    double salesFigure;
    cout << "Please enter the quarterly sales figure for the " << division << " division: $";
    cin >> salesFigure;
    while (salesFigure < 0)//input validation not allowing input lower than 0
    {   cout << endl;
        cout << "Please make sure your sales figure is at least $0.00." << endl << endl;
        cout << "Please enter the quarterly sales figure for the " << division << " division: $";
        cin >> salesFigure;
    }
    return salesFigure;//return the value (only if greater than 0)
}
//function to find highest value and print results
void findHighest(double& northE, double& southE, double& northW, double& southW, string& one,
string& two, string& three, string& four)
{
    double highest = 0;
    string highestDivision;
    if (northE > highest)
    {   
        highest = northE;
        highestDivision = one;
    }
    if (southE > highest)
    {
        highest = southE;
        highestDivision = two;
    }
    if (northW > highest)
    {
        highest = northW;
        highestDivision = three;
    }
    if (southW > highest)
    {
        highest = southW;
        highestDivision = four;
    }
    cout << setprecision(2) << fixed;
    cout << "The highest grossing division is " << highestDivision << " at $" << highest;
    cout << " per quarter.";
    cout << endl << endl;
}