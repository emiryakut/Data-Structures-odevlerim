#include <stdio.h>

#define MAX 100

int tree[MAX];

void initTree() {
    for (int i = 0; i < MAX; i++)
        tree[i] = -1;
}

void insert(int index, int value) {
    if (index < MAX)
        tree[index] = value;
}

void traverse() {
    for (int i = 0; i < MAX; i++) {
        if (tree[i] != -1)
            printf("Index %d : %d\n", i, tree[i]);
    }
}

int main() {
    initTree();

    insert(0, 10);
    insert(1, 20);
    insert(2, 30);
    insert(3, 40);
    insert(4, 50);
    insert(5, 60);
    insert(6, 70);

    traverse();
    return 0;
}
