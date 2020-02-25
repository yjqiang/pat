# define _CRT_SECURE_NO_WARNINGS
# include <cstring>
# include <cstdio>
# include <cstdlib>
# include <iostream>
# include <algorithm>
# include <climits>
# include <queue>
# include <map>

using namespace std;


int main() {
	int n, b, s, g;  // b  bai; s shi; g ge

	scanf("%d", &n);
	b = n / 100;
	n = n % 100;
	s = n / 10;
	g = n % 10;

	int i;
	for (i = 0; i < b; ++i)
		printf("B");
	for (i = 0; i < s; ++i)
		printf("S");
	for (i = 1; i <= g; ++i)
		printf("%d", i);
	system("pause");
	return 0;
}