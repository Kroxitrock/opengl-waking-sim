#pragma once
#include "GameObject.h"
#include "Cube.h"

class Table : public GameObject
{
private:
	std::vector<GameObject*> parts;
public:
	// FIXME: create shader manager to handle shaders
	Table(Shader *shader, Camera *mainCamera) {

		GameObject* stub = new Cube(shader, mainCamera, glm::vec3(0.2f, 1.0f, 0.2f),
			glm::vec3(0.0f, 0.0f, 0.0f), 0.0f, glm::vec3(0.0f, 0.0f, 0.0f));
		GameObject* plot = new Cube(shader, mainCamera, glm::vec3(1.0f, 0.1f, 1.0f),
			glm::vec3(0.0f, 0.0f, 0.0f), 0.0f, glm::vec3(0.0f, 0.5f, 0.0f));

		parts.push_back(stub);
		parts.push_back(plot);
	}
	void update() {
		for (GameObject* obj : parts) {
			obj->update();
		}
	}
};

