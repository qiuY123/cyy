#define _CRT_SECURE_NO_WARNINGS 1 

#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int Datetype;

typedef struct Stack
{
    Datetype* a;
    int top;
    int capacity;
}ST;

void StackInit(ST* p)
{
    assert(p);
    p->a = (Datetype*)malloc(sizeof(Datetype) * 2);
    p->capacity = 2;
    p->top = 0;
}
void StackDestory(ST* p)
{
    assert(p);
    free(p->a);
    p->a = NULL;
    p->top = p->capacity = 0;
}
void StackPush(ST* p, Datetype x)
{
    assert(p);
    if (p->top == p->capacity)
    {
        Datetype* temp = (Datetype*)realloc(p->a, p->capacity * 2 * sizeof(Datetype));
        if (temp == NULL)
        {
            printf("realloc fail");
            exit(-1);
        }
        else
        {
            p->a = temp;
            p->capacity *= 2;
        }
    }
    p->a[p->top] = x;
    p->top++;
}
void StackPop(ST* p)
{
    assert(p);
    assert(p->top > 0);

    p->top--;
}
Datetype StackTop(ST* p)
{
    assert(p);
    assert(p->top > 0);

    return p->a[p->top - 1];
}
int StackSize(ST* p)
{
    assert(p);

    return p->top;
}
int StackEmpty(ST* p)
{
    assert(p);
    if (p->top)
    {
        return 1;//p->top不为0返回1
    }
    return 0;//p->top为0返回0
}

typedef struct {
    ST e1;
    ST e2;
} MyQueue;


MyQueue* myQueueCreate() {
    MyQueue* obj = (MyQueue*)malloc(sizeof(MyQueue));
    StackInit(&obj->e1);
    StackInit(&obj->e2);
    return obj;
}

void myQueuePush(MyQueue* obj, int x) {
    if (StackEmpty(&obj->e1))
    {
        StackPush(&obj->e1, x);
    }
    else
    {
        StackPush(&obj->e2, x);
    }
}

int myQueuePop(MyQueue* obj) {
    ST* empty = &obj->e1;
    ST* inempty = &obj->e2;
    if (StackEmpty(&obj->e1))
    {
        empty = &obj->e2;
        inempty = &obj->e1;
    }
    while (StackSize(inempty) > 1)
    {
        StackPush(empty, StackTop(inempty));
        StackPop(inempty);
    }
    int top = StackTop(inempty);
    StackPop(inempty);
    while (StackSize(empty))
    {
        StackPush(inempty, StackTop(empty));
        StackPop(empty);
    }
    return top;
}

int myQueuePeek(MyQueue* obj) {
    ST* empty = &obj->e1;
    ST* inempty = &obj->e2;
    if (StackEmpty(&obj->e1))
    {
        empty = &obj->e2;
        inempty = &obj->e1;
    }
    while (StackSize(inempty) > 1)
    {
        StackPush(empty, StackTop(inempty));
        StackPop(inempty);
    }
    int top = StackTop(inempty);
    StackPush(empty, StackTop(inempty));
    StackPop(inempty);
    while (StackSize(empty))
    {
        StackPush(inempty, StackTop(empty));
        StackPop(empty);
    }
    return top;
}

bool myQueueEmpty(MyQueue* obj) {
    return !StackEmpty(&obj->e1) && !StackEmpty(&obj->e2);
}

void myQueueFree(MyQueue* obj) {
    StackDestory(&obj->e1);
    StackDestory(&obj->e2);
    free(obj);
}

