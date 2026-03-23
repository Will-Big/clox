#ifndef CLOX_VM_H
#define CLOX_VM_H

#include "chunk.h"

#define STACK_MAX 256

typedef struct
{
    Chunk* chunk;      // 실행할 바이트코드
    uint8_t* ip;       // 지금 어디를 실행 중인지 (instruction pointer)
    Value stack[256];  // 계산에 쓰는 스택
    Value* stackTop;   // 스택의 현재 꼭대기
    Obj* objects;      // 힙에 할당된 모든 객체의 링크드 리스트
} VM;

extern VM vm;

typedef enum
{
    INTERPRET_OK,
    INTERPRET_COMPILE_ERROR,
    INTERPRET_RUNTIME_ERROR,
} InterpretResult;

void initVM();
void freeVM();

InterpretResult interpret(const char* source);
void push(Value value);
Value pop();

#endif //CLOX_VM_H
