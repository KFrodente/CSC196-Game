#pragma once
#include "Core/Core.h"
#include "Renderer/Model.h"

class GameObject 
{
public:
	GameObject() = default;
	GameObject(const yogi::Transform& transform, const yogi::Model& model) :
		m_transform{ transform },
		m_model{ model }
	{}

	virtual void Update(float dt) = 0;
	virtual void Draw(yogi::Renderer& renderer);

protected:
	yogi::Transform m_transform;
	yogi::Model m_model;

};