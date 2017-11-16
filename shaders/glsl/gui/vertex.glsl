#version 410

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec2 uv_coords;

uniform mat4 projection;
out vec2 TexCoords;

void main() {
    gl_Position = projection * vec4(position.xy, 0.0, 1.0);
    TexCoords = uv_coords;
}
