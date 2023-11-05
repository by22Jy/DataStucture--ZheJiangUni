// 计算表达式 利用堆栈先进后出原则
// 遇到数直接输出 
// 遇到左括号直接进栈
// 遇到右括号 将运算符一直出栈直到左括号
// 其他运算符 如果高于前面的优先级直接入栈 否则一直出栈直至该运算符为最高优先级
// 最后将运算符一个个出栈

//
// Created by ByteDance on 2023/10/26.
//
#include<iostream>
#include<cstdlib>
#include<cctype>
#include<string>
#include<sstream>
using namespace std;
const int N = 200;

bool stn=true;
typedef struct{
    char data[N];
    int top;
}Stack;

void InitStack(Stack *&s){
    s = (Stack*)malloc(sizeof (Stack));
    s->top = 0;
}

int Push(Stack *&s, char e){
    if(s->top == N - 1) return 0;
    s->top ++;
    s->data[s->top] = e;
    return 1;
}

int Pop(Stack *&s){
    if(s->top == -1) return 0;
    s->top--;
    return 1;
}

bool StackEmpty(Stack *s){
    return s->top == 0;
}

char StackTop(Stack *s){
    return s->data[s->top];
}

// 检查括号匹配
bool areBracketsMatching(const string& expr) {
    Stack* s;
    InitStack(s);
    for (int i=0;i<expr.length();i++) {
        char ch = expr[i];
        if (ch == '(' || ch == '[' || ch == '{') {
            Push(s,ch);
        }
        else if (ch == ')' || ch == ']' || ch == '}') {
            if (StackEmpty(s) || (ch == ')' && StackTop(s) != '(') ||
                (ch == ']' && StackTop(s) != '[') || (ch == '}' && StackTop(s) != '{')) {
                return false;  // 括号不匹配
            }
            Pop(s);
        }
    }

    return StackEmpty(s);  // 如果为空 所有括号都匹配
}

// 将中缀表达式 转换为后缀表达式
string infixToPostfix(string &infix) {
    string postfix;
    Stack* operators;
    InitStack(operators);
    for (int i = 0; i < infix.length(); i++) {
        char ch = infix[i];
        if (std::isdigit(ch)) {
            postfix += ch;
            postfix += ' ';  // 使用空格分隔数字
        } else if (ch == '(' || ch == '[' || ch == '{') {
            Push(operators, ch);
        } else if (ch == ')' || ch == ']' || ch == '}') {
            char closing = ch;
            char opening;

            if (closing == ')') {
                opening = '(';
            } else if (closing == ']') {
                opening = '[';
            } else if (closing == '}') {
                opening = '{';
            }

            while (!StackEmpty(operators) && StackTop(operators) != opening) {
                postfix += StackTop(operators);
                postfix += ' ';
                Pop(operators);
            }
            if (!StackEmpty(operators) && StackTop(operators) == opening) {
                Pop(operators); // 弹出对应的开括号
            } else {
                return "Invalid expression";
            }
        } else if (ch == '+' || ch == '-') {
            while (!StackEmpty(operators) && (StackTop(operators) == '+' || StackTop(operators) == '-' || StackTop(operators) == '*' || StackTop(operators) == '/')) {
                postfix += StackTop(operators);
                postfix += ' ';
                Pop(operators);
            }
            Push(operators, ch);
        } else if (ch == '*' || ch == '/') {
            Push(operators, ch);
        }
    }

    while (!StackEmpty(operators)) {
        if (StackTop(operators) == '(' || StackTop(operators) == ')' ||
            StackTop(operators) == '[' || StackTop(operators) == ']' ||
            StackTop(operators) == '{' || StackTop(operators) == '}') {
            return "Invalid expression";
        }
        postfix += StackTop(operators);
        postfix += ' ';
        Pop(operators);
    }

    return postfix;
}


// 函数用于检查字符是否是运算符
bool isOperator(const std::string& token) {
    return token == "+" || token == "-" || token == "*" || token == "/";
}

// 计算
int evaluate(int operand1,int operand2,const string& op){
    if(op == "+") return operand1 + operand2;
    else if(op == "-") return operand1 - operand2;
    else if(op == "*") return operand1 * operand2;
    else{
        if(operand2 != 0) return operand1 / operand2;
        else throw runtime_error("division by zero");
    }
}

// 后缀表达式计算
int evaluatePostExpression(const string& postfixExpression){
    // 初始化储存数字的栈
    Stack* operandStack;
    InitStack(operandStack);
    istringstream tokens(postfixExpression);
    string token;

    while(tokens >> token){
        if(!isOperator(token)){
            // 如果是操作数 而不是运算符 入栈
            int operand;
            istringstream(token) >> operand;
            Push(operandStack,operand);
        }
        else{
            // 如果是运算符 从栈中弹出两个操作数进行运算
            int operand1 = StackTop(operandStack);
            Pop(operandStack);
            int operand2 = StackTop(operandStack);
            Pop(operandStack);
            int res = evaluate(operand2,operand1,token);
            Push(operandStack,res);
        }
    }
    // 如果最后栈只剩一个元素 即为运算最终结果
    if(operandStack->top == 1) return StackTop(operandStack);
    else throw std::runtime_error("Invalid postfix expression");
}

int main()
{
    while(1){
        string input_string;
        cout<<"请输入表达式"<<endl;
        cin>>input_string;
        if(areBracketsMatching(input_string)){
            cout<<"输入表达式有效"<<endl;
            cout<<"计算结果为:"<<evaluatePostExpression(infixToPostfix(input_string));
            puts(" ");
        }
        else{
            cout<<"表达式有误，请重新输入"<<endl;
        }
    }

}