# define _CRT_SECURE_NO_WARNINGS
# include <cstdlib>
# include <cstdio>
# include <vector>
# include <ctime>
# include <iostream>
# include <cstring>
# include <climits>

using namespace std;


int main() {
	int unlock_Sign_in_time = INT_MAX;
	char unlock_ID_number[16];

	int lock_Sign_out_time = INT_MIN;
	char lock_ID_number[16];

	int cur_Sign_in_time, cur_Sign_out_time;
	char cur_ID_number[16];

	int M;
	int hour, minute, second;
	scanf("%d", &M);
	int i;
	for (i = 0; i < M; ++i) {
		scanf("%s", cur_ID_number);
		scanf("%d:%d:%d", &hour, &minute, &second);
		cur_Sign_in_time = hour * 10000 + minute * 100 + second;
		scanf("%d:%d:%d", &hour, &minute, &second);
		cur_Sign_out_time = hour * 10000 + minute * 100 + second;

		if (cur_Sign_in_time < unlock_Sign_in_time) {
			strcpy(unlock_ID_number, cur_ID_number);
			unlock_Sign_in_time = cur_Sign_in_time;
		}
		if (cur_Sign_out_time > lock_Sign_out_time) {
			strcpy(lock_ID_number, cur_ID_number);
			lock_Sign_out_time = cur_Sign_out_time;
		}

	}
	printf("%s %s", unlock_ID_number, lock_ID_number);


	system("pause");
	return 0;
}