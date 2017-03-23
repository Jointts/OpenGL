#version 440

out vec4 color;
uniform vec3 outline_color;

void main()
{
    color = vec4(outline_color, 1.0f);
}
