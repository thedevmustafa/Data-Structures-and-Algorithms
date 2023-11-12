// Evaluating postfix expression
// Declarations are imported from list.cpp file

#include "list.cpp"
#include "string"
#include "sstream"
#include "cmath"

// Function to check if value is operator
bool isOpcode(string opcode)
{
    string list = "+-*/^";
    if (list.find(opcode) < 5)
        return true;
    else
        return false;
}

// Function to check if value is number
bool isNum(string data)
{
    try
    {
        stof(data);
        return true;
    }
    catch (invalid_argument)
    {
        return false;
    }
}

// Function for performing operations
double performOpr(double operand1, double operand2, string opr)
{
    if (opr == "+")
    {
        return operand1 + operand2;
    }
    else if (opr == "-")
    {
        return operand1 - operand2;
    }
    else if (opr == "*")
    {
        return operand1 * operand2;
    }
    else if (opr == "/")
    {
        return operand1 / operand2;
    }
    else if (opr == "^")
    {
        return pow(operand1, operand2);
    }
    else
        return 0;
}

double evaluate(string postfix)
{
    singly_linked_list stack = singly_linked_list(); // Stack created for storing the values
    stringstream ss(postfix);
    string token;
    while (ss >> token)
    {
        if (isNum(token)) // Condition 1: if token is number, throw it into the stack
        {
            stack.add(token);
        }
        else if (isOpcode(token)) // Condition 2: if operator, then pop out the operands from stack and perfom operation
        {
            double operand2 = stof(stack.last());
            stack.remove_end();
            double operand1 = stof(stack.last());
            stack.remove_end();
            float result = performOpr(operand1, operand2, token);
            stack.add(to_string(result));
        }
        else // Conditon 3: if invalid token, then close the program with error message
        {
            cout << "Error!: Wrong Input" << endl;
            exit(0);
        }
    }
    return stof(stack.last()); // Convert the string to double and return to the caller
}

int main()
{
    string postfix;
    cout << "Enter Postfix expression: ";
    getline(cin, postfix);
    cout << "Answer: " << evaluate(postfix) << endl;
    return 0;
}