#version 330 core

uniform sampler2D tex;

in vec2 TexCoord;
out vec4 FragColor;

void main() {
    FragColor = texture(tex, TexCoord);
}
