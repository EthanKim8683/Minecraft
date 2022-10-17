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
  static GLuint createShader(std::string, GLenum);
  static GLuint createProgram(std::string, std::string);
  static GLuint loadShader(std::string, GLenum);
  static GLuint loadProgram(std::string, std::string);
};

#endif // !defined(HELPER_H)