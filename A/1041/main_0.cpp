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

int counts[10001] = { 0 };
int nums[100001];

int main() {
	int N;
	scanf("%d", &N);

	int num;
	int i;
	for (i = 0; i < N; ++i) {
		scanf("%d", &num);
		nums[i] = num;
		++counts[num];
	}
	for (i = 0; i < N; ++i) {
		if (counts[nums[i]] == 1) {
			printf("%d", nums[i]);
			system("pause");
			return 0;
		}
			
	}
	printf("None");
	system("pause");
	return 0;
}