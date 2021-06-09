#pragma once
#include "Camera.h"
#include "GameObject.h"
#include "Shader.h"
#include "PointLightManager.h"
#include "ShaderManager.h"

class Lamp : public GameObject
{
private:
	unsigned int VBO;
	unsigned int VAO;
	Shader* shader;

	glm::vec3 scaleVec;
	glm::vec3 rotateVec;
	glm::vec3 transalteVec;
	float rotateAngle;
	PointLight* pointLight;

	glm::mat4 scale(glm::mat4 model);
	glm::mat4 rotate(glm::mat4 model);
	glm::mat4 translate(glm::mat4 model);

public:
	Lamp(glm::vec3 scaleVec = glm::vec3(0.0f, 0.0f, 0.0f),
		glm::vec3 rotateVec = glm::vec3(0.0f, 0.0f, 0.0f), float rotateAngle = 0.0f,
		glm::vec3 transalteVec = glm::vec3(0.0f, 0.0f, 0.0f));
	void update();

};

