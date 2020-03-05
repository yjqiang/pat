#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#include <map>

#include <set>

#include <climits>
#include <cstdio>
#include <queue>
#include <string>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

char s[10001];
int counts[128] = { 0 };
char wanted[] = "PATest";

int main() {
	scanf("%s", s);
	int i;
	for (i = 0; s[i] != '\0'; ++i)
		++counts[(int)s[i]];

	bool is_end;

	do {
		is_end = true;
		for (i = 0; wanted[i] != '\0'; ++i)
			if (counts[(int)wanted[i]] > 0) {
				printf("%c", wanted[i]);
				--counts[(int)wanted[i]];
				is_end = false;
			}

	} while (!is_end);

	system("pause");
	return 0;
}