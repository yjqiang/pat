#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cctype>
#include <algorithm>
#include <cmath>
# include <climits>
#include <cstring>
#include <map>
#include <cstdio>
#include <queue>

using namespace std;

struct User {
	int arrive_seconds;  // since 8:00 to the real time, how many seconds. Not the real arrival time
	int processing_minutes;
};

User users[10000];
int windows[100] = { 0 };  // end_time  since 8:00

int cmp(const void* p0, const void* p1) {
	User* user0 = (User*)p0;
	User* user1 = (User*)p1;
	return user0->arrive_seconds - user1->arrive_seconds;
}

int main() {
	int N, K;
	scanf("%d%d", &N, &K);

	int index;
	int hour, minute, second, processing_minutes, seconds;
	int real_N = 0;
	for (index = 0; index < N; ++index) {
		scanf("%d:%d:%d %d", &hour, &minute, &second, &processing_minutes);
		seconds = hour * 3600 + minute * 60 + second;
		if (seconds > 61200)  // 17:00:00
			continue;

		users[real_N].arrive_seconds = seconds - 28800;  // 8:00:00
		users[real_N].processing_minutes = processing_minutes > 60 ? 60 : processing_minutes;
		++real_N;
	}
	qsort(users, real_N, sizeof(User), cmp);

	int wait_seconds = 0;
	int index_window;

	int min_index_window, min_element_window;
	for (index = 0; index < real_N; ++index) {
		min_element_window = INT_MAX;
		for (index_window = 0; index_window < K; ++index_window)
			if (windows[index_window] < min_element_window) {
				min_element_window = windows[index_window];
				min_index_window = index_window;
			}

		if (min_element_window <= users[index].arrive_seconds) {
			windows[min_index_window] = users[index].arrive_seconds + users[index].processing_minutes * 60;
		}
		else {
			wait_seconds += min_element_window - users[index].arrive_seconds;
			windows[min_index_window] += users[index].processing_minutes * 60;
		}
	}
	printf("%.1f\n", wait_seconds / (60.0 * real_N));


	system("pause");


	return 0;
}