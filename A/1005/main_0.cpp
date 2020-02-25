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

	if (!sum) {
		printf(eng[0]);
		return 0;
	}

	vector<int> s;
	while (sum) {
		s.push_back(sum % 10);
		sum /= 10;
	}
	
	int i = s.size() - 1;
	printf("%s", eng[s[i]]);
	for (--i; i >= 0; --i)
	{
		printf(" %s", eng[s[i]]);
	}

	system("pause");
	return 0;
}