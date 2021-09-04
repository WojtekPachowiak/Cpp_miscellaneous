#pragma once

#include<iostream>
#include<thread>
#include<chrono>


struct Timer {
	std::chrono::time_point<std::chrono::steady_clock> start, end;
	std::chrono::duration<float> duration;

	Timer(){
		start = std::chrono::high_resolution_clock::now();
	}

	~Timer(){
		end = std::chrono::high_resolution_clock::now();
		duration = end - start;
		duration = std::chrono::duration_cast<std::chrono::milliseconds>(duration);
		std::cout << "Timer took " << duration.count() << "ms" << std::endl;
	}
};


void ShitFunc() {
	Timer timer;
	for (size_t i = 0; i < 100; i++)
	{
		std::cout << "ay\n";
	}

}


void fake_main() {
	ShitFunc();
}
