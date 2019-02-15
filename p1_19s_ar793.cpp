//----------------------------------------------------------------------------------------------------------------------
// Author: Abrar Rouf
// UCID: ar793
// Implementation of DFA for CS 341
//----------------------------------------------------------------------------------------------------------------------
#include <iostream>

using namespace std;

enum State {q1, q2, q3};

int main()
{
    cout << "Project 1 for CS 341\n";
    cout << "Semester: Spring 2019\n";
    cout << "Written by: Abrar Rouf, ar793\n";
    cout << "Instructor: Marvin Nakayama, marvin@njit.edu\n";

    while (true)
    {
        char decision;
        cout << "Do you want to enter a string? (y/n)\n";
        cin >> decision;

        if (decision == 'y')
        {
            char c;
            int i = 0;
            string input;
            State DFA_State = q1;

            cout << "Please enter a string: \n";
            cin >> input;
            cout << input << endl << endl;

            while (i < input.length())
            {
                switch(DFA_State)
                {
                    case q1:
                        cout << " Current state: q1\n\n";
                        if (isalpha(input[i]) && islower(input[i])) DFA_State = q2;
                        break;
                    case q2:
                        cout << "Character read: " << input[i] << endl;
                        cout << " Current state: q2\n\n";
                        i++;
                        if (isalpha(input[i]) && islower(input[i])) continue;
                        else if (input[i] == '@')
                        {
                            DFA_State = q3;
                            break;
                        }
                        break;
                    case q3:
                        cout << "Character read: " << input[i] << endl;
                        cout << " Current state: q3\n\n";
                        i++;
                }
            }
        }
        else if (decision == 'n') break;
    }

    return 0;
}