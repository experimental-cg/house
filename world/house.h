#ifndef HOUSE_H_
#define HOUSE_H_

#include "../glad.h"
#include "../setup.h"
#include "../cglm/cglm.h"
#include "../shaders.h"

void setupHouse(void);
void cleanupHouse(void);
void renderHouse(mat4 view, mat4 projection);

#endif // HOUSE_H_
