#include <stdio.h>
#include <string.h>

#define MAX 15

typedef struct {
    char data[MAX];
    int head;
    int tail;
    int count;
} CircularBuffer;

void init_buffer(CircularBuffer *cb) {
    cb->head = 0;
    cb->tail = 0;
    cb->count = 0;
}

int is_full(CircularBuffer *cb) {
    return cb->count == MAX;
}

int is_empty(CircularBuffer *cb) {
    return cb->count == 0;
}

void push(CircularBuffer *cb, char item) {
    if (is_full(cb)) {
        printf("\nFull!");
        return;
    }
    cb->data[cb->tail] = item;
    cb->tail = (cb->tail + 1) % MAX;
    cb->count++;
}

char pop(CircularBuffer *cb) {
    if (is_empty(cb)) {
        return '\0';
    }
    char item = cb->data[cb->head];
    cb->head = (cb->head + 1) % MAX;
    cb->count--;
    return item;
}

int main() {
    CircularBuffer cb;
    init_buffer(&cb);

    char input_name[50];
    char tag[] = "CE-ESY";

    printf("Name: ");
    scanf("%s", input_name);

    strcat(input_name, tag);

    for (int i = 0; i < strlen(input_name); i++) {
        push(&cb, input_name[i]);
    }

    printf("Output: ");
    while (!is_empty(&cb)) {
        printf("%c", pop(&cb));
    }
    printf("\n");

    return 0;
}
