# FunctionCalling
Exercise puts into practice solving the given problems with maximum use of Function Calling

Problem 1: 
Write a program that computes the annual after-tax cost of a new house for the first year of ownership. The cost is computed
as the annual mortgage cost minus the tax savings. The input should be the price of the house and the down payment. The annual mortgage
cost can be estimated as 3 percent of the initial loan balance credited toward paying off the loan principal plus 6 percent of the initial
loan balance in interest. The initial loan balance is the price minus the down payment. Assume a 35 percent marginal tax rate and assume
that the interest payments are tax deductible. So, the tax savings is 35 percent of the interest payment. Your program should use at least
two function definitions and should allow the user to repeat this caluclation as often as the user wishes.

Problem 7:
Your time machine is capable of going foward in time up to 24 hours. The machine is configured to jump ahead in minutes. To enter the
proper number of minutes into your machine, you would like a program that can take a start time (in hours, minutes, and a Boolean
indicating AM or PM) and a future time (in hours, minutes, and a Boolean indicating AM and PM) and calculate the difference in minutes
between the start and future time.
A time is specified in your program with three variables:

int hours, minutes;
bool isAM;

For example, to represent 11:50 AM, you would store:

hours = 11
minutes = 50
isAM = false;

That means that you need six variables to store a start and future time.

Write a program that allows the user to enter a start time and a future time. Include a function named computeDifference that takes
the six variables as parameters that represent the start time and future time. Your function should return, as an int, the time 
difference in minutes. For example, given a start time of 11:59 AM and a future time of 12:01 PM, your program should compute 2 minutes
as the time difference. Given a start time of 11:59 AM and a future time of 11:58 AM, your program should compute 1439 minutes as the
time difference (23 hours and 59 minutes).

You may need "AM" or "PM" from the user's input by reading in two character values. Characters can be compared just like numbers. 
For example, if the variable a_char is of type char, then (a_char == 'A') is a Boolean expression that evaluates to true if 
a_char contains the letter A.

Problem 9:

Your sports league uses the following lottery system to select draft picks for the four worst teams in the league:

* The last place team gets 20 balls in an urn.
* The second-to-last place team gets 10 balls in the urn.
* The third-to-last place team gets 6 balls in the urn.
* The fourth-to-last place team gets 4 balls in the urn.

TO determine the first pick in the draft a ball is selected at random. The team owning that ball gets the first pick. The ball is then
put back in the urn.
To determine the second pick in the draft, a ball is selected at random. If the ball belongs to the team that got the first pick 
then it is put back in and the process repeats until a ball is selected that does not belong to the first pick.
To determine subsequent picks in the draft, the process repeats until a ball is selected that belongs to a team that has not already
been chosen.
Write a function that takes as input which of the four teams have already been granted picks, simulates selecting a ball from the urn
according to the lottery rules, and returns the team that belongs to the selected ball. You get to choose how to design your function
to preform these actions. Write a main function that outputs the draft order (e.g., a possible order is: second-to-last picks 1, last 
place picks 2, third-to-last picks 3, and fourth-to-last picks 4). IF you change the random seed then the order should differ if you
run the program multiple times.
For a slightly harder version of the problem, allow the user to input the names of the four teams. The program should then output
the team names in the draft order.
