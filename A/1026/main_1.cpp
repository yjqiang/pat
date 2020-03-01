#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#include <map>

#include <set>
#include <cstring>
#include <climits>
#include <cstdio>
#include <queue>

using namespace std;

struct Player {
	int arrive_time;  // (a%3600):((a%3600)/60):(a%60)
	int play_time; // minutes
};

#define N_MAX 10000
#define K_MAX 101

Player ordinary_players[N_MAX];
Player vip_players[N_MAX];
int tables[K_MAX];
bool is_vip_tables[K_MAX] = { false };  // (is_vip_table[i]) => i is vip_table  else: ordinay_table
int counts[K_MAX] = { 0 };

int myCmp(const void* p0, const void* p1) {
	Player* player0 = (Player*)p0;
	Player* player1 = (Player*)p1;
	return player0->arrive_time - player1->arrive_time;
}

bool findNextByCmpArriveTime(int& index_first_ordinary_player, int N_ordinary_players, int& index_first_vip_player, int N_vip_players, int& arrive_time, int& play_time) {
	// assert (index_first_ordinary_player < N_ordinary_players || index_first_vip_player < N_vip_players)
	int a, b;
	if (index_first_ordinary_player < N_ordinary_players)
		a = ordinary_players[index_first_ordinary_player].arrive_time;
	else
		a = INT_MAX;

	if (index_first_vip_player < N_vip_players)
		b = vip_players[index_first_vip_player].arrive_time;
	else
		b = INT_MAX;

	// assert a != b
	if (a < b) {
		arrive_time = a;
		play_time = ordinary_players[index_first_ordinary_player].play_time;
		++index_first_ordinary_player;
		return false; // not vip
	}
	else {
		arrive_time = b;
		play_time = vip_players[index_first_vip_player].play_time;
		++index_first_vip_player;
		return true; // vip
	}

}

int main() {
	int N, N_ordinary_players, N_vip_players;
	scanf("%d", &N);

	int i;
	int hour, minute, second, play_time, is_vip;
	N_ordinary_players = 0;
	N_vip_players = 0;
	for (i = 0; i < N; ++i) {
		scanf("%d:%d:%d %d %d", &hour, &minute, &second, &play_time, &is_vip);
		play_time = (play_time > 120) ? 120 : play_time;  // 2 hour
		if (is_vip == 1) {
			vip_players[N_vip_players].arrive_time = hour * 3600 + minute * 60 + second;
			vip_players[N_vip_players].play_time = play_time;
			++N_vip_players;
		}
		else {
			ordinary_players[N_ordinary_players].arrive_time = hour * 3600 + minute * 60 + second;
			ordinary_players[N_ordinary_players].play_time = play_time;
			++N_ordinary_players;
		}
	}

	int K, M, id_vip_table;
	scanf("%d %d", &K, &M);

	for (i = 0; i < M; ++i) {
		scanf("%d", &id_vip_table);
		is_vip_tables[id_vip_table] = true;
	}

	qsort(vip_players, N_vip_players, sizeof(Player), myCmp);
	qsort(ordinary_players, N_ordinary_players, sizeof(Player), myCmp);


	for (i = 1; i <= K; ++i)
		tables[i] = 28800; // 08:00:00

	int h;
	int min_element, min_index;
	int index_first_ordinary_player = 0, index_first_vip_player = 0;
	int arrive_time;
	bool bool_is_vip;
	for (i = 0; i < N; ++i) {
		// find which table can be finished soon
		min_element = INT_MAX;
		for (h = 1; h <= K; ++h)
			if (tables[h] < min_element) {
				min_element = tables[h];
				min_index = h;
			}

		// choose which player would be the next one
		if (is_vip_tables[min_index]) {
			if (index_first_vip_player < N_vip_players && vip_players[index_first_vip_player].arrive_time <= min_element){
				arrive_time = vip_players[index_first_vip_player].arrive_time;
				play_time = vip_players[index_first_vip_player].play_time;
				++index_first_vip_player;
			}
			else
				findNextByCmpArriveTime(index_first_ordinary_player, N_ordinary_players, index_first_vip_player, N_vip_players, arrive_time, play_time);
		}

		else {
			bool_is_vip = findNextByCmpArriveTime(index_first_ordinary_player, N_ordinary_players, index_first_vip_player, N_vip_players, arrive_time, play_time);
			
			if (bool_is_vip) {
				for (h = 1; h <= K; ++h)  // find the first available vip desk
					if (is_vip_tables[h] && tables[h] <= arrive_time) {
						min_index = h;
						break;
					}
			}
		}

		// other staff
		if (min_element > arrive_time) {  // user comes too early
			tables[min_index] += play_time * 60;
			if (min_element < 75600) {  // 21:00:00
				printf("%02d:%02d:%02d %02d:%02d:%02d %d\n", arrive_time / 3600, (arrive_time % 3600) / 60, arrive_time % 60,
					min_element / 3600, (min_element % 3600) / 60, min_element % 60,
					int((min_element - arrive_time) / 60.0 + 0.5)
				);
				++counts[min_index];
			}
		}
		else {
			tables[min_index] = play_time * 60 + arrive_time;
			if (arrive_time < 75600) {  // 21:00:00
				printf("%02d:%02d:%02d %02d:%02d:%02d %d\n", arrive_time / 3600, (arrive_time % 3600) / 60, arrive_time % 60,
					arrive_time / 3600, (arrive_time % 3600) / 60, arrive_time % 60,
					0
				);
				++counts[min_index];
			}
		}
	}
	printf("%d", counts[1]);
	for (i = 2; i <= K; ++i)
		printf(" %d", counts[i]);
	system("pause");
	return 0;
}