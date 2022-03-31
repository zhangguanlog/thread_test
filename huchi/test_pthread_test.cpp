#include <iostream>
#include <unistd.h>
#include <sys/prctl.h>
#include "test_pthread_test.h"

using namespace std;

test_pthread_create::test_pthread_create()
{

}

test_pthread_create::~test_pthread_create()
{

}

void *test_pthread_create::thread_fn_a(void *pragma)
{
	prctl(PR_SET_NAME, "thread_fn_one");
	while (1)
	{
		cout << "I am a!" << endl;
		sleep(5);
	}

	return NULL;
}

void *test_pthread_create::thread_fn_b(void *pragma)
{
	prctl(PR_SET_NAME, "thread_fn_two");

	while (1)
	{
		cout << "I am b!" << endl;
		sleep(5);
	}

	return NULL;
}

void *test_pthread_create::thread_fn_c(void *pragma)
{
	prctl(PR_SET_NAME, "thread_fn_three");

	while (1)
	{
		cout << "I am c!" << endl;
		sleep(5);
	}

	return NULL;
}

int test_pthread_create::start_test()
{
	int result;

	result = pthread_create(&m_thread_a, NULL, thread_fn_a, this);
	if (result != 0)
	{
		cout << "a create error!" << endl;
	}

	result = pthread_create(&m_thread_b, NULL, thread_fn_b, this);
	if (result != 0)
	{
		cout << "b create error!" << endl;
	}

	result = pthread_create(&m_thread_b, NULL, thread_fn_c, this);
	if (result != 0)
	{
		cout << "c create error!" << endl;
	}

	return 0;
}


int main(int argc, char *argv[])
{
	test_pthread_create *test = new test_pthread_create;

	test->start_test();

	while(1)
	{
		cout << "I AM D" << endl;
		sleep(4);
	}

	delete test;

	return 0;
}

