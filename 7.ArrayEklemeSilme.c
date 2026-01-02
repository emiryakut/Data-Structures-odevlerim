#include <stdio.h>

#define MAX 100

int arr[MAX];
int size = 0;

void insertAt(int index, int value) {
    if (size >= MAX || index < 0 || index > size) return;

    for (int i = size; i > index; i--)
        arr[i] = arr[i - 1];

    arr[index] = value;
    size++;
}

void deleteAt(int index) {
    if (index < 0 || index >= size) return;

    for (int i = index; i < size - 1; i++)
        arr[i] = arr[i + 1];

    size--;
}

void traverse() {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
}

int main() {
    insertAt(0, 10);
    insertAt(1, 20);
    insertAt(1, 15);

    deleteAt(1);

    traverse();
    return 0;
}
