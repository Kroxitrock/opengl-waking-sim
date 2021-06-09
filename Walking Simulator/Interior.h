#pragma once
#include "ObjectContainer.h"
#include "Table.h"
#include "Lamp.h"

class Interior : public ObjectContainer
{
public:
	Interior(glm::vec3 position = glm::vec3(0.0f)) : ObjectContainer(position) {
		tableComposition(5.0f);
		tableComposition(-5.0f);
		lampComposition(7.4f);
		lampComposition(-7.4f);
	}


	void lampComposition(float x) {
		GameObject* lamp1 = new Lamp(glm::vec3(0.1f, 0.1f, 0.5f),
			glm::vec3(0.0f, 0.0f, 0.0f), 0.0f, position + glm::vec3(x, 3.5f, 0.0f));
		GameObject* lamp2 = new Lamp(glm::vec3(0.1f, 0.1f, 0.5f),
			glm::vec3(0.0f, 0.0f, 0.0f), 0.0f, position + glm::vec3(x, 3.5f, 4.0f));
		GameObject* lamp3 = new Lamp(glm::vec3(0.1f, 0.1f, 0.5f),
			glm::vec3(0.0f, 0.0f, 0.0f), 0.0f, position + glm::vec3(x, 3.5f, -4.0f));

		this->parts.push_back(lamp1);
		this->parts.push_back(lamp2);
		this->parts.push_back(lamp3);
	}

	void tableComposition(float x) {
		GameObject* table1 = new Table(glm::vec3(x, 0.0f, 4.0f));
		GameObject* table2 = new Table(glm::vec3(x, 0.0f, 2.0f));
		GameObject* table3 = new Table(glm::vec3(x, 0.0f, 0.0f));
		GameObject* table4 = new Table(glm::vec3(x, 0.0f, -2.0f));
		GameObject* table5 = new Table(glm::vec3(x, 0.0f, -4.0f));

		this->parts.push_back(table1);
		this->parts.push_back(table2);
		this->parts.push_back(table3);
		this->parts.push_back(table4);
		this->parts.push_back(table5);

	}
};

