#version 410
layout (location=0) in vec3 aPos;
layout (location=1) in vec3 aColor;
layout (location=2) in vec2 aTexCoord;

out vec3 fColor;
out vec2 fTexCoord;

void main() {
    fColor = aColor;
    fTexCoord = aTexCoord;
    gl_Position = vec4(aPos, 1.0);
}