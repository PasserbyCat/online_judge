#include <iostream>
#include <deque>
using namespace std;
int main()
{
	long long people;
	unsigned int command, now = 1, temp;
	cin >> people >> command;
	while (people != 0 || command != 0) {

		cout << "Case " << now << ":\n";
		now++;//每一輪case

		deque<unsigned int>all;
		for (unsigned int i = 0; i < people && i < command; i++) {
			all.push_back(i + 1);
		}//只需要存人數且人數必然小魚等於指令，人數多於指令的部分不會被叫到
		for (unsigned int i = 0; i < command; i++) {
			char input;
			cin >> input;
			if (input == 'N') {//人物出場
				temp = all.front();//將第一個送出去
				all.push_back(temp);//放到最後一位
				all.pop_front();
				cout << temp << endl;
			}
			else if (input == 'E') {
				unsigned int number;
				cin >> number;//需要優先的人員
				for (unsigned int j = 0; j < all.size(); j++)
					if (all[j] == number) {//如果優先人員存在於排隊序列中，將他的位置移除
						all.erase(all.begin() + j);
						break;
					}
				all.push_front(number);//把優先人員放到最前面
			}
		}
		cin >> people >> command;
	}
}