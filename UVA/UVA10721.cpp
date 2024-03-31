//UVA10721-kぃmゼ计璶=n
#include <iostream>
using namespace std;
int main()
{
	long long table[51][51][51] = {};//
	for (int i = 1; i < 51; i++)
		for (int j = 1; j <= i; j++)
			for (int k = 1; k < 51; k++)
				if (k > i - j + 1)
					table[i][j][k] = table[i][j][i - j + 1];//讽k == i - j + 1瞷程礚阶k或糤ぃ穦Τ
				else if (i == j || j * k == i)//┏
					table[i][j][k] = 1;
				else
					for (int l = k; l > 0; l--)
						table[i][j][k] += table[i - l][j - 1][k];//–计琌j - 1︽计癬ㄓi - 1i - k硈
	int n, k, m;
	while(cin >> n >> k >> m)
		cout << table[n][k][m] << endl;
}