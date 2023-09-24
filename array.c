#include <stdlib.h>

typedef struct {
    int *nums;
    unsigned int size;
    unsigned int max_size;
} array;

void _extend(array *arr, unsigned int new_max_size) {
    int *res = malloc(sizeof(int) * new_max_size);
    for (unsigned int i = 0; i < arr->size; i++) {
        res[i] = arr->nums[i];
    }
    free(arr->nums);
    arr->nums = res;
    arr->max_size = new_max_size;
}

void push(array *arr, int num) {
    if (arr->size >= arr->max_size) {
        _extend(arr, arr->max_size ? arr->max_size * 2 : 8);
    }
    arr->nums[arr->size] = num;
    arr->size += 1;
}

void insert(array *arr, int num, unsigned int index) {
    if (arr->size >= arr->max_size) {
        _extend(arr, arr->max_size * 2);
    }
    for (unsigned int i = arr->size - 1; i > index; i --) {
        arr->nums[i] = arr->nums[i - 1];
    }
    arr->nums[index] = num;
}

void remove(array *arr, unsigned int index) {
    if (index >= arr->size) {
        return;
    }
    for (unsigned int i = index; i < arr->size - 1; i++)
    {
        arr->nums[i] = arr->nums[i + 1];
    }
    arr->size -= 1;
}

int find(array arr, int num) {
    for (unsigned int i = 0; i < arr.size; i ++) {
        if (arr.nums[i] == num) {
            return i;
        }
    }
    return -1;
}

int main() {
    array arr = {NULL, 0, 0};
    push(&arr, 1);
    remove(&arr, 0);
    return 1;
}
