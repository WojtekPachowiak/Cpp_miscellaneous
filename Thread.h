#pragma once
#include<iostream>
#include <thread>


static bool isFinished = false;

void PrintHello() {
	using namespace std::literals::chrono_literals;
	while (!isFinished)
	{
		std::cout << "hello!" << std::endl;
		std::this_thread::sleep_for(1s);
	}
}

void fake_main() {
	std::thread thread1(PrintHello);


	std::cin.get();
	isFinished = true;

	thread1.join();

	std::cout << "Finish ;p" << std::endl;
}