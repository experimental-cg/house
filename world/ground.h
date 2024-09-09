#ifndef GROUND_H_
#define GROUND_H_

#include "../glad.h"
#include "../setup.h"
#include "../cglm/cglm.h"
#include "../shaders.h"

void setupGround(void);
void cleanupGround(void);
void renderGround(mat4 view, mat4 projection);

#endif // GROUND_H_
