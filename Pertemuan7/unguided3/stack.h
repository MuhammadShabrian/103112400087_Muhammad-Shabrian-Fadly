#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

const int MAX_STACK = 20;

typedef char infotype;

struct Stack {
    infotype info[MAX_STACK];
    int top;
};

void createStack(Stack &S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);
void getInputStream(Stack &S);

#endif
