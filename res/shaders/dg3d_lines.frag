#version 460 core

out vec4 FinalColor;

in vec4 out_color;

void main()
{
    FinalColor = out_color;
}