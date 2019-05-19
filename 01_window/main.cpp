#include<iostream>
#include<GL/glew.h>
#include<GLFW/glfw3.h>
#include<string>
#include "../include/window.h"

using namespace std;

int width = 800;
int height = 600;

int main()
{

    Window *w = new Window(width, height);
    int window_success = w->initialize();

    while(!w->getShouldClose())
    {
        process_input(w->getWindowPtr());
        glfwSwapBuffers(w->getWindowPtr());
        glfwPollEvents();
    }

    return 0;
}
