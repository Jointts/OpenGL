#version 440

in vec2 TexCoords;
in vec3 NormalCoords;
in vec3 FragPos;

out vec4 color;

uniform float ambientStrength;
uniform vec3 ambientColor;
uniform vec3 lightColor;
uniform vec3 lightDirection;
uniform sampler2D diffuse1;

void main()
{
    vec4 object_color = vec4(texture(diffuse1, TexCoords));
    vec3 ambient_color = ambientStrength * ambientColor;
    vec3 norm = normalize(NormalCoords);
    vec3 lightDir = normalize(lightDirection);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse_color = diff * lightColor;
    vec3 result = (ambient_color + diffuse_color);
    color = vec4(result, 1.0f) * object_color;
}
