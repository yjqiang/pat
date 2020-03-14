#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <map>
#include <cmath>
#include <climits>
#include <queue>
#include <set>

using namespace std;

char nums[10][6] = { "ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu" };

char group_elements[4][5] = { "", "Shi", "Bai", "Qian" };
char groups[3][4] = {"", "Wan", "Yi" };

// ����0|3210|3210�и�����
// ÿһ��4�����֣���ǧ���ټ�ʮ��
// ��ӡ��ÿ�������֮���ٸ��ݵڼ��飬��ӡ ��/��/none
char s[11];

int main(){
	
	scanf("%s", &s);

	int i;

	bool is_first;

	if (s[0] == '-') {
		printf("Fu");
		i = 1;
		is_first = false;
	}
	else {
		i = 0;
		is_first = true;
	}

	int n_1 = strlen(s) - 1;
	int start;

	// �ڼ����飨4������һ�飬none/��/�ڣ�
	int group_id;
	

	for (; i <= n_1;) {
		// ÿ�ĸ�һ��
		// ���ܲ���ǡ�ô���һ���
		start = (n_1 - i) % 4;
		group_id = (n_1 - i) / 4;

		// ����ĳһ���4���������ܲ���4����
		while (start != -1) {
			if (s[i] == '0') {
				// �ҵ�����������ķ�0���ֵ�λ�ã������ǵ���һ��Ŀ�ͷ��
				for (++i, --start; start >= 0 && s[i] == '0'; ++i, --start);
				// û�����������λ�ã���ӡ0
				if (start >= 0)
					printf(" ling");
				else
					// ������һ�鿪ͷ��
					break;
			}

			if (is_first)
				is_first = false;
			else
				printf(" ");
			// assert s[i] != '0' ���㷨��֤�����
			printf("%s", nums[s[i] - '0']);

			// ��λ����û�к�׺�ģ�ʮλ��λǧλ�е�
			if (start > 0)
				printf(" %s", group_elements[start]);

			++i;
			--start;
		}

		// ���һ�鲻��ӡ��׺������Ĵ�ӡ ��/����Щ
		if (group_id > 0)
			printf(" %s", groups[group_id]);

	}

	// ���⴦��
	if (n_1 == 0 && s[0] == '0')
		printf("ling");

	system("pause");
	return 0;
}