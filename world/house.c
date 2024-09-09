#include "house.h"

static unsigned int VAO, VBO, EBO;
static unsigned int texture_house;

void setupHouse(void) {
  float house[] = {
    // vertices               normals            textures
    // x,    y,    z
    // -z direction (front door)
    0.0f, 0.0f, 0.0f,    0.0f,  0.0f, -1.0f,    0.0f, 0.0f,
    1.0f, 0.0f, 0.0f,    0.0f,  0.0f, -1.0f,    0.5f, 0.0f,
    1.0f, 1.0f, 0.0f,    0.0f,  0.0f, -1.0f,    0.5f, 0.5f,

    0.0f, 0.0f, 0.0f,    0.0f,  0.0f, -1.0f,    0.0f, 0.0f,
    0.0f, 1.0f, 0.0f,    0.0f,  0.0f, -1.0f,    0.0f, 0.5f,
    1.0f, 1.0f, 0.0f,    0.0f,  0.0f, -1.0f,    0.5f, 0.5f,

    // +z direction (window)
    0.0f, 0.0f, 1.0f,    0.0f,  0.0f,  1.0f,    0.5f, 0.0f,
    1.0f, 0.0f, 1.0f,    0.0f,  0.0f,  1.0f,    1.0f, 0.0f,
    1.0f, 1.0f, 1.0f,    0.0f,  0.0f,  1.0f,    1.0f, 0.5f,

    0.0f, 0.0f, 1.0f,    0.0f,  0.0f,  1.0f,    0.5f, 0.0f,
    0.0f, 1.0f, 1.0f,    0.0f,  0.0f,  1.0f,    0.5f, 0.5f,
    1.0f, 1.0f, 1.0f,    0.0f,  0.0f,  1.0f,    1.0f, 0.5f,

    // -x direction (window)
    0.0f, 0.0f, 0.0f,   -1.0f,  0.0f,  0.0f,    0.5f, 0.0f,
    0.0f, 0.0f, 1.0f,   -1.0f,  0.0f,  0.0f,    1.0f, 0.0f,
    0.0f, 1.0f, 1.0f,   -1.0f,  0.0f,  0.0f,    1.0f, 0.5f,

    0.0f, 0.0f, 0.0f,   -1.0f,  0.0f,  0.0f,    0.5f, 0.0f,
    0.0f, 1.0f, 0.0f,   -1.0f,  0.0f,  0.0f,    0.5f, 0.5f,
    0.0f, 1.0f, 1.0f,   -1.0f,  0.0f,  0.0f,    1.0f, 0.5f,

    // +x direction (window)
    1.0f, 0.0f, 0.0f,    1.0f,  0.0f,  0.0f,    0.5f, 0.0f,
    1.0f, 0.0f, 1.0f,    1.0f,  0.0f,  0.0f,    1.0f, 0.0f,
    1.0f, 1.0f, 1.0f,    1.0f,  0.0f,  0.0f,    1.0f, 0.5f,

    1.0f, 0.0f, 0.0f,    1.0f,  0.0f,  0.0f,    0.5f, 0.0f,
    1.0f, 1.0f, 0.0f,    1.0f,  0.0f,  0.0f,    0.5f, 0.5f,
    1.0f, 1.0f, 1.0f,    1.0f,  0.0f,  0.0f,    1.0f, 0.5f,

    // -y (bottom)
    0.0f, 0.0f, 0.0f,    0.0f, -1.0f,  0.0f,    0.5f, 0.5f,
    0.0f, 0.0f, 1.0f,    0.0f, -1.0f,  0.0f,    1.0f, 0.5f,
    1.0f, 0.0f, 1.0f,    0.0f, -1.0f,  0.0f,    1.0f, 1.0f,

    0.0f, 0.0f, 0.0f,    0.0f, -1.0f,  0.0f,    0.5f, 0.5f,
    1.0f, 0.0f, 0.0f,    0.0f, -1.0f,  0.0f,    0.5f, 1.0f,
    1.0f, 0.0f, 1.0f,    0.0f, -1.0f,  0.0f,    1.0f, 1.0f,

    // +y (top)
    0.0f, 1.0f, 0.0f,    0.0f,  1.0f,  0.0f,    0.0f, 0.5f,
    0.0f, 1.0f, 1.0f,    0.0f,  1.0f,  0.0f,    0.5f, 0.5f,
    1.0f, 1.0f, 1.0f,    0.0f,  1.0f,  0.0f,    0.5f, 1.0f,

    0.0f, 1.0f, 0.0f,    0.0f,  1.0f,  0.0f,    0.0f, 0.5f,
    1.0f, 1.0f, 0.0f,    0.0f,  1.0f,  0.0f,    0.0f, 1.0f,
    1.0f, 1.0f, 1.0f,    0.0f,  1.0f,  0.0f,    0.5f, 1.0f,
  };

  // generate vertex attribute object
  glGenVertexArrays(1, &VAO);
  glGenBuffers(1, &VBO);

  // cube
  glBindVertexArray(VAO);

  // generate vertex buffer object
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(house) * sizeof(float), house, GL_STATIC_DRAW);

  // position attribute
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);

  // normal attribute
  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3*sizeof(float)));
  glEnableVertexAttribArray(1);

  // texture attribute
  glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6*sizeof(float)));
  glEnableVertexAttribArray(2);

  texture_house = load_texture("textures/house.png", true);

  glActiveTexture(GL_TEXTURE0);
}

void cleanupHouse(void) {
  glDeleteVertexArrays(1, &VAO);
  glDeleteBuffers(1, &VBO);
  glDeleteBuffers(1, &EBO);
}

void renderHouse(mat4 view, mat4 projection) {
  mat4 model = GLM_MAT4_IDENTITY_INIT;

  glBindVertexArray(VAO);
  glUseProgram(spHouse);
  glm_mat4_identity(model);
  glm_translate(model, (vec3) {0.0f, -0.49f, -2.0f});
  //glm_translate(model, (vec3) {0.0f, 0.49f, -2.0f});
  glm_scale_uni(model, 1.0);
  setMat4(spHouse, "model", model);

  int gridSize = 300;

  glBindTexture(GL_TEXTURE_2D, texture_house);
  setInt(spHouse, "texture", 2);
  setInt(spHouse, "gridSize", gridSize);
  setMat4(spHouse, "view", view);
  setMat4(spHouse, "projection", projection);

  //glDrawArrays(GL_TRIANGLES, 0, 36);
  glDrawArraysInstanced(GL_TRIANGLES, 0, 36, gridSize * gridSize);
}
