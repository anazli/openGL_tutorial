#include "../include/camera.h"

void Camera::update()
{
    target.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    target.y = sin(glm::radians(pitch));
    target.x = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
    target = glm::normalize(target);

    right = glm::normalize(glm::cross(target, worldUp));
    up = glm::normalize(glm::cross(right, target));
}

void Camera::move(Direction d)
{
    moveSpeed = 0.5f;
    if(d == FORWARD)
        position += target * moveSpeed;
    if(d == BACKWARD)
        position -= target * moveSpeed;
    if(d == LEFT)
        position -= right * moveSpeed;
    if(d == RIGHT)
        position += right * moveSpeed;
}
