#include <iostream>
#include <set>
using namespace std;
int main()
{
	int day;
	cin >> day;//總共有幾天
	while (day) {//0天代表不再有其他測資，程式結束

		multiset<int>all;
		long long sum = 0;
		for (int i = 0; i < day; i++) {

			int ticket, temp;
			cin >> ticket;//有幾個人購買
			for (int j = 0; j < ticket; j++) {
				cin >> temp;
				all.insert(temp);
			}

			multiset<int>::iterator it = all.begin();//最小購買金額
			multiset<int>::reverse_iterator rit = all.rbegin();//最大購買金額
			sum += *rit - *it;
			all.erase(all.lower_bound(*it));
			all.erase(all.lower_bound(*rit));
		}

		cout << sum << endl;
		cin >> day;
	}
}
 