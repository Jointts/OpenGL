#version 410

in vec2 TexCoords;
in vec3 NormalCoords;
in vec3 FragPos;
in vec3 VertexPos;
in vec3 outColor;

out vec4 color;

struct PointLight{
    vec3 position;
    vec3 diffuse;

    float constant;
    float linear;
    float quadratic;
};

uniform float ambientStrength;
uniform vec3 ambientColor;
uniform vec3 lightColor;
uniform vec3 lightDirection;
uniform float lightStrength;
uniform sampler2D diffuse1;
uniform PointLight pointLight;

void applyAmbient(inout vec4 color, float ambientStrength, vec3 ambientColor);
void applyDirectionalLight(inout vec4 color, vec3 normalCoord, vec3 lightColor, vec3 lightDirection, float lightStrength);
void applyPointLight(inout vec4 color);

void main()
{
    vec4 object_color = vec4(texture(diffuse1, TexCoords));
    if(outColor != 0){
        object_color = vec4(outColor, 1.0);
    }
    applyAmbient(object_color, ambientStrength, ambientColor);
    applyDirectionalLight(object_color, NormalCoords, lightColor, lightDirection, lightStrength);
    applyPointLight(object_color);
    color = object_color * vec4(pointLight.diffuse, 1.0);
}

void applyAmbient(inout vec4 color, float ambientStrength, vec3 ambientColor){
    color *= vec4(ambientColor * ambientStrength, 1.0);
}

void applyDirectionalLight(inout vec4 color, vec3 normalCoord, vec3 lightColor, vec3 lightDirection, float lightStrength){
    vec3 norm = normalize(normalCoord);
    vec3 lightDir = normalize(lightDirection);
    float diff = max(dot(norm, lightDir), 0.0);
    color *= vec4((diff * lightColor) * lightStrength, 1.0);
}

void applyPointLight(inout vec4 color){
    float distance = length(pointLight.position - FragPos);
    float attenuation = 1.0 / (pointLight.constant + pointLight.linear * distance +
        		    pointLight.quadratic * (distance * distance));
    color += attenuation;
}
