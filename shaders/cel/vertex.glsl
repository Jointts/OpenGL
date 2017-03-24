#version 410

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec2 uv_coords;

uniform mat4 view;
uniform mat4 perspective;
uniform mat4 model;

uniform float cel_offset;

void main() {
    vec4 calculated_offset = vec4(position + normal * cel_offset, 1.0);
    gl_Position = perspective * view * model * calculated_offset;
}
