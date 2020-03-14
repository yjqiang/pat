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
	int N;
	scanf("%d", &N);

	int i;
	int ID, x, y, score;

	// 最好的score 得分最少（距离中心最近）
	int closest_score, furthest_score;
	int closest_ID, furthest_ID;

	closest_score = INT_MAX;
	furthest_score = INT_MIN;

	for (i = 0; i < N; ++i) {
		scanf("%d%d%d", &ID, &x, &y);
		score = x * x + y * y;

		if (score < closest_score) {
			closest_score = score;
			closest_ID = ID;
		}
		if (score > furthest_score) {
			furthest_score = score;
			furthest_ID = ID;
		}
	}

	printf("%04d %04d", closest_ID, furthest_ID);
		
	
	system("pause");
	return 0;
}