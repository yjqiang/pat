#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#include <map>

#include <set>

#include <climits>
#include <cstdio>
#include <queue>
#include <string>

using namespace std;

#define N_MAX 100001
char broken[N_MAX];
char normal[N_MAX];

bool dict[128] = { false };

int main() {
	cin.getline(broken, N_MAX - 1);
	cin.getline(normal, N_MAX - 1);
	int i;
	char char_tmp;

	for (i = 0; broken[i] != '\0'; ++i)
		dict[broken[i]] = true;


	for (i = 0; normal[i] != '\0'; ++i) {
		char_tmp = normal[i];
		if (isupper(char_tmp) && dict['+'])
			continue;
		if (dict[toupper(char_tmp)])
			continue;
		printf("%c", normal[i]);
	}
	


	system("pause");
	return 0;
}