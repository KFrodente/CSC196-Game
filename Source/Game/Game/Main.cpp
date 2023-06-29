#include <iostream>
#include <chrono>
#include "Core/Memory.h"
#include "Core/Random.h"
#include "Core/FileIO.h"
#include "Core/Time.h"
#include "Renderer/Renderer.h"

using namespace std;



int main() 
{
	yogi::g_memoryTracker.DisplayInfo();

	int* p = new int;
	yogi::g_memoryTracker.DisplayInfo();
	
	delete(p);
	yogi::g_memoryTracker.DisplayInfo();
	
	yogi::MemoryAllocation timer;
	for (int i = 0; i < 10000000; i++) {}



	auto start = std::chrono::high_resolution_clock::now();

	for (int i = 0; i < 10000000; i++) {}
	auto end = std::chrono::high_resolution_clock::now();

	cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << endl;

	//cout << yogi::getFilePath() << endl;
	//yogi::setFilePath("assets");
	//cout << yogi::getFilePath() << endl;
	//size_t size;

	//yogi::getFileSize("game.txt", size);
	//cout << size << endl;

	//std::string s;
	//yogi::readFile("game.txt", s);

	//cout << s << endl;

	//yogi::seedRandom((unsigned int)time(nullptr));
	///*for (int i = 0; i < 3; i++)
	//{
	//	cout << yogi::random(10, 12) << endl;
	//}*/
}