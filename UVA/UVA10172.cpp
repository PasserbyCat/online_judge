#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>
using namespace std;
int main()
{
	int SET, time[1000] = {};
	cin >> SET;//���X������
	for (int a = 0; a < SET; a++) {
		int N, S, Q;//���X��_�C���˴X�ӳf��_�C���i�H�Ȧs�h�ֳf��
		cin >> N >> S >> Q;
		stack<int>bus;
		vector<queue<int>>station;
		bool empty = true;
		station.resize(N);//��N��
		for (int i = 0; i < N; i++) {
			int Qi;
			cin >> Qi;//�ӯ����X�ӳf��
			for (int j = 0; j < Qi; j++) {
				int temp;
				cin >> temp;
				station[i].push(temp - 1);//�N�C�@�����f����i�ӯ����Ȧs�Ŷ�
			}
		}
		int place = 0;
		do {
			empty = true;
			while (place != 0)//�Ĥ@�����Ψ��f
				if (!bus.empty())//�����n���f���i�H���f�~�i�H����
					if (bus.top() == place % N) {//�Y�O�f����n�n�e�F�ӯ��A�������f
						bus.pop();
						time[a]++;
					}
					else if (station[place % N].size() != Q) {//�Y�O�f�����O�n�e�F�ӯ��A�s�i�ӯ����Ȧs�Ŷ�
						station[place % N].push(bus.top());
						bus.pop();
						time[a]++;
					}
					else//�Y�O�ӯ������s�Ŷ��w���A�N���}�j��
						break;
				else
					break;
			while (1)
				if (bus.size() != S && !station[place % N].empty()) {//��ӯ��Ȧs�Ŷ����f���ˤW��
					bus.push(station[place % N].front());
					station[place % N].pop();
					time[a]++;
				}
				else//�b���l�˺��Ϊ̸ӯ����Ȧs�Ŷ��w�L�f�������}�j��
					break;
			place++;
			time[a] += 2;
			for (int i = 0; i < station.size(); i++)//�Y�O�C�@�����s�Ŷ����S���f���ɡA��empty�]��false
				if (!station[i].empty())
					break;
				else if (i == station.size() - 1)
					empty = false;
		} while (empty || !bus.empty());//�bempty��false�B���W�S���f�������}�j��
	}
	for (int a = 0; a < SET; a++)
		cout << time[a] - 2<< endl;
}