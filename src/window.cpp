#include "../include/window.h"
#include<iostream>

using std::cout; using std::endl;

int Window::initialize()
{
    if(!glfwInit())
    {
        cout << "GLFW initialization failed!" << endl;
        glfwTerminate();
        return EXIT_FAILURE;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    window = glfwCreateWindow(width, height, name, nullptr, nullptr);
    if(!window)
    {
        cout << "GLFW window creation failed!" << endl;
        glfwTerminate();
        return EXIT_FAILURE;
    }
    glfwGetFramebufferSize(window, &buffer_width, &buffer_height);
    glfwMakeContextCurrent(window);
    glewExperimental = GL_TRUE;
    if(glewInit() != GLEW_OK)
    {
        cout << "Glew initialization failed!" << endl;
        return EXIT_FAILURE;
    }

    glViewport(0, 0, buffer_width, buffer_height);

    return EXIT_SUCCESS;
}

Window::~Window()
{
    glfwDestroyWindow(window);
    glfwTerminate();
}


void process_input(GLFWwindow *mainWindow, Camera &cam)
{
    if(glfwGetKey(mainWindow, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(mainWindow, true);
    
    if(glfwGetKey(mainWindow, GLFW_KEY_UP) == GLFW_PRESS)
        cam.move(FORWARD); 
    if(glfwGetKey(mainWindow, GLFW_KEY_DOWN) == GLFW_PRESS)
        cam.move(BACKWARD); 
    if(glfwGetKey(mainWindow, GLFW_KEY_LEFT) == GLFW_PRESS)
        cam.move(LEFT); 
    if(glfwGetKey(mainWindow, GLFW_KEY_RIGHT) == GLFW_PRESS)
        cam.move(RIGHT); 
}

void frame_buffer_size_callback(GLFWwindow *mainWindow, int width, int height)
{
    glViewport(0, 0, width, height);
}