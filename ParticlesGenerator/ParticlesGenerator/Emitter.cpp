#include "Emitter.h"
#include "Particle.h"


Emitter::~Emitter()
{
	for (int i = 0; i < particles.size(); i++)
	{
		this->particles[i].~Particle();
	}
}

Emitter::Emitter(glm::vec3 position, GLfloat radius)
{
	this->m_Position = position;
	this->m_radius = radius;
	this->m_radius = radius;
}

void Emitter::Draw(Shader &shader)
{
	for (int i = 0; i < this->particles.size(); i++)
	{
		this->particles[i].Draw(shader);
		std::cout << " Draw from emitter particle number:" << i + 1 << std::endl;
	}
}

void Emitter::Update(GLfloat dt)
{
	for (int i = 0; i < this->particles.size(); i++)
	{
		std::cout << " Update from emitter particle number: " << i+1 << std::endl;
		this->particles[i].Update(dt);

		std::cout << " Emitter's particle positions: " << std::endl;
		std::cout << particles[i].getPosition().x << " " << particles[i].getPosition().y << " " << particles[i].getPosition().z << std::endl;

	}
}

void Emitter::SetParticlesAttributes()
{
	int rand = 1;
	for (int i = 0; i < particles.size(); i++)
	{
		rand *= -1;
		this->particles[i].setLife(10.0f);										//(((rand() % 10) + 1) * 15);
		this->particles[i].setVelocity(glm::vec3(0.001f, 0.001f, 0.0f));				//(((rand() % 10) + 1) * 2));
		//particles[i].Update(dt);                                           
	}
}