#pragma once
#include "Interior.h"

class Room : public ObjectContainer
{
public:
	Room(glm::vec3 position = glm::vec3(0.0f)) {
		Material floorMaterial = { "m-013-015-bg.jpg", 32.0f };
		Material ceilingMaterial = { "m-011.jpg", 32.0f };
		Material wallMaterial = { "m-025.jpg", 32.0f };

		GameObject* floor = new Cube("floor", floorMaterial,glm::vec3(15.0f, 0.1f, 15.0f),
			glm::vec3(0.0f, 0.0f, 0.0f), 0.0f, position + glm::vec3(0.0f, -0.5f, 0.0f));
		GameObject* wall1 = new Cube("wall1", wallMaterial,glm::vec3(0.1f, 5.0f, 15.0f),
			glm::vec3(0.0f, 0.0f, 0.0f), 0.0f, position + glm::vec3(-7.5f, 2.0f, 0.0f));
		GameObject* wall2 = new Cube("wall2", wallMaterial,glm::vec3(0.1f, 5.0f, 15.0f),
			glm::vec3(0.0f, 0.0f, 0.0f), 0.0f, position + glm::vec3(7.5f, 2.0f, 0.0f));

		GameObject* wall3 = new Cube("wall3", wallMaterial,glm::vec3(15.0f, 5.0f, 0.1f),
			glm::vec3(0.0f, 1.0f, 0.0f), 0.0f, position + glm::vec3(0.0f, 2.0f, 7.5f));

		GameObject* wall4 = new Cube("wall4", wallMaterial,glm::vec3(15.0f, 5.0f, 0.1f),
			glm::vec3(0.0f, 1.0f, 0.0f), 0.0f, position + glm::vec3(0.0f, 2.0f, -7.5f));

		GameObject* ceiling = new Cube("ceiling", ceilingMaterial, glm::vec3(15.0f, 0.1f, 15.0f),
			glm::vec3(0.0f, 0.0f, 0.0f), 0.0f, position + glm::vec3(0.0f, 4.5f, 0.0f));
		GameObject* interior = new Interior();
		

		this->parts.push_back(floor);
		this->parts.push_back(wall1);
		this->parts.push_back(wall2);
		this->parts.push_back(wall3);
		this->parts.push_back(wall4);
		this->parts.push_back(ceiling);
		this->parts.push_back(interior);
	}
};

