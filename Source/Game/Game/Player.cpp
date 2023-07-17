#include "Player.h"
#include "Input/InputSystem.h"
#include "Renderer/Renderer.h"

void Player::Update(float dt)
{
	float rotate = 0;
	if (yogi::g_inputSystem.GetKeyDown(SDL_SCANCODE_A)) rotate = -1;
	if (yogi::g_inputSystem.GetKeyDown(SDL_SCANCODE_D)) rotate = 1;
	m_transform.rotation += rotate * m_turnRate * yogi::g_time.GetDeltaTime();


	float thrust = 0;
	if (yogi::g_inputSystem.GetKeyDown(SDL_SCANCODE_W)) thrust = 1;
	if (yogi::g_inputSystem.GetKeyDown(SDL_SCANCODE_S)) thrust = -1;

	yogi::vec2 forward = yogi::vec2{ 0, -1 }.Rotate(m_transform.rotation);
	m_transform.position += forward * m_speed * thrust * yogi::g_time.GetDeltaTime();
	m_transform.position.x = yogi::Wrap(m_transform.position.x, yogi::g_renderer.GetWidth());
	m_transform.position.y = yogi::Wrap(m_transform.position.y, yogi::g_renderer.GetHeight());
}
