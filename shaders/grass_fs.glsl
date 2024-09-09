#version 330 core

out vec4 FragColor;
in vec2 pos;
uniform float time;

void main() {
    float y = sn(pos*50) + 2*sn(pos*60) + 3*sn(pos*80);
    y /= 1 + 2 + 3;
    FragColor = vec4(0.3, y, 0.2, 1.0);
}
