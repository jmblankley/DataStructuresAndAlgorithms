// !!!!!! You will have to add code inside of this class. Some of
//        the code provided here is designed to help you, but you
//         do not need to use it if you do not want to.

#include "Statement.hpp"

#include <cstdlib>
#include <iomanip>
#include <iostream>

using namespace std;

int __nextSnum = 0; // keeps track of the next statement number to use.
int __paramValue;   // this is a global to help with passing a parameter.

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
  else if (_operation == "call") /////  HERE IS WHERE YOU NEED TO START ADDING CODE TO EXECUTE
  {
    // get the function name
    string funcName = _operands.front();

    // construct ActivationRecord with function name, nextAddr, and the parameter value then push to stack
    ActivationRecord *ar = new ActivationRecord(funcName, nextAddr, __paramValue);
    withStack.push(ar);

    // Get first statement number
    Function func = ft.lookup(funcName);
    int newAddr = func.firstInstruction();

    // Update nextAddr with the new address
    nextAddr = newAddr;
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
    string op = _operands.front();
    ActivationRecord *peeker = withStack.peek();
    peeker->incomingReturnValue() = stoi(op);

    // pop the ActivationRecord from the stack
    ActivationRecord *popped = withStack.pop();

    // update nextAddr to the return address from the popped ActivationRecord
    int addr = popped->returnAddress();
    nextAddr = addr;
  }
  else if (_operation == "storet")
  {
    // get operand
    string op = _operands.front();

    // get AR from the top of the stack
    ActivationRecord *top = withStack.top();

    // set incoming return value to the operand
    top->incomingReturnValue() = stoi(op);
  }
  else if (_operation == "param")
  {
    __paramValue = stoi(_operands.front());
  }
  else if (_operation == "sub")
  {
    int a = stoi(_operands.front());
    auto sec = next(_operands.begin(), 1);
    int b = stoi(*sec);

    int c = a - b;
  }
  else if (_operation == "add")
  {
    int a = stoi(_operands.front());
    auto sec = next(_operands.begin(), 1);
    int b = stoi(*sec);

    int c = a + b;
  }
  else if (_operation == "mul")
  {
    int a = stoi(_operands.front());
    auto sec = next(_operands.begin(), 1);
    int b = stoi(*sec);

    int c = a * b;
  }
  else if (_operation == "div")
  {
    int a = stoi(_operands.front());
    auto sec = next(_operands.begin(), 1);
    int b = stoi(*sec);

    int c = a / b;
  }
  else if (_operation == "skipz")
  {
    int zero = stoi(_operands.front());
    auto sec = next(_operands.begin(), 1);
    int numToSkip = stoi(*sec);

    if (zero == 0)
    {
      nextAddr += numToSkip;
    }
  }
  else if (_operation == "skipnz")
  {
    int zero = stoi(_operands.front());
    if (zero == 0)
    {
      auto sec = next(_operands.begin(), 1);
      int numToSkip = stoi(*sec);

      nextAddr += numToSkip;
    }
  }
  else if (_operation == "read")
  {
    string input;
    cin >> input;

    ActivationRecord *read = withStack.pop();

    setValue(read, input, nextAddr);
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
