#ifndef TEXTURE_H
#define TEXTURE_H

#include <iostream>

#include <glad/glad.h> 

//GLFW
#include <glfw3.h>

// GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "stb_image.h"


class Texture
{
private:
	GLuint m_texID;
	GLuint m_nrOfTex;
public:
	Texture();
	void Init(GLuint nrOfTex, char* imgName);
	//void Init(char* imgName);
	void Bind();

};


#endif

