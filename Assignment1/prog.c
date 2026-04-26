
#include <stdio.h>
#include <string.h>
#define SIZE 10

typedef struct {
    char buffer[SIZE];
    int head;
    int tail;
    int count;
} CircularBuffer;

void initBuffer(CircularBuffer *cb) {
    cb->head = 0;
    cb->tail = 0;
    cb->count = 0;
}

int isFull(CircularBuffer *cb) {
    return cb->count == SIZE;
}

int isEmpty(CircularBuffer *cb) {
    return cb->count == 0;
}

void writeBuffer(CircularBuffer *cb, char data) {
    if (isFull(cb)) {
        printf("Buffer Overflow!\n");
        return;
    }
    cb->buffer[cb->head] = data;
    cb->head = (cb->head + 1) % SIZE;
    cb->count++;
}

char readBuffer(CircularBuffer *cb) {
    if (isEmpty(cb)) {
        printf("Buffer Underflow!\n");
        return '\0';
    }
    char data = cb->buffer[cb->tail];
    cb->tail = (cb->tail + 1) % SIZE;
    cb->count--;
    return data;
}

int main() {
    CircularBuffer cb;
    initBuffer(&cb);

    char name[50];
    printf("Enter your name: ");
    scanf("%s", name);

    strcat(name, "YSE-EC");

    // إدخال الاسم في المخزن
    for (int i = 0; i < strlen(name); i++) {
        writeBuffer(&cb, name[i]);
    }

    // قراءة آخر عنصر
    while (!isEmpty(&cb)) {
        char c = readBuffer(&cb);
        printf("%c", c);
    }

    printf("\nBuffer is now empty.\n");
    return 0;
}
