#include "VAO.h"

Vao::Vao()
{
}
void Vao::Init(GLuint nrOfVaos)
{
	this->m_nrOfVaos = nrOfVaos;
	glGenVertexArrays(this->m_nrOfVaos, &this->m_vaoID);
}

void Vao::Bind()
{
	glBindVertexArray(this->m_vaoID);
}

void Vao::AttribPointer(GLuint index, GLuint componentsCount, GLuint stride, GLuint ptr)
{
	glVertexAttribPointer(index, componentsCount, GL_FLOAT, GL_FALSE, stride * sizeof(GLfloat), (GLvoid*)(ptr * (sizeof(GLfloat))));
	glEnableVertexAttribArray(index);
}

void Vao::UnBind()
{
	glBindVertexArray(0);
}

Vao::~Vao()
{
	glDeleteVertexArrays(this->m_nrOfVaos, &this->m_vaoID);
}