#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int num;
	struct node* next;
}node;

void init();
void finish();
void countDFS();
void dfs(int);
void push(int, int);

int n, m;
node list[100001];
int* timetable;
int* visited;
int count = 1;

int main() {
	init();
	countDFS();
	finish();

	return 0;
}

void countDFS() {
	int t = 0;
	for (int i = 0; i < n; i++) {
		if (visited[timetable[i]] == 0) {
			dfs(timetable[i]);
			count++;
		}
	}

	for (int i = 0; i < n-1; i++) {
		if (visited[timetable[i]] != visited[timetable[i + 1]]) {
			t++;
		}
	}
	printf("%d", t);
}

void dfs(int v) {
	visited[v] = count;
	node* cur = &list[v];
	while (cur->next != NULL) {
		if (visited[cur->next->num] == 0) {
			dfs(cur->next->num);
		}
		cur = cur->next;
	}
}

void init() {
	scanf("%d %d", &n, &m);
	timetable = (int*)malloc(n * sizeof(int));
	visited = (int*)calloc(n + 1, sizeof(int));
	for (int i = 0; i < n+1; i++) {
		list[i].num = i;
		list[i].next = NULL;
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		push(a, b);
		push(b, a);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &timetable[i]);
	}
}

void push(int a, int b) {
	node* cur;
	node* tmp = (node*)malloc(sizeof(node));
	tmp->num = b;
	cur = &list[a];
	while (cur->next != NULL) {
		cur = cur->next;
	}
	tmp->next = cur->next;
	cur->next = tmp;

}

void finish() {
	for (int i = 0; i <= n; i++) {
		node* tmp;
		node* cur = list[i].next;
		if (cur == NULL) {
			continue;
		}
		while (cur != NULL) {
			tmp = cur;
			cur = cur->next;
			free(tmp);
		}
	}
	free(timetable);
	free(visited);
}