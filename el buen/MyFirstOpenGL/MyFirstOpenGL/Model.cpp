#include "Model.h"
#include <iostream>


Model::Model(const std::vector<float>& vertexs, const std::vector<float>& uvs, const std::vector<float>& normals)
{
	this->numVertexs = vertexs.size() / 3;

	// Generamos el VAO Y VBO
	glGenVertexArrays(1, &this->VAO);

	glGenBuffers(1, &this->VBO);

	//definimos el VAO como activo
	glBindVertexArray(this->VAO);

	glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
	glBufferData(GL_ARRAY_BUFFER, vertexs.size() * sizeof(float), vertexs.data(), GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);



	//Activamos el atributo 0
	glEnableVertexAttribArray(0);


	//Desvinculo VAO Y VBO
	glBindBuffer(GL_ARRAY_BUFFER,0);
	glEnableVertexAttribArray(0);
}

void Model::Render() const
{

}