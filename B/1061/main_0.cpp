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

#define M_MAX 101
int right_answers[M_MAX];
int scores[M_MAX];



int main() {
	int N, M;
	scanf("%d %d", &N, &M);

	int i;
	for (i = 0; i < M; ++i)
		scanf("%d", scores + i);
	for (i = 0; i < M; ++i)
		scanf("%d", right_answers + i);

	int h;
	int score;
	int answer;
	// 一个循环代表一个学生
	for (i = 0; i < N; ++i) {
		score = 0;
		for (h = 0; h < M; ++h) {
			scanf("%d", &answer);
			if (answer == right_answers[h])
				score += scores[h];
		}
		printf("%d\n", score);
	}

	system("pause");
	return 0;
}