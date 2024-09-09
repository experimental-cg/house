#version 330 core

layout (location = 0) in vec2 aPos;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

uniform ivec2 tiles;

out vec2 TexCoord;

void main() {
   gl_Position = projection * view * model * vec4(aPos * tiles, 0.0, 1.0);
   TexCoord = aPos * tiles;
}
