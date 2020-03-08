#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <map>
#include <cmath>
#include <climits>
#include <queue>

using namespace std;

#define N_MAX 100001
char s[N_MAX];


int main() {
	cin.getline(s, N_MAX);

	int sum = 0;
	char char_tmp;
	int i;
	for (i = 0; s[i] != '\0'; ++i) {
		char_tmp = tolower(s[i]);
		if (isalpha(char_tmp))
			sum += char_tmp - 'a' + 1;
	}

	int count1 = 0;
	int count0 = 0;
	while (sum) {
		if (sum % 2)
			++count1;
		else
			++count0;
		sum /= 2;
	}
	printf("%d %d", count0, count1);

	system("pause");
	return 0;
}