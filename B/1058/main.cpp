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

struct Task {
	int score;
	int n_all;
	int n_right_answers;
	char right_answers[5];
};

#define M_MAX 100
int counts_error[M_MAX] = { 0 };

Task tasks[M_MAX];

int main() {
	int N, M;
	scanf("%d %d", &N, &M);

	int i, h;
	char c;

	for (i = 0; i < M; ++i) {
		scanf("%d %d %d", &(tasks[i].score), &(tasks[i].n_all), &(tasks[i].n_right_answers));
		for (h = 0; h < tasks[i].n_right_answers; ++h) {
			// 读取空格以及有效字符
			scanf(" %c", &c);
			tasks[i].right_answers[h] = c;
		}
		tasks[i].right_answers[tasks[i].n_right_answers] = '\0';
	}

	int n_answers;
	int k;
	char answers[5];
	int score;
	// N 个人
	for (i = 0; i < N; ++i) {
		score = 0;
		// M 道题目
		for (h = 0; h < M; ++h) {
			while (getchar() != '(');
			scanf("%d", &n_answers);
			for (k = 0; k < n_answers; ++k)
				scanf(" %c", answers + k);
			answers[n_answers] = '\0';
			while (getchar() != ')');

			if (strcmp(answers, tasks[h].right_answers))
				++counts_error[h];
			else
				score += tasks[h].score;
			
		}
		printf("%d\n", score);
	}

	vector<int> results;
	int max_element = -1;
	for (i = 0; i < M; ++i) {
		// printf("%d -> %d\n", i, counts_error[i]);
		if (counts_error[i] > max_element) {
			max_element = counts_error[i];
			results.clear();
			results.push_back(i+1);
		}
		else if (counts_error[i] == max_element)
			results.push_back(i+1);
	}
	
	
	if (max_element == 0)
		printf("Too simple");
	else {
		printf("%d", max_element);
		for (i = 0; i < results.size(); ++i)
			printf(" %d", results[i]);
	}

	system("pause");
	return 0;
}