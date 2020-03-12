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
	// ����ֵ
	int score;
	// ѡ�����
	int num_choices;
	// ��ȷѡ�����
	int correct_num_choices;
	// ���ַ����洢��ȷ�Ĵ�
	char correct_choices[6];
	
};

#define M_MAX 100

Test tests[M_MAX];
// ����ѡ��ͳ��
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
	// ��ѡ����ѡ
	bool is_less, is_more;
	// �÷�
	double score;

	// ÿ��ѭ��һ��ѧ��
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

			// �Ƚϴ���ѧ�����Ծ�
			// �����ڹ鲢
			for (i0 = 0, i1 = 0; actual_choices[i0] != '\0' && tests[h].correct_choices[i1] != '\0'; ) {
				if (actual_choices[i0] == tests[h].correct_choices[i1]) {
					++i0;
					++i1;
				}
				else if (actual_choices[i0] < tests[h].correct_choices[i1]) {
					// ����ض�ѡ��
					++counts[h][actual_choices[i0] - 'a'];
					is_more = true;
					// printf("%d+%c ", h, actual_choices[i0]);
					++i0;
				}
				else {
					// �������ѡ��
					++counts[h][tests[h].correct_choices[i1] - 'a'];
					// printf("%d-%c ", h, tests[h].correct_choices[i1]);
					is_less = true;
					++i1;
				}
			}
			// ����ض�ѡ��
			for (; actual_choices[i0] != '\0'; ++i0) {				
				++counts[h][actual_choices[i0] - 'a'];
				// printf("%d+%c ", h, actual_choices[i0]);
				is_more = true;
			}
			// �������ѡ��
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
	// ��ÿ����Ŀ����Ҫ����ÿ��ѡ������ͳ��
	for (i = 0; i < M; ++i)
		for (h = 0; h < tests[i].num_choices; ++h) {
			// �д���Ĳ�ͳ��
			if (counts[i][h] != 0) {
				if (counts[i][h] == max_wrong) {
					result.choice = h + 'a';
					// ��Ŵ�1��ʼ
					result.test_id = i + 1;
					results.push_back(result);
				}
				else if (counts[i][h] > max_wrong) {
					results.clear();
					result.choice = h + 'a';
					// ��Ŵ�1��ʼ
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