#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#include <map>

#include <set>
#include <cstring>

using namespace std;

int addr_list[100001]; // addr_list[0] ----> addr_list[1]  ----> addr_list[1] ....
int datas[100000];  // datas[addr] = addr->data
int nexts[100000];  // nexts[addr] = addr->next

int main() {
	int int_head, N, K;
	scanf("%d%d%d", &int_head, &N, &K);

	int Address, Data, Next;
	int i;
	for (i = 0; i < N; ++i) {
		scanf("%d%d%d", &Address, &Data, &Next);
		datas[Address] = Data;
		nexts[Address] = Next;
	}
	
	int count = 0;
	int addr = int_head;
	while (addr != -1) {
		addr_list[count] = addr;
		addr = nexts[addr];
		++count;
	}
	addr_list[count] = -1;

	int tmp;
	int left, right;
	for (i = 0; i + K - 1 < count; i += K)
		for (left = i, right = i + K -1; left < right; ++left, --right) {
			tmp = addr_list[left];
			addr_list[left] = addr_list[right];
			addr_list[right] = tmp;
		}

	for (i = 0; i < count - 1; ++i)
		printf("%05d %d %05d\n", addr_list[i], datas[addr_list[i]], addr_list[i + 1]);

	printf("%05d %d -1\n", addr_list[i], datas[addr_list[i]]);
	system("pause");
	return 0;
}