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

int s[85][85];

int main() {
	int n;
	for (n = 0; scanf("%s", s[n]) != EOF; ++n);

	int i;
	printf("%s", s[n - 1]);
	for (i = n-2; i >= 0; --i)
		printf(" %s", s[i]);
	

	system("pause");
	return 0;
}