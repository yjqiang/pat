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
	// ����ֵ
	int score;
	// ѡ�����
	int num_choices;
	// ��ȷѡ�����
	int correct_num_choices;
	// ��λ�洢��ȷ�Ĵ𰸣� ��aΪ00001��bΪ00010��cΪ00100��dΪ01000��eΪ10000
	int correct_choices;
	
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
	int hash[] = { 1, 2, 4, 8, 16 };

	int i, h;
	char char_tmp;
	for (i = 0; i < M; ++i) {
		// ��ʼ��
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

	// �÷�
	double score;
	int el;

	// ÿ��ѭ��һ��ѧ��
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

			// �Ƚϴ���ѧ�����Ծ�
			el = actual_choices ^ tests[h].correct_choices; // �������Ƿ��в�һ����ѡ��
			// ȫ��
			if (el == 0){
				score += tests[h].score;
			}
			else {
				// ��ѡ��
				if ((actual_choices | tests[h].correct_choices) == tests[h].correct_choices)
					score += tests[h].score / 2.0;

				// ͳ�ƴ����ѡ��
				for (k = 0; k < 5; ++k)
					// ĳ��ѡ��ȶ�
					if (hash[k] & el)
						++counts[h][k];
			}
				
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