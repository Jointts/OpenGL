#version 410

layout (location = 0) in vec3 position;

uniform mat4 view;
uniform mat4 perspective;

void main() {
    gl_Position = perspective * view * vec4(position, 1.0f);
}
