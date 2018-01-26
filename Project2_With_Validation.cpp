#include <iostream>

using namespace std;

int main() {
    int userInput, sumPos=0, sumNeg=0, sumAll=0;
    const int arraySize = 10;
    int array[arraySize];

    cout << "You will be entering 10 whole numbers\nPlease hit 'enter' after each entry.\n";
    for (int i = 0; i <= 9; i++) {

        cout << "Please enter any whole number: "<< endl;
        //cin >> array[i];

        while(!(cin >> array[i])) {
            cout << "That is not a whole number! Please enter a whole number: " << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            i--;
            cout << "Input any whole number: " << endl;
            cin >> array[i];
           // cin >> array[i];
        }
    }
    cout << "You entered these 10 numbers: ";
    for (int i = 0; i <= 9; i++) {
        cout << array[i] << " ";
    }

    for (int i = 0; i <= 9; i++) {

        if (array[i] > 0) {
            sumPos += array[i];
        } else {
            sumNeg += array[i];
        }
        sumAll += array[i];
    }
    cout << endl;
    cout << array[4];
    cout << "The sum of all numbers greater than zero is: " << sumPos << endl;
    cout << "The sum of all numbers less than zero is: " << sumNeg << endl;
    cout << "The sum of all numbers is: " << sumAll << endl;

}