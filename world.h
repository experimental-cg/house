#ifndef WORLD_H_
#define WORLD_H_

#include "glad.h"
#include "setup.h"
#include "cglm/cglm.h"
#include "shaders.h"

#include "world/ground.h"
#include "world/house.h"

void setupWorld(void);
void cleanupWorld(void);
void renderWorld(mat4 view, mat4 projection);

#endif // WORLD_H_
