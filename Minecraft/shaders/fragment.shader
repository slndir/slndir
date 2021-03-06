#version 440 core
out vec4 FragColor;

in vec4 vertexColor;
in vec2 TexCoord;

uniform sampler2D texture0;

void main()
{
	FragColor = texture(texture0, TexCoord);
}