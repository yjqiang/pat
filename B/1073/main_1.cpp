// https://www.liuchuo.net/archives/4216
#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
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
	// 用位存储正确的答案， 设a为00001，b为00010，c为00100，d为01000，e为10000
	int correct_choices;
	
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
	int hash[] = { 1, 2, 4, 8, 16 };

	int i, h;
	char char_tmp;
	for (i = 0; i < M; ++i) {
		// 初始化
		tests[i].correct_choices = 0;
		scanf("%d %d %d", &(tests[i].score), &(tests[i].num_choices), &(tests[i].correct_num_choices));
		for (h = 0; h < tests[i].correct_num_choices; ++h) {
			scanf(" %c", &char_tmp);
			tests[i].correct_choices += hash[char_tmp-'a'];
		}
	}

	int k;
	int num_choices;
	int actual_choices;

	// 得分
	double score;
	int el;

	// 每个循环一个学生
	for (i = 0; i < N; ++i) {
		score = 0;

		for (h = 0; h < M; ++h) {
			while (getchar() != '(');
			scanf("%d", &num_choices);
			actual_choices = 0;
			for (k = 0; k < num_choices; ++k) {
				scanf(" %c", &char_tmp);
				actual_choices += hash[char_tmp - 'a'];
			}
			while (getchar() != ')');

			// 比较答案与学生的试卷
			el = actual_choices ^ tests[h].correct_choices; // 这两者是否有不一样的选择
			// 全对
			if (el == 0){
				score += tests[h].score;
			}
			else {
				// 少选了
				if ((actual_choices | tests[h].correct_choices) == tests[h].correct_choices)
					score += tests[h].score / 2.0;

				// 统计错误的选项
				for (k = 0; k < 5; ++k)
					// 某个选项比对
					if (hash[k] & el)
						++counts[h][k];
			}
				
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