#pragma once
#include "ObjectContainer.h"
#include "Cube.h"
#include "Lamp.h"

class Table : public ObjectContainer
{
public:
	Table() {
		Material plotMaterial = {"metall001-new-tileable.png", 16.0f};
		Material stubMaterial = {"metall005-new-tileable.png", 16.0f};

		GameObject* stub = new Cube(stubMaterial, glm::vec3(0.2f, 1.0f, 0.2f),
			glm::vec3(0.0f, 0.0f, 0.0f), 0.0f, glm::vec3(0.0f, 0.0f, 0.0f));
		GameObject* plot = new Cube(plotMaterial, glm::vec3(1.0f, 0.1f, 1.0f),
			glm::vec3(0.0f, 0.0f, 0.0f), 0.0f, glm::vec3(0.0f, 0.5f, 0.0f));
		GameObject* light = new Lamp(glm::vec3(0.5f), glm::vec3(0.0f, 0.0f, 0.0f), 0.0f, glm::vec3(3.0f, 2.0f, 1.0f));

		this->parts.push_back(stub);
		this->parts.push_back(plot);
		this->parts.push_back(light);
	}
};

