#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
struct ANS {
	int order;//存序列
	int number;//存arrival
};
int main()
{
	int c, n, t, m, take;
	cin >> c;//c代表有幾組側資
	vector<int>answer;
	for (int a = 0; a < c; a++) {
		if (a != 0)
			cout << endl;
		int time = 0;
		cin >> n >> t >> m;//n代表可以在幾台車_t代表渡河要花多久_m代表總共有幾台車要渡河
		answer.resize(m);//有m筆資料代表有m筆answer
		queue<ANS>left, right;//分左岸和右岸
		ANS input;
		for (int i = 0; i < m; i++) {
			int temp;
			string word;
			cin >> temp >> word;
			input.number = temp;//抵達時間
			input.order = i;//第幾台車
			if (word == "left")//左岸放進左側
				left.push(input);
			else//右岸放進右側
				right.push(input);
		}
		input.number = 2147483647;
		left.push(input);//後頭放最大值，比較用
		right.push(input);//後頭放極大值，比較用
		bool place = true;//船一開始在左岸
		while (left.size() != 1 || right.size() != 1) {//兩個都只剩我們自己塞入的極大值時結束迴圈
			take = 0;//告訴使用者現在船上有幾台車
			if (place) {//船在左側的動作
				while (left.size() != 1 && take < n)//船上的車輛數目不能大於載運量，且左岸必須要有車子才可執行
					if (left.front().number <= time) {//當車子已經抵達時，就將車子放上船
						take++;
						answer[left.front().order] = time + t;//把他的抵達時間算出來放入序列之中
						left.pop();
					}
					else//尚未有車子抵達就直接離開迴圈
						break;
				if (take > 0);//已經有車子在船上十以下均不執行(以下皆是船抵達時尚未有車的情況)
				else if (left.front().number <= right.front().number) {//若是左岸的下一輛車比右岸的下一輛車更早抵達
					time = left.front().number;//直接將時間推移到左岸下一輛車的抵達時間
					while (time == left.front().number && take < n) {//若是有複數的車載同一時間抵達，一起載上船(在船上容量還沒爆滿的情況)
						answer[left.front().order] = time + t;
						left.pop();
						take++;
					}
				}
				else if (time > right.front().number);//右岸的下一輛車比左岸的下一輛車更早抵達，且該輛車已經抵達右岸，則直接將船開往右岸
				else
					time = right.front().number;//右岸的下一輛車比左岸的下一輛車更早抵達，但該輛車尚未抵達右岸，等到車抵達右岸再將船開過去
				time += t;//船抵達右岸的時間
				place = false;//船開往右岸
			}
			else {//船在右側的動作
				while (right.size() != 1 && take < n)//船上的車輛數目不能大於載運量，且右岸必須要有車子才可執行
					if (right.front().number <= time) {//當車子已經抵達時，就將車子放上船
						take++;
						answer[right.front().order] = time + t;//把他的抵達時間算出來放入序列之中
						right.pop();
					}
					else//尚未有車子抵達就直接離開迴圈
						break;
				if (take > 0);//已經有車子在船上十以下均不執行(以下皆是船抵達時尚未有車的情況)
				else if (left.front().number >= right.front().number) {//若是右岸的下一輛車比左岸的下一輛車更早抵達
					time = right.front().number;//直接將時間推移到右岸下一輛車的抵達時間
					while (time == right.front().number && take < n) {//若是有複數的車載同一時間抵達，一起載上船(在船上容量還沒爆滿的情況)
						answer[right.front().order] = time + t;
						right.pop();
						take++;
					}
				}
				else if (time > left.front().number);//左岸的下一輛車比左岸的下一輛車更早抵達，且該輛車已經抵達左岸，則直接將船開往左岸
				else
					time = left.front().number;//左岸的下一輛車比右岸的下一輛車更早抵達，但該輛車尚未抵達左岸，等到車抵達左岸再將船開過去
				time += t;//船抵達左岸的時間
				place = true;//船開往左岸
			}
		}
		for (int i = 0; i < answer.size(); i++)
			cout << answer[i] << endl;//將該次的運作結果輸出
	}
}