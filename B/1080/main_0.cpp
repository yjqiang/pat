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

#define NUM_MAX 30000
struct Student {
	string stu_id;

	// ������ҵ�ɼ�
	int G_p;
	// ����
	int G_mid;
	// ��ĩ
	int G_final;
	

	// ����
	int G;
};

Student students[NUM_MAX];

// �����ʱ�򣬰��û�����students���±��Ӧ
map<string, int>indexes;

int getIndex(string& stu_id) {
	int result;
	if (indexes.find(stu_id) == indexes.end()) {
		indexes[stu_id] = indexes.size();

		result = indexes[stu_id];
		// ��ʼ������
		students[result].stu_id = stu_id;
		students[result].G_p = -1;
		students[result].G_mid = -1;
		students[result].G_final = -1;
		return result;
	}
	return indexes[stu_id];
}

bool cmp(Student& a, Student& b) {
	if (a.G != b.G)
		return b.G < a.G;
	return a.stu_id < b.stu_id;
}

int main() {
	ios::sync_with_stdio(false);
	int P, M, N;
	cin >> P >> M >> N;

	int i;
	string s;
	int index, grade;
	for (i = 0; i < P; ++i) {
		cin >> s >> grade;
		index = getIndex(s);
		students[index].G_p = grade;
	}
	for (i = 0; i < M; ++i) {
		cin >> s >> grade;
		index = getIndex(s);
		students[index].G_mid = grade;
	}
	for (i = 0; i < N; ++i) {
		cin >> s >> grade;
		index = getIndex(s);
		students[index].G_final = grade;
	}

	int num = indexes.size();

	vector<Student>results;
	// �����ճɼ�����ɸѡ
	for (i = 0; i < num; ++i)
		if (students[i].G_p >= 200) {
			if (students[i].G_mid > students[i].G_final)
				// ��������
				students[i].G = int((students[i].G_mid * 0.4 + students[i].G_final * 0.6) + 0.5);
			else
				students[i].G = students[i].G_final;

			if (students[i].G >= 60)
				results.push_back(students[i]);

		}
	
	sort(results.begin(), results.end(), cmp);

	num = results.size();
	for (i = 0; i < num; ++i)
		printf("%s %d %d %d %d\n", results[i].stu_id.c_str(),
			results[i].G_p,
			results[i].G_mid,
			results[i].G_final,
			results[i].G);
	
	system("pause");
	return 0;
}