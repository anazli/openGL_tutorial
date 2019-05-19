#ifndef SHADER_H
#define SHADER_H

#include<iostream>
#include<cstdio>
#include<fstream>
#include<string>
#include<cstring>
#include<GL/glew.h>

class Shader {
    public:
        Shader(GLuint id = 0, GLuint proj = 0, GLuint mod = 0):
            shaderID(id), 
            uniformProjection(proj),
            uniformModel(mod){}
        ~Shader()
        {
            clearShader();
        }

        void createFromString(const char *vertexCode, const char *fragmentCode);
        void createFromFiles(const char *vertexLoc, const char *fragmentLoc);

        std::string readFile(const char *fileLocation);

        void useShader();
        void clearShader();

    private:
        GLuint shaderID, uniformProjection, uniformModel;
        void addShader(GLuint theProgram, const char *shaderCode, GLenum shaderType);
        void compileShader(const char *vertexCode, const char *fragmentCode);
};

#endif