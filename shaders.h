#ifndef SHADERS_H_
#define SHADERS_H_

#include "cglm/cglm.h"
#include "glad.h"
#include <GLFW/glfw3.h>

extern unsigned int spMVPTileTextureQuad;
extern unsigned int spHouse;

void setupShaders(void);
void cleanupShaders(void);

void setMat4(unsigned int sp, char *name, mat4 m);
void setVec3(unsigned int sp, char *name, float x, float y, float z);
void setVec3v(unsigned int sp, char *name, vec3 v);
void setFloat(unsigned int sp, char *name, float f);
void setInt(unsigned int sp, char *name, int i);
void setVec2i(unsigned int sp, char *name, int a, int b);


#endif // SHADERS_H_
