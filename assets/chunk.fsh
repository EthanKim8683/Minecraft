#version 300 es

precision mediump float;

in vec2 v_texcoord;

out vec4 color;

void main() {
  color = vec4(v_texcoord, 0,1);
}