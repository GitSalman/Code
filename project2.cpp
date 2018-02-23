/*
+Created by Salman Iqbal on 2/13/2018.
+Homework #3, project #2
+Program developed to compute what coins to give out for any amount of change from 1 cent to 99 cents.
*/

#include <iostream>
#include <limits>
using namespace std;

int num, amount_left;

void compute_coins(int coin_value, int& num, int& amount_left);

int main() {

    cout << "=========================" << endl;
    cout << "|          Coin         |" << endl;
    cout << "|         Change        |" << endl;
    cout << "|       Calculator      |" << endl;
    cout << "=========================" << endl;

    cout << "This program will compute your clothing sizes.\n\n";

    char reCalculate;

    do {
        do {
            cout << "Please input the amount of change from 1 cent to 99 cents: ";
            cin >> amount_left;
            //PreCondition:  0 < AmtChange < 100, 0 <= AmtLeft < 100, valid number
            while (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Please enter a valid number between 1 and 99!\n"
                     << "Input the amount of change from 1 to 99 cents: ";
                cin >> amount_left;
            }
            if (amount_left < 0 || amount_left >= 100)
            {
                cout << "You must enter a number between 1 and 99!" << endl;
            }
        } while (amount_left < 0 || amount_left >= 100);


        compute_coins(25, num, amount_left);
        cout << "Quarters: " << num << "\n";
        compute_coins(10, num, amount_left);
        cout << "Dimes:    " << num << "\n";
        compute_coins(1, num, amount_left);
        cout << "Pennies:  " << num << "\n";

        cout << "Would you like to input another amount of change? (Y/N): ";
        cin >> reCalculate;
        reCalculate = toupper(reCalculate);

    } while (reCalculate == 'Y');
}
/*PreCondition:  0 < AmtChange < 100, 0 <= AmtLeft < 100
PostCondition: num has been set equal to the max number of coins of denomination CoinValue cents
that can be obtained from AmtLeft. Additionally, AmtLeft remaining value becomes the
 remainder of amount_left divided by coin_value*/

void compute_coins(int coin_value, int& num, int& amount_left)
{
if ((coin_value > 0 && coin_value < 100) && (amount_left >= 0 && amount_left < 100))
{
    num = (amount_left / coin_value);
    amount_left %= coin_value;
}
}
