#include "Lamp.h"
unsigned int loadTexture(char const* path);

#pragma region Lamp Coordinate Configs

// set up vertex data (and buffer(s)) and configure vertex attributes
// ------------------------------------------------------------------
float lamp_vertices[] = {
    -0.5f, -0.5f, -0.5f,
     0.5f, -0.5f, -0.5f,
     0.5f,  0.5f, -0.5f,
     0.5f,  0.5f, -0.5f,
    -0.5f,  0.5f, -0.5f,
    -0.5f, -0.5f, -0.5f,

    -0.5f, -0.5f,  0.5f,
     0.5f, -0.5f,  0.5f,
     0.5f,  0.5f,  0.5f,
     0.5f,  0.5f,  0.5f,
    -0.5f,  0.5f,  0.5f,
    -0.5f, -0.5f,  0.5f,

    -0.5f,  0.5f,  0.5f,
    -0.5f,  0.5f, -0.5f,
    -0.5f, -0.5f, -0.5f,
    -0.5f, -0.5f, -0.5f,
    -0.5f, -0.5f,  0.5f,
    -0.5f,  0.5f,  0.5f,

     0.5f,  0.5f,  0.5f,
     0.5f,  0.5f, -0.5f,
     0.5f, -0.5f, -0.5f,
     0.5f, -0.5f, -0.5f,
     0.5f, -0.5f,  0.5f,
     0.5f,  0.5f,  0.5f,

    -0.5f, -0.5f, -0.5f,
     0.5f, -0.5f, -0.5f,
     0.5f, -0.5f,  0.5f,
     0.5f, -0.5f,  0.5f,
    -0.5f, -0.5f,  0.5f,
    -0.5f, -0.5f, -0.5f,

    -0.5f,  0.5f, -0.5f,
     0.5f,  0.5f, -0.5f,
     0.5f,  0.5f,  0.5f,
     0.5f,  0.5f,  0.5f,
    -0.5f,  0.5f,  0.5f,
    -0.5f,  0.5f, -0.5f
};

unsigned int lamp_indices[] = {  // note that we start from 0!
    0, 1, 3,   // first triangle
    1, 2, 3    // second triangle
};
#pragma endregion

Lamp::Lamp(glm::vec3 scaleVec, glm::vec3 rotateVec, float rotateAngle, glm::vec3 transalteVec) {
    this->shader = ShaderManager::getShaderByName("light");
    this->scaleVec = scaleVec;
    this->rotateVec = rotateVec;
    this->rotateAngle = rotateAngle;
    this->transalteVec = transalteVec;

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(lamp_vertices), lamp_vertices, GL_STATIC_DRAW);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(lamp_indices), lamp_indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE,3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glBindVertexArray(0);

    shader->use();

    glm::mat4 projection = glm::mat4(1.0f);
    projection = glm::perspective(glm::radians(45.0f), 1280.0f / 720.0f, 0.1f, 100.0f);


    pointLight = new PointLight({true, transalteVec, glm::vec3(0.05f, 0.05f, 0.05f),
        glm::vec3(0.8f, 0.8f, 0.8f), glm::vec3(1.0f), 1.0f, 0.22, 0.20});

    PointLightManager::addPointLight(pointLight);

    shader->setMat4("projection", projection);
}

void Lamp::update() {

    shader->use();

    // make sure to initialize matrix to identity matrix first
    glm::mat4 model = glm::mat4(1.0f);

    // Handle transformations
    model = translate(model);
    model = rotate(model);
    model = scale(model);

    // retrieve the matrix uniform locations
    // pass them to the shaders
    shader->setMat4("view", Camera::instance->GetViewMatrix());
    shader->setMat4("model", model);

    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 36);

    glBindVertexArray(0);
}

glm::mat4 Lamp::scale(glm::mat4 model)
{
    if (this->scaleVec.x != 0.0f || this->scaleVec.y != 0.0f || this->scaleVec.z != 0.0f) {

        return glm::scale(model, this->scaleVec);
    }
    return model;
}

glm::mat4 Lamp::rotate(glm::mat4 model)
{
    if (this->rotateVec.x != 0.0f || this->rotateVec.y != 0.0f || this->rotateVec.z != 0.0f) {
        return glm::rotate(model, glm::radians(this->rotateAngle), this->rotateVec);
    }
    return model;
}

glm::mat4 Lamp::translate(glm::mat4 model)
{
    if (this->transalteVec.x != 0.0f || this->transalteVec.y != 0.0f || this->transalteVec.z != 0.0f) {
        return glm::translate(model, this->transalteVec);
    }
    return model;
}