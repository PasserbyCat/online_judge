#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <climits>
using namespace std;
int main()
{
	int c;
	cin >> c;//總共有幾筆測資
	while (c--) {
		int l, m, cross = 0;//l表示船的長度_m表示車子的數量_cross表示渡河的次數
		bool place = true;//true表示左岸，false表示右岸
		cin >> l >> m;
		l *= 100;//l原本是公尺要轉成公分
		queue<int>left, right;//分別存左岸的車和右岸的車
		for (int i = 0; i < m; i++) {
			int temp;
			string word;
			cin >> temp >> word;
			if (word == "left")
				left.push(temp);
			else
				right.push(temp);
		}
		left.push(2000000000);//放極端值，有好處
		right.push(2000000000);//放極端值，有好處
		while (left.size() != 1 || right.size() != 1) {
			int temp = l;//temp偵測船是否塞滿了
			if (place) {
				while (temp >= 0) {
					if (temp != l)//第一次不執行
						left.pop();
					temp -= left.front();//每次將一台車放上船，若是發現車子上去船會超過就終止，反之將上船的車子從左岸移除
				}
				temp += left.front();
				place = false;//過河
			}
			else {
				while (temp >= 0) {
					if (temp != l)//第一次不執行
						right.pop();
					temp -= right.front();//每次將一台車放上船，若是發現車子上去船會超過就終止，反之將上船的車子從右岸移除
				}
				temp += right.front();
				place = true;//過河
			}
			cross++;
		}
		cout << cross << endl;//輸出渡河次數
	}
}