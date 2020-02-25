# define _CRT_SECURE_NO_WARNINGS
# include <cstdlib>
# include <cstdio>
# include <vector>

using namespace std;

char eng[10][6] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

int main() {
	int tmp, sum = 0;
	
	while (scanf("%1d", &tmp) != EOF)
		sum += tmp;

	if (sum >= 100)
		printf("%s ", eng[sum / 100]);

	if (sum >= 10)
		printf("%s ", eng[(sum % 100) / 10]);

	printf("%s", eng[sum % 10]);
	system("pause");
	return 0;
}