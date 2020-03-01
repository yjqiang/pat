#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#include <map>

#include <set>
#include <cstring>
#include <climits>
#include <cstdio>

using namespace std;

struct User {
	char registration_number[14];
	int score;
	int local_rank;
	int location_number;
	int final_rank;
};

#define MAX_N 100
#define MAX_K 300

User users[MAX_N][MAX_K];
int test_locations[MAX_N];
int my_counts[MAX_N][101] = { 0 };
User all_users[MAX_N * MAX_K];

int cmp(const void* p0, const void* p1) {
	User* user0 = (User*)p0;
	User* user1 = (User*)p1;
	if (user0->score != user1->score)
		return user0->score - user1->score;
	return strcmp(user1->registration_number, user0->registration_number);

}

int main() {
	int N, K;

	scanf("%d", &N);

	int i, h;
	int sum = 0;
	for (i = 0; i < N; ++i) {
		scanf("%d", &K);
		test_locations[i] = K;
		sum += K;
		for (h = 0; h < K; ++h) {
			scanf("%s%d", users[i][h].registration_number, &(users[i][h].score));
			users[i][h].location_number = i + 1;
		}
	}

	printf("%d\n", sum);

	int tmp_int = 0;
	for (i = 0; i < N; ++i) {
		K = test_locations[i];
		qsort(users[i], K, sizeof(User), cmp);
		for (h = K - 1; h >= 0; --h) {
			if (h == K - 1 || users[i][h].score != users[i][h + 1].score)
				users[i][h].local_rank = K - h;
			else
				users[i][h].local_rank = users[i][h + 1].local_rank;

			// move
			strcpy(all_users[tmp_int].registration_number, users[i][h].registration_number);
			all_users[tmp_int].local_rank = users[i][h].local_rank;
			all_users[tmp_int].location_number = users[i][h].location_number;
			all_users[tmp_int].score = users[i][h].score;

			++tmp_int;
		}
	}

	qsort(all_users, sum, sizeof(User), cmp);



	for (i = sum - 1; i >= 0; --i) {
		if (i == sum - 1 || all_users[i].score != all_users[i + 1].score)
			all_users[i].final_rank = sum - i;
		else
			all_users[i].final_rank = all_users[i + 1].final_rank;
	}

	for (i = sum - 1; i >= 0; --i)
		printf("%s %d %d %d\n", all_users[i].registration_number, all_users[i].final_rank, all_users[i].location_number, all_users[i].local_rank);

	system("pause");
	return 0;
}