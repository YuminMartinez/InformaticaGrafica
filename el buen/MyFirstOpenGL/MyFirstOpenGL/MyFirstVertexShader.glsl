#version 440 core

layout(location = 0) in vec3 posicion;
layout(location = 0) in vec2 uvsVertexShaders;

uniform mat4 translationMatrix;
uniform mat4 rotationMatrix;
uniform mat4 scaleMatrix;



out vec2 uvsGeometryShader;

void main()
{

//mat4 model= translationMatrix * rotationMatrix * scaleMatrix;

    uvsGeometryShader = uvsVertexShaders;
    gl_Position =  vec4(posicion, 1.0);
}