#version 410

in vec2 TexCoords;
in vec3 NormalCoords;
in vec3 FragPos;

out vec4 color;

uniform float ambientStrength;
uniform vec3 ambientColor;
uniform vec3 lightColor;
uniform vec3 lightDirection;
uniform float lightStrength;
uniform sampler2D diffuse1;

void applyAmbient(inout vec4 color, float ambientStrength, vec3 ambientColor);
void applyDirectionalLight(inout vec4 color, vec3 normalCoord, vec3 lightColor, vec3 lightDirection, float lightStrength);

void main()
{
    vec4 object_color = vec4(texture(diffuse1, TexCoords));
    applyAmbient(color, ambientStrength, ambientColor);
    applyDirectionalLight(color, NormalCoords, lightColor, lightDirection, lightStrength);
    color *= object_color;
}

void applyAmbient(inout vec4 color, float ambientStrength, vec3 ambientColor){
    color += vec4(0.4, 0.4, 0.4, 1.0);
}

void applyDirectionalLight(inout vec4 color, vec3 normalCoord, vec3 lightColor, vec3 lightDirection, float lightStrength){
    vec3 norm = normalize(normalCoord);
    vec3 lightDir = normalize(lightDirection);
    float diff = max(dot(norm, lightDir), 0.0);
    color += vec4((diff * lightColor) * lightStrength, 1.0);
}