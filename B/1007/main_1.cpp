# define _CRT_SECURE_NO_WARNINGS
# include <cstdlib>
# include <cstdio>
# include <vector>
# include <ctime>
# include <iostream>
# include <cstring>
# include <climits>
# include <cmath>

using namespace std;

bool is_ok(int n) {
	int half = (int)sqrt(n);
	int i;
	for (i = 3; i <= half; i += 2)
		if (!(n % i))
			return false;

	return true;
}

int main() {
	int N;
	scanf("%d", &N);
	
	int i;
	N -= 2;
	int count = 0;
	for (i = 3; i <= N; i += 2) {
		if (is_ok(i) && is_ok(i + 2)) {
			printf("%d %d\n", i, i + 2);
			++count;
		}
			
	}
	printf("%d", count);

	system("pause");
	return 0;
}