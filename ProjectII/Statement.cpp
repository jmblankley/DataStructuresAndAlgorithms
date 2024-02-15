/******************************************************************************
 *
 * File:        Statement.cpp
 * Author:      Joshua M Blankley
 * Date: 		2/2024
 * Purpose:     Implementation of the execute function for Statement class.
 *              This file contains the implementation of the execute function
 *              and associated helper functions to execute statements based on
 *              their operation and operands. These changes are an update to
 * 				the exisitng codebase.
 *
 ******************************************************************************/
#include "Statement.hpp"

#include <cstdlib>
#include <iomanip>
#include <iostream>

using namespace std;

int __nextSnum = 0; // keeps track of the next statement number to use.
int __paramValue;	// this is a global to help with passing a parameter.

/****
 **** If you are following project specifications, then you will likley
 **** find this function quite useful. When given an ActivationRecord
 **** (pointer) and a string containing an operand, this function returns
 **** the operand's value (as found in the ActivationRecord.)
 ****/
int getValue(ActivationRecord *ar, const std::string &operand)
{
	if (operand == "$$") // looking for the parameter
		return ar->parameterValue();
	else if (isdigit(operand[0]) || operand[0] == '-') // constant value (int)
	{
		return atoi(operand.c_str());
	}
	else // ID
	{
		// find the variable in the activation record
		Variable *var = (Variable *)ar->getVariable(operand);

		// if the variable was not found, let the user know.
		if (var == NULL)
		{
			cerr << "Attempt to use an uninitialized variable: "
				 << operand << endl;
			return 0;
		}
		else
			return var->value(); // return value of the associated variable
	}
}

/****
 **** If you are following project specifications, then you will likley
 **** find this function quite useful. When given an ActivationRecord
 **** (pointer), a string containing an variable name, and a new value,
 **** this function sets that variable to the new value (in the associated
 **** ActivationRecord.) If the variable isn't found in the Activation
 ***  Record, it is added to the ActivationRecord.
 ****/
void setValue(ActivationRecord *ar, const std::string &varName, int toVal)
{
	if (varName == "$$") // parameter
		ar->parameterValue() = toVal;
	else // anything else must be a variable
	{
		// get the Variable from the ActivationRecord
		Variable *var = (Variable *)ar->getVariable(varName);

		// no such variable? Means we need to add it to the ActivationRecord
		if (var == NULL)
		{
			ar->addVariable(varName);
			var = (Variable *)ar->getVariable(varName);
		}

		// now that we know we have a variable, set its value ...
		var->value() = toVal;
	}
}

//
// ********   YOU MUST CODE LARGE PARTS OF THIS !!!!   **********
//
// Executes a statement. See the project handout for details. Some
//  initial statements are given as examples.
//
//     withStack - The ActivationRecord (i.e. execution)  stack to use
//     ft - the table of function names & starting points
//
//  *should return the statement number (ddress) of the next statement to run
int Statement::execute(Stack &withStack, const FunctionTable &ft) const
{
	// the next statement will be 1 after this one ... with the exception
	//  of calls, rets, and skips (see project handout.)
	int nextAddr = _snum + 1;

	if (_operation == "printS") // print string.
	{
		cout << _operands.front();
	}
	else if (_operation == "printN") // print number
	{
		// get the value to print from the current activation record.
		int valueOfN = getValue(withStack.top(), _operands.front());

		// print that value
		cout << valueOfN;
	}
	else if (_operation == "printNL") // drop down a line in output
	{
		cout << endl; // yep, it's that simple!
	}
	else if (_operation == "call")
	{
		// Get the function name
		string funcName = this->operands().front();

		// Get the next statement number
		int nextStatementNumber = nextAddr;

		// Construct ActivationRecord with function name, next statement number, and parameter value, then push it onto the stack
		ActivationRecord *ar = new ActivationRecord(funcName, nextStatementNumber, __paramValue);
		withStack.push(ar);

		// Get the first statement number of the called function from the FunctionTable
		Function func = ft.lookup(funcName);
		int newAddr = func.firstInstruction();

		// Update nextAddr to the first statement number of the called function
		nextAddr = newAddr;

		// Set the return value to be the first statement number in the called function
		return nextAddr;
	}

	else if (_operation == "ret")
	{
		// pop the top item from the stack
		ActivationRecord *popped = withStack.pop();

		// get the return address for this ActivationRecord
		int addr = popped->returnAddress();

		// updated nextAddr with the return address from the popped ActivationRecord
		nextAddr = addr;
	}
	else if (_operation == "retv")
	{
		// place it into the “incoming return value” of the Activation Record found one beneath the top element found on the stack
		string op = this->operands().front();
		ActivationRecord *peeker = withStack.peek();
		peeker->incomingReturnValue() = getValue(withStack.top(), op);

		// pop the ActivationRecord from the stack
		ActivationRecord *popped = withStack.pop();

		// update nextAddr to the return address from the popped ActivationRecord
		int addr = popped->returnAddress();
		nextAddr = addr;
	}
	else if (_operation == "storet")
	{
		// Get the operand
		string operand = this->operands().front();

		// Get the incoming return value from the top Activation Record on the stack
		int incomingReturnValue = withStack.top()->incomingReturnValue();

		// Set the value of the operand to be equal to the incoming return value
		setValue(withStack.top(), operand, incomingReturnValue);
	}
	else if (_operation == "param")
	{
		// Get the operand
		string operand = _operands.front();

		// Set the global variable __paramValue to be equal to the value of the operand
		__paramValue = getValue(withStack.top(), operand);
	}
	else if (_operation == "sub")
	{
		// Get the operands from the statement
		string a = this->operands().front();
		auto sec = next(this->operands().begin(), 1);
		string b = *sec;

		// Subtract the values obtained from the stack
		int c = getValue(withStack.top(), a) - getValue(withStack.top(), b);

		// Get the variable name to store the result
		string varName = *next(_operands.begin(), 2);

		// Set the value of the variable with the result
		setValue(withStack.top(), varName, c);
	}
	else if (_operation == "add")
	{
		// Get the operands from the statement
		string a = _operands.front();
		auto sec = next(_operands.begin(), 1);
		string b = *sec;

		// Add the values obtained from the stack
		int c = getValue(withStack.top(), a) + getValue(withStack.top(), b);

		// Get the variable name to store the result
		string varName = *next(_operands.begin(), 2);

		// Set the value of the variable with the result
		setValue(withStack.top(), varName, c);
	}
	else if (_operation == "mul")
	{
		// Get the operands from the statement
		string a = _operands.front();
		auto sec = next(_operands.begin(), 1);
		string b = *sec;

		// Multiply the values obtained from the stack
		int c = getValue(withStack.top(), a) * getValue(withStack.top(), b);

		// Get the variable name to store the result
		string varName = *next(_operands.begin(), 2);

		// Set the value of the variable with the result
		setValue(withStack.top(), varName, c);
	}
	else if (_operation == "div")
	{
		// Get the operands from the statement
		string a = _operands.front();
		auto sec = next(_operands.begin(), 1);
		string b = *sec;

		// Divide the values obtained from the stack
		int c = getValue(withStack.top(), a) / getValue(withStack.top(), b);

		// Get the variable name to store the result
		string varName = *next(_operands.begin(), 2);

		// Set the value of the variable with the result
		setValue(withStack.top(), varName, c);
	}
	else if (_operation == "div")
	{
		// Get the operands from the statement
		string a = _operands.front();
		auto sec = next(_operands.begin(), 1);
		string b = *sec;

		// Divide the values obtained from the stack
		int c = getValue(withStack.top(), a) / getValue(withStack.top(), b);

		// Get the variable name to store the result
		string varName = *next(_operands.begin(), 2);

		// Set the value of the variable with the result
		setValue(withStack.top(), varName, c);
	}
	else if (_operation == "skipnz")
	{
		// Get the operands from the statement
		string firstOp = this->operands().front();
		auto sec = next(this->operands().begin(), 1);
		string secOp = *sec;

		// Get the values from the stack
		int zero = getValue(withStack.top(), firstOp);
		int numToSkip = getValue(withStack.top(), secOp);

		// If the first operand is not zero, skip the specified number of statements
		if (zero != 0)
		{
			nextAddr += numToSkip;
		}
	}
	else if (_operation == "read")
	{
		// Get the variable name from the statement
		string varName = this->operands().front();

		// Read an integer value from the user
		int input;
		cin >> input;

		// Set the value of the specified variable in the top ActivationRecord
		ActivationRecord *in = withStack.top();
		setValue(in, varName, input);
	}
	else if (_operation == "dump")
	{
		// printing out the stack
		cout << endl
			 << withStack << endl;
	}
	else
	{
		cout << _operation << ": not implememnted" << endl;
	}
	return nextAddr;
}

// prints out this statement to the specified stream (overloads <<)
ostream &operator<<(ostream &os, const Statement &s)
{
	// print the statement number in the specified width.
	os.width(5);
	os << s._snum << " ";

	// print the operation
	os << s._operation << '\t';

	// print each operand ..
	list<string>::const_iterator lsci = s._operands.begin();
	for (int i = 0; i < s._operandCount; i++)
	{
		os << *lsci << " ";

		lsci++;
	}

	return os;
}
