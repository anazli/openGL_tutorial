#include<iostream>
#include<GL/glew.h>
#include<GLFW/glfw3.h>
#include<string>
#include "../include/window.h"
#include "../include/shader.h"

using namespace std;

int width = 800;
int height = 600;

static const char *vShader = "              \n\
#version 330 core                           \n\
layout (location = 0) in vec3 pos;          \n\
void main()                                 \n\
{                                           \n\
    gl_Position = vec4(pos, 1.0f);          \n\
}                                           \n\
";

static const char *fShader = "              \n\
#version 330 core                           \n\
out vec4 color;                             \n\
void main()                                 \n\
{                                           \n\
    color = vec4(0.0f, 0.0f, 1.0f, 1.0f);   \n\
}                                           \n\
";

int main()
{
    Window *w = new Window(width, height, "triangle");
    int window_success = w->initialize();


    GLfloat vertices[] = {
        -0.5f, -0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
         0.0f,  0.5f, 0.0f
    };

    GLuint VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    Shader *sh = new Shader;
    ifstream vertexStream, fragmentStream;
    sh->createFromFiles("../shaders/shader.vs", "../shaders/shader.fs");

    glfwSetFramebufferSizeCallback(w->getWindowPtr(), frame_buffer_size_callback);

    while(!w->getShouldClose())
    {
        process_input(w->getWindowPtr());
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        sh->useShader();
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glfwSwapBuffers(w->getWindowPtr());
        glfwPollEvents();
    }

    glDeleteBuffers(1, &VBO);
    glDeleteVertexArrays(1, &VAO);

    return 0;
}
