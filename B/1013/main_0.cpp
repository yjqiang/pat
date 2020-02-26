# define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cctype>
#include <algorithm>
#include <cmath>
# include <climits>
#include <cstring>
#include <map>

using namespace std;


bool is_ok(int n) {
	if (!(n % 2) && n != 2)
		return false;

	int half = (int)sqrt(n);
	int i;
	for (i = 3; i <= half; i += 2)
		if (!(n % i))
			return false;

	return true;
}

int main() {
	int M, N;
	scanf("%d%d", &M, &N);

	int count;
	int cur = 2;
	
	for (count = 1; count < M; ++count) {  // P1 = 2 P2 = 3
		for (; !is_ok(cur); ++cur);
		++cur;
	}


	int print_ctrl = 0;
	for (; count <= N; ++count) {
		for (; !is_ok(cur); ++cur);
		if (!print_ctrl)
			printf("%d", cur);
		else if (print_ctrl == 9)
			printf(" %d\n", cur);
		else
			printf(" %d", cur);

		print_ctrl = (print_ctrl + 1) % 10;
		++cur;

	}


	system("pause");
	return 0;
}