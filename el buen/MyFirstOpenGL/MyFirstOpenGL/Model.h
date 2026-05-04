#ifndef MODEL_h
#define MODEL_h



#include <vector>
#include <GL/glew.h>
#include "GameObject.h"

class Model : GameObject
{
public:
	Model(const std::vector<float>& vertexs,const std::vector<float> & uvs, const std::vector<float>& normals);
	void  Render() const;

private:
	GLuint VAO, VBO, uvVBO;

	
	unsigned int numVertexs;
};

#endif