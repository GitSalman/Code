/*
+Created by Salman Iqbal on 1/31/2018.
+Homework #2, project #1
+Program developed to compute the cost of a long-distance call.
+Lots of validation added, so sorry if this is hell broken
*/

#include <iostream>
#include <sstream>
#include <string.h>


using namespace std;


string weekDay(char, char);

string timeCheck(string);

string finalTime, delimiter = ":";

int timeStringToInt(string);

float costOfCall(string testDay, int finalTimeInt, int talkTime);

int finalTimeInt = 0;

char timeArray[4];


int main() {

    char reCalculate;

    do {
        string day, testDay, timeOfDay, time;
        int talkTime;
        char timeArray[4];

        cout << "=========================" << endl;
        cout << "|     Long-Distance     |" << endl;
        cout << "|         Call          |" << endl;
        cout << "|         Cost          |" << endl;
        cout << "=========================" << endl;

        cout << "This program will compute the cost of a long-distance call.\n\n";

        do {
            cout << "What day of the week did you make the call?: ";
            cin >> day;

            char day1 = toupper(day.at(0));
            char day2 = toupper(day.at(1));

            testDay = weekDay(day1, day2);

        } while (testDay != "weekday" && testDay != "weekend");

        cout << "You entered " << day << " (" << testDay << ").\n";

        cout << "What time did your call start? Please input in 24-hour notation (##:##): ";

        cin >> time;

        timeStringToInt(time);

        cout << "Please enter the length of your call in minutes (rounded to the nearest minute): ";
        cin >> talkTime;

        cout << "The cost of your call is: $" << costOfCall(testDay, finalTimeInt, talkTime) << endl;

        cout << "Would you like to calculate the cost of another call? (Y/N)" << endl;
        cin >> reCalculate;
        reCalculate = toupper(reCalculate);

    } while (reCalculate == 'Y');

}

string weekDay(char day1, char day2) {
    if (day1 == 'M' && day2 == 'O') {
        string setDay = "weekday";
        return setDay;
    } else if (day1 == 'T' && day2 == 'U') {
        string setDay = "weekday";
        return setDay;
    } else if (day1 == 'W' && day2 == 'E') {
        string setDay = "weekday";
        return setDay;
    } else if (day1 == 'T' && day2 == 'H') {
        string setDay = "weekday";
        return setDay;
    } else if (day1 == 'F' && day2 == 'R') {
        string setDay = "weekday";
        return setDay;
    } else if (day1 == 'S' && day2 == 'A') {
        string setDay = "weekend";
        return setDay;
    } else if (day1 == 'S' && day2 == 'U') {
        string setDay = "weekend";
        return setDay;
    } else {
        string setDay = "Invalid input! Please reenter a day of the week!\n\n";
        cout << setDay;
        return setDay;
    }
}


float costOfCall(string testDay, int finalTimeInt, int talkTime) {

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    bool timeCompare = false;
    if (finalTimeInt >= 800 && finalTimeInt <= 1800) {
        timeCompare = true;
    }
    float callCost = 0.f;
    if (testDay.compare("weekday") == 0) {
        if (timeCompare) callCost = .4;
        else callCost = .25;
    } else callCost = .15;
    return (talkTime * callCost);
}

string timeCheck(string time) {
    while (time.length() != 5) {
        cout << "Please enter a valid time in the format of (##:##): ";
        cin >> time;
    }

    return time;
}

int timeStringToInt(string time) {

    int alphabet = 0, number = 0, i;

    do {

        timeCheck(time);


        string timeToken1 = time.substr(0, time.find(delimiter));
        string timeToken2 = time.substr(3, 2);

        finalTime = timeToken1 + timeToken2;

        strncpy(timeArray, time.c_str(), 4);


        for (i = 0; timeArray[i] != '\0'; i++) {
            // check for alphabet
            if (isalpha(timeArray[i]) != 0)
                alphabet++;

                // check for decimal digits
            else if (isdigit(timeArray[i]) != 0)
                number++;
        }

        stringstream finalTimeToInt(finalTime);

        finalTimeToInt >> finalTimeInt;


    } while ((number != 4) && (finalTimeInt < 0 || finalTimeInt > 2400));

    return finalTimeInt;
}