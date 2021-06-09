#pragma once
#include "GameObject.h"
#include "ShaderManager.h"
#include "PointLightManager.h"
#include "Camera.h"
#include "stb_image.h"

#include <glad/glad.h>
#include <glfw3/glfw3.h>
#include <iostream>

struct Material {
	const char* textureName;
	float shininess;
};

class Cube : public GameObject
{
private:
	unsigned int VBO;
	unsigned int VAO;
	unsigned int texture;
	Shader *shader;
	Material material;

	glm::vec3 scaleVec;
	glm::vec3 rotateVec;
	glm::vec3 transalteVec;

	glm::mat4 scale(glm::mat4 model);
	glm::mat4 rotate(glm::mat4 model);
	float rotateAngle;
	glm::mat4 translate(glm::mat4 model);

public:
	Cube(Material material, glm::vec3 scaleVec = glm::vec3(0.0f, 0.0f, 0.0f),
		glm::vec3 rotateVec = glm::vec3(0.0f, 0.0f, 0.0f), float rotateAngle = 0.0f,
		glm::vec3 transalteVec = glm::vec3(0.0f, 0.0f, 0.0f));
	void update();
};

