#include <iostream>
#include <queue>
using namespace std;
struct Register
{
	int name = 0;
	int pretime = 0;//�C���һݮɶ�
	int alltime = 0;//�U�@��Ĳ�o�O�ĴX��
	bool operator > (const Register& a) const //greater�ݩ�
	{
		return (alltime > a.alltime) || (alltime == a.alltime && name > a.name);
	}
};
int main()
{
	priority_queue<Register, vector<Register>, greater<Register>>all;//�Ѥp�ƨ�j��priority_queue
	Register buffer;
	string temp;
	cin >> temp;
	while (temp != "#") {
		cin >> buffer.name >> buffer.pretime >> temp;
		buffer.alltime = buffer.pretime;
		all.push(buffer);
	}
	int number;
	cin >> number;
	for (int i = 0; i < number; i++) {
		buffer = all.top();//�̤W������Y�O�U�@�ӿ�X��
		all.pop();
		cout << buffer.name << endl;
		buffer.alltime += buffer.pretime;//�U��Ĳ�o�ɶ����A����Ĳ�o�ɶ��[�W�C���һݮɶ�
		all.push(buffer);//�N���X�Ӫ��F�譫�s��ipriority_queue
	}
}