#include "GameObject.h"


void GameObject::Draw(yogi::Renderer& renderer)
{
	m_model.Draw(renderer, m_transform);
}
