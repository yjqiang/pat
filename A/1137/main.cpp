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

struct Student {
	string StudentID;
	int G;
	// 在线分数
	int G_p;
	// 期中
	int G_mid_term;
	// 期末
	int G_final_term;
};

// indices[string] = index
// students[index] = student
map<string, int> indices;

vector<Student> students;
int n_students = 0;

bool cmp(Student& a, Student& b) {
	if (a.G != b.G)
		return a.G > b.G;
	return a.StudentID < b.StudentID;
}

int main() {
	ios::sync_with_stdio(false);
	int P, M, N;
	cin >> P >> M >> N;

	int i;
	string StudentID;
	int G_p;
	int G_mid_term;
	int G_final_term;

	for (i = 0; i < P; ++i) {
		cin >> StudentID >> G_p;
		// 输入的时候就筛选
		//  first obtain no less than 200 points from the online programming assignments
		if (G_p >= 200) {
			indices[StudentID] = n_students++;
			students.push_back(Student{ StudentID, -1, G_p, -1, -1});
		}
	}

	for (i = 0; i < M; ++i) {
		cin >> StudentID >> G_mid_term;
		// 输入的时候就筛选
		//  没有find到说明没有G_p，不合要求，不录入
		if (indices.find(StudentID) != indices.end())
			students[indices[StudentID]].G_mid_term = G_mid_term;
	}

	for (i = 0; i < N; ++i) {
		cin >> StudentID >> G_final_term;
		// 输入的时候就筛选
		//  没有find到说明没有G_p，不合要求，不录入
		if (indices.find(StudentID) != indices.end())
			students[indices[StudentID]].G_final_term = G_final_term;
	}

	for (i = 0; i < n_students; ++i) {
		G_final_term = students[i].G_final_term;
		G_mid_term = students[i].G_mid_term;
		// G_mid_term > G_final_term => G_mid_term 有效
		if (G_mid_term > G_final_term)
			// 四舍五入
			students[i].G = int(0.4 * G_mid_term + 0.6 * G_final_term + 0.5);
		else
			students[i].G = G_final_term;
	}

	// printf("\n");
	sort(students.begin(), students.end(), cmp);

	for (i = 0; i < n_students; ++i) {
		if (students[i].G >= 60)
			printf("%s %d %d %d %d\n",
				students[i].StudentID.c_str(),
				students[i].G_p,
				students[i].G_mid_term,
				students[i].G_final_term,
				students[i].G);
		else
			break;
	}

	system("pause");
	return 0;
}