#ifndef EBO_H
#define EBO_H

#include <glad/glad.h> 
//GLFW
#include <glfw3.h>

// GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Ebo
{
private:
	GLuint m_eboID;
	GLuint m_nrOfEbos;
public:
	Ebo();
	~Ebo();
	void Init(GLuint nrOfEbos);
	void Bind(GLuint *indices, GLuint nrOfIndices);
	//void UnBind();
};

#endif
