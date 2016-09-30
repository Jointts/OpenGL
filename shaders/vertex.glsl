#version 440

layout (location = 0) in vec3 position;
layout (location = 1) in vec2 UVcoords;
out vec2 pass_UVcoords;

uniform mat4 model;
uniform mat4 view;
uniform mat4 perspective;

void main() {
    gl_Position = perspective * view * model * vec4(position, 1.0f);
    pass_UVcoords = UVcoords;
}
