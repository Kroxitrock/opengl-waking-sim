#pragma once
#include "ObjectContainer.h"
#include "Cube.h"

class Table : public ObjectContainer
{
public:
	Table(glm::vec3 position = glm::vec3(0.0f)) : ObjectContainer(position) {
		Material plotMaterial = {"metall001-new-tileable.png", 24.0f};
		Material stubMaterial = {"metall005-new-tileable.png", 16.0f};

		GameObject* stub = new Cube("table", stubMaterial, glm::vec3(0.2f, 1.0f, 0.2f),
			glm::vec3(0.0f, 0.0f, 0.0f), 0.0f, this->position + glm::vec3(0.0f, 0.0f, 0.0f));
		GameObject* plot = new Cube("table", plotMaterial, glm::vec3(1.0f, 0.1f, 1.0f),
			glm::vec3(0.0f, 0.0f, 0.0f), 0.0f, this->position + glm::vec3(0.0f, 0.5f, 0.0f));

		this->parts.push_back(stub);
		this->parts.push_back(plot);
	}
};

