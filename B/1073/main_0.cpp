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

struct Test {
	// 满分值
	int score;
	// 选项个数
	int num_choices;
	// 正确选项个数
	int correct_num_choices;
	// 用字符串存储正确的答案
	char correct_choices[6];
	
};

#define M_MAX 100

Test tests[M_MAX];
// 错误选项统计
int counts[M_MAX][5] = { 0 };

struct Result {
	int test_id;
	char choice;
};


int main() {
	int N, M;
	scanf("%d%d", &N, &M);

	int i, h;
	char char_tmp;
	for (i = 0; i < M; ++i) {
		scanf("%d %d %d", &(tests[i].score), &(tests[i].num_choices), &(tests[i].correct_num_choices));
		for (h = 0; h < tests[i].correct_num_choices; ++h) {
			scanf(" %c", &char_tmp);
			tests[i].correct_choices[h] = char_tmp;
		}
		tests[i].correct_choices[tests[i].correct_num_choices] = '\0';
	}

	int k;
	int num_choices;
	char actual_choices[6];

	int i0, i1;
	// 少选，多选
	bool is_less, is_more;
	// 得分
	double score;

	// 每个循环一个学生
	for (i = 0; i < N; ++i) {
		score = 0;
		for (h = 0; h < M; ++h) {
			while (getchar() != '(');
			scanf("%d", &num_choices);
			for (k = 0; k < num_choices; ++k) {
				scanf(" %c", &char_tmp);
				actual_choices[k] = char_tmp;
			}
			actual_choices[num_choices] = '\0';
			while (getchar() != ')');

			is_less = false;
			is_more = false;

			// 比较答案与学生的试卷
			// 类似于归并
			for (i0 = 0, i1 = 0; actual_choices[i0] != '\0' && tests[h].correct_choices[i1] != '\0'; ) {
				if (actual_choices[i0] == tests[h].correct_choices[i1]) {
					++i0;
					++i1;
				}
				else if (actual_choices[i0] < tests[h].correct_choices[i1]) {
					// 错误地多选了
					++counts[h][actual_choices[i0] - 'a'];
					is_more = true;
					// printf("%d+%c ", h, actual_choices[i0]);
					++i0;
				}
				else {
					// 错误地少选了
					++counts[h][tests[h].correct_choices[i1] - 'a'];
					// printf("%d-%c ", h, tests[h].correct_choices[i1]);
					is_less = true;
					++i1;
				}
			}
			// 错误地多选了
			for (; actual_choices[i0] != '\0'; ++i0) {				
				++counts[h][actual_choices[i0] - 'a'];
				// printf("%d+%c ", h, actual_choices[i0]);
				is_more = true;
			}
			// 错误地少选了
			for (; tests[h].correct_choices[i1] != '\0'; ++i1) {
				++counts[h][tests[h].correct_choices[i1] - 'a'];
				// printf("%d-%c ", h, tests[h].correct_choices[i1]);
				is_less = true;
			}
			// printf("\n");
			if (!is_less && !is_more)
				score += tests[h].score;
			else if (is_less && !is_more)
				score += tests[h].score / 2.0;
		}
		printf("%.1lf\n", score);
	}

	int max_wrong = -1;
	vector<Result>results;
	Result result;
	// 对每个题目，都要讨论每个选项错误的统计
	for (i = 0; i < M; ++i)
		for (h = 0; h < tests[i].num_choices; ++h) {
			// 有错题的才统计
			if (counts[i][h] != 0) {
				if (counts[i][h] == max_wrong) {
					result.choice = h + 'a';
					// 编号从1开始
					result.test_id = i + 1;
					results.push_back(result);
				}
				else if (counts[i][h] > max_wrong) {
					results.clear();
					result.choice = h + 'a';
					// 编号从1开始
					result.test_id = i + 1;
					results.push_back(result);
					max_wrong = counts[i][h];
				}
					

			}
		}

	for (i = 0; i < results.size(); ++i)
		printf("%d %d-%c\n", max_wrong, results[i].test_id, results[i].choice);
	if (!results.size())
		printf("Too simple");
	system("pause");
	return 0;
}