#include <iostream>
#include <map>
#include <string>
#include <iomanip>
using namespace std;
int main()
{
	string temp;
	int blank;
	cin >> blank;//���X���ϰ�ݭn�PŪ
	temp = "\n";
	getline(cin, temp);//11��P12��O���F�ѨMcin��getline�|�Q���������D
	/*getchar();�Ϊk�P11��+12��
	getchar();*/
	cout << fixed << setprecision(4);//�j���X�p���I��|��
	for (int i = 0; i <= blank; i++) {
		map<string, int>treenode;
		int total = 0;
		while (getline(cin, temp)) {
			if (temp == "")
				break;
			//if (treenode.count(temp))
				treenode[temp]++;//���Ϊk�N�]�tinsert
			//else
				//treenode.insert(pair<string, int>(temp, 1));
			total++;
		}
		map<string, int>::iterator it = treenode.begin();
		for (map<string, int>::iterator it = treenode.begin(); it != treenode.end(); it++)
			cout << it->first << " " 
				<< it->second * 100.0 / total //100.0�j��Nint�૬���H�p���I����
				<< endl;
		if (i != 0 && i != blank)//�Ĥ@���û��O�Ū��F�̫�@�����ο�Xendl�A���ŦX�y�k
			cout << endl;
	}
}
