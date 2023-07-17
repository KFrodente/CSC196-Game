#pragma once
#include "GameObject.h"

class Enemy : public GameObject
{
public:

	Enemy(float speed, float turnRate, const yogi::Transform& transform, const yogi::Model& model) :
		GameObject{ transform, model },
		m_speed{ speed },
		m_turnRate{ turnRate }
	{}

	void Update(float dt) override;

private:
	float m_speed = 0;
	float m_turnRate = 0;
};