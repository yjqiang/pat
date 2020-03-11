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

int main() {
	int N;
	scanf("%d", &N);

	int i;
	for (i = 0; i < N; ++i)
		scanf("%d", nums + i);

	int result = 0;
	for (i = 0; i < N; ++i) {
		// i���λ��δ��λ
		if (i != nums[i]) {
			// 0 ��λ�ˣ��Ͱ�0������ˮ
			if (nums[0] == 0) {
				swap(nums[0], nums[i]);
				++result;
			}

			// 0 δ�ָ�ԭλ��
			while (nums[0] != 0) {
				// ʹ�ø���Сδ��λ���ϵ��������ֶ�������ȷλ��
				swap(nums[0], nums[nums[0]]);
				++result;
			}
		}
	}

	printf("%d", result);
	system("pause");
	return 0;
}