#version 410

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec2 uv_coords;

out vec2 TexCoords;
out vec3 NormalCoords;
out vec3 FragPos;

uniform mat4 view;
uniform mat4 perspective;
uniform mat4 model;

void main() {
    gl_Position = perspective * view * model * vec4(position, 1.0f);
    TexCoords = uv_coords;
    NormalCoords = normal;
    FragPos = vec3(model * vec4(position, 1.0));
}
