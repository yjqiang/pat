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



int main() {
	int N, M;
	scanf("%d%d", &N, &M);

	int i;
	int article_id;
	// 违禁物品
	set<int> ban_article_ids;
	for (i = 0; i < M; ++i) {
		scanf("%d", &article_id);
		ban_article_ids.insert(article_id);
	}

	char stu_name[5];
	int K;
	int h;

	int n_ban_stu = 0, n_ban_article = 0;
	// 是否该查禁物品是该生的第一个被查禁的
	bool is_first;
	for (i = 0; i < N; ++i) {
		scanf("%s%d", stu_name, &K);

		is_first = true;
		for (h = 0; h < K; ++h) {
			scanf("%d", &article_id);
			if (ban_article_ids.find(article_id) != ban_article_ids.end()) {
				++n_ban_article;
				if (is_first) {
					printf("%s: %04d", stu_name, article_id);
					is_first = false;
				}
				else
					printf(" %04d", article_id);
			}
		}

		// 该生有被查禁的物品
		if (!is_first) {
			++n_ban_stu;
			printf("\n");
		}

	}
	printf("%d %d", n_ban_stu, n_ban_article);

	system("pause");
	return 0;
}