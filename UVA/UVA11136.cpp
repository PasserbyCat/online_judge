#include <iostream>
#include <set>
using namespace std;
int main()
{
	int day;
	cin >> day;//�`�@���X��
	while (day) {//0�ѥN���A����L����A�{������

		multiset<int>all;
		long long sum = 0;
		for (int i = 0; i < day; i++) {

			int ticket, temp;
			cin >> ticket;//���X�ӤH�ʶR
			for (int j = 0; j < ticket; j++) {
				cin >> temp;
				all.insert(temp);
			}

			multiset<int>::iterator it = all.begin();//�̤p�ʶR���B
			multiset<int>::reverse_iterator rit = all.rbegin();//�̤j�ʶR���B
			sum += *rit - *it;
			all.erase(all.lower_bound(*it));
			all.erase(all.lower_bound(*rit));
		}

		cout << sum << endl;
		cin >> day;
	}
}
 