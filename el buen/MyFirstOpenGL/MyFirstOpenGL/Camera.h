#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm.hpp>
#include "GameObject.h"
class Camera : GameObject
{
public:
	glm::vec3 position = glm::vec3(0.5f, 0.5f, 1.f);
	glm::vec3 localVectorUp = glm::vec3(0.f, 1.f, 0.f);


	float fFov = 45.f;
	float fFnear = 0.1f;
	float fFar = 10.f;
};