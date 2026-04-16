#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Q {
	int count;
	int arr[100001];
	int front, rear;
}Queue;

void push(Queue* q, int x) {
	q->arr[q->rear++] = x;
	q->count++;
	//printf("\n");
}

void pop(Queue* q) {
	if (q->count == 0) {
		printf("-1\n");
		return;
	}
	q->count--;
	int del = q->arr[q->front++];
	printf("%d\n", del);
	return;
}

void size(Queue* q) {
	printf("%d\n", q->count);
}

void front(Queue* q) {
	if (q->count == 0) {
		printf("-1\n");
		return;
	}
	printf("%d\n", q->arr[q->front]);
}

void empty(Queue* q) {
	if (q->count == 0) {
		printf("1\n");
		return;
	}
	else printf("0\n");
}

void back(Queue* q) {
	if (q->count == 0) {
		printf("-1\n");
		return;
	}
	else printf("%d\n", q->arr[q->rear - 1]);
}


int main() {
	Queue* queue = (Queue*)malloc(sizeof(Queue));
	queue->front = 0;
	queue->rear = 0;
	queue->count = 0;

	int n, i;
	
	scanf("%d", &n);
	for (i = 0; i < n; i++){
		char cmd[10];
		scanf("%s", cmd);
		if (strcmp(cmd, "push") == 0) {
			int t;
			scanf("%d", &t);
			push(queue,t);
		}
		else if (strcmp(cmd, "pop") == 0) {
			pop(queue);
		}
		else if (strcmp(cmd, "size") == 0) size(queue);
		else if (strcmp(cmd, "empty") == 0) empty(queue);
		else if (strcmp(cmd, "front") == 0) front(queue);
		else if (strcmp(cmd, "back") == 0) back(queue);

	}
	free(queue);
}