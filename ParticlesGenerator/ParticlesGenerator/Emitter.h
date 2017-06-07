#ifndef EMITTER_H
#define EMITTER_H

#include <iostream>

#include <glad/glad.h> 
//GLFW
#include <glfw3.h>

#include "Shader.h"
#include "Camera.h"
#include "Texture.h"

// GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Particle.h"


class Emitter
{
private:
	GLuint m_nrOfParticles;
	glm::vec3 m_Position;
	GLfloat m_radius;

	std::vector<Particle> particles;

public:
	Emitter();
	Emitter(GLuint nrParticles, glm::vec3 position, GLfloat radius);
	~Emitter();

	void Draw(Shader &shader);
	void Update(GLfloat dt);
	void SetParticlesAttributes();
};

#endif