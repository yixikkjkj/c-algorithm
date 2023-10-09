
#define NULL 0

typedef struct {
    int val;
    struct LinkedNode *next;
} LinkedNode;

typedef struct {
    LinkedNode *guard;
    unsigned int size;
} LinkedList;

LinkedNode *new_linked_node(int val) {
    LinkedNode *node = (LinkedNode *)malloc(sizeof(LinkedNode));
    node->val = val;
    node->next = NULL;
    return node;
}

LinkedList new_linked_list() {
    LinkedNode *guard = new_linked_node(0);
    guard->next = guard;
    LinkedList list = {guard, 0};
    return list;
}

void push(LinkedList *list, int val) {
    LinkedNode *node = new_linked_node(val);
    LinkedNode *curr = list->guard;
    for (unsigned int i = 0; i < list->size; i++) {
        curr = curr->next;
    }
    list->size++;
    LinkedNode *next = curr->next;
    curr->next = node;
    node->next = next;
}

void insert(LinkedList *list, int val, unsigned int index) {
    if (index >= list->size) {
        return;
    }
    LinkedNode *node = new_linked_node(val);
    LinkedNode *curr = list->guard;
    for (unsigned int i = 0; i < index; i++) {
        curr = curr->next;
    }
    list->size++;
    LinkedNode *next = curr->next;
    curr->next = node;
    node->next = next;
}

void remove(LinkedList *list, unsigned int index) {
    if (index >= list->size) {
        return;
    }
    LinkedNode *node = list->guard;
    for (unsigned int i = 0; i < index; i++) {
        node = node->next;
    }
    // 要移除的就是下一个node
    LinkedNode *rm_node = node->next;
    node->next = rm_node->next;
    list->size--;
    free(rm_node);
}

void print_list(LinkedList *list) {
    LinkedNode *node = list->guard->next;
    for (unsigned int i = 0; i < list->size; i++) {
        printf("%d ", node->val);
        node = node->next;
    }
    printf("\n");
}

LinkedNode *access(LinkedList *list, unsigned int index) {
    if (index >= list->size) {
        return NULL;
    }
    LinkedNode *node = list->guard;
    for (unsigned int i = 0; i <= index; i++) {
        node = node->next;
    }
    return node;
}

int main() {
    LinkedList list = new_linked_list();
    push(&list, 1);
    push(&list, 2);
    push(&list, 3);
    print_list(&list);
    insert(&list, 4, 0);
    print_list(&list);
    remove(&list, 1);
    print_list(&list);
    LinkedNode *node = access(&list, 1);
    printf("%d \n", node->val);
    return 0;
}
