#ifndef VBO_H
#define VBO_H
#include <iostream>

#include <glad/glad.h> 
//GLFW
#include <glfw3.h>

// GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Vbo
{
private:
	GLuint m_vboID;
	GLuint m_nrOfVbos;

public:
	Vbo();
	~Vbo();
	void Init(GLuint nrOfVbos);
	void Bind(GLfloat *data, GLuint nrOfElements);

	//void UnBind();



};

#endif
