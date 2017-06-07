#include "VBO.h"

Vbo::Vbo()
{

}
void Vbo::Init(GLuint nrOfVbos)
{
	this->m_nrOfVbos = nrOfVbos;
	glGenBuffers(this->m_nrOfVbos, &this->m_vboID);
}

Vbo::~Vbo()
{
	glDeleteBuffers(this->m_nrOfVbos, &this->m_vboID);
}
void Vbo::Bind(GLfloat *data, GLuint nrOfElements)
{
	glBindBuffer(GL_ARRAY_BUFFER, this->m_vboID);
	glBufferData(GL_ARRAY_BUFFER, nrOfElements * sizeof(GLfloat), data, GL_STATIC_DRAW);
}



