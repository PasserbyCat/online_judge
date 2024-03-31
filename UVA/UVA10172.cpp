#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>
using namespace std;
int main()
{
	int SET, time[1000] = {};
	cin >> SET;//有幾筆測資
	for (int a = 0; a < SET; a++) {
		int N, S, Q;//有幾站_每車裝幾個貨物_每站可以暫存多少貨物
		cin >> N >> S >> Q;
		stack<int>bus;
		vector<queue<int>>station;
		bool empty = true;
		station.resize(N);//有N站
		for (int i = 0; i < N; i++) {
			int Qi;
			cin >> Qi;//該站有幾個貨物
			for (int j = 0; j < Qi; j++) {
				int temp;
				cin >> temp;
				station[i].push(temp - 1);//將每一站的貨物放進該站的暫存空間
			}
		}
		int place = 0;
		do {
			empty = true;
			while (place != 0)//第一次不用卸貨
				if (!bus.empty())//必須要有貨物可以卸貨才可以執行
					if (bus.top() == place % N) {//若是貨物剛好要送達該站，直接卸貨
						bus.pop();
						time[a]++;
					}
					else if (station[place % N].size() != Q) {//若是貨物不是要送達該站，存進該站的暫存空間
						station[place % N].push(bus.top());
						bus.pop();
						time[a]++;
					}
					else//若是該站的站存空間已滿，就離開迴圈
						break;
				else
					break;
			while (1)
				if (bus.size() != S && !station[place % N].empty()) {//把該站暫存空間的貨物裝上車
					bus.push(station[place % N].front());
					station[place % N].pop();
					time[a]++;
				}
				else//在車子裝滿或者該站的暫存空間已無貨物時離開迴圈
					break;
			place++;
			time[a] += 2;
			for (int i = 0; i < station.size(); i++)//若是每一站的存空間都沒有貨物時，機empty設為false
				if (!station[i].empty())
					break;
				else if (i == station.size() - 1)
					empty = false;
		} while (empty || !bus.empty());//在empty為false且車上沒有貨物時離開迴圈
	}
	for (int a = 0; a < SET; a++)
		cout << time[a] - 2<< endl;
}