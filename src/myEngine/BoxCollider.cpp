#include "BoxCollider.h"
#include "Entity.h"
#include "Transform.h"
#include "Application.h"
#include <vector>

void BoxCollider::onInit()
{
	m_size = glm::vec3(1.0f, 1.0f, 1.0f);
	m_lastPosition = getEntity()->GetTransform()->GetPos();
}

void BoxCollider::SetOffset(glm::vec3 _offset)
{
	m_offset = _offset;
}

void BoxCollider::SetSize(glm::vec3 _size)
{
	m_size = _size;
}

void BoxCollider::onTick()
{
	CollideBox();
}

void BoxCollider::CollideBox()
{
	std::vector<std::shared_ptr<Entity> > bces;

	getApplication()->GetEntities<BoxCollider>(bces);
	glm::vec3 np = getEntity()->GetTransform()->GetPos() + m_offset;

	for (std::vector<std::shared_ptr<Entity> >::iterator it = bces.begin();
		it != bces.end(); it++)
	{
		if (*it == getEntity())
		{
			continue;
		}

		std::shared_ptr<BoxCollider> bc =
			(*it)->GetComponent<BoxCollider>();

		glm::vec3 sp = bc->GetCollisionResponse(np, m_size);
		np = sp;
		np = np - m_offset;
		getEntity()->GetTransform()->SetPos(np);
		m_lastPosition = np;
	}
}

bool BoxCollider::IsColliding(glm::vec3 _position, glm::vec3 _size)
{
	glm::vec3 a = getEntity()->GetTransform()->GetPos() + m_offset;
	glm::vec3& as = this->m_size;
	glm::vec3& b = _position;
	glm::vec3& bs = _size;

	if (a.x > b.x) // a right of b
	{
		if (a.x - as.x > b.x + bs.x) // left edge of a greater than right edge of b (not colliding)
		{
			return false;
		}
	}
	else
	{
		if (b.x - bs.x > a.x + as.x)
		{
			return false;
		}
	}

	if (a.z > b.z) // a front of b
	{
		if (a.z - as.z > b.z + bs.z) // back edge of a greater than front edge of b (not colliding)
		{
			return false;
		}
	}
	else
	{
		if (b.z - bs.z > a.z + as.z)
		{
			return false;
		}
	}

	if (a.y > b.y) // a above b
	{
		if (a.y - as.y > b.y + bs.y) // bottom edge of a greater than top edge of b (not colliding)
		{
			return false;
		}
	}
	else
	{
		if (b.y - bs.y > a.y + as.y)
		{
			return false;
		}
	}

	return true;
}

glm::vec3 BoxCollider::GetCollisionResponse(glm::vec3 _position, glm::vec3 _size)
{
	float amount = 0.1f;
	float step = 0.1f;

	while (true)
	{
		if (!IsColliding(_position, _size)) break;
		_position.x += amount;
		if (!IsColliding(_position, _size)) break;
		_position.x -= amount;
		_position.x -= amount;
		if (!IsColliding(_position, _size)) break;
		_position.x += amount;
		_position.z += amount;
		if (!IsColliding(_position, _size)) break;
		_position.z -= amount;
		_position.z -= amount;
		if (!IsColliding(_position, _size)) break;
		_position.z += amount;
		_position.y += amount;
		if (!IsColliding(_position, _size)) break;
		_position.y -= amount;
		_position.y -= amount;
		if (!IsColliding(_position, _size)) break;
		_position.y += amount;
		amount += step;
	}

	return _position;
}