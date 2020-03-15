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

struct School {
	// 加权值
	double double_sum;

	// 加权的整数部分
	int int_sum;
	int count;

	string school_name;
};

// indexes[school] = 在schools里面的index 
map<string, int>indexes;
School schools[100000];

// 查找学校的index，用于输入的时候的定位
int str2int(string& s) {
	int result;
	if (indexes.find(s) == indexes.end()) {
		result = indexes.size();
		indexes[s] = result;


		// 初始化
		schools[result].double_sum = 0;
		schools[result].count = 0;
		schools[result].school_name = s;
		return result;
	}

	return indexes[s];
}

int cmp(const void* p0, const void* p1) {
	School* a = (School*)p0;
	School* b = (School*)p1;

	if (a->int_sum != b->int_sum)
		return b->int_sum - a->int_sum;
	if (a->count != b->count)
		return a->count - b->count;
	return a->school_name.compare(b->school_name);
}

int main() {
	int N;
	string ID, school_name;
	int score;

	cin >> N;

	int i, h;
	int index;
	for (i = 0; i < N; ++i) {
		cin >> ID >> score >> school_name;

		for (h = school_name.size() - 1; h >= 0; --h)
			school_name[h] = tolower(school_name[h]);

		index = str2int(school_name);

		switch (ID[0]) {
		case 'B': schools[index].double_sum += score / 1.5; break;
		case 'A': schools[index].double_sum += score; break;
		case 'T': schools[index].double_sum += score * 1.5; break;
		}

		++schools[index].count;
	}

	int n_school = indexes.size();

	printf("%d\n", n_school);
	for (i = 0; i < n_school; ++i)
		schools[i].int_sum = int(schools[i].double_sum);

	qsort(schools, n_school, sizeof(School), cmp);

	int rank;
	long long cur_sum;

	rank = 0;
	cur_sum = INT_MAX;
	for (i = 0; i < n_school; ++i) {
		if (schools[i].int_sum != cur_sum) {
			cur_sum = schools[i].int_sum;
			rank = i + 1;
		}
		//else
		//	rank = rank;
		printf("%d %s %d %d\n", rank, schools[i].school_name.c_str(), schools[i].int_sum, schools[i].count);

	}


	system("pause");
	return 0;
}