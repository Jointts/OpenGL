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

vec4 applyAmbient();
vec4 applyDirectionalLight();
vec4 applyPointLight();
vec4 applyHemisphereLight();

void main()
{
    vec4 object_color = vec4(texture(diffuse1, TexCoords));
    if(outColor != 0){
        object_color = vec4(outColor, 1.0);
    }
	object_color *= applyDirectionalLight();
	object_color += applyPointLight();
    color = object_color;
}

vec4 applyAmbient(){
    return vec4(ambientStrength * vec3(ambientColor), 1.0);
}

vec4 applyDirectionalLight(){
    vec3 norm = normalize(NormalCoords);
    vec3 lightDir = normalize(directionalLight.lightDirection);
    float diff = max(dot(norm, lightDir), 0.0);
    return vec4((diff * directionalLight.lightColor) * directionalLight.lightStrength, 1.0);
}

vec4 applyPointLight(){
    float distance = length(pointLight.position - FragPos);
    float attenuation = 1.0 / (pointLight.constant + pointLight.linear * distance +
        		    pointLight.quadratic * (distance * distance));
    return attenuation * vec4(pointLight.diffuse, 1.0);
}

vec4 applyHemisphereLight(){
    vec3 norm = normalize(NormalCoords);
    vec3 downVector = vec3(0.0, 1.0, 0.0);
    float lightStrength = max(dot(norm, downVector), 0.0);
    vec3 lightColor = vec3(1.0, 1.0, 1.0);
    return vec4(min(lightStrength, 0.1) * lightColor, 1.0);
}
