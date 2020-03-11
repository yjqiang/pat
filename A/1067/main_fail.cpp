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

using namespace std;

#define N_MAX 100002

int nums[N_MAX];
bool check_set[N_MAX] = { false };

int main() {
	int N;
	scanf("%d", &N);

	int i;
	for (i = 0; i < N; ++i)
		scanf("%d", nums + i);

	int start;
	// count_sets 未排好顺序的最小集合的个数，sum_sets_element为这样的集合元素个数之和。
	int count_sets, sum_sets_element;
	for (count_sets= 0, sum_sets_element=0, i = 0; i < N; ++i) {
		
		if (!check_set[i]) {
			// 找到一个新的set，set内乱序
			if (nums[i] != i) {
				++count_sets;
				
				// 找到set的大小
				start = i;
				do {
					check_set[i] = true;
					++sum_sets_element;
					// printf("%d ", i);
					i = nums[i];
					
				} while (i != start);
				// printf("\n");
			}
		}
		check_set[i] = true;
	}
	if (count_sets == 0)
		printf("0");
	else
		printf("%d", sum_sets_element + count_sets - 2);


	system("pause");
	return 0;
}