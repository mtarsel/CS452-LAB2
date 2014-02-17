#ifndef INITSHADERS_H_
#define INITSHADERS_H_

#include "GL/glew.h"
#include "GL/freeglut.h"
#include "GL/gl.h"
#include "GL/glu.h"

#include <vector>
#include <cstdio>
#include <iostream>
#include <fstream>
using namespace std;

const GLchar* loadshader(const char* filename);
GLuint createShader(GLenum type, const GLchar* shadeSource);
GLuint createProgram(const vector<GLuint> shadeList);

typedef struct{
    GLenum type;
    const char* filename;
} ShaderInfo;

GLuint createShader(GLenum shader_type, const GLchar* shaderSource){
    GLuint shader = glCreateShader(shader_type);
    glShaderSource(shader, 1, &shaderSource, NULL);
    glCompileShader(shader);
    
    return shader;
}

const GLchar* loadshader(const char* filename){
    fprintf(stdout, "Loading shader %s \n", filename);

    FILE* f = fopen(filename,"rb");

    //Open file with error checking
    if(f == NULL){
	fprintf(stderr, "Failed to open shader file %s", filename);
	return NULL;
     }
 
    //Get shader file length
    fseek(f, 0, SEEK_END);
    long filesize = ftell(f);
    fseek(f, 0, SEEK_SET);

    if(filesize == 0){
	fprintf(stderr, "File %s is empty", filename);
	return NULL;
    }

    //read shader source code into char array
    GLchar* ShaderSource = new GLchar[filesize+1];
    fread(ShaderSource, 1, filesize, f);    
    
    fclose(f);

    ShaderSource[filesize]= 0; 	

    return ShaderSource;
}

GLuint createProgram(const vector<GLuint> shadeList){
    
    GLuint program = glCreateProgram();
    for(GLuint i = 0; i < shadeList.size(); i++){
	glAttachShader(program, shadeList[i]);
    }

    glBindAttribLocation(program, 0, "in_position");
    glBindAttribLocation(program, 1, "in_color");

    glLinkProgram(program);

    return program;

}

#endif 

void initShaders(ShaderInfo* shaders){
    
    ShaderInfo* loc_shaders = shaders;
    vector<GLuint> ShadeList;
    
    while((*loc_shaders).type != GL_NONE){
	GLuint new_shader = createShader((*loc_shaders).type, loadshader((*loc_shaders).filename));
	ShadeList.push_back(new_shader);
	loc_shaders++;
    }

    GLuint program = createProgram(ShadeList);

    glUseProgram(program);
}
