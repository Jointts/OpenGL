#version 410

struct PointLight{
    vec3 position;
    vec3 diffuse;

    float constant;
    float linear;
    float quadratic;
};

struct DirectionalLight{
    vec3 lightColor;
    vec3 lightDirection;
    float lightStrength;
};

in vec2 TexCoords;
in vec3 NormalCoords;
in vec3 FragPos;
in vec3 VertexPos;
in vec3 outColor;

out vec4 color;

uniform float ambientStrength;
uniform vec3 ambientColor;
uniform sampler2D diffuse1;
uniform PointLight pointLight;
uniform DirectionalLight directionalLight;

void applyAmbient(inout vec4 color, float ambientStrength, vec3 ambientColor);
void applyDirectionalLight(inout vec4 color);
void applyPointLight(inout vec4 color);
void applyHemisphereLight(inout vec4 color, vec3 normalCoord);

void main()
{
    vec4 object_color = vec4(texture(diffuse1, TexCoords));
    if(outColor != 0){
        object_color = vec4(outColor, 1.0);
    }
    applyDirectionalLight(object_color);
    applyAmbient(object_color, ambientStrength, ambientColor);
    applyPointLight(object_color);
//    applyHemisphereLight(object_color, NormalCoords);
    color = object_color;
}

void applyAmbient(inout vec4 color, float ambientStrength, vec3 ambientColor){
    color *= vec4(ambientColor * ambientStrength, 1.0);
}

void applyDirectionalLight(inout vec4 color){
    vec3 norm = normalize(NormalCoords);
    vec3 lightDir = normalize(directionalLight.lightDirection);
    float diff = max(dot(norm, lightDir), 0.0);
    color *= vec4((diff * directionalLight.lightColor) * directionalLight.lightStrength, 1.0);
}

void applyPointLight(inout vec4 color){
    float distance = length(pointLight.position - FragPos);
    float attenuation = 1.0 / (pointLight.constant + pointLight.linear * distance +
        		    pointLight.quadratic * (distance * distance));
    color += attenuation * vec4(pointLight.diffuse, 1.0);
}

void applyHemisphereLight(inout vec4 color, vec3 normalCoord){
    vec3 norm = normalize(normalCoord);
    vec3 downVector = vec3(0.0, 1.0, 0.0);
    float lightStrength = max(dot(norm, downVector), 0.0);
    vec3 lightColor = vec3(1.0, 1.0, 1.0);
    color += vec4(min(lightStrength, 0.1) * lightColor, 1.0);
}
