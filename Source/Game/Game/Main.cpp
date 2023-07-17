#include <iostream>
#include "Core/Core.h"
#include "Renderer/Model.h"
#include "Player.h"
#include "Renderer/Renderer.h"
#include "Input/InputSystem.h"
#include <vector>
#include <thread>
#include "Enemy.h"
#include "Audio/AudioSystem.h"

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
		m_pos += m_vel * yogi::g_time.GetDeltaTime();
		
	}
public:
	vec2 m_pos;
	vec2 m_vel;
};


int main(int argc, char* argv[])
{
	constexpr float a = yogi::Deg2Rad(180.0f);

	int m1 = yogi::Max(4.0f, 3.0f);
	int m2 = yogi::Max(4, 3);


	yogi::g_audioSystem.Initialize();
	yogi::setFilePath("assets");
	yogi::g_audioSystem.AddAudio("hitSound1", "hitSound1.wav");

	yogi::g_inputSystem.Initialize();

	yogi::seedRandom((unsigned int)time(nullptr));


	yogi::g_renderer.Initialize();
	yogi::g_renderer.CreateWindow("CSC196", 800, 600);


	yogi::Model model;

	model.Load("ship.txt");

	/*yogi::vec2 v{5, 5};
	v.Normalize();


	
	vector<Star> stars;
	for (int i = 0; i < 5000; i++) {
		vec2 pos(vec2(yogi::random(renderer.GetWidth()), yogi::random(renderer.GetHeight())));
		vec2 vel(yogi::randomf(1, 4), 0.0f);
		stars.push_back(Star(pos, vel));
	}*/

	/*int r = yogi::random(256);
	int g = yogi::random(256);
	int b = yogi::random(256);*/
	
	int r = 255;
	int g = 255;
	int b = 85;

	yogi::Transform transform{ {400, 300}, 0, 5 };
	yogi::vec2 position{400, 300};
	float speed = 600;
	constexpr float turnSpeed = yogi::Deg2Rad(180);

	Player player{ 200, yogi::Pi, {{400, 300}, 0, 5}, model };

	std::vector<Enemy> enemies;
	for (int i = 0; i < 1000; i++) {
		Enemy enemy{ 300, yogi::Pi, {{yogi::random(800), yogi::random(600)}, yogi::randomf(0, yogi::TwoPi), 2}, model};
		enemies.push_back(enemy);
	}

	//main game loop
	bool quit = false;
	while (!quit) 
	{
		//update engine
		yogi::g_time.Tick();
		yogi::g_inputSystem.Update();

		yogi::g_audioSystem.Update();

		if (yogi::g_inputSystem.GetKeyDown(SDL_SCANCODE_ESCAPE))
		{
			quit = true;
		}

		if (yogi::g_inputSystem.GetKeyDown(SDL_SCANCODE_SPACE) && !yogi::g_inputSystem.GetPreviousKeyDown(SDL_SCANCODE_SPACE))
		{
			yogi::g_audioSystem.PlayOneShot("hitSound1");
		}

		//update game
		player.Update(yogi::g_time.GetDeltaTime());
		for (auto& enemy : enemies) enemy.Update(yogi::g_time.GetDeltaTime());

		//draw game

		/*position += direction * speed * yogi::g_time.GetDeltaTime();*/

		yogi::g_renderer.SetColor(0, 0, 0, 0);
		yogi::g_renderer.BeginFrame();
		// draw
		//r = yogi::random(256);
		//g = yogi::random(256);
		//b = yogi::random(256);

		//yogi::Vector2 vel(1.0f, 0.3f); 

		yogi::g_renderer.SetColor(r,g, b, 0);

		player.Draw(yogi::g_renderer);

		for (auto& enemy : enemies) enemy.Draw(yogi::g_renderer);
		//model.Draw(yogi::g_renderer, transform.position, transform.rotation, transform.scale, false);
		
		yogi::g_renderer.EndFrame();
	}
	
	return 0;
}