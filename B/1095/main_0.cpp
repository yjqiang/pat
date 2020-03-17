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

using namespace std;

struct Student {
	char ID[14];
	// ������
	int room;
	int score;
};

Student students[10000];

// ��PAT����index����ӦΪstudents��Ŀ����±�
map<char, vector<int>> PATs;

// ��roomid����index����ӦΪstudents��Ŀ����±�
// ����������999
map<int, vector<int>> rooms;

// ��time����index����ӦΪstudents��Ŀ����±�
//time������999999
map<int, vector<int>> times;

bool cmp1(int& a, int& b) {
	if (students[a].score != students[b].score)
		return students[a].score > students[b].score;
	return strcmp(students[a].ID, students[b].ID) < 0;
}

// �Ե��������ܸ�������
int counts[1000];

bool cmp3(int& a, int& b) {
	if (counts[a] != counts[b])
		return counts[a] > counts[b];
	return a < b;
}


int main() {
	int N, M;
	scanf("%d%d", &N, &M);

	char PAT;
	int room, time;

	int i, h;
	for (i = 0; i < N; ++i) {
		scanf("%s", students[i].ID);
		sscanf(students[i].ID, "%c%3d%6d", &PAT, &room, &time);
		scanf("%d", &(students[i].score));
		students[i].room = room;

		// index����
		PATs[PAT].push_back(i);

		rooms[room].push_back(i);

		times[time].push_back(i);
	}

	int command;
	vector<int>::iterator vector_i;
	int sum;
	
	vector<int> for_3;

	for (i = 1; i <= M; ++i) {
		scanf("%d", &command);
		if (command == 1) {
			// %c�����հ�
			scanf(" %c", &PAT);
			printf("Case %d: %d %c\n", i, command, PAT);

			if (PATs.find(PAT) == PATs.end())
				printf("NA\n");
			else {
				sort(PATs[PAT].begin(), PATs[PAT].end(), cmp1);
				for (vector_i = PATs[PAT].begin(); vector_i != PATs[PAT].end(); ++vector_i)
					printf("%s %d\n", students[*vector_i].ID, students[*vector_i].score);
			}
		}
		else if (command == 2) {
			scanf("%d", &room);
			printf("Case %d: %d %d\n", i, command, room);
			if (rooms.find(room) == rooms.end())
				printf("NA\n");
			else {
				sum = 0;
				for (vector_i = rooms[room].begin(); vector_i != rooms[room].end(); ++vector_i)
					sum += students[*vector_i].score;
				printf("%d %d\n", rooms[room].size(), sum);
			}
		}
		// command == 3
		else {
			scanf("%d", &time);
			printf("Case %d: %d %06d\n", i, command, time);
			if (times.find(time) == times.end())
				printf("NA\n");
			else {
				for (h = 0; h < 1000; ++h)
					counts[h] = 0;
				for_3.clear();
				// ͳ������
				for (vector_i = times[time].begin(); vector_i != times[time].end(); ++vector_i)
					++counts[students[*vector_i].room];

				for (h = 0; h < 1000; ++h)
					if (counts[h])
						for_3.push_back(h);
				sort(for_3.begin(), for_3.end(), cmp3);
				for (vector_i = for_3.begin(); vector_i != for_3.end(); ++vector_i)
					printf("%d %d\n", *vector_i, counts[*vector_i]);
			}
		}
	}
		
	system("pause");
	return 0;
}