#pragma once
#include "ObjectContainer.h"
#include "Cube.h"

class Bench : public ObjectContainer
{
public:
	Bench(glm::vec3 position = glm::vec3(0.0f)) : ObjectContainer(position) {
		Material plotMaterial = { "metall005-new-tileable.png", 16.0f };
		Material legMaterial = { "metall010-new-tileable.png", 16.0f };

		GameObject* leg1 = new Cube(legMaterial, glm::vec3(0.1f, 0.5f, 0.1f),
			glm::vec3(0.0f, 0.0f, 0.0f), 0.0f, this->position + glm::vec3(0.0f, -0.2f, 4.0f));
		GameObject* leg2 = new Cube(legMaterial, glm::vec3(0.1f, 0.5f, 0.1f),
			glm::vec3(0.0f, 0.0f, 0.0f), 0.0f, this->position + glm::vec3(0.0f, -0.2f, 2.0f));
		GameObject* leg3 = new Cube(legMaterial, glm::vec3(0.1f, 0.5f, 0.1f),
			glm::vec3(0.0f, 0.0f, 0.0f), 0.0f, this->position + glm::vec3(0.0f, -0.2f, 0.0f));
		GameObject* leg4 = new Cube(legMaterial, glm::vec3(0.1f, 0.5f, 0.1f),
			glm::vec3(0.0f, 0.0f, 0.0f), 0.0f, this->position + glm::vec3(0.0f, -0.2f, -2.0f));
		GameObject* leg5 = new Cube(legMaterial, glm::vec3(0.1f, 0.5f, 0.1f),
			glm::vec3(0.0f, 0.0f, 0.0f), 0.0f, this->position + glm::vec3(0.0f, -0.2f, -4.0f));
		GameObject* plot = new Cube(plotMaterial, glm::vec3(1.0f, 0.1f, 9.0f),
			glm::vec3(0.0f, 0.0f, 0.0f), 0.0f, this->position + glm::vec3(0.0f, 0.1f, 0.0f));

		this->parts.push_back(leg1);
		this->parts.push_back(leg2);
		this->parts.push_back(leg3);
		this->parts.push_back(leg4);
		this->parts.push_back(leg5);
		this->parts.push_back(plot);
	}
};

