/*
    File name: lab_2a.cpp
    Date: 1/31/2023
    Author: Kayla Humphrey
    Purpose: A test to gauge the user's knowledge of the Super Bowl.
*/
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int userAnswer = 0;
    int correctAnswers = 0;
    double totalQuestions = 3.0; //double to fix integer divison problems 
    double grade = 0.0;
    cout << "\n\n********** Super Bowl Test **********";
    /*
        This is the question segment. 
        A question is asked and the user is prompted for their answer.
        Then, their answer is read and stored to userAnswer.
        If the answer is correct, correctAnswers goes up by one.
        Otherwise, correctAnswers does not change and it goes to the next question.
    */
    cout << "\n\nHow well do you know the Super Bowl? Answer the questions without cheating :)" 
         << "\n\n1) What two teams are playing in the 2023 Super Bowl?"
         << "\n1. The Eagles vs. the Chiefs"
         << "\n2. The Cowboys vs. the Packers"
         << "\n3. The Patriots vs. the Steelers"
         << "\n4. The Dolphins vs. the Ravens"
         << "\n(Enter 1, 2, 3, or 4):  ";
    cin >> userAnswer;
    if(userAnswer == 1)
    {
        correctAnswers += 1;
    }

    cout << "\n\n2) Where is the 2023 Super Bowl being held?"
         << "\n1. Miami, Florida"
         << "\n2. Nashville, Tennessee"
         << "\n3. Glendale, Arizona"
         << "\n4. New Orleans, Louisiana"
         << "\n(Enter 1, 2, 3, or 4):  ";
    cin >> userAnswer;
    if(userAnswer == 3)
    {
        correctAnswers += 1;
    }

    cout << "\n\n3) What year was the first Super Bowl?"
         << "\n1. 1918"
         << "\n2. 1631"
         << "\n3. 2020"
         << "\n4. 1967"
         << "\n(Enter 1, 2, 3, or 4):  ";
    cin >> userAnswer;
    if(userAnswer == 4)
    {
        correctAnswers += 1;
    }
    
    //Calculation of the final grade.
    grade = (correctAnswers / totalQuestions) * 100;
    //output of final grade
    cout << "\n********************************"
         << "\nCongrats! Your final grade is " << grade << "." 
         << "\n********************************";

    return 0;

}
