# define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cctype>
#include <algorithm>
#include <cmath>

using namespace std;

long long convert(char* s, long long radix) {
	long long sum = 0;
	long long tmp_ll;
	int cur;
	int i;
	char tmp;
	for (i = 0; s[i] != '\0'; ++i) {
		tmp = s[i];
		cur = (tmp <= '9' && tmp >= '0') ? (tmp - '0') : (tmp - 'a' + 10);
		tmp_ll = sum * radix;
		if (tmp_ll / radix != sum)
			return -1;

		tmp_ll += cur;
		if (tmp < 0)
			return -1;
		sum =  tmp_ll;
	}
	return sum;
}

long long find_radix(char* s, long long target) {
	int i;
	char highest = '0' - 1;
	for (i = 0; s[i] != '\0'; ++i)
		highest = max(highest, s[i]);

	long long low = ((highest <= '9' && highest >= '0') ? (highest - '0') : (highest - 'a' + 10)) + 1;
	long long high = target + 1;
	while (low <= high) {
		long long mid = (high - low) / 2 + low;
		long long t = convert(s, mid);

		if (t < 0 || t > target)
			high = mid - 1;
		else if (t == target)
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
	return 0;
}