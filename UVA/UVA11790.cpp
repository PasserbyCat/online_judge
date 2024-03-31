//UVA11790-Murcia's Skyline
#include <iostream>
using namespace std;
int main()
{
	int test;//�`�@���X������
	cin >> test;
	for (int i = 0; i < test; i++) {
		int build, * height, * delen, * inlen, * weight, maxin = 0, maxde = 0;
		cin >> build;//�o�����X�ɼ�
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
		for (int j = 0; j < build; j++)//���Ӷ��ǧ�subsequence
			for (int k = 0; k < j; k++) {
				if (height[j] > height[k]) {
					if (inlen[j] < inlen[k] + weight[j])
						inlen[j] = inlen[k] + weight[j];//�p��increasing subsequence
				}
				else if (height[j] < height[k]) {
					if (delen[j] < delen[k] + weight[j])
						delen[j] = delen[k] + weight[j];//�p��decreasing subsequence
				}
			}
		for (int j = 0; j < build; j++) {
			if (inlen[j] > maxin)
				maxin = inlen[j];//��̪���increasing subsequence
			if (delen[j] > maxde)
				maxde = delen[j];//��̪���decreasing subsequence
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