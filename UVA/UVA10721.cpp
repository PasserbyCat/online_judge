//UVA10721-k�Ӥ��j��m�������Ƭۥ[�n=n
#include <iostream>
using namespace std;
int main()
{
	long long table[51][51][51] = {};//�ت�
	for (int i = 1; i < 51; i++)
		for (int j = 1; j <= i; j++)
			for (int k = 1; k < 51; k++)
				if (k > i - j + 1)
					table[i][j][k] = table[i][j][i - j + 1];//��k == i - j + 1�ɡA��n�X�{�̤j�ȡA�L��k�b�A���W�[�]���|����j����
				else if (i == j || j * k == i)//��
					table[i][j][k] = 1;
				else
					for (int l = k; l > 0; l--)
						table[i][j][k] += table[i - l][j - 1][k];//�C�@�ӼƬҬOj - 1�檺�ƥ[�_�ӥBi - 1��i - k���s�[
	int n, k, m;
	while(cin >> n >> k >> m)
		cout << table[n][k][m] << endl;
}