#include <stdio.h>

#define MAX 100

/* ---------- ORTAK ---------- */
int minHeap[MAX], maxHeap[MAX];
int minSize = 0, maxSize = 0;

int parent(int i) { return (i - 1) / 2; }
int left(int i) { return 2 * i + 1; }
int right(int i) { return 2 * i + 2; }

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* ---------- MIN HEAP ---------- */
void insertMin(int value) {
    int i = minSize;
    minHeap[minSize++] = value;

    while (i != 0 && minHeap[parent(i)] > minHeap[i]) {
        swap(&minHeap[i], &minHeap[parent(i)]);
        i = parent(i);
    }
}

void heapifyMin(int i) {
    int smallest = i;
    int l = left(i);
    int r = right(i);

    if (l < minSize && minHeap[l] < minHeap[smallest])
        smallest = l;
    if (r < minSize && minHeap[r] < minHeap[smallest])
        smallest = r;

    if (smallest != i) {
        swap(&minHeap[i], &minHeap[smallest]);
        heapifyMin(smallest);
    }
}

int extractMin() {
    if (minSize <= 0) return -1;

    int root = minHeap[0];
    minHeap[0] = minHeap[--minSize];
    heapifyMin(0);

    return root;
}

/* ---------- MAX HEAP ---------- */
void insertMax(int value) {
    int i = maxSize;
    maxHeap[maxSize++] = value;

    while (i != 0 && maxHeap[parent(i)] < maxHeap[i]) {
        swap(&maxHeap[i], &maxHeap[parent(i)]);
        i = parent(i);
    }
}

void heapifyMax(int i) {
    int largest = i;
    int l = left(i);
    int r = right(i);

    if (l < maxSize && maxHeap[l] > maxHeap[largest])
        largest = l;
    if (r < maxSize && maxHeap[r] > maxHeap[largest])
        largest = r;

    if (largest != i) {
        swap(&maxHeap[i], &maxHeap[largest]);
        heapifyMax(largest);
    }
}

int extractMax() {
    if (maxSize <= 0) return -1;

    int root = maxHeap[0];
    maxHeap[0] = maxHeap[--maxSize];
    heapifyMax(0);

    return root;
}

/* ---------- MAIN ---------- */
int main() {
    insertMin(10);
    insertMin(5);
    insertMin(20);

    insertMax(10);
    insertMax(5);
    insertMax(20);

    printf("Min Heap root: %d\n", extractMin());
    printf("Max Heap root: %d\n", extractMax());

    return 0;
}
