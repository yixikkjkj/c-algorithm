
#define NULL 0

typedef struct {
    int val;
    struct StackNode *next;
} StackNode;

typedef struct {
    unsigned int size;
    StackNode *top;
} Stack;

StackNode *new_stack_node(int val) {
    StackNode *node = (StackNode *)malloc(sizeof(StackNode));
    node->val = val;
    node->next = NULL;
    return node;
}

void push(Stack *stack, int val) {
    StackNode *node = new_stack_node(val);
    node->next = stack->top;
    stack->top = node;
    stack->size++;
}

StackNode *pop(Stack *stack) {
    if (stack->size == 0) {
        return NULL;
    }
    stack->size--;
    StackNode *node = stack->top;
    stack->top = node->next;
    return node;
}

StackNode *peek(Stack *stack) {
    if (stack->size == 0) {
        return NULL;
    }
    return stack->top;
}

Stack new_stack() {
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->size = 0;
    stack->top = new_stack_node(0);
    return *stack;
}

void print_stack(Stack *stack) {
    StackNode *curr = stack->top;
    for (unsigned int i = 0; i < stack->size; i++) {
        printf("%d ", curr->val);
        curr = curr->next;
    }
    printf("\n");
}

int main() {
    Stack stack = new_stack();
    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);
    print_stack(&stack);
    StackNode *node = pop(&stack);
    printf("%d \n", node->val);
    print_stack(&stack);
    StackNode *node1 = peek(&stack);
    printf("%d \n", node1->val);
    return 0;
}
