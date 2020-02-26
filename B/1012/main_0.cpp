# define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cctype>
#include <algorithm>
#include <cmath>
# include <climits>
#include <cstring>

using namespace std;

int main() {
	int N;
	int A1 = 0, A2 = 0, A3 = 0, A5 = 0;
	double A4 = 0.0;

	bool is_A1, is_A2, is_A3, is_A4, is_A5;
	is_A1 = is_A2 = is_A3 = is_A4 = is_A5 = false;

	scanf("%d", &N);

	int count_A2 = 1;
	int sum_A4 = 0;
	int count_A4 = 0;

	int index;
	int tmp;
	int remainder;
	for (index = 0; index < N; ++index) {
		scanf("%d", &tmp);
		remainder = tmp % 5;
		if (!remainder) {
			if (!(tmp % 2)) {
				is_A1 = true;
				A1 += tmp;
			}
		}
		else if (remainder == 1) {
			is_A2 = true;
			A2 += (count_A2 == 1) ? tmp : -tmp;
			count_A2 = -count_A2;
		}
		else if (remainder == 2) {
			is_A3 = true;
			++A3;
		}
		else if (remainder == 3) {
			is_A4 = true;
			sum_A4 += tmp;
			++count_A4;
		}
		else if (remainder == 4) {
			is_A5 = true;
			A5 = max(A5, tmp);
		}
	}
	A4 = sum_A4 / (double)count_A4;
	is_A1 ? printf("%d", A1) : printf("N");
	is_A2 ? printf(" %d", A2) : printf(" N");
	is_A3 ? printf(" %d", A3) : printf(" N");
	is_A4 ? printf(" %.1lf", A4) : printf(" N");
	is_A5 ? printf(" %d", A5) : printf(" N");

	system("pause");
	return 0;
}