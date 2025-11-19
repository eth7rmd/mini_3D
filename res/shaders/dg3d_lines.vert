#version 460 core
layout (location = 0) in vec3 aPos;

out vec4 out_color;

uniform vec4 u_color;

void main() {
    gl_Position = vec4(aPos, 1.0);
    out_color = u_color;
}