// Converting infix to postfix
// Declarations are imported from list.cpp file

#include "list.cpp"
#include "string"
#include "sstream"

// Function for operators precedence
int precedence(string op)
{
    if (op == "+" || op == "-")
        return 1;
    if (op == "*" || op == "/")
        return 2;
    if (op == "^")
        return 3;
    else
        return 0;
}

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

// Function that will convert the infix to postfix
string postfix(string infix)
{
    singly_linked_list outputQueue;
    singly_linked_list opcodeStack;
    string token;

    stringstream ss(infix); // This will tokenize the infix string and store it into ss (string stream)

    while (ss >> token) // This will provide each token to token variable
    {
        if (isNum(token)) // Condition 1: if token is number thorw it into output queue
        {
            outputQueue.add(token);
        }
        else if (isOpcode(token)) // Condition 2: if token is operator check below condition too
        {

            // Condition A: Until operator stack is not empty AND
            // Token's operator precedence is smaller than the operator stack's top operator precedence AND
            // Top element in the operator's stack is not brackets i.e. "(" and ")"
            // pop the operators from the operator's stack and add them to output queue

            while (!opcodeStack.isEmpty() && precedence(opcodeStack.last()) >= precedence(token) && isOpcode(opcodeStack.last()))
            {
                outputQueue.add(opcodeStack.last());
                opcodeStack.remove_end();
            }

            opcodeStack.add(token);
        }
        else if (token == "(") // Condition 3: if token is opening bracket "(", just throw it into the operator's stack
        {
            opcodeStack.add(token);
        }
        else if (token == ")") // Condition 4: if token is closing bracket ")" then check below conditions
        {
            // Condition A: Until operator stack is not empty AND
            // Operator's stack top element is not opening bracket "("
            // pop the operators from the operator's stack and add them to output queue

            while (!opcodeStack.isEmpty() && opcodeStack.last() != "(")
            {
                outputQueue.add(opcodeStack.last());
                opcodeStack.remove_end();
            }

            // Condition B: if operators stack is not empty AND
            // Top element is opening bracket "("
            // Just pop that out

            if (!opcodeStack.isEmpty() && opcodeStack.last() == "(")
            {
                opcodeStack.remove_end();
            }
        }
        else // Last Condition 5: if token is not operator and not num then the input expression is wrong, display error and exit the code
        {
            cout << "Error!: Wrong Input" << endl;
            exit(0);
        }
    }

    while (!opcodeStack.isEmpty()) // We may have operators in the stack so pop them and add them to the output queue
    {
        outputQueue.add(opcodeStack.last());
        opcodeStack.remove_end();
    }

    return outputQueue.toString(); // Convert the output queue to string and return to the caller
}

int main()
{
    string infix;
    cout << "Enter a valid infix expression with spaces (2 * 2 + 2): ";
    getline(cin, infix);
    cout << "In postfix: " << postfix(infix);
    return 0;
}
