#include <stdio.h>

#define N 50
#define MAX_MATCH 7

int reward_code[N];
int rewards[N];

void init(int* array) {
	int i;
	for(i = 0; i < N; i++) {
		array[i] = 0;
	}
}

int judge(int* bought_code) {
	int i, sum = 0;
	for (i = 0; i < N; i++) {
		if (bought_code[i] + reward_code[i] == 2) {
			sum++;
		}
	}
	return MAX_MATCH - sum;
}

int main() {
	int num; //lottery numbers
	int code; //reward code
	int i, j;
	int sum; //matched sum
	int bought_code[N];

	init(reward_code);
	init(rewards);

	freopen("lottery.in", "r", stdin);
	freopen("lottery.out", "w", stdout);
	scanf("%d", &num);
	for(i = 0; i < 7; i++) {
		scanf("%d", &code);
		reward_code[code] = 1;
	}
	for(i = 0; i < num; i++) {
		init(bought_code);
		for(j = 0; j < 7; j++) {
			scanf("%d", &code);
			bought_code[code] = 1;
		}
		rewards[judge(bought_code)] += 1;
	}
	for (i = 0; i < MAX_MATCH; i++) 
		printf("%d%c", rewards[i], (i == (MAX_MATCH - 1))? '\n':' ');
	return 0;
}
