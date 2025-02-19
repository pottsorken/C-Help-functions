#include <stdlib.h>
#include <stdio.h>


typedef struct stack
{
    int top;
    int size;
    int *array;
} stack;

// Functions
stack *new_stack(int size);
void push(stack *stk, int val);
void push_dynamic(stack *stk, int val);
int pop(stack *stk) ;
int pop_dynamic(stack *stk) ;

stack *new_stack(int size)
{
    int *array = (int *)malloc(size * sizeof(int));
    stack *stk = (stack *)malloc(sizeof(stack));

    stk->top = 0;
    stk->size = size;
    stk->array = array;

    return stk;
}

void push(stack *stk, int val)
{
    if (stk->top == stk->size)
    {
        printf("The stack is full\n");
        return;
    }

    *(stk->array) = val;
    stk->top++;
    stk->array++;
}

void push_dynamic(stack *stk, int val)
{
    if (stk->top == stk->size)
    {
        int *copy = (int *)malloc(stk->size * 2 * sizeof(int));
        for (int i = 0; i < stk->size; i++)
        {
            int *from = stk->array - stk->top + i;
            copy[i] = *from;
        }
        free(stk->array);
        stk->array = copy + stk->top;
        stk->size *= 2;
    }

    *(stk->array) = val;
    stk->top++;
    stk->array++;
}

int pop(stack *stk) 
{
    if (stk->top == 0)
    {
        printf("This stack is empty, no pop operation allowed!");
        return 0;
    }

    stk->array--;
    stk->top--;
    return *(stk->array);
}

int pop_dynamic(stack *stk)
{
    if (stk->top == 0)
    {
        printf("This stack is empty, no pop operation allowed!");
        return 0;
    }

    if (stk->top * 2 == stk->size)
    {
        int *copy = (int *)malloc(stk->top * sizeof(int));

        for (int i = 0; i < stk->top; i++)
        {
            int *from = stk->array - stk->top + i;
            copy[i] = *from;
        }

        free(stk->array);
        stk->array = copy + stk->top;
        stk->size = stk->top;
    }
    stk->array--;
    stk->top--;
    int val = *(stk->array);
    return val;
}