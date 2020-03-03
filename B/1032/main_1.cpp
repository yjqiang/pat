#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#include <map>

#include <set>
#include <cstring>
#include <climits>
#include <cstdio>
#include <queue>

using namespace std;

#define N_MAX 100001
int schools[N_MAX] = { 0 };

int main() {
	
	int N;
	scanf("%d", &N);

	
	int i;
	int id, score;
	for (i = 0; i < N; ++i) {
		scanf("%d%d", &id, &score);
		schools[id] += score;
	}

	int max_element, max_index;
	max_element = INT_MIN;
	for (i = 1; i <= N; ++i) {
		if (schools[i] > max_element) {
			max_element = schools[i];
			max_index = i;
		}
	}
	printf("%d %d", max_index, max_element);


	system("pause");
	return 0;
}