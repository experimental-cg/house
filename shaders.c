#include "shaders.h"
#include "setup.h"
#include <string.h>

unsigned int spMVPTileTextureQuad;
unsigned int spHouse;

static unsigned int load_shaders(const char *vsName, const char *fsName) {
  int   vsPathLen = strlen("shaders/_vs.glsl") + strlen(vsName) + 2;
  char *vsPath = malloc(vsPathLen * sizeof(char));
  sprintf(vsPath, "shaders/%s_vs.glsl", vsName);
  vsPath[vsPathLen] = '\0';
  const GLchar *vsSource = read_file(vsPath);
  free(vsPath);

  int   fsPathLen = strlen("shaders/_fs.glsl") + strlen(fsName) + 2;
  char *fsPath = malloc(fsPathLen * sizeof(char));
  sprintf(fsPath, "shaders/%s_fs.glsl", fsName);
  fsPath[fsPathLen] = '\0';
  const GLchar *fsSource = read_file(fsPath);
  free(fsPath);

  unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertexShader, 1, &vsSource, NULL);
  glCompileShader(vertexShader);
  free((void *) vsSource);

  // check shader source
  int  success;
  char infoLog[512];
  glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
  if(!success) {
    glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
    printf("Vertex shader compilation failed for %s:\n%s\n", vsName, infoLog);
    exit(1);
  }

  unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragmentShader, 1, &fsSource, NULL);
  glCompileShader(fragmentShader);
  free((void *) fsSource);

  // check shader source
  glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
  if(!success) {
    glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
    printf("Fragment shader compilation failed for %s:\n%s\n", fsName, infoLog);
    exit(1);
  }

  // create shader program
  unsigned int shaderProgram = glCreateProgram();
  glAttachShader(shaderProgram, vertexShader);
  glAttachShader(shaderProgram, fragmentShader);
  glLinkProgram(shaderProgram);

  // check for linking errors
  glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
  if(!success) {
    glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
    printf("Shader linking failed for %s and %s:\n%s\n", vsName, fsName, infoLog);
    exit(1);
  }
  glDeleteShader(vertexShader);
  glDeleteShader(fragmentShader);

  return shaderProgram;
}

void setupShaders(void) {
  spMVPTileTextureQuad = load_shaders("mvp_texture_tiled", "texture");
  spHouse = load_shaders("house", "house");
}

void cleanupShaders(void) {
  glDeleteProgram(spMVPTileTextureQuad);
  glDeleteProgram(spHouse);
}

void setMat4(unsigned int sp, char *name, mat4 m) {
  unsigned int loc = glGetUniformLocation(sp, name);
  glUniformMatrix4fv(loc, 1, GL_FALSE, (float *)m);
}

void setVec3(unsigned int sp, char *name, float x, float y, float z) {
  unsigned int loc = glGetUniformLocation(sp, name);
  glUniform3f(loc, x, y, z);
}

void setVec3v(unsigned int sp, char *name, vec3 v) {
  unsigned int loc = glGetUniformLocation(sp, name);
  glUniform3fv(loc, 1, v);
}

void setFloat(unsigned int sp, char *name, float f) {
  unsigned int loc = glGetUniformLocation(sp, name);
  glUniform1f(loc, f);
}

void setInt(unsigned int sp, char *name, int i) {
  unsigned int loc = glGetUniformLocation(sp, name);
  glUniform1i(loc, i);
}

void setVec2i(unsigned int sp, char *name, int a, int b) {
  unsigned int loc = glGetUniformLocation(sp, name);
  glUniform2i(loc, a, b);
}
