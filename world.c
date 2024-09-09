#include "world.h"

void setupWorld(void) {
  setupGround();
  setupHouse();
}

void cleanupWorld(void) {
  cleanupGround();
  cleanupHouse();
}

void renderWorld(mat4 view, mat4 projection) {
  //glDisable(GL_DEPTH_TEST);
  renderGround(view, projection);
  //glEnable(GL_DEPTH_TEST);
  renderHouse(view, projection);
}
