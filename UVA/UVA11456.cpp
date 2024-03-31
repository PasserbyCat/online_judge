//UVA11456-Trainsorting
#include <iostream>
using namespace std;
int main()
{
	int test;//總共有幾筆測資
	cin >> test;
	for (int i = 0; i < test; i++) {
		int car, * weight, * delen, * inlen, answer = 0;
		cin >> car;//這次有幾輛車
		weight = new int[car]();
		delen = new int[car]();
		inlen = new int[car]();
		for (int j = 0; j < car; j++) {
			cin >> weight[j];
			delen[j] = 1;
			inlen[j] = 1;
		}
		for (int j = car - 1; j >= 0; j--)//從最後一台車往回計算，因為前面的車放頭尾，後面的車放中間，要先上車
			for (int k = car - 1; k > j; k--) {
				if (weight[j] > weight[k]) {
					if (inlen[j] < inlen[k] + 1)
						inlen[j] = inlen[k] + 1;//計算increasing subsequence
				}
				else if (weight[j] < weight[k]) {
					if (delen[j] < delen[k] + 1)
						delen[j] = delen[k] + 1;//計算decreasing subsequence
				}
			}
		for (int j = 0; j < car; j++)
			if (answer < delen[j] + inlen[j])
				answer = delen[j] + inlen[j] - 1;//同一筆subsequence中，會有一個數字重複計算
		cout << answer << endl;
		delete[]weight;
		delete[]delen;
		delete[]inlen;
	}
}