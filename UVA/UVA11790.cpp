//UVA11790-Murcia's Skyline
#include <iostream>
using namespace std;
int main()
{
	int test;//總共有幾筆測資
	cin >> test;
	for (int i = 0; i < test; i++) {
		int build, * height, * delen, * inlen, * weight, maxin = 0, maxde = 0;
		cin >> build;//這次有幾棟樓
		height = new int[build]();
		delen = new int[build]();
		inlen = new int[build]();
		weight = new int[build]();
		for (int j = 0; j < build; j++)
			cin >> height[j];
		for (int j = 0; j < build; j++) {
			cin >> weight[j];
			inlen[j] = delen[j] = weight[j];
		}
		for (int j = 0; j < build; j++)//按照順序找subsequence
			for (int k = 0; k < j; k++) {
				if (height[j] > height[k]) {
					if (inlen[j] < inlen[k] + weight[j])
						inlen[j] = inlen[k] + weight[j];//計算increasing subsequence
				}
				else if (height[j] < height[k]) {
					if (delen[j] < delen[k] + weight[j])
						delen[j] = delen[k] + weight[j];//計算decreasing subsequence
				}
			}
		for (int j = 0; j < build; j++) {
			if (inlen[j] > maxin)
				maxin = inlen[j];//找最長的increasing subsequence
			if (delen[j] > maxde)
				maxde = delen[j];//找最長的decreasing subsequence
		}
		if (maxde > maxin)
			cout << "Case " << i + 1 << ". Decreasing (" << maxde << "). Increasing (" << maxin << ").\n";
		else 
			cout << "Case " << i + 1 << ". Increasing (" << maxin << "). Decreasing (" << maxde << ").\n";
		delete[]height;
		delete[]weight;
		delete[]delen;
		delete[]inlen;
	}
}