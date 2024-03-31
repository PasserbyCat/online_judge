#include <iostream>
#include <set>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	int turn;
	cin >> turn;
	for (int i = 0; i < turn; i++) {

		set<int> snowflake;
		queue<int> all;
		int max = 0, size = 0, number, temp;

		cin >> number;
		for (int j = 0; j < number; j++) {
			cin >> temp;
			while (snowflake.count(temp)) {//直到set裡已經沒有temp元素了
				snowflake.erase(all.front());//刪掉queue的第一個
				all.pop();//刪掉queue的第一個
			}
			snowflake.insert(temp);
			all.push(temp);
			if (max < all.size())//queue.size()即為不重複數列的長度
				max = all.size();//若是比曾經存過的長度長就將queue.size()存進去
		}

		cout << max << endl;
	}
}