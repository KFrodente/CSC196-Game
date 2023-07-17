#include "Enemy.h"
#include "Renderer/Renderer.h"

void Enemy::Update(float dt)
{
	yogi::vec2 forward = yogi::vec2{ 0, -1 }.Rotate(m_transform.rotation);
	m_transform.position += forward * m_speed * yogi::g_time.GetDeltaTime();
	m_transform.position.x = yogi::Wrap(m_transform.position.x, yogi::g_renderer.GetWidth());
	m_transform.position.y = yogi::Wrap(m_transform.position.y, yogi::g_renderer.GetHeight());
}
