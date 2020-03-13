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

#define K_MAX 6
#define N_MAX 10001

struct User {
	int user_id;
	// �ܷ�
	int score;
	// ������Ŀ;
	int count_full;
	// -2��ʾû���ύ��-1��ʾûpass�������ʾ��������
	int partial_scores_obtained[K_MAX];
};

int N, K, M;

// �����ʱ��index��user_id��ͬ�������룻֮�󲻸����� 
User users[N_MAX];
// ��Ŀ��ֵ�������indexһ��
int full_marks[K_MAX];

bool isAvailable(int* scores) {
	int i;
	for (i = 1; i <= K; ++i)
		// -1 -2 ������
		if (scores[i] >= 0)
			return true;
	return false;
}

int cmp(const void* p0, const void* p1) {
	User* user0 = (User*)p0;
	User* user1 = (User*)p1;

	if (user0->score != user1->score)
		return user1->score - user0->score;
	if (user0->count_full != user1->count_full)
		return user1->count_full - user0->count_full;
	return user0->user_id - user1->user_id;
}

int main() {
	scanf("%d%d%d", &N, &K, &M);
	int i, h;

	for (i = 1; i <= N; ++i)
		for (h = 0; h < K_MAX; ++h)
			// ȫ������Ϊδ�ύ
			users[i].partial_scores_obtained[h] = -2;

	
	int score;
	for (i = 1; i <= K; ++i) {
		scanf("%d", &score);
		full_marks[i] = score;
	}

	int user_id, problem_id;
	for (i = 0; i < M; ++i) {
		scanf("%d%d%d", &user_id, &problem_id, &score);
		// ����ύ��ȡ��߷�
		users[user_id].partial_scores_obtained[problem_id] = max(users[user_id].partial_scores_obtained[problem_id], score);
	}
	
	// ɾ�����в��ϸ���û���For those who has never submitted any solution that can pass the compiler, or has never submitted any solution��
	// hΪ��ָ��
	int g;
	for (i = 1, h = 1; h <= N; ++h)
		if (isAvailable(users[h].partial_scores_obtained)) {
			// �����У�����һֱû��user_id�ģ�user_id��indexһ��
			users[i].user_id = h;
			for (g = 1; g <= K; ++g)
				users[i].partial_scores_obtained[g] = users[h].partial_scores_obtained[g];

			++i;
		}
	// �޳�����Ҫ����û�֮��������N
	N = i - 1;
	
	// printf("\n\n");

	// �����������
	for (i = 1; i <= N; ++i) {
		users[i].score = 0;
		users[i].count_full = 0;
		for (h = 1; h <= K; ++h) {
			if (users[i].partial_scores_obtained[h] == full_marks[h])
				++users[i].count_full;
			// -1 -2 �����������
			if (users[i].partial_scores_obtained[h] >= 0)
				users[i].score += users[i].partial_scores_obtained[h];
		}
	}

	qsort(users + 1, N, sizeof(User), cmp);

	int cur_rank = 0, cur_score = INT_MAX;
	for (i = 1; i <= N; ++i) {
		// �����طֽ�������������
		if (users[i].score != cur_score) {
			cur_rank = i;
			cur_score = users[i].score;
		}
		printf("%d %05d %d", cur_rank, users[i].user_id, users[i].score);
		for (h = 1; h <= K; ++h) {
			score = users[i].partial_scores_obtained[h];
			if (score == -1)
				printf(" 0");
			else if (score == -2)
				printf(" -");
			else
				printf(" %d", score);
		}
		printf("\n");

	}

	system("pause");
	return 0;
}