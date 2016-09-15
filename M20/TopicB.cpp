//
//  TopicB.cpp
//  Topic B Project
//
//  Created by Dak Washbrook on 9/13/16.
//
//  Current Project Status: COMPLETED - It compiles and works. This is the extra credit version.
//  Tested on XCode
//  Tested on VStudio
//

#include <iostream>
#include <string>
#include "LinkedStack.h"
#include "LinkedQueue.h"

/**
* Enable or disable Extra credit functionality.
*
* @var bool    EXTRA_CREDIT
*/
const bool EXTRA_CREDIT = true;

/**
* Helper functions
* See TopicB.cpp
*/
void output(std::string message);
std::string getInput(std::string question);
void endProgram(const int returnValue);

template<typename T>
bool fillQueueFromFile(LinkedQueue<T>& queue, std::string filename);

LinkedStack<char> stringToStack(std::string line);

template<typename T>
void examineQueue(LinkedQueue<T>& queue);

template<typename T>
bool isBalanced(LinkedStack<T> stack);

int main() {
    
    output("Create queue object lq");
	LinkedQueue<std::string> lq;
    
    output("Get the file input");
    std::string filename;
    do {
        filename = getInput("Enter input file name");
    } while (!fillQueueFromFile(lq, filename));
    
    output("After getting the file input, test other functions*******");
    
    output("Create lg1, a copy of queue.");
	LinkedQueue<std::string> lq1{ lq };
    
    output("Display the contents of the copy queue lq1:");
    std::cout << lq1 << std::endl << std::endl;
    
    output("Attempt to peek the now empty copy queue lq1:");
    try {
        lq1.peekFront();
    } catch (PrecondViolatedExcept& e) {
        output(e.what());
    }
    
    output("Assign lq to lq1 and then display lq1:");
    lq1 = lq;
    std::cout << lq1 << std::endl << std::endl;
    
    output("Put the first string in lq into a stack of chars, ls1");
	LinkedStack<char> ls1 = stringToStack(lq.peekFront());
    
    output("Create a copy, ls2, of the stack and display the copy:");
    LinkedStack<char> ls2{ ls1 };
    
    std::cout << ls2;
    
    output("Assign the first stack, ls1, to the second stack, ls2, and then display the second stack:");
    ls2 = ls1;
    
    std::cout << ls2;
    
    output("Do the expression checking:");
    
	examineQueue(lq);
    
    output("Program Over.");
    
    endProgram(0);
    return 0;
}

/**
 * Output message to console.
 * 
 * @param   std::string message
 */
void output(std::string message) {
    std::cout << message << std::endl << std::endl;
}

template<typename T>
void examineQueue(LinkedQueue<T>& queue) {
	std::string line;
	while (!queue.isEmpty()) {
		line = queue.peekFront();
		output("The next string is:   " + line);
		LinkedStack<char> checker = stringToStack(line);
		(isBalanced(checker)) ? output("   is a correct expression.") : output("   is NOT a correct expression.");
		queue.dequeue();
	}
}

/**
 * Get user inputer and return it.
 *
 * @param   std::string question
 * @return  std::string answer
 */
std::string getInput(std::string question) {
    std::string answer;
    std::cout << question << ": ";
    std::cin >> answer;
    return answer;
}

/**
 * End Program Message
 */
void endProgram(const int code) {
    std::cout << "Press Enter to end -->  ";
	std::cin.ignore();
	std::cin.ignore();
    exit(code);
}

template<typename T>
bool fillQueueFromFile(LinkedQueue<T>& queue, std::string filename) {
	std::string line;
	std::ifstream file{ filename };
	if (file.is_open()) {
		while (getline(file, line)) {
			queue.enqueue(line);
		}
	}
	else {
		file.clear();
		file.close();
		std::cout << filename << " cannot be opened." << std::endl;
	}
	bool good{ file.is_open() };
	file.close();
	return good;
}

LinkedStack<char> stringToStack(std::string line) {
	LinkedStack<char> stack;
	bool FLAG{ false };
	for (char& character : line) {
		if (EXTRA_CREDIT) {
			if (character == '\\') {
				FLAG = true;
				continue;
			}
			if (FLAG) {
				FLAG = false;
				continue;
			}
		}
		stack.push(character);
	}
	return stack;
}

/**
* Checks if the stack has token balance.
*
* @return  bool
*/
template<typename T>
bool isBalanced(LinkedStack<T> stack) {
	int parenthesis = 0, brackets = 0, braces = 0, singleQuotes = 0, doubleQuotes = 0;

	// For each on the stack, determine the token and pop it off the stack.
	while (!stack.isEmpty()) {
		switch (stack.peek()) {
		case '{':
			braces--;
			break;
		case '}':
			braces++;
			break;
		case '[':
			brackets--;
			break;
		case ']':
			brackets++;
			break;
		case '(':
			parenthesis--;
			break;
		case ')':
			parenthesis++;
			break;
		case '\'':
			singleQuotes++;
			break;
		case '"':
			doubleQuotes++;
		default:
			break;
		}
		stack.pop();
	}
	// If all checks are passed it returns true, else false.
	if (parenthesis == 0 &&
		brackets == 0 &&
		braces == 0 &&
		(singleQuotes % 2 == 0) &&
		(doubleQuotes % 2 == 0)) {
		return true;
	}
	else {
		return false;
	}
}
