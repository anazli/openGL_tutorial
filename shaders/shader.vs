#version 330 core
layout (location = 0) in vec3 pos;
layout (location = 1) in vec3 col;
out vec3 color;
uniform mat4 transform;
void main()
{
    gl_Position = transform * vec4(pos, 1.0f);
    color = col; 
}