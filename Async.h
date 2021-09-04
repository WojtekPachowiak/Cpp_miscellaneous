#pragma once

#include<iostream>
#include <future>
#include <vector>


#define ASYNC_DONE_WELL 1
static std::mutex mutex;
static int acc = 0;



void ShitFunc() {
	int temp = 0;
	temp = temp; //just so compiler doesn't get mad that "temp" is not referenced anywhere


	for (int i = 0; i < 10000000; i++)
	{
#if ASYNC_DONE_WELL
		temp += i;
#else
		acc = acc + i;
#endif 
	}

	std::cout << std::this_thread::get_id() << " finished\n";

#if ASYNC_DONE_WELL
	std::lock_guard<std::mutex> lock(mutex);
	acc += temp;
#endif 

}



void fake_main() {

	std::vector<std::future<void>> futures;

	for (size_t i = 0; i < 10; i++)
	{
		futures.push_back(std::async(std::launch::async, ShitFunc));
	}

	std::this_thread::sleep_for(std::chrono::seconds(2));

	std::cout << "\n" << std::this_thread::get_id() << " is a main thread.\n\n";
	std::cout << "acc is equal to " << acc<< "\n";
}