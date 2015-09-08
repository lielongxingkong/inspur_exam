#include <stdio.h>
#define N 1005

int A[N][N];
int S[N][N];

int max(int x, int y) {
	return x > y ? x : y;
}

int main() {
	int i, j;
	int n, m, k;
	int x, y, z;

	for(i = 0; i < N; i++) {
		for(j = 0; j < N; j++) {
			A[i][j]=0;
			S[i][j]=0;
		}
	}

	freopen("bus.in","r",stdin);
	scanf("%d %d %d", &n, &m, &k);
	for(i = 0; i < k; i++) {
		scanf("%d %d %d", &x, &y, &z);
		A[x][y] = z;
	}
/*
	for(j = m; j >=1; j--) {
		for(i = 1; i <= n; i++) {
			printf("%d ", A[i][j]);
		}
		printf("\n");
	}
*/

	//S[m][n] = max { S[m-1][n] , S[m][n-1] } + A[m][n]
	for(j = 1; j <= m; j++) {
		for(i = 1; i <= n; i++) {
			S[i][j] = max(S[i-1][j] , S[i][j-1]) 
				    + A[i][j];
		}
	}
/*
	for(j = m; j >=1; j--) {
		for(i = 1; i <= n; i++) {
			printf("%d ", S[i][j]);
		}
		printf("\n");
	}
*/

	freopen("bus.out","w",stdout);
	printf("%d\n",S[n][m]);

	return 0;
}
