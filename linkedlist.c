
#define NULL 0

typedef struct {
    int val;
    struct LinkedNode *next;
} LinkedNode;

typedef struct {
    LinkedNode *head;
    unsigned int size;
} LinkedList;

LinkedNode *new_linked_node(int val) {
    LinkedNode *node = (LinkedNode *)malloc(sizeof(LinkedNode));
    node->val = val;
    node->next = NULL;
    return node;
}

LinkedList new_linked_list() {
    LinkedList list = {NULL, 0};
    return list;
}

void push(LinkedList *list, int val) {
    LinkedNode *node = new_linked_node(val);
    if (list->head == NULL) {
        list->head = node;
        list->size = 1;
        return;
    }
    LinkedNode *current = list->head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = node;
    list->size++;
}
