#if !defined(HELPER_H)
#define HELPER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include <GLES3/gl3.h>
#include <emscripten/emscripten.h>
#include <emscripten/html5.h>

struct Helper {
  static GLuint createShader(std::string source, GLenum type);
  static GLuint createProgram(std::string vertexSource, std::string fragmentSource);
  static GLuint loadShader(std::string path, GLenum type);
  static GLuint loadProgram(std::string vertexPath, std::string fragmentPath);
};

#endif // !defined(HELPER_H)