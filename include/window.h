#ifndef WINDOW_H
#define WINDOW_H

#include<GL/glew.h>
#include<GLFW/glfw3.h>

class Window {
    public:
        Window(GLint w = 0, GLint h = 0): width(w), height(h){}
        ~Window();
        int initialize();

        GLfloat getBufferWidth()const{return buffer_width;}
        GLfloat getBufferHeight()const{return buffer_height;}
        GLFWwindow *getWindowPtr()const{return window;}

        bool getShouldClose()const{return glfwWindowShouldClose(window);}
        void swapBuffers(){glfwSwapBuffers(window);}
    private:
        GLFWwindow *window;
        GLint width, height;
        GLint buffer_width, buffer_height;
};

void process_input(GLFWwindow *mainWindow);
void frame_buffer_size_callback(GLFWwindow *mainWindow, int width, int height);

#endif