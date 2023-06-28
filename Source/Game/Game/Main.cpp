#include <iostream>
#include "Core/Memory.h"
#include "Core/Random.h"
#include "Core/FileIO.h"

using namespace std;



int main() 
{

	int* p = new int;
	
	delete(p);


	cout << yogi::getFilePath() << endl;
	yogi::setFilePath("assets");
	cout << yogi::getFilePath() << endl;
	size_t size;

	yogi::getFileSize("game.txt", size);
	cout << size << endl;

	std::string s;
	yogi::readFile("game.txt", s);

	cout << s << endl;

	yogi::seedRandom((unsigned int)time(nullptr));
	/*for (int i = 0; i < 3; i++)
	{
		cout << yogi::random(10, 12) << endl;
	}*/
}