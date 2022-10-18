#if !defined(ENV_C)
#define ENV_C

#include "Env.hpp"

void Env::initChunkProgram() {
  chunkProgram = Helper::loadProgram("assets/chunk.vsh", "assets/chunk.fsh");
  glUseProgram(chunkProgram);

  chunkPositionAttribLocation = glGetAttribLocation(chunkProgram, "a_position");
  chunkTexcoordAttribLocation = glGetAttribLocation(chunkProgram, "a_texcoord");

  chunkMatrixUniformLocation = glGetUniformLocation(chunkProgram, "u_matrix");
}

void Env::updateMatrix(const Mat4& matrix) {
  glUniformMatrix4fv(chunkMatrixUniformLocation, 1, false, &matrix.data[0 * 4 + 0]);
}

#endif // !defined(ENV_C)