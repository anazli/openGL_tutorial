#version 330 core
in vec3 color;
out vec4 fragColor;
void main()
{
    //color = vec4(0.0f, 0.0f, 1.0f, 1.0f);
    fragColor = vec4(color, 1.0f);
}