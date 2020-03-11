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
	// count_sets δ�ź�˳�����С���ϵĸ�����sum_sets_elementΪ�����ļ���Ԫ�ظ���֮�͡�
	int count_sets, sum_sets_element;
	for (count_sets= 0, sum_sets_element=0, i = 0; i < N; ++i) {
		
		if (!check_set[i]) {
			// �ҵ�һ���µ�set��set������
			if (nums[i] != i) {
				++count_sets;
				
				// �ҵ�set�Ĵ�С
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