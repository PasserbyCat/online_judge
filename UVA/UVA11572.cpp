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
			while (snowflake.count(temp)) {//����set�̤w�g�S��temp�����F
				snowflake.erase(all.front());//�R��queue���Ĥ@��
				all.pop();//�R��queue���Ĥ@��
			}
			snowflake.insert(temp);
			all.push(temp);
			if (max < all.size())//queue.size()�Y�������ƼƦC������
				max = all.size();//�Y�O�񴿸g�s�L�����ת��N�Nqueue.size()�s�i�h
		}

		cout << max << endl;
	}
}