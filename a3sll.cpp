#include <iostream>
#include <string>

using namespace std;

// Linked List Node
struct Node
{
    char data;
    Node *next;
};

// Function to check if a character is an operand
bool isOperand(char c)
{
    // Check if the character is a letter or a digit
    return (isalpha(c) || isdigit(c));
}

// Function to check if a character is a bracket
bool isBracket(char c)
{
    // Check if the character is a bracket
    return (c == '(' || c == '{' || c == '[');
}

// Function to push an element onto the stack
void push(Node *&top, char data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = top;
    top = newNode;
}

// Function to pop an element from the stack
char pop(Node *&top)
{
    if (top == NULL)
    {
        return '#';
    }
    else
    {
        char data = top->data;
        Node *temp = top;
        top = top->next;
        delete temp;
        return data;
    }
}

// Function to check if the stack is empty
bool isEmpty(Node *top)
{
    return (top == NULL);
}

int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/' || op == '%')
        return 2;
    if (op == '^')
        return 3;
    return 0;
}

// Function to convert infix to postfix
string infixToPostfix(string infix)
{
    Node *stack = NULL;
    string postfix = "";
    for (int i = 0; i < infix.length(); i++)
    {
        // If the current character is an operand, add it to the postfix string
        if (isOperand(infix[i]))
        {
            postfix += infix[i];
        }
        // If the current character is an opening bracket, push it onto the stack
        else if (isBracket(infix[i]))
        {
            push(stack, infix[i]);
        }
        // If the current character is a closing bracket
        else if (infix[i] == ')' || infix[i] == '}' || infix[i] == ']')
        {
            // While the top of the stack is not a matching opening bracket
            while (!isEmpty(stack) && !isBracket(stack->data))
            {
                // Pop the top operator from the stack and add it to the postfix string
                postfix += pop(stack);
            }
            // Pop the matching opening bracket from the stack
            pop(stack);
        }
        // If the current character is an operator
        else
        {
            // While the stack is not empty and the top of the stack has a higher precedence than the current operator
            while (!isEmpty(stack) && precedence(stack->data) >= precedence(infix[i]))
            {
                // Pop the top operator from the stack and add it to the postfix string
                postfix += pop(stack);
            }
            // Push the current operator onto the stack
            push(stack, infix[i]);
        }
    }

    // While the stack is not empty, pop the remaining operators from the stack and add them to the postfix string
    while (!isEmpty(stack))
    {
        postfix += pop(stack);
    }
    // Return the postfix string
    return postfix;
}

int main()
{
    string infix = "A*(B+C)*D";
    cout << "Infix: " << infix << endl;
    cout << "Postfix: " << infixToPostfix(infix) << endl;
    return 0;
}
