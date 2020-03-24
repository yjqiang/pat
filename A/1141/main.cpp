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

// indices[school_name] = index
// schools[index] = school
map<string, int>indices;

struct School {
	string school_name;
	// 加权分
	double double_TWS;
	int int_TWS;
	// 学生数
	int Ns;

	bool operator<(const School& b)const{
		if (int_TWS != b.int_TWS)
			return int_TWS > b.double_TWS;
		if (Ns != b.Ns)
			return Ns < b.Ns;
		return school_name < b.school_name;
	}
};
int n_schools = 0;
vector<School> schools;

int str2int(string& school_name) {
	int result;
	if (indices.find(school_name) == indices.end()) {
		result = n_schools++;
		indices[school_name] = result;
		schools.push_back(School{ school_name, 0, 0, 0 });
	}
	else
		result = indices[school_name];
	return result;
}

int main() {
	ios::sync_with_stdio(false);
	int N;
	cin >> N;

	string school_name;
	int score;
	string ID;
	int index;
	int i, h;
	for (i = 0; i < N; ++i) {
		cin >> ID >> score >> school_name;
		// 转为小写
		for (h = school_name.size() - 1; h >= 0; --h)
			school_name[h] = tolower(school_name[h]);

		index = str2int(school_name);
		if (ID[0] == 'B')
			schools[index].double_TWS += score / 1.5;
		else if (ID[0] == 'A')
			schools[index].double_TWS += score;
		else
			schools[index].double_TWS += score * 1.5;

		++schools[index].Ns;
	}
	
	for (i = 0; i < n_schools; ++i)
		schools[i].int_TWS = (int)schools[i].double_TWS;

	sort(schools.begin(), schools.end());
	printf("%d\n", n_schools);

	int cur_score = -1;
	int cur_rank;
	for (i = 0; i < n_schools; ++i) {
		// score 变了排名就改了
		// 否则排名并列
		if (schools[i].int_TWS != cur_score) {
			cur_score = schools[i].int_TWS;
			cur_rank = i + 1;
		}

		printf("%d %s %d %d\n", cur_rank, schools[i].school_name.c_str(), schools[i].int_TWS, schools[i].Ns);
	}
	
	system("pause");
	return 0;
}