#include <iostream>
#include <string>

using namespace std;

// Linked List Node
struct Node
{
    int data;
    Node *next;
};

// Function to check if a character is an operator
bool isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Function to check if a character is a bracket
bool isBracket(char c)
{
    return (c == '(' || c == '{' || c == '[');
}

// Function to push an element onto the stack
void push(Node *&top, int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = top;
    top = newNode;
}

// Function to pop an element from the stack
int pop(Node *&top)
{
    if (top == NULL)
    {
        return -1;
    }
    else
    {
        int data = top->data;
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

// Function to perform exponentiation operation
int power(int base, int exponent)
{
    int result = 1;
    for (int i = 0; i < exponent; i++)
    {
        result *= base;
    }
    return result;
}

// Function to perform the arithmetic operation
int performOperation(int a, int b, char op)
{
    switch (op)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b;
    case '^':
        int pow = power(a, b);
        return pow;
    }
    return -1;
}

// Function to evaluate postfix expression
int evaluatePostfix(string postfix)
{
    Node *stack = NULL;
    for (int i = 0; i < postfix.length(); i++)
    {
        // If the current character is an operand, push it onto the stack
        if (!isOperator(postfix[i]) && !isBracket(postfix[i]))
        {
            push(stack, postfix[i] - '0');
        }
        // If the current character is an operator
        else if (isOperator(postfix[i]))
        {
            // Pop the two operands from the stack
            int b = pop(stack);
            int a = pop(stack);
            // Perform the operation and push the result back onto the stack
            push(stack, performOperation(a, b, postfix[i]));
        }
        else if (isBracket(postfix[i]))
        {
            if (postfix[i] == ')')
            {
                while (stack->data != '(')
                {
                    int b = pop(stack);
                    int a = pop(stack);
                    char op = pop(stack);
                    push(stack, performOperation(a, b, op));
                }
                pop(stack);
            }
        }
    }
    // The final result will be at the top of the stack
    return pop(stack);
}

int main()
{
    string postfix = "23*54*+";
    cout << "Postfix: " << postfix << endl;
    cout << "Evaluated postfix: " << evaluatePostfix(postfix) << endl;
    return 0;
}
