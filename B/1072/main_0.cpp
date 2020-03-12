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
	// Î¥½ûÎïÆ·
	set<int> ban_article_ids;
	for (i = 0; i < M; ++i) {
		scanf("%d", &article_id);
		ban_article_ids.insert(article_id);
	}

	char stu_name[5];
	int K;
	int h;
	vector<int> results;
	int n_results;

	int n_ban_stu = 0, n_ban_article = 0;
	for (i = 0; i < N; ++i) {
		scanf("%s%d", stu_name, &K);

		results.clear();
		for (h = 0; h < K; ++h) {
			scanf("%d", &article_id);
			if (ban_article_ids.find(article_id) != ban_article_ids.end()) {
				++n_ban_article;
				results.push_back(article_id);
			}
		}

		n_results = results.size();
		if (n_results) {
			++n_ban_stu;
			printf("%s:", stu_name);
			for (h = 0; h < n_results; ++h)
				printf(" %04d", results[h]);
			printf("\n");
		}
	}
	printf("%d %d", n_ban_stu, n_ban_article);

	system("pause");
	return 0;
}