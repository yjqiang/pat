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
#include <set>
#include <unordered_set>

using namespace std;

#define LEN_MAX 1000001

bool is_exist[128] = { false };

char s[LEN_MAX];

int main() {
	// 读A处理A
	cin.getline(s, LEN_MAX);

	int cur;
	int i;
	for (i = 0; s[i] != '\0'; ++i) {
		cur = s[i];

		if (!is_exist[cur])
			printf("%c", cur);

		is_exist[cur] = true;
	}

	// 读B处理B
	cin.getline(s, LEN_MAX);
	for (i = 0; s[i] != '\0'; ++i) {
		cur = s[i];

		if (!is_exist[cur])
			printf("%c", cur);

		is_exist[cur] = true;
	}
		
	system("pause");
	return 0;
}