#pragma once
#include <pthread.h>

class test_pthread_create
{
public:
	test_pthread_create();
	~test_pthread_create();
	
public:
	int start_test();
	static void *thread_fn_a(void *pragma);
	static void *thread_fn_b(void *pragma);
	static void *thread_fn_c(void *pragma);

private:
	pthread_t m_thread_a;
	pthread_t m_thread_b;
	pthread_t m_thread_c;

};



