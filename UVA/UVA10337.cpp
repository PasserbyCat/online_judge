//UVA10337 - 給定飛行距離與各飛行場域的風速，算出飛行的最少耗油量
#include <iostream>
using namespace std;
int main()
{
	int test, ** sky, mile, ** arrive;
	cin >> test;
	sky = new int* [10]();
	arrive = new int* [10]();
	for (int z = 0; z < test; z++) {
		cin >> mile;
		mile /= 100;//每100公尺換一次飛行高度
		for (int i = 9; i > -1; i--) {
			sky[i] = new int[mile + 1]();
			for (int j = 0; j < mile; j++)
				cin >> sky[i][j];//輸入風速
			arrive[i] = new int[mile + 1]();
			for (int j = 0; j < mile + 1; j++)
				arrive[i][j] = 1000000;//設定極端值
		}
		arrive[0][0] = 0;
		for (int i = 0; i < mile; i++)
			for (int j = 0; j < 10; j++) {//若是下一格的耗油量較多，改為較少的
				if (arrive[j][i + 1] > arrive[j][i] - sky[j][i] + 30)
					arrive[j][i + 1] = arrive[j][i] - sky[j][i] + 30;
				if (j == 0) {//沒有更低的
					if (arrive[j][i + 1] > arrive[j + 1][i] - sky[j + 1][i] + 20)
						arrive[j][i + 1] = arrive[j + 1][i] - sky[j + 1][i] + 20;
				}
				else if (j == 9) {//沒有更高的
					if (arrive[j][i + 1] > arrive[j - 1][i] - sky[j - 1][i] + 60)
						arrive[j][i + 1] = arrive[j - 1][i] - sky[j - 1][i] + 60;
				}
				else {
					if (arrive[j][i + 1] > arrive[j + 1][i] - sky[j + 1][i] + 20)
						arrive[j][i + 1] = arrive[j + 1][i] - sky[j + 1][i] + 20;
					if (arrive[j][i + 1] > arrive[j - 1][i] - sky[j - 1][i] + 60)
						arrive[j][i + 1] = arrive[j - 1][i] - sky[j - 1][i] + 60;
				}
			}
		cout << arrive[0][mile] << endl << endl;//最後必定在第0格
		for (int i = 9; i > -1; i--) {
			delete[]sky[i];
			delete[]arrive[i];
		}
	}
	delete[]sky;
	delete[]arrive;
}
