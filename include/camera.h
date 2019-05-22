#ifndef CAMERA_H
#define CAMERA_H

#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<GLFW/glfw3.h>

enum Direction {
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT
};

class Camera {
    public:
        Camera()
        {up = target = position = glm::vec3(0., 0., 0.);}
        Camera(const glm::vec3& p, const glm::vec3& t): position(p), target(t)
        {
            yaw = 0.0f;
            pitch = 0.0f;
            moveSpeed = 5.0f;
            turnSpeed = 1.0f;
            worldUp = glm::vec3(0., 1., 0.);
            right = glm::normalize(glm::cross(target, worldUp));
            up = glm::normalize(glm::cross(right, target));

            update();
            cam_look_at = look_at();
        }

        glm::mat4 look_at()const{return glm::lookAt(position, position + target, up);}
        void move(Direction d);

    private:
        glm::vec3 position;
        glm::vec3 target;
        glm::vec3 up;
        glm::vec3 right;
        glm::vec3 worldUp;
        glm::mat4 cam_look_at;

        GLfloat yaw;
        GLfloat pitch;
        GLfloat moveSpeed;
        GLfloat turnSpeed;

        void update();
};

#endif