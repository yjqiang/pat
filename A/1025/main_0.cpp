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
};

#define MAX_N 100
#define MAX_K 300

User users[MAX_N][MAX_K];
int test_locations[MAX_N];
int my_counts[MAX_N][101] = { 0 };

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
		for (h = 0; h < K; ++h)
			scanf("%s%d", users[i][h].registration_number, &(users[i][h].score));
	}

	printf("%d\n", sum);

	for (i = 0; i < N; ++i) {
		K = test_locations[i];
		qsort(users[i], K, sizeof(User), cmp);
		for (h = K - 1; h >= 0; --h) {
			if (h == K - 1 || users[i][h].score != users[i][h + 1].score)
				users[i][h].local_rank = K - h;
			else
				users[i][h].local_rank = users[i][h + 1].local_rank;
		}
	}




	int count, final_rank, last_index, pre_score;

	pre_score = INT_MAX;
	int max_score, max_location_number, local_rank;
	char min_registration_number[14];
	
	for (count = 1; count <= sum; ++count) {
		max_score = -1;
		min_registration_number[0] = '\0';
		for (i = 0; i < N; ++i) {
			last_index = test_locations[i] - 1;
			if (last_index >= 0) {
				if (users[i][last_index].score > max_score ||
					(users[i][last_index].score == max_score && (min_registration_number[0] == '\0' || strcmp(users[i][last_index].registration_number, min_registration_number) < 0))) {
					max_score = users[i][last_index].score;
					strcpy(min_registration_number, users[i][last_index].registration_number);
					max_location_number = i;
					local_rank = users[i][last_index].local_rank;
				}
			}
		}

		if (max_score != pre_score) {
			final_rank = count;
			pre_score = max_score;
		}
		else {
			// final_rank = final_rank;
			;
		}

		--test_locations[max_location_number];
		printf("%s %d %d %d\n", min_registration_number, final_rank, max_location_number + 1, local_rank);


	}




	system("pause");
	return 0;
}