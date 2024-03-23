/*	Name : Fatima	Roll No. 22i-1074
	section : D		A3
	Q1 header file
*/

#pragma once
#include <iostream>
using namespace std;

template <class T>
class Node {
public:
	T data;
	Node* next;
	Node() {
		data = 0;
		next = NULL;
	}

	Node(T dataToenter) {
		data = dataToenter;
		next = NULL;
	}

};

template<class T>
class Stack {
public:
	Node<T>* top;			// string top (changes in undo & redo)
	Node<T>* EndofStr;		// to keep track of end of string  (will not change in undo & redo)
	
	int backspaceIndex;
	char lastOperation;
	char backspaces[10];

	Stack() {
		top = NULL;
		EndofStr = NULL;
		backspaceIndex = 0;
		//backspaces = new char;		// array to store the backspaced data
		lastOperation = NULL;
	}

	~Stack() {
		Node<T>* temp = top;
		if (temp != NULL) {
			while (temp != NULL) {
				Node<T>* temp2 = temp->next;
				delete temp;
				temp = temp2;
			}
		}
		EndofStr = NULL;
	}

	void push(const T datatoenter) {
		Node<T>* newNodeTOadd = new Node <T>(datatoenter);

		if (!top) {
			top = newNodeTOadd;
			return;
		}

		Node<T>* temp = top;
		top = newNodeTOadd;
		top->next = temp;
		EndofStr = top;
	}

	T pop() {
		Node<T>* temp  = top;
		//temp = top;
		if (temp != NULL) {
			temp = top;
			top = temp->next;
			return temp->data;
		}
		EndofStr = top;
	}

	T peek() {						// return data of top
		Node<T>* temp = top;
		if (temp != NULL)
			return temp->data;
		else {
			cout << "Stack empty" << endl;
			return 0;
		}

	}

	void clear() {
		Node<T>* temp = top;
		while (temp != NULL) {
			Node<T>* temp2 = temp->next;
			delete temp;
			temp = temp2;
		}
		// or 
		top = nullptr;
		cursor = NULL;
	}

	bool isEmpty() {
		if (top == NULL) {
			return true;
		}
		else {
			return false;
		}
	}

	void cursorMovement(char cInput) {			// changes top
		if (cInput == '4') {
			// left
			if (top != NULL) {
				top = top->next;
			}
		}
		else if (cInput == '6') {
			// right
			Node<T>* temp = EndofStr;
			if (temp) {
				while (temp->next != top) {
					temp = temp->next;
				}
				top = temp;
			}
		}
		
	}

	void backspace() {
		if (top != nullptr) {
			Node<T>* temp = top;
			top = top->next;
			backspaces[backspaceIndex] = temp->data;
			temp->data = '@';
		}
		/*Node<T>* temp = EndofStr;
		while (temp != top) {
			temp = temp->next;
		}
		if (EndofStr) {
			EndofStr->next = temp;
			top = EndofStr;
		}*/
		top = EndofStr;
		backspaceIndex++;
		lastOperation = 'b';						// set that last operation done is backspace
	}

	void undo() {
		if (lastOperation == 'b') {
			Node<T>* temp = EndofStr;
			while (temp->data != '@') {
				temp = temp->next;
				if (!temp) {
					break;
				}
			}
			if (temp != NULL) {
				temp->data = backspaces[backspaceIndex - 1];
				backspaceIndex--;
			}
		}
		else if (top != NULL) {
			top = top->next;
		}
		lastOperation = 'u';
	}

	void redo() {
		Node<T>* temp = EndofStr;
		if (temp) {
			while (temp->next != top ) {
				temp = temp->next;
				if (temp == NULL) {
					break;
				}
			}
			if (temp) {				// to remain in the size
				top = temp;
			}
		}
		lastOperation = 'r';
	}

	void print() {
		int j = 0;
		char* resultstr = new char[10];
		Node<char>* current = top;
		while (current) {
			resultstr[j] = current->data;
			j++;
			current = current->next;
			
		}
		resultstr[j] = '\0';

		// print 
		int i = j;
		//cout << endl;
		cout << "Data :";
		while (i >= 0) {
			if (resultstr[i] != '@')
				cout << resultstr[i];
			i--;
		}

	}

};