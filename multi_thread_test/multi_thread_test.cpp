#include <iostream>
#include <unistd.h>
#include "multi_thread_test.h"

using namespace std;

multi_thread_create::multi_thread_create()
{
	m_max_num = 10240000;
	m_num = 0;
}

multi_thread_create::~multi_thread_create()
{
	pthread_join(m_thread_a, NULL);
	pthread_join(m_thread_b, NULL);
	cout << 2 * m_max_num << " " << m_num << endl;
}

void *multi_thread_create::thread_fn(void *program)
{
	int i = 0;
	multi_thread_create *handle = (multi_thread_create*)program;

	for (i = 0; i < handle->m_max_num; i++)
	{
		pthread_mutex_lock(&(handle->m_mutex));
		handle->m_num++;
		pthread_mutex_unlock(&(handle->m_mutex));
	}

	return NULL;
}

void multi_thread_create::start_test()
{
	int result;

	pthread_mutex_init(&m_mutex, NULL);

	result = pthread_create(&m_thread_a, NULL, thread_fn, this);
	if (result)
	{
		cout << "one create error!" << endl;
	}
	
	result = pthread_create(&m_thread_b, NULL, thread_fn, this);
	if (result)
	{
		cout << "two create error!" << endl;
	}
}

int main(int argc, char *argv[])
{
	multi_thread_create *example = new multi_thread_create;

	example->start_test();
	// sleep(2);
	delete example;

	return 0;
}


