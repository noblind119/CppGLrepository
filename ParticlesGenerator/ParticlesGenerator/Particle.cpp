#include "Particle.h"
#include "Camera.h"

GLfloat vertices[] = {
	0.5f,  0.5f, 0.0f,		1.0f, 1.0f,
	0.5f, -0.5f, 0.0f,		1.0f, 0.0f,
	-0.5f, -0.5f, 0.0f,		0.0f, 0.0f,
	-0.5f,  0.5f, 0.0f,		0.0f, 1.0f
};

//Camera camera(glm::vec3(0.0f, 0.0f, 10.0f));




GLuint indices[] = {  // Note that we start from 0!
	0, 1, 3,   // First Triangle
	1, 2, 3    // Second Triangle
};

Particle::~Particle()
{
	this->vao.~Vao();
	this->vbo.~Vbo();
	this->ebo.~Ebo();
}


Particle::Particle()
{
	this->m_Position = glm::vec3(0.0f);
	this->m_Life = 0.0f;
	this->m_Velocity = glm::vec3(0.0f);
}

Particle::Particle(glm::vec3 position, glm::vec3 velocity, GLfloat life, GLchar *imgName)
{
	this->m_Position = position;
	this->m_Velocity = velocity;
	this->m_Life = life;

	this->vao.Init(1);
	this->vbo.Init(1);
	this->ebo.Init(1);

	this->vao.Bind();
		this->vbo.Bind(vertices, 20);
		this->ebo.Bind(indices, 6);
		this->vao.AttribPointer(0, 3, 5, 0);
		this->vao.AttribPointer(1, 2, 5, 3);
	this->vao.UnBind();

	this->texture.Init(1, imgName);

}

void Particle::Draw(Shader &shader)
{
	
	shader.Use();

	glm::mat4 model;
	glm::mat4 view;
	glm::mat4 projection;

	model = glm::translate(model, glm::vec3(this->getPosition()));
	model = glm::scale(model, glm::vec3(0.05f, 0.05f, 0.0f));
	view = glm::lookAt(glm::vec3(0.0f, 0.0f, 3.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	projection = glm::perspective(45.0f, (float)1600 / (float)1200, 0.1f, 100.0f);

	GLuint modelLoc(glGetUniformLocation(shader.Program, "model"));
	GLuint viewLoc(glGetUniformLocation(shader.Program, "view"));
	GLuint projLoc(glGetUniformLocation(shader.Program, "projection"));

	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
	glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));

	this->texture.Bind();
	glUniform1i(glGetUniformLocation(shader.Program, "ourTexture"), 0);
	std::cout << " Texture Binded " << std::endl;

	this->vao.Bind();
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	this->vao.UnBind();
	std::cout << " VAO Binded " << std::endl;
}

void Particle::SetAttributes()
{
	this->m_Life = 10.0f;
	//std::cout << this->m_Life << std::endl;
	this->m_Velocity = glm::vec3(0.0f, 0.001f, 0.0f);
}
void Particle::Update(GLfloat dt)
{
	//if (this->m_Life > 0)
	//{
		this->m_Position += this->m_Velocity * dt;
	
	//}
	
}

void Particle::setLife(GLfloat life)
{
	this->m_Life = life;
}
GLfloat Particle::getLife()
{
	return this->m_Life;
}

void Particle::setPosition(glm::vec3 position)
{
	this->m_Position = position;
}
glm::vec3 Particle::getPosition()
{
	return this->m_Position;
}

void Particle::setVelocity(glm::vec3 velocity)
{
	this->m_Velocity = velocity;
}
glm::vec3 Particle::getVelocity()
{
	return this->m_Velocity;
}