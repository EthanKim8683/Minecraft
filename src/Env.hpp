#if !defined(ENV_H)
#define ENV_H

#include <GLES3/gl3.h>

#include "Helper.hpp"
#include "Mat4.hpp"

struct Helper;
struct Mat4;

struct Env {
  GLuint chunkProgram;
  GLuint chunkPositionAttribLocation;
  GLuint chunkTexcoordAttribLocation;
  GLuint chunkMatrixUniformLocation;

  void initChunkProgram();

  void updateMatrix(const Mat4&);
};

#endif // !defined(ENV_H)