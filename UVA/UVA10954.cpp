#include <iostream>
#include <queue>
using namespace std;
int main()
{
	int number;
	cin >> number;//有幾個數字
	while (number) {
		priority_queue<int>all;
		int total;
		for (int i = 0; i < number; i++) {
			int temp;
			cin >> temp;
			all.push(-temp);//用負數存，剛好是minheap，無視-號的情況
		}
		int answer = 0;
		for (int i = 0; !all.empty(); i++) {
			if (i != 0)//第一筆測資還沒有total
				all.push(-total);//在還有資料的時候，將total放回原本的priority_queue
			total = -all.top();
			all.pop();
			total += -all.top();
			all.pop();
			answer += total;//將total加進answer裡
		}
		cout << answer << endl;
		cin >> number;
	}
}