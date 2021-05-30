#pragma once
#include "GameObject.h"
#include "Shader.h"
#include "Camera.h"
#include "stb_image.h"

#include <glad/glad.h>
#include <glfw3/glfw3.h>
#include <glm/glm.hpp>
#include <iostream>
class Cube : public GameObject
{
private:
	unsigned int VBO;
	unsigned int VAO;
	unsigned int texture;
	Shader *shader;
	unsigned int modelLoc;
	unsigned int viewLoc;
	unsigned int projectionLoc;

	glm::vec3 scaleVec;
	glm::vec3 rotateVec;
	glm::vec3 transalteVec;

	Camera* mainCamera;

	glm::mat4 scale(glm::mat4 model);
	glm::mat4 rotate(glm::mat4 model);
	float rotateAngle;
	glm::mat4 translate(glm::mat4 model);

public:
	Cube(Shader *shader, Camera* mainCamera, glm::vec3 scaleVec = glm::vec3(0.0f, 0.0f, 0.0f),
		glm::vec3 rotateVec = glm::vec3(0.0f, 0.0f, 0.0f), float rotateAngle = 0.0f,
		glm::vec3 transalteVec = glm::vec3(0.0f, 0.0f, 0.0f));
	void update();
};

