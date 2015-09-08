#include <stdio.h>

int is_big(char c) {
	return c >= 'A' && c <= 'Z';
}

int is_little(char c) {
	return c >= 'a' && c <= 'z';
}

char little2big(char c) {
	return c + ('A' - 'a');
}

char big2little(char c) {
	return c - ('A' - 'a');
}

int is_char(char c) {
	return is_big(c) || is_little(c);
}

int judgeA(char *word) {
	int i = 0;
	if (!is_little(word[0]))
		return 0;
	while (word[i] != '\0') {
		if (!is_char(word[i]))
			return 0;
		i++;
	}
	return 1;
}

int judgeB(char *word) {
	int i = 0;
	if (!is_little(word[0]))
		return 0;
	while (word[i] != '\0') {
		if (!is_little(word[i]) && word[i] != '_')
			return 0;
		if (word[i] == '_' && word[i + 1] == '_') // __
			return 0;
		i++;
	}
	if (word[i-1] == '_') // last is _
		return 0;
	return 1;
}

void A2B(char *word) {
	int i = 0;
	while (word[i] != '\0') {
		if (is_little(word[i]))
			printf("%c", word[i]);	
		else if (is_big(word[i]))
			printf("_%c", big2little(word[i]));
		i++;
	}
	printf("\n");
}

void B2A(char *word) {
	int i = 0;
	while (word[i] != '\0') {
		if (is_little(word[i])) {
			printf("%c", word[i]);	
			i += 1;
		}
		else if ('_' == word[i]) {
			printf("%c", little2big(word[i+1]));
			i += 2;
		}
	}
	printf("\n");
}

int main() {
	int n;
	int i;
	char word[105];

	freopen("language.in", "r", stdin);
	freopen("language.out", "w", stdout);

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%s", word);
		if(judgeA(word))
			A2B(word);
		else if(judgeB(word))
			B2A(word);
		else
			printf("Error\n");
	}
	return 0;
}
