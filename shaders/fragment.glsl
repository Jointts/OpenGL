#version 440

in vec3 positions;
in vec2 pass_UVcoords;
out vec4 color;

uniform sampler2D textureSampler;

void main()
{
    color = texture(textureSampler, pass_UVcoords);
}
