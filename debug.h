#ifndef CLOX_DEBUG_H
#define CLOX_DEBUG_H

#include "chunk.h"

// 청크 전체를 디스어셈블하여 출력
void disassembleChunk(Chunk* chunk, const char* name);

// 단일 명령어를 디스어셈블. 다음 명령어의 오프셋을 반환
int disassembleInstruction(Chunk* chunk, int offset);

#endif //CLOX_DEBUG_H
