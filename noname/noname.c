#include <stdio.h>

#define MAX 25
int mat[MAX][MAX];
int S, T, N;

void printD() {
	int i, j;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N - i; j++) {
			printf("%d%c", mat[j][i], (j == N - i - 1) ? '\n' : ' ');
		}
	}
}

int main() {
	int i, j, count = 0;
	int output;
	freopen("noname.in", "r", stdin);
//	freopen("noname.out", "w", stdout);

	scanf("%d %d %d", &S, &T, &N);
	
	for (i = 0; i < N; i++) {
		for (j = 0; j < N - i; j++) {
			mat[i][j] = (count + S - 1) % T + 1;
			count++;
		}
	}
	printD();

	return 0;
}
