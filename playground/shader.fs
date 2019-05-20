#version 330 core
out vec4 frag_color;
uniform vec2 res;
void main()
{
    vec3 rgb = vec3(gl_FragCoord.x/res.x, gl_FragCoord.y/res.y, 0.2f);
    frag_color = vec4(rgb, 1.0f);
}