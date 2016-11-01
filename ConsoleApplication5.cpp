// Demo.cpp : Defines the entry point for the console application. //
#include "stdafx.h" 
#include <iostream> 
#include <string>
#include <ctime>
// For this program, the user will be prompted as to which question they would like to choose to work through, either 1, 7, or 9.
// The user will then be asked to input relevent information to output the correct result as stated by the question.
// The setup of each question focuses on calling functions as much as possible, thus each function being
// called is outside of the void block, which leaves vary little computation being done inside of the void functions.
using namespace std;

//These are the global variables that remain unchanged
//They are called for various points in different problems
double tax_rate = 0.35, principle_percentage = .03, interest_percentage = .06;
int minutes_per_hour = 60, TwelveHourMinutes = 720, TwentyFourHourMinutes = 1440;

//Program will take the user input of the price of a house and the down payment, then use this information
//to compute the annual after tax cost of the new house.
void Problem_1()
{
	double price_of_house, down_payment, ILB, PrincPay, IntrPay, AnnualM, TaxS, Cost;
	cout << "Enter the price of the house ";        //user enters in house price and down payment
	cin >> price_of_house;
	cout << endl;
	cout << "Enter the amount of the downpayment ";
	cin >> down_payment;
	cout << endl;

	//This block calls each function needed to calculate the annual after tax cost
	//Each function is noted with what it accomplishes below
	double initial_loan_balance(double price_of_house, double down_payment);
	ILB = initial_loan_balance(price_of_house, down_payment);
	double principle_payment(double PrincPay);
	PrincPay = principle_payment(ILB);
	double interest_payment(double ILB);
	IntrPay = interest_payment(ILB);
	double annual_mortgage(double PrincPay, double IntrPay);
	AnnualM = annual_mortgage(PrincPay, IntrPay);
	double tax_savings(double IntrPay);
	TaxS = tax_savings(IntrPay);
	double house_cost(double AnnualM, double TaxS);
	Cost = house_cost(AnnualM, TaxS);

	cout << "Your annual cost of this house is ";    //Function returns after-tax annual cost
	cout << Cost << endl;
}

// This function has the user input the current time and a desired future time to travel to with a time machine.
// It then converts these times into minutes and calculated the difference between these times, also accounting
// for AM and PM.
void Problem_7()
{
	int hours, minutes, future_hours, future_minutes, time_difference;
	bool isAM = false, future_isAM = false;
	char AM_test, future_AM_test, throw_away_char;

	cout << "What is the current hour?\n";  //User inputs the current time in hours, minutes and if it is AM or PM
	cin >> hours;
	cout << endl;
	cout << "What is the current minutes?\n";
	cin >> minutes;
	cout << endl;
	cout << "Is it currently AM or PM?\n";
	cin >> AM_test >> throw_away_char;     //Throwaway char stores the M from AM and PM, so the other functions only
	cout << endl;                          //have to check the A and P of the char

	bool AM_Test(char AM_test);        //Calls the function that stores if the time is AM or PM, listed below
	isAM = AM_Test(AM_test);

	cout << "What is your future hour?\n";
	cin >> future_hours;
	cout << endl;
	cout << "What is your future minutes?\n";
	cin >> future_minutes;
	cout << endl;
	cout << "Will your future time be AM or PM?\n";
	cin >> future_AM_test >> throw_away_char;
	cout << endl;

	bool AM_Test(char future_AM_test);
	future_isAM = AM_Test(future_AM_test);

	// Calls the function that calculates the difference between the time in minutes, listed below
	int computeDifference(int hours, int minutes, bool isAM, int future_hours, int future_minutes, bool future_isAM);
	time_difference = computeDifference(hours, minutes, isAM, future_hours, future_minutes, future_isAM);
	cout << "The difference between these two times is:\n";
	cout << time_difference << " minute(s)\n";
}

// This will take the input from the user of the name of 4 teams, then pick a draft order based on a randomization
// which relies on how many balls the team has access to.
void Problem_9()
{
	string Team1, Team2, Team3, Team4, TeamTest, FirstPick, SecondPick, ThirdPick, FourthPick;
	cout << "Enter the name of the teams in order starting from last place\n";    //User enters team names
	cout << "Team 1: ";
	cin >> Team1;
	cout << endl << "Team 2: ";
	cin >> Team2;
	cout << endl << "Team 3: ";
	cin >> Team3;
	cout << endl << "Team 4: ";
	cin >> Team4;
	cout << endl;

	//Calls function which picks the team that has first pick
	string Pick1(string Team1, string Team2, string Team3, string Team4);
	FirstPick = Pick1(Team1, Team2, Team3, Team4);
	cout << "The team with first pick is " << FirstPick << endl;

	// These call the functions that pick the next 3 teams for draft pick, each running until the team picked has not
	// been picked yet is chosen, then outputs it.
	string Remaining_Choices1(string FirstPick, string Team1, string Team2, string Team3, string Team4);
	SecondPick = Remaining_Choices1(FirstPick, Team1, Team2, Team3, Team4);
	cout << "The team with second pick is " << SecondPick << endl;

	string Remaining_Choices2(string FirstPick, string SecondPick, string Team1, string Team2, string Team3, string Team4);
	ThirdPick = Remaining_Choices2(FirstPick, SecondPick, Team1, Team2, Team3, Team4);
	cout << "The team with third pick is " << ThirdPick << endl;

	string Final_Choice(string FirstPick, string SecondPick, string ThirdPick, string Team1, string Team2, string Team3, string Team4);
	FourthPick = Final_Choice(FirstPick, SecondPick, ThirdPick, Team1, Team2, Team3, Team4);
	cout << "The team with fourth pick is " << FourthPick << endl;

}

//The switchcase void function is what runs by defaut when the main function runs the first time.
//This function asks the user which question they would like to run and takes them to the appropriate void function.
void run()
{
	using namespace std;
	int input;
	cout << "Which problem would you like to run?: ";
	cin >> input;       // user inputs 1, 7, or 9    depending on which problem they want to do
	switch (input)
	{
	case 1:
		Problem_1();
		break;
	case 7:
		Problem_7();
		break;
	case 9:
		Problem_9();
		break;
	default:
		cout << "error\n";  //if the user enters in something that isnt a correct problem number
		break;              //the program will default to main
	}

}

//The main function is the base state of the function which runs first and is what the program returns to once
//each void function has finished running. 
int _tmain(int argc, _TCHAR* argv[])
{
	using namespace std;
	char ans;

	do
	{
		srand(time(0));                   //Seeds a random number from clock time
		run();                            //Run my program
		cout << "Test Again? (Y/N)";
		cin >> ans;
		//cout << " " << ans << endl;     //Add if automated testing
	} while (ans == 'Y' || ans == 'y');

	return 0;
}

//Problem 1 Functions
double principle_payment(double a)
{
	double PrPay;
	PrPay = (a * principle_percentage);    //multiplies the initial loan balance by .03 to obtain 3% towards principle
	return PrPay;
}

double initial_loan_balance(double a, double b)
{
	double InLB;
	InLB = (a - b);        //initial loan balance is obtained by minusing the down payment from the price of the house
	return InLB;
}

double interest_payment(double a)
{
	double Intr;
	Intr = (a * interest_percentage);  //multiplies the initial loan balance by .06 to obtain 6% towards interest
	return Intr;
}

double annual_mortgage(double a, double b)
{
	double AnMor;
	AnMor = (a + b);       //adds the 3% being put towards principle, and the 6% being put towards interest
	return AnMor;
}

double tax_savings(double a)
{
	double TaxS;
	TaxS = (a * tax_rate);  //Multiplies the tax rate of 35% by the interest payment to obtain the tax savings
	return TaxS;
}

double house_cost(double a, double b)
{
	double Cst;
	Cst = (a - b);   //minuses the tax savings from the annual mortgage to obtain the annual after tax cost of the house
	return Cst;
}

// Problem 7 functions
int computeDifference(int a, int b, bool c, int d, int e, bool f)
{
	int Curr_min_total, future_min_total, difference, curr_min, fut_min;
	int Hrs_min_convert(int a);      //calls function to change the hours to min
	curr_min = Hrs_min_convert(a);
	fut_min = Hrs_min_convert(d);
	int min_total(int curr_min, int fut_min);   //calls the function to add the converted hours min, to the given min
	Curr_min_total = min_total(curr_min, b);
	future_min_total = min_total(fut_min, e);
	if (c == false && a != 12)   //calc doesnt happen for 12 since am/pm switches at 12 instead of 1                         
	{                            //and 12 pm or am does not need the additional minutes
		int pm_additional_min(int Curr_min_total);       //calls the function to add more minutes to the pm time
		Curr_min_total = pm_additional_min(Curr_min_total);
	}
	else if (a == 12)  //720 minutes must be subtracted in the case of 12 am, to normalize it vs other AMs
	{
		int pm_minus_min(int Curr_min_total);
		Curr_min_total = pm_minus_min(Curr_min_total);
	}
	if (f == false && d != 12)
	{
		int pm_additional_min(int future_min_total);
		future_min_total = pm_additional_min(future_min_total);
	}
	else if (d == 12) //same case as above for 12 am
	{
		int pm_minus_min(int future_min_total);
		Curr_min_total = pm_minus_min(future_min_total);
	}

	if (Curr_min_total > future_min_total)
	{
		int diff_total_greaterthan(int Curr_min_total, int future_min_total);
		difference = diff_total_greaterthan(Curr_min_total, future_min_total);   //function call for greater than answer
	}
	else
	{
		int diff_total_lessthan(int Curr_min_total, int future_min_total);     //function call for less than answer
		difference = diff_total_lessthan(Curr_min_total, future_min_total);
	}

	return difference;   //returns answer for void function
}

int pm_minus_min(int a)
{
	int pm_diff;
	pm_diff = (a - TwelveHourMinutes); //this function minuses 720 minutes, used for 12am
	return pm_diff;
}

int pm_additional_min(int a)
{
	int pm_diff;       //if the time is PM, will add 720 minutes to the total for a military time
	pm_diff = (a + TwelveHourMinutes);
	return pm_diff;
}

int Hrs_min_convert(int a)
{
	int total_min;
	total_min = a * minutes_per_hour;  //multiplies the hour by 60 in order to give how many minutes are in that hour
	return total_min;
}

int min_total(int a, int b)
{
	int total;
	total = a + b; //adds the converted hours to minutes, with the already known minutes
	return total;
}

int diff_total_lessthan(int a, int b)
{
	int less_diff;
	less_diff = (b - a); //minuses the greater from the lesser is the future time is greater in total minutes
	return less_diff;
}

int diff_total_greaterthan(int a, int b)
{
	int greater_diff;
	greater_diff = (TwentyFourHourMinutes - (a - b)); //this case normally happens if the time starts at pm and goes to am
	return greater_diff;                              //this will correct for this and return the correct answer
}

bool AM_Test(char a)
{
	bool AM;
	if (a == 'A' || a == 'a')   //is the user input is A or a, will give a value of true to AM_Test
	{
		AM = true;
	}
	else
		AM = false;
	return AM;
}

//Problem 3/9 Functions
string Pick1(string a, string b, string c, string d)
{
	string TeamChoice;
	int ball = (rand() % 40) + 1; //Random number from 1 to 40, used to pick a ball.
	if (ball <= 20)
		TeamChoice = a;
	else if (ball > 20 && ball <= 30)  //The number chosen is checked against these else ifs to assign it to the
		TeamChoice = b;                //correct team, based on how many balls they were allowed.
	else if (ball > 30 && ball <= 36)
		TeamChoice = c;
	else
		TeamChoice = d;
	return TeamChoice;
}

string Remaining_Choices1(string a, string b, string c, string d, string e)
{
	string Choice2 = a;
	while (Choice2 == a)
	{
		Choice2 = Pick1(b, c, d, e);   //runs the randomizer function to pick a number and assign the pick to a team,
	}                                  //but only returns the result if the result is different from the first pick
	return Choice2;
}

string Remaining_Choices2(string a, string b, string c, string d, string e, string f)
{
	string Choice3 = a;
	while (Choice3 == a || Choice3 == b)
	{
		Choice3 = Pick1(c, d, e, f);  //randomized number function, returning the result only if diff from
	}                                 //first and second choice
	return Choice3;
}

string Final_Choice(string a, string b, string c, string d, string e, string f, string g)
{
	string Choice4 = a;
	while (Choice4 == a || Choice4 == b || Choice4 == c)
	{
		Choice4 = Pick1(d, e, f, g);  //final randomization, different from first, second, and third pick
	}
	return Choice4;
}







//Output



