#include "Model.h"
#include <iostream>


Model::Model(const std::vector<float>& vertexs, const std::vector<float>& uvs, const std::vector<float>& normals)
{
	this->numVertexs = vertexs.size() / 3;

	std::cout << numVertexs;

	// Generamos el VAO Y VBO
	glGenVertexArrays(1, &this->VAO);

	glGenBuffers(1, &this->VBO);

	//definimos el VAO como activo
	glBindVertexArray(this->VAO);

	glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
	glBufferData(GL_ARRAY_BUFFER, vertexs.size() * sizeof(float), vertexs.data(), GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

		// el primero es la layerrr, del vertexshader


	//Activamos el atributo 0
	glEnableVertexAttribArray(0);


	//Desvinculo VAO Y VBO
	glBindBuffer(GL_ARRAY_BUFFER,0);
	glEnableVertexAttribArray(0);
}

void Model::Render() const
{
	// vinculo VAO como activo 
		//Definimos que queremos usar el VAO con los puntos
	glBindVertexArray(this->VAO);

	//Definimos CUANTOS TRIANGULOS RENDERIZAMOS
	glDrawArrays(GL_TRIANGLES, 0, this->numVertexs);
	// COMO DIBUJAR, EL OFFSET, Y EL NUMERO DE VERTICES

	//Dejamos de usar el VAO indicado anteriormente
	glBindVertexArray(0);



}