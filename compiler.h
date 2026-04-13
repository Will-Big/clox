#ifndef CLOX_COMPILER_H
#define CLOX_COMPILER_H

#include "vm.h"

// 소스 코드를 바이트코드로 컴파일. 성공 시 true, 에러 시 false
bool compile(const char* source, Chunk* chunk);

#endif //CLOX_COMPILER_H
