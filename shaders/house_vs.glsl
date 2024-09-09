#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec2 aTexCoords;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

uniform vec3 lightPos;
uniform int gridSize;

out vec3 FragPos;
out vec3 Normal;
out vec3 LightPos;
out vec2 TexCoords;

float n(vec2 co){
  return fract(sin(dot(co, vec2(12.9898, 78.233))) * 43758.5453);
}

void main() {
  vec3 pos = aPos;
  vec2 offset;

  offset.x = (gl_InstanceID / gridSize - gridSize/2)*5.0 - 10.0;
  offset.y = (gl_InstanceID % gridSize - gridSize/2)*5.0 + 10.0;

  float angle = n(offset + 4.12)*10;
  pos.xz = vec2(
      dot(pos.xz, vec2(cos(angle), sin(angle))),
      dot(pos.xz, vec2(sin(angle), -cos(angle)))
      );

  // random scale
  //pos /= n(offset + 1.5)*7.0;
  pos *= n(offset + 1.5)*2.0;

  pos.xz += offset;

  pos.xz += vec2(n(offset)*10.0, n(offset + 2.7)*10.0);

  gl_Position = projection * view * model * vec4(pos, 1.0);
  FragPos = vec3(view * model * vec4(pos, 1.0));
  Normal = transpose(inverse(mat3(view * model))) * aNormal;
  LightPos = vec3(view * vec4(lightPos, 1.0));
  TexCoords = aTexCoords;
}
