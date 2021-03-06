#version 410

in vec2 TexCoords;
out vec4 color;

uniform vec3 textColor;
uniform bool renderText;
uniform sampler2D diffuse;

void main() {
    vec4 object_color = vec4(texture(diffuse, TexCoords));
	if (renderText) {
		object_color = vec4(textColor, texture(diffuse, TexCoords).r);
	}
	if (object_color.a < 0.1) discard;
    color = object_color;
}
