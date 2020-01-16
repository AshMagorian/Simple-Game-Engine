#include "Component.h"
#include <glm/glm.hpp>

class BoxCollider : public Component
{
private:

	void CollideBox();

	glm::vec3 m_size;
	glm::vec3 m_offset;
	glm::vec3 m_lastPosition;

	bool IsColliding(glm::vec3 _position, glm::vec3 _size);

	glm::vec3 GetCollisionResponse(glm::vec3 _position, glm::vec3 _size);


public:
	void onInit();
	void onTick();

	void SetOffset(glm::vec3 _offset);
	void SetSize(glm::vec3 _size);

};