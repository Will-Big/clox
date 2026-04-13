#ifndef CLOX_VM_H
#define CLOX_VM_H

#include "chunk.h"
#include "table.h"

#define STACK_MAX 256

typedef struct
{
    Chunk* chunk;      // 실행할 바이트코드
    uint8_t* ip;       // 지금 어디를 실행 중인지 (instruction pointer)
    Value stack[256];  // 계산에 쓰는 스택
    Value* stackTop;   // 스택의 현재 꼭대기
    Obj* objects;      // 힙에 할당된 모든 객체의 링크드 리스트
    Table strings;     // 문자열 검색 및 비교를 위한 해쉬 맵
} VM;

extern VM vm;

// 인터프리터 실행 결과
typedef enum
{
    INTERPRET_OK,              // 정상 실행
    INTERPRET_COMPILE_ERROR,   // 컴파일 에러
    INTERPRET_RUNTIME_ERROR,   // 런타임 에러
} InterpretResult;

// VM 초기화 (스택 리셋, 객체 리스트 초기화, 문자열 테이블 초기화)
void initVM();

// VM 종료 (문자열 테이블 해제, 모든 힙 객체 해제)
void freeVM();

// 소스 코드를 컴파일하고 실행
InterpretResult interpret(const char* source);

// VM 스택에 값 푸시
void push(Value value);

// VM 스택에서 값 팝
Value pop();

#endif //CLOX_VM_H
