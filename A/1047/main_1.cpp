#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>

using namespace std;

#define K_MAX 2501
#define N_MAX 40000

vector<int> courses[K_MAX];
char students[N_MAX][5];

bool cmp(int& a, int& b) {
	return strcmp(students[a], students[b]) < 0;
}

int main() {
	int N, K;
	scanf("%d%d", &N, &K);

	int C, course_id;
	int i, h;
	for (i = 0; i < N; ++i) {
		scanf("%s %d", students[i], &C);
		for (h = 0; h < C; ++h) {
			scanf("%d", &course_id);
			courses[course_id].push_back(i);
		}
	}
	int n;
	for (i = 1; i <= K; ++i) {
		sort(courses[i].begin(), courses[i].end(), cmp);
		n = courses[i].size();
		printf("%d %d\n", i, n);
		for (h = 0; h < n; ++h)
			printf("%s\n", students[courses[i][h]]);
	}
	

	system("pause");
	return 0;
}