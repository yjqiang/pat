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

// 统计证号 最大9999=>36
bool cache[40] = { false };

int main() {
	int N;

	scanf("%d", &N);

	int i;
	int num;
	// 统计各位数字之和
	int sum;
	for (i = 0; i < N; ++i) {
		scanf("%d", &num);
		sum = 0;
		while (num) {
			sum += num % 10;
			num /= 10;
		}
		cache[sum] = true;
	}

	int count = 0;
	for (i = 0; i < 40; ++i)
		if (cache[i])
			++count;
	printf("%d\n", count);
	if (count) {
		bool is_first = true;
		for (i = 0; i < 40; ++i)
			if (cache[i]) {
				if (is_first){
					printf("%d", i);
					is_first = false;
				}
				else
					printf(" %d", i);
			}
	}


	system("pause");
	return 0;
}