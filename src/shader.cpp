#include "../include/shader.h"

using std::cout; using std::cin;
using std::endl; using std::string;
using std::getline; using std::ios;
using std::ifstream;


void Shader::addShader(GLuint theProgram, const char *shaderCode, GLenum shaderType)
{
    GLuint theShader = glCreateShader(shaderType);
    const GLchar *theCode[1];
    theCode[0] = shaderCode;

    GLint codeLength[1];
    codeLength[0] = strlen(shaderCode);

    glShaderSource(theShader, 1, theCode, codeLength);
    glCompileShader(theShader);

    GLint success = 0;
    GLchar infoLog[512];

    glGetShaderiv(theShader, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        glGetShaderInfoLog(theShader, sizeof(infoLog), nullptr, infoLog);
        cout << "Failed to compile " << shaderType << " shader" << endl;
    }

    glAttachShader(theProgram, theShader);
}

void Shader::compileShader(const char *vertexCode, const char *fragmentCode)
{
    shaderID = glCreateProgram();
    if(!shaderID)
    {
        cout << "Failed to create shader program" << endl;
    }
    addShader(shaderID, vertexCode, GL_VERTEX_SHADER);
    addShader(shaderID, fragmentCode, GL_FRAGMENT_SHADER);

    GLint success = 0;
    GLchar infoLog[512];

    glLinkProgram(shaderID);
    glGetProgramiv(shaderID, GL_LINK_STATUS, &success);
    if(!success)
    {
        glGetProgramInfoLog(shaderID, sizeof(infoLog), nullptr, infoLog);
        cout << "Failed to link shader program!" << infoLog << endl;
    }

    //uniformModel = glGetUniformLocation(shaderID, "model");
    //uniformProjection = glGetUniformLocation(shaderID, "projection");
}


void Shader::createFromString(const char *vertexCode, const char *fragmentCode)
{
    compileShader(vertexCode, fragmentCode);
}


void Shader::createFromFiles(const char *vertexLoc, const char *fragmentLoc)
{
    string vertexString = readFile(vertexLoc);
    string fragmentString = readFile(fragmentLoc);
    const char *vertexCode = vertexString.c_str();
    const char *fragmentCode = fragmentString.c_str();

    compileShader(vertexCode, fragmentCode);
}

string Shader::readFile(const char *fileLocation)
{
    string content;
    ifstream in;
    in.open(fileLocation);

    string line = "";
    while(!in.eof())
    {
        getline(in, line);
        content.append(line + '\n');
    }

    in.close();
    return content;
}

void Shader::useShader()
{
    glUseProgram(shaderID);
}

void Shader::clearShader()
{
    if(shaderID != 0)
    {
        glDeleteProgram(shaderID);
        shaderID = 0;
    }

    uniformProjection = 0;
    uniformModel = 0;
}