#include <iostream>
#include <thread>

using namespace std;

void foo(int i) { cout << "foo() i = " << i << endl; }

struct task_struct
{
	int& i;

	task_struct(int& ii):i(ii){ 
		cout << "task_struct constructor i = " << i << endl;
	}

	void operator()()
	{
		for(unsigned j = 0; j < 10; ++j)
		{
			cout << j << ": foo()\n";
			foo(i);
		}
	}
};

void A_function_creating_a_thread_within()
{
	int state = 99;
	task_struct task(state);
	cout << "Launching a thread\n";
	std::thread t(task);
	// cout << "detaching the thread\n";
	// t.detach();
	cout << "joining the thread\n";
	t.join();
}

int main()
{
	A_function_creating_a_thread_within();
	cout << "END OF PROGRAM\n";
	return 0;
}