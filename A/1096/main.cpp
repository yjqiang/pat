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



int main() {
	long long N;

	scanf("%lld", &N);

	// 连续因数有两个即以上元素时候，最大为sqrt(N) + 1否则(sqrt(N) + 1) * (sqrt(N) + 2)大于N
	long long max_result = (long long)sqrt(N) + 1;

	// [start, end]闭区间
	long long start, end;
	long long multiply_result;

	// 最大长度，以及对应的最小序列的起始
	long long max_num, max_start;
	max_num = -1;
	for (start = 2; start <= max_result; ++start) {
		multiply_result = 1;
		for (end = start; end <= max_result; ++end) {
			multiply_result *= end;
			if (N % multiply_result != 0)
				break;
			
			// 注意等于时候不处理，因为结果要求最小序列
			if (end - start + 1 > max_num) {
				max_num = end - start + 1;
				max_start = start;
			}
		}
	}
	// 一个元素找不到，为质数
	if (max_num == -1)
		printf("1\n%lld", N);
	else {
		// 找到一个元素也包含在这里
		printf("%lld\n", max_num);
		end = max_start + max_num - 1;
		printf("%lld", max_start);
		for (start = max_start + 1; start <= end; ++start)
			printf("*%lld", start);
	}


	system("pause");
	return 0;
}