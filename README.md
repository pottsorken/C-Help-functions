This repository is created to store some of the functions and programmes I have made in courses in university. It is to act as a helping hand when I face similar problems to those I have already dealt with.

## Content
* **timekeeping.h** - For benchmarking
    * long nano_seconds(struct timespec *t_start, struct timespec *t_stop)
* **stack.h** - For creating and handling a stack
    * typedef struct stack
    * stack *new_stack(int size)
    * void push(stack *stk, int val)
    * void push_dynamic(stack *stk, int val)
    * int pop(stack *stk) 
    * int pop_dynamic(stack *stk) 
