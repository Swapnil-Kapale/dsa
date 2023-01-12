#include <iostream>
#include <string>
using namespace std;
class convert
{
public:
    string expression;
    int top,
        top_postfix;
    char stack[100],
        postfix[200];
    convert()
    {
        top = -1;
        top_postfix = -1;
    }
    // functions
    void store();
    void push(char c);
    void pop_bracket(char c);
    void pop_operator();
    void push_postfix(char c);
    int precedence(char c);
};
void convert::store()
{
    int i;
    for (i = 0; expression[i] != '\0'; i++)
    {
        if (expression[i] == '(' || expression[i] == '[' || expression[i] == '{')
        {
            push(expression[i]);
        }
        else if (expression[i] == ')' || expression[i] == ']' ||
                 expression[i] == '}')
        {
            pop_bracket(expression[i]);
        }
        else if (expression[i] == '+' || expression[i] == '-' ||
                 expression[i] == '*' || expression[i] == '/')
        {
            if (top == -1)
            {
                push(expression[i]);
            }
            else if (precedence(expression[i]) <= precedence(stack[top]))
            {
                while (precedence(expression[i]) <= precedence(stack[top]) && top != -1)
                {
                    push_postfix(stack[top]);
                    pop_operator();
                }
                push(expression[i]);
            }
            else
            {
                push(expression[i]);
            }
        }
        else
        {
            push_postfix(expression[i]);
        }
    }
    // empty stack
    for (i = top; i >= 0; i--)
    {
        push_postfix(stack[i]);
    }
    for (i = 0; i <= top_postfix; i++)
    {
        cout << postfix[i];
    }
}
void convert::push(char c)
{
    if (top == 99)
    {
        cout << "\n Stack is full";
    }
    else
    {
        top++;

        stack[top] = c;
    }
}
void convert::pop_bracket(char c)
{
    if (c == ')')
    {
        c = '(';
    }
    else if (c == ']')
    {
        c = '[';
    }
    else
    {
        c = '{';
    }
    int i;
    for (i = top; stack[i] != c; i--)
    {
        push_postfix(stack[i]);
        pop_operator();
    }
    pop_operator();
}
void convert::pop_operator()
{
    top--;
}
void convert::push_postfix(char c)
{
    if (top_postfix == 199)
    {
        cout << "\n Stack is full";
    }
    else if (c == '(' || c == '{' || c == '[')
    {
    }
    else
    {
        top_postfix++;
        postfix[top_postfix] = c;
    }
}
int convert::precedence(char c)
{
    int p = 0;
    if (c == '*' || c == '/')
    {
        p = 3;
    }
    else if (c == '+' || c == '-')
    {
        p = 2;
    }
    else
    {
        p = 1;
    }
    return p;
}
int main()
{
    cout << "Program To convert Infix -> Postfix\n";
    cout << "Enter Expression you want to convert: ";
    convert ex;
    cin >> ex.expression; //"(a+b)*(c-d)";
    ex.store();
    return 0;
}
