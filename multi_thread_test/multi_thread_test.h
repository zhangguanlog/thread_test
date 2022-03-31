#pragma once
#include <pthread.h>


class multi_thread_create
{
public:
	multi_thread_create();
	~multi_thread_create();

public:
	void start_test();
	static void *thread_fn(void *program);

public:
	pthread_t m_thread_a;
	pthread_t m_thread_b;
	pthread_mutex_t m_mutex;
	long long int m_num;
	long long int m_max_num;

};

