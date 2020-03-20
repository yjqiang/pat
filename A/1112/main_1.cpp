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

char s[1001];

// 一定正常的（不是n*k的一定没卡）
bool normal[128] = { false };

// 打印卡住的键的时候，只打印一次就可以了
bool duplicate[128] = { false };


int main() {
	int k;
	scanf("%d %s", &k, s);

	char c;
	int i, h;
	int start;  // 重复字符串的起始位置(重复长度为1也包含在内)
	int len; // 重复字符串长度

	for (i = 0; s[i] != '\0';) {
		start = i;
		c = s[i];
		for (++i; s[i] != '\0' && s[i] == c; ++i);

		len = i - start;
		if (len % k != 0)
			normal[c] = true;
	}

	for (i = 0; s[i] != '\0';) {
		start = i;
		c = s[i];
		for (++i; s[i] != '\0' && s[i] == c; ++i);

		len = i - start;
		// 未在normal，才算真的卡了
		if (!normal[c])
			if (!duplicate[c]) {
				duplicate[c] = true;
				printf("%c", c);
			}
			
	}
	printf("\n");
	for (i = 0; s[i] != '\0';) {
		start = i;
		c = s[i];
		for (++i; s[i] != '\0' && s[i] == c; ++i);

		len = i - start;
		// 未在normal，才算真的卡了
		if (!normal[c])
			len = len / k;  // 打印出来的个数/k == 实际的个数

		for (h = 0; h < len; ++h)
			printf("%c", c);
	}

	system("pause");
	return 0;
}