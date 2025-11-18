#version 460 core

layout (std140, binding = 0) uniform uBlockMatrices {
    mat4 view;
    mat4 projection;
};

layout(std430, binding = 0) buffer LineBuffer {
    vec4 line_points[];
};

uniform vec4 u_color;
