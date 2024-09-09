#ifndef SETUP_H_
#define SETUP_H_

#include "glad.h"
#include <GLFW/glfw3.h>
#include "stb_image.h"
#include <stdbool.h>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
GLFWwindow* setup_window(void);
char *read_file(char* file_path);
unsigned int load_texture(char *name, bool rgba);

#endif // SETUP_H_
