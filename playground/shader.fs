#version 330 core
out vec4 frag_color;
uniform vec2 res;
uniform float time;

void main()
{
    //gradient
    vec3 rgb = vec3(gl_FragCoord.x/res.x, gl_FragCoord.y/res.y, 0.2f);
    frag_color = vec4(time * rgb.x, 0.0f, 0.0f, 1.0f);
    //circle
    /*vec2 center = vec2(time, time);
    float rx = rgb.x - center.x;
    float ry = rgb.y - center.y;
    if((rx * rx + ry * ry) < 0.10f)
    {
        frag_color = vec4(1.0f, 0.0f, 0.0f, 1.0f);
    }
    else
        frag_color = vec4(rgb, 1.0f);*/
}