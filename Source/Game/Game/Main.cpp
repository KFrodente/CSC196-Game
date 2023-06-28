#include <iostream>
#include "../../Engine/Core/Random.h"
#include "../../Engine/Core/FileIO.h"

using namespace std;

int main() 
{
	cout << yogi::getFilePath() << endl;

	yogi::seedRandom((unsigned int)time(nullptr));
	for (int i = 0; i < 3; i++) 
	{
		cout << yogi::random(10, 12) << endl;
	}
}