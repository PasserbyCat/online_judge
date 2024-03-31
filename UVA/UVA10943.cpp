//UVA10943_How do you add?
//此題運用重複組合
#include <iostream>
using namespace std;
int truth[46]{ 2, 3, 5,	7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97,
101, 103, 107, 109,	113, 127, 131, 137,	139, 149, 151 ,157 ,163	,167, 173, 179, 181, 191, 193, 197 ,199 };//列出質數表
int main()
{
	int N, K;//K是未知數個數，N是數個未知數的合 範例 : N = 5, K = 3 則表示成 x+y+z=5有幾種組合
	while (cin >> N >> K) {
		if (N == 0 || K == 0)//終止條件
			break;
		int up = N + K - 1, down = up - N, answer = 1;//重複組合的上界up = N + K - 1
		if (down > N)//重複組合的下界down = up - N = K - 1，我們取較小的值，運算上比較簡單
			down = N;
		int co[46] = {};//配合質數表，進行質因數分解，用來記錄該質數有幾次方
		for (; down > 0; down--, up--)//用上下界直接進行遞減運算(也就是約分)
			for (int k = 0, i = up, j = down; truth[k] <= up; k++) {
				while (i % truth[k] == 0) {
					co[k]++;//分子次方用+的
					i /= truth[k];
				}
				while (j % truth[k] == 0) {
					co[k]--;//分母次方用-的
					j /= truth[k];
				}
			}
		for (int i = 0; i < 46; i++)
			for (int j = 0; j < co[i]; j++) {//進行最後的運算
				answer *= truth[i];
				answer %= 1000000;
			}
		cout << answer << endl;
	}
}
