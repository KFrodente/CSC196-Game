#include <iostream>
#include "Core/Core.h"
#include "Renderer/Model.h"
#include "Renderer/Renderer.h"
#include "Input/InputSystem.h"
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
	yogi::InputSystem inputSystem;
	inputSystem.Initialize();

	yogi::seedRandom((unsigned int)time(nullptr));

	yogi::Renderer renderer;
	renderer.Initialize();
	renderer.CreateWindow("CSC196", 800, 600);

	std::vector<vec2> points{ { 1, 1}, { 15, 1 }, { 15, 15 }, { 1, 15 }};

	yogi::Model model(points);

	yogi::vec2 v{5, 5};
	v.Normalize();


	vector<Star> stars;
	for (int i = 0; i < 5000; i++) {
		vec2 pos(vec2(yogi::random(renderer.GetWidth()), yogi::random(renderer.GetHeight())));
		vec2 vel(yogi::randomf(1, 4), 0.0f);
		stars.push_back(Star(pos, vel));
	}

	/*int r = yogi::random(256);
	int g = yogi::random(256);
	int b = yogi::random(256);*/
	
	int r = 255;
	int g = 255;
	int b = 85;

	bool quit = false;
	while (!quit) 
	{
		inputSystem.Update();
		if (inputSystem.GetKeyDown(SDL_SCANCODE_ESCAPE))
		{
			quit = true;
		}

		if (inputSystem.GetMouseButtonDown(0)) cout << "left mouse down";
		if (inputSystem.GetMouseButtonDown(1)) cout << "middle mouse down";
		if (inputSystem.GetMouseButtonDown(2)) cout << "right mouse down";
		
		cout << inputSystem.GetMousePosition().x << ", " << inputSystem.GetMousePosition().y << endl;

		renderer.SetColor(0, 0, 0, 0);
		renderer.BeginFrame();
		// draw
		//r = yogi::random(256);
		//g = yogi::random(256);
		//b = yogi::random(256);

		yogi::Vector2 vel(1.0f, 0.3f); 

		renderer.SetColor(r,g, b, 0);

		/*for (auto& star : stars) {

			star.Update();

			if (star.m_pos.x >= renderer.GetWidth()) star.m_pos.x = 0;
			if (star.m_pos.y >= renderer.GetHeight()) star.m_pos.y = 0;
			r = yogi::random(256);
			g = yogi::random(256);
			b = yogi::random(256);
			renderer.SetColor(r, g, b, 1);
			renderer.DrawPoint(star.m_pos.x, star.m_pos.y);
		}*/
		
		model.Draw(renderer, {300, 300}, 5, true);
		model.Draw(renderer, {100, 300}, 5, true);
		model.Draw(renderer, {300, 100}, 5, true);
		model.Draw(renderer, {100, 100}, 5, true);
		
		/*model.Draw(renderer, {200, 300}, 5, true);
		model.Draw(renderer, {100, 200}, 5, true);
		model.Draw(renderer, {200, 100}, 5, true);
		model.Draw(renderer, {300, 200}, 5, true);*/
		
		model.Draw(renderer, {250, 250}, 5, true);
		model.Draw(renderer, {150, 250}, 5, true);
		model.Draw(renderer, {250, 150}, 5, true);
		model.Draw(renderer, {150, 150}, 5, true);
		
		model.Draw(renderer, {200, 200}, 5, true);



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
	return 0;
}