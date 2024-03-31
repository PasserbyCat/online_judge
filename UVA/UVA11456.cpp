//UVA11456-Trainsorting
#include <iostream>
using namespace std;
int main()
{
	int test;//�`�@���X������
	cin >> test;
	for (int i = 0; i < test; i++) {
		int car, * weight, * delen, * inlen, answer = 0;
		cin >> car;//�o�����X����
		weight = new int[car]();
		delen = new int[car]();
		inlen = new int[car]();
		for (int j = 0; j < car; j++) {
			cin >> weight[j];
			delen[j] = 1;
			inlen[j] = 1;
		}
		for (int j = car - 1; j >= 0; j--)//�q�̫�@�x�����^�p��A�]���e���������Y���A�᭱�����񤤶��A�n���W��
			for (int k = car - 1; k > j; k--) {
				if (weight[j] > weight[k]) {
					if (inlen[j] < inlen[k] + 1)
						inlen[j] = inlen[k] + 1;//�p��increasing subsequence
				}
				else if (weight[j] < weight[k]) {
					if (delen[j] < delen[k] + 1)
						delen[j] = delen[k] + 1;//�p��decreasing subsequence
				}
			}
		for (int j = 0; j < car; j++)
			if (answer < delen[j] + inlen[j])
				answer = delen[j] + inlen[j] - 1;//�P�@��subsequence���A�|���@�ӼƦr���ƭp��
		cout << answer << endl;
		delete[]weight;
		delete[]delen;
		delete[]inlen;
	}
}