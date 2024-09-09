#include "main.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

static void cleanup(void) {
  cleanupWorld();
  cleanupShaders();
  glfwTerminate();
}

int main(void) {
  glfwInit();
  atexit(cleanup);
  GLFWwindow *window = setup_window();
  handle_control_callbacks(window);

  setupShaders();
  setupWorld();

  glEnable(GL_DEPTH_TEST);

  mat4 view;
  vec3 lookAt;

  while(!glfwWindowShouldClose(window)) {
    handle_controls(window);

    glClearColor(0.6f, 0.7f, 0.8f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // view moves the 3d world around the camera
    glm_vec3_add(cameraPos, cameraFront, lookAt);
    glm_lookat(cameraPos, lookAt, cameraUp, view);

    // projection projects 3d world onto a flat screen
    mat4 projection = GLM_MAT4_IDENTITY_INIT;
    glm_perspective(glm_rad(fov), 1600.0f / 900.0f, 0.1f, 1000000.0f, projection);

    renderWorld(view, projection);

    // end
    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  return 0;
}
