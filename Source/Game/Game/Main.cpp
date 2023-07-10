#include <iostream>
#include "Core/Core.h"
#include "Renderer/Renderer.h"
#include <vector>

using namespace std;
using vec2 = yogi::Vector2;

class Star
{
public:
	Star(const vec2& pos, const vec2& vel):
		m_pos{ pos },
		m_vel{ vel }{}

	void Update()
	{
		m_pos += m_vel;
	}
public:
	vec2 m_pos;
	vec2 m_vel;
};


int main(int argc, char* argv[])
{
	yogi::seedRandom((unsigned int)time(nullptr));

	yogi::Renderer renderer;
	renderer.Initialize();
	renderer.CreateWindow("CSC196", 800, 600);

	vector<Star> stars;
	for (int i = 0; i < 5000; i++) {
		vec2 pos(vec2(yogi::random(renderer.GetWidth()), yogi::random(renderer.GetHeight())));
		vec2 vel(yogi::randomf(1, 4), 0.0f);
		stars.push_back(Star(pos, vel));
	}

	int r = yogi::random(256);
	int g = yogi::random(256);
	int b = yogi::random(256);
	while (true) 
	{
		renderer.SetColor(0, 0, 0, 0);
		renderer.BeginFrame();
		// draw

		yogi::Vector2 vel(1.0f, 0.3f); 


		for (auto& star : stars) {

			star.Update();

			if (star.m_pos.x >= renderer.GetWidth()) star.m_pos.x = 0;
			if (star.m_pos.y >= renderer.GetHeight()) star.m_pos.y = 0;
			r = yogi::random(256);
			g = yogi::random(256);
			b = yogi::random(256);
			renderer.SetColor(r, g, b, 1);
			renderer.DrawPoint(star.m_pos.x, star.m_pos.y);
		}

		/*for (int i = 0; i < 100; i++) {
			yogi::Vector2 pos(yogi::random(renderer.GetWidth()), yogi::random(renderer.GetHeight()));
			r = yogi::random(256);
			g = yogi::random(256);
			b = yogi::random(256);
			renderer.SetColor(r, g, b, 1);
			renderer.DrawPoint(pos.x, pos.y);
		}*/
		renderer.EndFrame();
	}

	//yogi::CreateWindow("CSC196", 800, 600);
	//cin.get(); //pauses

	/*yogi::g_memoryTracker.DisplayInfo();

	int* p = new int;
	yogi::g_memoryTracker.DisplayInfo();
	
	delete(p);
	yogi::g_memoryTracker.DisplayInfo();
	
	yogi::MemoryAllocation timer;
	for (int i = 0; i < 10000000; i++) {}



	auto start = std::chrono::high_resolution_clock::now();

	for (int i = 0; i < 10000000; i++) {}
	auto end = std::chrono::high_resolution_clock::now();

	cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << endl;*/

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