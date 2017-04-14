#version 410

out vec4 color;
uniform vec3 vertex_color;

void main()
{
    color = vec4(vertex_color, 1.0f);
}
