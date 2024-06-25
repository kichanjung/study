#include<iostream>
#include<list>
#include<vector>
#include<stack>
#include<queue>

using namespace std;

class Vec
{
private:
	vector<int> v;
	stack<int> ack;
	queue<int> que;

public:
	void Vec_Run();
	void Ack_Run();
	void Que_Run(queue<int> que);
};

void Vec::Vec_Run()
{
	for (int i = 0; i <= 10; i++)
	{
		v.push_back(i);
	}
	for (int a : v) {
		std::cout << a << " ";
	}
	cout << "\n";
	v.pop_back();

	for (int a : v) std::cout << a << " ";
	cout << "\n";

	v.erase(v.begin(), v.begin() + 1);

	for (int a : v) std::cout << a << " ";
	cout << "\n";

	auto a = find(v.begin(), v.end(), 100);
	if (a == v.end()) cout << "not found" << "\n";

	fill(v.begin(), v.end(), 10);
	for (int a : v) cout << a << " ";
	cout << "\n";
	v.clear();
	for (int a : v) cout << a << " ";
	cout << "\n";
}

void Vec::Ack_Run()
{
	for (int i = 0; i < 10; i++) ack.push(i);

	while (ack.size()) {
		std::cout << ack.top() << " ";
		ack.pop();
	}
}

void Vec::Que_Run(queue<int> que)
{
	queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	while (!que.empty())
	{
		std::cout << que.front() << " ";
		que.pop();
	}
	/*std::cout << q.front() << "\n";
	q.pop();
	std::cout << q.size() << "\n";*/
}


int main()
{
	Vec v;
	//v.Vec_Run();
	//v.Ack_Run();
	queue<int> que;
	que.push(10);
	que.push(20);
	que.push(30);
	que.push(40);
	v.Que_Run(que);


	/*list<int> a;
	for (int i = 0; i < 10; i++)a.push_back(i);
	for (int i = 0; i < 10; i++)a.push_front(i);

	auto it = a.begin();
	it++;
	a.insert(it, 1000);
	for (auto it : a) cout << it << " ";
	cout << '\n';
	a.pop_front();
	a.pop_back();
	for (auto it : a) cout << it << " ";
	cout << "\n";*/
	return 0;
}