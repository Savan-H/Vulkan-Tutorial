// Shaders need to compiled before using them into an intermediate binary format called the Standard portable intermediate representation V (SPIR-V)

#version 450

layout(location=0) in vec2 position;

void main() {
	gl_Position = vec4(position, 0.0, 1.0);
}