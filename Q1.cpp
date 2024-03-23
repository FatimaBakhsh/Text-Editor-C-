/*	Name : Fatima	Roll No. 22i-1074
	section : D		A3 
	Q1 cpp file
*/

#include <iostream>
#include "pch.h"
#include "Q1.h"
using namespace std;

int main() {
	Stack<char> objStack;
	bool input = true;

	cout << "Enter the data string, to END enter [0]";
	while (input) {
		cout << endl;
		char cInput;
		cin >> cInput;
		
		if (cInput == 'b' || cInput == 'B') {				// backspace
			objStack.backspace();
		}
		else if (cInput == 'u' || cInput == 'U') {			// undo
			objStack.undo();
		}
		else if (cInput == 'r' || cInput == 'R') {			// redo
			objStack.redo();
		}
		else if (cInput == '4' || cInput == '6') {			// cursor movement
			objStack.cursorMovement(cInput);
		}
		else if (cInput == '0') {							// end
			input = false;
		}
		else {
			objStack.push(cInput);							// data enter
		}

		objStack.print();
	}


	return 0;
}