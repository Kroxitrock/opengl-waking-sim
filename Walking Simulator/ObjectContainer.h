#pragma once
#include "GameObject.h"
#include <vector>

class ObjectContainer : public GameObject
{
protected:
	std::vector<GameObject*> parts;
	glm::vec3 position;
public:
	ObjectContainer(glm::vec3 position = glm::vec3(0.0f)) {
		this->position = position;
	}

	void update() {
		for (GameObject* obj : parts) {
			obj->update();
		}
	}
};