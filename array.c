#include <stdlib.h>

typedef struct {
    int *nums;
    unsigned int size;
} array;

int randomAccess(array arr, unsigned int size) {
    int index = rand() % size;
    return arr.nums[index];
}

void push(array arr, int num) {
    arr.nums[arr.size] = num;
    arr.size += 1;
}

void insert(array arr, int num, unsigned int index) {
    for (unsigned int i = arr.size - 1; i > index; i --) {
        arr.nums[i] = arr.nums[i - 1];
    }
    arr.nums[index] = num;
}

void remove(array arr, unsigned int index) {
    for (unsigned int i = index; i < arr.size - 1; i ++) {
        arr.nums[i] = arr.nums[i + 1];
    }
}

int find(array arr, int num) {
    for (unsigned int i = 0; i < arr.size; i ++) {
        if (arr.nums[i] == num) {
            return i;
        }
    }
    return -1;
}

void extend(array arr, unsigned int new_size) {
    int *res = malloc(sizeof(int) * new_size);
    for (unsigned int i = 0; i < arr.size; i++) {
        res[i] = arr.nums[i];
    }
    for (unsigned int i = arr.size; i < new_size; i++) {
        res[i] = 0;
    }
    free(arr.nums);
    arr.nums = res;
    arr.size = new_size;
}
