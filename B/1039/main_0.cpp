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

int counts[128] = { 0 };
char a[1001];

int main() {
	scanf("%s", a);

	int i;
	for (i = 0; a[i] != '\0'; ++i)
		++counts[int(a[i])];

	scanf("%s", a);
	for (i = 0; a[i] != '\0'; ++i)
		--counts[int(a[i])];

	int result_more = 0;
	int result_less = 0;
	for (i = 0; i < 128; ++i) {
		if (counts[i] >= 0)
			result_more += counts[i];
		else
			result_less += -counts[i];
	}
	if (result_less)
		printf("No %d", result_less);
	else
		printf("Yes %d", result_more);

		
	system("pause");
	return 0;
}