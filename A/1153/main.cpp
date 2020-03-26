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
#include <unordered_set>
#include <unordered_map>

using namespace std;

#define N_MAX 10000

struct Student {
	char card_num[14];
	int site;  // 方便type 3 query
	int score;
};
Student students[N_MAX];

// 根据不同的query，写index，对应于students的下标
map<char, vector<int>>indices_level;
map<int, vector<int>>indices_site;
map<int, vector<int>>indices_time;

bool cmp1(int& index0, int& index1) {
	if (students[index0].score != students[index1].score)
		return students[index0].score > students[index1].score;
	return strcmp(students[index0].card_num, students[index1].card_num) < 0;
}

#define SITE_MAX 1000
int counts_site[SITE_MAX];
// map<int, int>counts;  map效率低
bool cmp3(int& site0, int& site1) {
	if (counts_site[site0] != counts_site[site1])
		return counts_site[site0] > counts_site[site1];
	return site0 < site1;
}

int main() {
	int N, M;
	scanf("%d%d", &N, &M);

	int i;
	char level;
	int site, time;
	int score;
	for (i = 0; i < N; ++i) {
		scanf("%s %d", students[i].card_num, &(students[i].score));
		sscanf(students[i].card_num, "%c%3d%6d", &level, &site, &time);
		students[i].site = site;
		indices_level[level].push_back(i);
		indices_site[site].push_back(i);
		indices_time[time].push_back(i);
	}

	int command;

	int h, n_size, index;
	int sum_score;

	for (i = 1; i <= M; ++i) {
		scanf("%d", &command);

		if (command == 1) {
			scanf(" %c", &level);
			printf("Case %d: %d %c\n", i, command, level);
			if (indices_level.find(level) == indices_level.end())
				printf("NA\n");
			else {
				sort(indices_level[level].begin(), indices_level[level].end(), cmp1);

				n_size = indices_level[level].size();
				for (h = 0; h < n_size; ++h) {
					index = indices_level[level][h];
					printf("%s %d\n", students[index].card_num, students[index].score);
				}
			}
		}
		else if (command == 2) {
			scanf("%d", &site);
			printf("Case %d: %d %03d\n", i, command, site);
			if (indices_site.find(site) == indices_site.end())
				printf("NA\n");
			else {
				sum_score = 0;
				n_size = indices_site[site].size();
				for (h = 0; h < n_size; ++h) {
					index = indices_site[site][h];
					sum_score += students[index].score;
				}
				printf("%d %d\n", n_size, sum_score);
			}
		}
		else {
			scanf("%d", &time);
			printf("Case %d: %d %06d\n", i, command, time);
			if (indices_time.find(time) == indices_time.end())
				printf("NA\n");
			else {
				// 统计site分布
				for (h = 0; h < SITE_MAX; ++h)
					counts_site[h] = 0;
				n_size = indices_time[time].size();
				for (h = 0; h < n_size; ++h) {
					index = indices_time[time][h];
					++counts_site[students[index].site];
				}

				// 排序
				vector<int>result;
				for (h = 0; h < SITE_MAX; ++h)
					if (counts_site[h])
						result.push_back(h);
				sort(result.begin(), result.end(), cmp3);

				// 打印
				n_size = result.size();
				for (h = 0; h < n_size; ++h) {
					printf("%03d %d\n", result[h], counts_site[result[h]]);
				}
			}
		}
	}


	system("pause");
	return 0;
}