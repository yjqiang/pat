#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#include <map>

#include <set>

#include <climits>
#include <cstdio>
#include <queue>
#include <string>
#include <cstdlib>

using namespace std;

char name[1000][11];
char password[1000][11];
bool results[10000];

bool isOk(char* a) {
	int i;
	char char_tmp;
	bool result = true;
	for (i = 0; a[i] != '\0'; ++i) {
		char_tmp = a[i];

		if (char_tmp == '1') {
			a[i] = '@';
			result = false;
		}
		else if (char_tmp == '0') {
			a[i] = '%';
			result = false;
		}
		else if (char_tmp == 'l') {
			a[i] = 'L';
			result = false;
		}
		else if (char_tmp == 'O') {
			a[i] = 'o';
			result = false;
		}


	}
	return result;
}

int main() {
	int N;
	scanf("%d", &N);

	int i;
	for (i = 0; i < N; ++i)
		scanf("%s %s", name[i], password[i]);

	int count = 0;
	for (i = 0; i < N; ++i) {
		results[i] = isOk(password[i]);
		if (!results[i])
			++count;
	}

	if (count) {
		printf("%d\n", count);
		for (i = 0; i < N; ++i)
			if (!results[i])
				printf("%s %s\n", name[i], password[i]);
	}
	else if (N == 1)
		printf("There is 1 account and no account is modified");
	else
		printf("There are %d accounts and no account is modified", N);
	system("pause");
	return 0;
}