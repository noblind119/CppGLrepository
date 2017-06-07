#include "Texture.h"
#include <SOIL.h>

Texture::Texture()
{

}
void Texture::Init(GLuint nrOfTex, char* imgName)
{
	this->m_nrOfTex = nrOfTex;
	glGenTextures(this->m_nrOfTex, &this->m_texID);
	glBindTexture(GL_TEXTURE_2D, this->m_texID);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// Set texture wrapping to GL_REPEAT
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	// Set texture filtering
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	int imgWidth, imgHeight, nrOfChannels;
	unsigned char* image = stbi_load(imgName, &imgWidth, &imgHeight, &nrOfChannels, 0);
	if (image)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, imgWidth, imgHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		std::cout << "Failed to load texture" << std::endl;
	}
	stbi_image_free(image);
	glBindTexture(GL_TEXTURE_2D, 0);
}


void Texture::Bind()
{
	glBindTexture(GL_TEXTURE_2D, this->m_texID);
}

