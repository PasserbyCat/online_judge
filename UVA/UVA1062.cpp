#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>
using namespace std;
int main()
{
	string input;
	vector<stack<char>>all;
	int j = 1;//存第幾個case
	while (cin >> input) {
		if (input == "end")//終止符號
			break;
		while (!input.empty()) {//每次只判斷一個位元，判斷後即刪除
			bool doing = true;//判斷有沒有push
			for (int i = 0; i < all.size(); i++)
				if (input[0] <= all[i].top()) {//比較小代表可以裝進去
					all[i].push(input[0]);
					input.erase(input.begin());
					doing = false;
					break;
				}
			if (doing) {//都沒有裝進去時，額外開一個新的stack儲存
				stack<char>temp;
				temp.push(input[0]);
				input.erase(input.begin());
				all.push_back(temp);
			}
		}
		cout << "Case " << j << ": " << all.size() << endl;
		j++;
		all.clear();//在所有測資結束後將vector清空
	}
}