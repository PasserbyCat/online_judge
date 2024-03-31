#include <iostream>
#include <queue>
using namespace std;
struct Register
{
	int name = 0;
	int pretime = 0;//每次所需時間
	int alltime = 0;//下一次觸發是第幾秒
	bool operator > (const Register& a) const //greater屬性
	{
		return (alltime > a.alltime) || (alltime == a.alltime && name > a.name);
	}
};
int main()
{
	priority_queue<Register, vector<Register>, greater<Register>>all;//由小排到大的priority_queue
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
		buffer = all.top();//最上面那位即是下一個輸出的
		all.pop();
		cout << buffer.name << endl;
		buffer.alltime += buffer.pretime;//下次觸發時間為，本次觸發時間加上每次所需時間
		all.push(buffer);//將取出來的東西重新放進priority_queue
	}
}