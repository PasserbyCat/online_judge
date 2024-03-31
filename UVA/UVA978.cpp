#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main()
{
	vector<int> fightground;

	int fight;
	cin >> fight;//有幾場戰鬥
	for (int i = 0; i < fight; i++) {

		multiset<int> green, blue;
		int ground, gnumber, bnumber;
		cin >> ground >> gnumber >> bnumber;//有幾個戰場；綠方有幾個單位；藍方有幾個單位

		fightground.resize(ground);//一次可對戰的最大戰場數

		int temp;
		for (int j = 0; j < gnumber; j++) {
			cin >> temp;
			green.insert(temp);//將綠方的士兵戰鬥力放進set
		}
		for (int j = 0; j < bnumber; j++) {
			cin >> temp;
			blue.insert(temp);//將藍方的士兵戰鬥力放進set
		}

		multiset<int>::reverse_iterator rbit = blue.rbegin(), rgit = green.rbegin();//從雙方戰鬥力最高的開始戰鬥
		while (!green.empty() && !blue.empty()) {//打架直到至少一方全數陣亡
			for (int j = 0; j < ground; j++) {
				fightground[j] = *rbit - *rgit;//每個戰場存戰鬥結果，正數代表藍方贏，負數代表綠方贏，0則代表雙方皆陣亡
				green.erase(green.lower_bound(*rgit));
				blue.erase(blue.lower_bound(*rbit));
				if (green.empty() || blue.empty())
					break;
			}
			for (int j = 0; j < ground; j++) {
				if (fightground[j] > 0)
					blue.insert(fightground[j]);//藍方戰贏後，將該士兵的剩餘戰鬥力在寫入set
				else if (fightground[j] < 0)
					green.insert(-fightground[j]);//綠方戰贏後，將該士兵的剩餘戰鬥力在寫入set
				fightground[j] = 0;
			}
		}

		if (!green.empty()) {//藍方全員陣亡，將綠方剩餘士兵與其戰鬥力輸出
			cout << "green wins\n";
			for (multiset<int>::reverse_iterator it = green.rbegin(); it != green.rend(); ++it)
				std::cout << *it << endl;
		}
		else if (!blue.empty()) {//綠方全員陣亡，將藍方剩餘士兵與其戰鬥力輸出
			cout << "blue wins\n";
			for (multiset<int>::reverse_iterator it = blue.rbegin(); it != blue.rend(); ++it)
				std::cout << *it << endl;
		}
		else
			cout << "green and blue died\n";
		if (i != fight - 1)//最後一筆資料不用換行
			cout << endl;
	}
	return 0;
}