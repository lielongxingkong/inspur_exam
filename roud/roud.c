#include <stdio.h>
#include <string.h>

#define MAX 505
#define INFINITY 9999999
unsigned int dist[MAX][MAX];
unsigned int d[MAX]; /* d[i] is the length of the shortest path between the source (s) and node i */
int M, N;

void parse_line() {
	char c;
	int index, here;
	char temp[5];
	int array[MAX];
	int i, j, count = 0;

	count = 0;
	index = 0;
	memset(temp, 0, sizeof(temp));
	memset(array, 0, sizeof(temp));

	while (1) {
		c = getchar();
		if (c >= '0' && c <= '9') {
			temp[index] = c;
			index++;
		} else if (c == ' ' || c == 10 || c == 13) {
			temp[index] = '\0';
			sscanf(temp, "%d", &here);
			array[count] = here;
			count++;

			index = 0;
			memset(temp, 0, sizeof(temp));
			if (c == 13 || c == 10)
				break;
		}
	}

	for (i = 0; i < count; i++)
		for (j = i + 1; j < count; j++)
			dist[array[i]][array[j]] = 1;
}

void printD() {
	int i, j;
/*
	for (i = 1; i <= N; ++i) {
		for (j = 1; j <= N; ++j) {
			printf("%d ", dist[j][i]);
		}
		printf("\n");
	}
*/
	for (i = 1; i <= N; ++i)
		printf("%15d", i);
	printf("\n");
	for (i = 1; i <= N; ++i) {
		printf("%15u", d[i]);
	}
	printf("\n");
}

void dijkstra(int s) {
	int i, k, mini;
	int visited[MAX];

	for (i = 1; i <= N; ++i) {
		d[i] = INFINITY;
		visited[i] = 0; /* the i-th element has not yet been visited */
	}

	d[s] = 0;

	for (k = 1; k <= N; ++k) {
		mini = -1;
		for (i = 1; i <= N; ++i)
			if (!visited[i] && ((mini == -1) || (d[i] < d[mini])))
				mini = i;

		visited[mini] = 1;

		for (i = 1; i <= N; ++i) 
			if (dist[mini][i]) 
				if (d[mini] + dist[mini][i] < d[i]) 
					d[i] = d[mini] + dist[mini][i];
	}
}

int main() {
	int i, j;
	int n;

	freopen("roud.in", "r", stdin);
	freopen("roud.out", "w", stdout);
	scanf("%d", &M);
	scanf("%d", &N);
	getchar();

	memset(dist, 0, sizeof(dist));
	for (i = 0; i < M; i++) {
		parse_line();
	}

	dijkstra(1);
	if (d[N] == INFINITY)
		printf("No\n");
	else
		printf("%d\n", d[N] - 1);

	//printD();

	return 0;
}
