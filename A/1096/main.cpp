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

	// ��������������������Ԫ��ʱ�����Ϊsqrt(N) + 1����(sqrt(N) + 1) * (sqrt(N) + 2)����N
	long long max_result = (long long)sqrt(N) + 1;

	// [start, end]������
	long long start, end;
	long long multiply_result;

	// ��󳤶ȣ��Լ���Ӧ����С���е���ʼ
	long long max_num, max_start;
	max_num = -1;
	for (start = 2; start <= max_result; ++start) {
		multiply_result = 1;
		for (end = start; end <= max_result; ++end) {
			multiply_result *= end;
			if (N % multiply_result != 0)
				break;
			
			// ע�����ʱ�򲻴�����Ϊ���Ҫ����С����
			if (end - start + 1 > max_num) {
				max_num = end - start + 1;
				max_start = start;
			}
		}
	}
	// һ��Ԫ���Ҳ�����Ϊ����
	if (max_num == -1)
		printf("1\n%lld", N);
	else {
		// �ҵ�һ��Ԫ��Ҳ����������
		printf("%lld\n", max_num);
		end = max_start + max_num - 1;
		printf("%lld", max_start);
		for (start = max_start + 1; start <= end; ++start)
			printf("*%lld", start);
	}


	system("pause");
	return 0;
}