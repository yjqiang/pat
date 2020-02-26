# define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cctype>
#include <algorithm>
#include <cmath>
# include <climits>
#include <cstring>

using namespace std;

long long x[100];

long long convert(char* s, long long radix) {
	long long sum = 0;
	int cur;
	int i;
	char tmp;
	for (i = 0; s[i] != '\0'; ++i) {
		tmp = s[i];
		cur = (tmp <= '9' && tmp >= '0') ? (tmp - '0') : (tmp - 'a' + 10);
		sum = sum * radix + cur;
	}
	return sum;
}

bool reconvert(long long num, long long radix) {
	if (!num) {
		x[0] = 1;
		x[1] = 0;
		return true;
	}
		
	long long tmp;
	int n;
	for (n = 1; num; ++n) {
		x[n] = num % radix;
		num /= radix;
	}
	--n;
	x[0] = n;

	//reverse
	int i, k;
	for (i = 1, k = n; i < k; ++i, --k) {
		tmp = x[i];
		x[i] = x[k];
		x[k] = tmp;
	}

	return true;
}


int compare_xs(char* s, int len) {
	long long int len_x = x[0];

	if (len_x < len)
		return -1;
	if (len_x > len)
		return 1;
	
	int i, k;
	char tmp_char;
	int s_ele;
	long long int x_ele;
	for (i = 1, k = 0; i <= len_x && k < len; ++i, ++k) {
		tmp_char = s[k];
		s_ele = (tmp_char <= '9' && tmp_char >= '0') ? (tmp_char - '0') : (tmp_char - 'a' + 10);
		x_ele = x[i];
		if (x_ele < s_ele)
			return -1;
		if (x_ele > s_ele)
			return 1;
	}
	return 0;
}

long long find_radix(char* s, long long target) {
	int i;
	char highest = '0' - 1;
	for (i = 0; s[i] != '\0'; ++i)
		highest = max(highest, s[i]);

	long long low = ((highest <= '9' && highest >= '0') ? (highest - '0') : (highest - 'a' + 10)) + 1;
	long long high = target + 1;
	int result;
	int len_s = strlen(s);
	while (low <= high) {
		long long mid = (high - low) / 2 + low;
		reconvert(target, mid);

		result = compare_xs(s, len_s);

		if (result < 0)  // x < s  =>  too much
			high = mid - 1;
		else if (result == 0)
			return mid;
		else
			low = mid + 1;
	}
	return -1;
}

int main() {
	char N1[11], N2[11];
	int tag, radix;
	long long int result;
	scanf("%s%s%d%d", N1, N2, &tag, &radix);
	result = tag == 1 ? find_radix(N2, convert(N1, radix)) : find_radix(N1, convert(N2, radix));
	if (result != -1) {
		printf("%lld", result);
	}
	else {
		printf("Impossible");
	}
	system("pause");
	return 0;
}