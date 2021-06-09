#pragma once
#include "GameObject.h"
#include <vector>

class ObjectContainer : public GameObject
{
protected:
	std::vector<GameObject*> parts;
public:

	void update() {
		for (GameObject* obj : parts) {
			obj->update();
		}
	}
};