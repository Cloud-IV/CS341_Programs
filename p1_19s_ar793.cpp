//----------------------------------------------------------------------------------------------------------------------
// Author: Abrar Rouf
// UCID: ar793
// (CS 341) Project 1: Implementation of DFA for Language L
//----------------------------------------------------------------------------------------------------------------------
#include <iostream>

using namespace std;

enum State {q1, q2, q3, q4, q5, q6, q7, q8, q9, q10};   //will be used for switch statement

int main()
{
    cout << "Project 1 for CS 341\n";
    cout << "Semester:  Spring 2019\n";
    cout << "Written by:  Abrar Rouf, ar793\n";
    cout << "Instructor:  Marvin Nakayama, marvin@njit.edu\n\n";

    while (true)    //loops until user inputs 'n' when prompted to continue or not
    {
        char decision;  //holds 'y' or 'n' depending on user input
        cout << "Do you want to enter a string? (y/n)\n";
        cin >> decision;

        if (decision == 'y')        //if decision is 'y', proceeds to ask user for string to be read
        {
            unsigned int i = 0;     //used to control what character of the user-inputted string is being read
            string input;           //will hold value of user-inputted string
            State DFA_State = q1;   //initializes state of DFA to q1
            bool acceptState = false;   //keeps track of whether DFA is in accept state or not

            cout << "Please enter a string: \n";
            cin >> input;
            cout << input << endl << endl;  //prints out user-inputted string as specified

            while (i < input.length())  //will process user string as long as i < length of the string
            {
                switch(DFA_State)
                {
                    case q1:    //initial state: proceeds to q2 if a symbol from ⌈ is read, otherwise proceeds to q10
                        cout << " Current state: q1\n\n";   //every state will have this to print out the current state
                        if (isalpha(input[i]) && islower(input[i])) DFA_State = q2; //checks if character is from ⌈
                        else if (input[i] == '.' || input[i] == '@') DFA_State = q10;
                        break;
                    case q2:    //stays in q2 if symbol is from ⌈; proceeds to q3/q9 if '@' or '.' is read, respectively
                        cout << "Character read: " << input[i] << endl; //in every state onward; prints symbol that
                        cout << " Current state: q2\n\n";               //caused transition to current state
                        i++;                                            //proceeds to next character in user string
                        if (isalpha(input[i]) && islower(input[i])) continue;
                        else if (input[i] == '@') DFA_State = q3;
                        else if (input[i] == '.') DFA_State = q9;
                        break;
                    case q3:    //proceeds to q4 if symbol is from ⌈; moves to q10 otherwise
                        cout << "Character read: " << input[i] << endl;
                        cout << " Current state: q3\n\n";
                        i++;
                        if (isalpha(input[i]) && islower(input[i])) DFA_State = q4;
                        else if (input[i] == '.' || input[i] == '@') DFA_State = q10;
                        break;
                    case q4:    //stays in q4 if symbol is from ⌈; moves to q5 if symbol is '.' or to q10 if '@'
                        cout << "Character read: " << input[i] << endl;
                        cout << " Current state: q4\n\n";
                        i++;
                        if (isalpha(input[i]) && islower(input[i])) continue;
                        else if (input[i] == '.') DFA_State = q5;
                        else if (input[i] == '@') DFA_State = q10;
                        break;
                    case q5:    //goes back to q4 if symbol is from ⌈-c; goes to q6 if 'c'; goes to q10 otherwise
                        cout << "Character read: " << input[i] << endl;
                        cout << " Current state: q5\n\n";
                        i++;
                        if (isalpha(input[i]) && islower(input[i]) && input[i] != 'c') DFA_State = q4;
                        else if (input[i] == 'c') DFA_State = q6;
                        else if (input[i] == '.' || input[i] == '@') DFA_State = q10;
                        break;
                    case q6:    //goes back to q4 if symbol is from ⌈-o; goes to q7 if 'o'; goes to q5 if symbol is '.';
                        cout << "Character read: " << input[i] << endl; //goes to q10 otherwise
                        cout << " Current state: q6\n\n";
                        i++;
                        if (isalpha(input[i]) && islower(input[i]) && input[i] != 'o') DFA_State = q4;
                        else if (input[i] == 'o') DFA_State = q7;
                        else if (input[i] == '.') DFA_State = q5;
                        else if (input[i] == '@') DFA_State = q10;
                        break;
                    case q7:    //goes back to q4 if symbol is from ⌈-m; goes to q8 if 'm'; goes to q5 if symbol is '.';
                        cout << "Character read: " << input[i] << endl; //goes to q10 otherwise
                        cout << " Current state: q7\n\n";
                        i++;
                        if (isalpha(input[i]) && islower(input[i]) && input[i] != 'm') DFA_State = q4;
                        else if (input[i] == 'm') DFA_State = q8;
                        else if (input[i] == '.') DFA_State = q5;
                        else if (input[i] == '@') DFA_State = q10;
                        break;
                    case q8:    //goes to q5 if symbol is '.', to q10 if symbol is '@', to q4 if symbol is from ⌈
                        cout << "Character read: " << input[i] << endl;
                        cout << " Current state: q8\n\n";
                        acceptState = true; //changes to true since q8 is an accept state
                        i++;
                        if (isalpha(input[i]) && islower(input[i]))
                        {
                            DFA_State = q4;
                            acceptState = false;    //changes to false since DFA is leaving q8
                        }
                        else if (input[i] == '.')
                        {
                            DFA_State = q5;
                            acceptState = false;
                        }
                        else if (input[i] == '@')
                        {
                            DFA_State = q10;
                            acceptState = false;
                        }
                        break;
                    case q9:    //goes to q2 if symbol is from ⌈, otherwise goes to q10
                        cout << "Character read: " << input[i] << endl;
                        cout << " Current state: q9\n\n";
                        i++;
                        if (isalpha(input[i]) && islower(input[i])) DFA_State = q2;
                        else if (input[i] == '.' || input[i] == '@') DFA_State = q10;
                        break;
                    case q10:   //trap state; DFA can never leave once in trap state
                        cout << "Character read: " << input[i] << endl;
                        cout << " Current state: q10\n\n";
                        i++;
                        continue;   //no need to check what symbol is being read, but any symbol from Σ is valid
                }
            }
            if (acceptState) cout << "DFA ended in accept state q" << DFA_State+1 << "; string \"" << input << "\" accepted.\n";
            else cout << "DFA ended in non-accept state q" << DFA_State+1 << "; string \"" << input << "\" rejected.\n";
        }
        else if (decision == 'n') break;    //breaks out of loop of prompting user for more strings
    }

    return 0;
}