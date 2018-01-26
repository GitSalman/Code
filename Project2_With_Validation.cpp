#include <iostream>

using namespace std;

#include <limits>

int main() {
    //std::cout << "Hello, World!" << std::endl;
    //return 0;
    int userInput;
    const int arraySize = 10;
    int array[arraySize];

    for (int i = 0; i <= 9; i++) {
        cout << "Input any whole number: " << endl;
        cin >> array[i];

        while(!(cin >> array[i])) {
            cout << "That is not a whole number! Please enter a whole number: " << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            i--;
            cout << "Input any whole number: " << endl;
            cin >> array[i];
           // cin >> array[i];
        }
        //cout << "You entered " << array[i] << "." << endl;

    }
    cout << "You entered these 10 numbers: ";
    for (int i = 0; i <= 9; i++) {
        cout << array[i] << ", ";
    }
}