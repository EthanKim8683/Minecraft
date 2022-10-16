#if !defined(HELPER_C)
#define HELPER_C

#include "Helper.hpp"

GLuint Helper::createShader(std::string source, GLenum type) {
  const GLuint shader = glCreateShader(type);
  const char* pointer = source.c_str();
  glShaderSource(shader, 1, &pointer, NULL);
  glCompileShader(shader);
  GLint success;
  glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
  if (!success) {
    GLint length = 0;
    glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &length);
    if (length > 1) {
      std::vector<char> buffer(length + 1);
      glGetShaderInfoLog(shader, length, NULL, &buffer[0]);
      printf("createShader:\n%s\n", &buffer[0]);
    }
    exit(1);
  }
  return shader;
}

GLuint Helper::createProgram(std::string vertexSource, std::string fragmentSource) {
  const GLuint vertexShader = createShader(vertexSource, GL_VERTEX_SHADER);
  const GLuint fragmentShader = createShader(fragmentSource, GL_FRAGMENT_SHADER);
  const GLuint program = glCreateProgram();
  glAttachShader(program, vertexShader);
  glAttachShader(program, fragmentShader);
  glLinkProgram(program);
  GLint success;
  glGetProgramiv(program, GL_LINK_STATUS, &success);
  if (!success) {
    GLint length = 0;
    glGetProgramiv(program, GL_INFO_LOG_LENGTH, &length);
    if (length > 1) {
      std::vector<char> buffer(length + 1);
      glGetProgramInfoLog(program, length, NULL, &buffer[0]);
      printf("createProgram:\n%s\n", &buffer[0]);
    }
    exit(1);
  }
  glDetachShader(program, vertexShader);
  glDetachShader(program, fragmentShader);
  glDeleteShader(vertexShader);
  glDeleteShader(fragmentShader);
  return program;
}

GLuint Helper::loadShader(std::string path, GLenum type) {
  std::ifstream stream(path);
  std::string source;
  if (stream.is_open()) {
    std::stringstream sout;
    sout << stream.rdbuf();
    source = sout.str();
    stream.close();
  } else {
    printf("loadShader:\nShader source error\n");
    exit(1);
  }
  return createShader(source, type);
}

GLuint Helper::loadProgram(std::string vertexPath, std::string fragmentPath) {
  std::ifstream vertexStream(vertexPath);
  std::ifstream fragmentStream(fragmentPath);
  std::string vertexSource;
  std::string fragmentSource;
  if (vertexStream.is_open()) {
    std::stringstream sout;
    sout << vertexStream.rdbuf();
    vertexSource = sout.str();
    vertexStream.close();
  } else {
    printf("loadProgram:\nVertex shader source error\n");
    exit(1);
  }
  if (fragmentStream.is_open()) {
    std::stringstream sout;
    sout << fragmentStream.rdbuf();
    fragmentSource = sout.str();
    fragmentStream.close();
  } else {
    printf("loadProgram:\nFragment shader source error\n");
    exit(1);
  }
  return createProgram(vertexSource, fragmentSource);
}

#endif // !defined(HELPER_C)