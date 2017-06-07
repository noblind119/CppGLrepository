#ifndef VAO_H
#define VAO_H
#include <iostream>

#include <glad/glad.h> 

//GLFW
#include <glfw3.h>

// GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Ebo.h"
#include "Vbo.h"

class Vao
{
private:
	GLuint m_vaoID;
	GLuint m_nrOfVaos;

public:
	Vao();
	
	~Vao();
	void Init(GLuint nrOfVaos);
	void Bind();
	void UnBind();
	void AttribPointer(GLuint index, GLuint componentsCount, GLuint stride, GLuint ptr);
};

#endif
