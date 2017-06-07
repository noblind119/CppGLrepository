#include "Ebo.h"

Ebo::Ebo()
{

}
void Ebo::Init(GLuint nrOfEbos)
{
	this->m_nrOfEbos = nrOfEbos;
	glGenBuffers(this->m_nrOfEbos, &this->m_eboID);
}

void Ebo::Bind(GLuint *indices, GLuint nrOfIndices)
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->m_eboID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, nrOfIndices * sizeof(GLuint), indices, GL_STATIC_DRAW);
}

Ebo::~Ebo()
{
	glDeleteBuffers(this->m_nrOfEbos, &this->m_eboID);
}

