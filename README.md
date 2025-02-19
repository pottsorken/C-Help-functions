
## Content
- **timekeeping.h** - For benchmarking
 - long nano_seconds(struct timespec *t_start, struct timespec *t_stop)
- **stack.h** - For creating and handling a stack
-- typedef struct stack
- - stack *new_stack(int size)
- - void push(stack *stk, int val)
- - void push_dynamic(stack *stk, int val)
- - int pop(stack *stk) 
- - int pop_dynamic(stack *stk) 
