#ifndef PARTICLE_H
#define PARTICLE_H

#include <iostream>
#include <glad/glad.h> 

//GLFW
#include <glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "stb_image.h"

#include "Texture.h"
#include "Shader.h"
#include "Vao.h"


class Particle
{
private:
	glm::vec3 m_Position;
	glm::vec3 m_Velocity;
	GLfloat m_Life;
	Vao vao;
	Vbo vbo;
	Ebo ebo;

	Texture texture;
	Shader shader;
public:
//	static const glm::mat4 view;
//	static const glm::mat4 projection;
	Particle();
	Particle(glm::vec3 position, glm::vec3 velocity, GLfloat Life, GLchar *imgName);
	~Particle();
	void SetAttributes();
	void Init();

	void Draw(Shader &shader);

	void Update(GLfloat dt);

	void setLife(GLfloat life);
	GLfloat getLife();

	void setPosition(glm::vec3 position);
	glm::vec3 getPosition();

	void setVelocity(glm::vec3 velocity);
	glm::vec3 getVelocity();
};

#endif