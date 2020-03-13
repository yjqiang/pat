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


int main() {
	int N, M;
	scanf("%d%d", &N, &M);
	int i, h;


	int min_mark, max_mark, mark;
	int sum;
	// 老师给出的评分
	int G2;

	// 合法的打分个数
	int count_marks;

	double result;
	for (i = 0; i < N; ++i) {
		scanf("%d", &G2);
		sum = 0;
		min_mark = INT_MAX;
		max_mark = -1;
		count_marks = 0;
		for (h = 1; h < N; ++h) {
			scanf("%d", &mark);
			if (mark <= M && mark >= 0) {
				++count_marks;
				sum += mark;
				if (mark < min_mark)
					min_mark = mark;
				if (mark > max_mark)
					max_mark = mark;
			}

		}
		// 去掉最高分最低分 sum - max_mark - min_mark
		sum = sum - max_mark - min_mark;
		count_marks -= 2;

		result = ((double)sum / count_marks + G2) / 2;
		printf("%d\n", (int)(result + 0.5));
	}

	

	system("pause");
	return 0;
}