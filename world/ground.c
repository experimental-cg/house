#include "ground.h"

static unsigned int VAO, VBO, EBO;
static unsigned int texture_grass;

void setupGround(void) {
  // note that we have 2 repeating triples of vertices
  float plane[] = {
    0.0f, 1.0f,
    1.0f, 1.0f,
    0.0f, 0.0f,
    1.0f, 0.0f
  };

  // generate vertex attribute object
  glGenVertexArrays(1, &VAO);
  glGenBuffers(1, &VBO);

  // cube
  glBindVertexArray(VAO);

  // generate vertex buffer object
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(plane) * sizeof(float), plane, GL_STATIC_DRAW);

  // position attribute
  glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);

  // texture attribute
  /* glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3*sizeof(float))); */
  /* glEnableVertexAttribArray(1); */

  texture_grass = load_texture("textures/default_grass.png", false);

  glActiveTexture(GL_TEXTURE0);
}

void cleanupGround(void) {
  glDeleteVertexArrays(1, &VAO);
  glDeleteBuffers(1, &VBO);
  glDeleteBuffers(1, &EBO);
}

void renderGround(mat4 view, mat4 projection) {
  mat4 model = GLM_MAT4_IDENTITY_INIT;
  const GLint first[] = {0, 1};
  const GLsizei count[] = {3, 3};

  // ground
  glBindVertexArray(VAO);
  glUseProgram(spMVPTileTextureQuad);
  glm_mat4_identity(model);
  int size = 10000;
  glm_translate(model, (vec3) {1.5f, -0.5f, -10.0f});
  glm_scale_uni(model, 0.3);
  glm_translate(model, (vec3) {-size/2, 0, -size/2});
  glm_rotate_x(model, glm_rad(90.0f), model);
  setMat4(spMVPTileTextureQuad, "model", model);

  setVec2i(spMVPTileTextureQuad, "tiles", size, size);
  glBindTexture(GL_TEXTURE_2D, texture_grass);
  setInt(spMVPTileTextureQuad, "texture", 2);
  setMat4(spMVPTileTextureQuad, "view", view);
  setMat4(spMVPTileTextureQuad, "projection", projection);

  glMultiDrawArrays(GL_TRIANGLES, first, count, 2);
}
