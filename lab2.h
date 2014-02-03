#ifndef LAB_2_INIT_SHADERS_H_
#define LAB_2_INIT_SHADERS_H_

// -----------------------
// --- I N C L U D E S ---
// -----------------------
#include "GL/glew.h"
#include "GL/freeglut.h"
#include "GL/gl.h"
#include "GL/glu.h"

#include <vector>
#include <cstdio>
#include <iostream>

using namespace std;

typedef struct{
    GLenum type;		// GL_VERTEX_SHADER or GL_FRAGMENT_SHADER
    const char* filename;   // Name of file to input
} ShaderInfo;

//create the shaders for your program
void initShaders(ShaderInfo* shaders);

//this funtion loads the shader from the vertex, fragments shaders 
const GLchar* inputShader(const char* filename);

//this function create your shader
GLuint createShader(GLenum type, const GLchar* shadeSource);

//this function creates the shading program we are going to link the shader too
GLuint createProgram(const vector<GLuint> shadeList);
#endif
