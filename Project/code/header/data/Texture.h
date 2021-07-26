#pragma once
#include <GL/glew.h>
#include <stb_image.h>
#include <iostream>
class Texture {
public:
	unsigned int ID;
	unsigned char* DATA;
	int tex_widht, tex_height, tex_nrChannels, desired_channels;
	Texture(const char* filename, bool jpg = true, bool vertically_on_load = true)
	{
		if (vertically_on_load)
			stbi_set_flip_vertically_on_load(true);
		else
			stbi_set_flip_vertically_on_load(false);
		if (jpg)
			desired_channels = STBI_rgb;
		else
			desired_channels = STBI_rgb_alpha;
		glGenTextures(1, &ID);
		glBindTexture(GL_TEXTURE_2D, ID);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		DATA = stbi_load(filename, &tex_widht, &tex_height, &tex_nrChannels, desired_channels);
		if (DATA)
		{
			std::cout << "[OpenGL Texture]: Texture at location: " << filename << " has benn loaded successfully.\n";
			switch (jpg)
			{
			case true:
				glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,tex_widht, tex_height, 0, GL_RGB, GL_UNSIGNED_BYTE, DATA);
				glGenerateMipmap(GL_TEXTURE_2D);
				break;
			default:
				glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, tex_widht, this->tex_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, DATA);
				glGenerateMipmap(GL_TEXTURE_2D);
				break;
			}
		}
		else
			std::cout << "[ERROR: Texture loading]: Failed to load texture at location: " << filename <<"\n";
		stbi_image_free(DATA);

	}
	void Bind()
	{
		glBindTexture(GL_TEXTURE_2D, ID);
	}
	void Unbind()
	{
		glBindTexture(GL_TEXTURE_2D, 0);
	}
	void Activate()
	{
		glActiveTexture(GL_TEXTURE_2D);
	}
};