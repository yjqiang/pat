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
#include <unordered_map>

using namespace std;

char str[100000];
char tmp[100000];

// 返回str长度
// num >= 1
int int2str(char* s, int num) {
	int i = 0;
	while (num){
		s[i++] = num % 10 + '0';
		num /= 10;
	}
	reverse(s, s + i);
	return i;
}

int main() {
	int N;
	scanf("%s%d", str, &N);

	int i, h, index_result;
	int start;
	int count;
	char c;
	for (i = 2; i <= N; ++i) {
		index_result = 0;
		for (h = 0; str[h] != '\0';) {
			// 这一个有重复元素(c)的小片段全遍历掉
			start = h;
			c = str[h];
			for (++h; str[h] != '\0' && str[h] == c; ++h);

			// count >= 1
			count = h - start;
			tmp[index_result++] = c;
			index_result += int2str(tmp + index_result, count);
		}
		tmp[index_result] = '\0';
		strcpy(str, tmp);
		
	}
	printf("%s\n", str);
	
	system("pause");
	return 0;
}