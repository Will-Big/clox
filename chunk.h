#ifndef CLOX_CHUNK_H
#define CLOX_CHUNK_H

#include "common.h"
#include "value.h"

// VM이 실행하는 바이트코드 명령어 종류
typedef enum
{
    OP_CONSTANT,    // 상수 로드
    OP_NIL,         // nil 값 푸시
    OP_TRUE,        // true 값 푸시
    OP_FALSE,       // false 값 푸시
    OP_EQUAL,       // 동등 비교 (==)
    OP_GREATER,     // 크기 비교 (>)
    OP_LESS,        // 크기 비교 (<)
    OP_ADD,         // 덧셈 또는 문자열 연결
    OP_SUBTRACT,    // 뺄셈
    OP_MULTIPLY,    // 곱셈
    OP_DIVIDE,      // 나눗셈
    OP_NOT,         // 논리 부정 (!)
    OP_NEGATE,      // 부호 반전 (-)
    OP_RETURN,      // 함수 반환
} OpCode;

// 바이트코드 청크: opcode 배열 + 상수 풀 + 줄 번호 정보
typedef struct
{
    int count;              // 현재 저장된 바이트 수
    int capacity;           // 할당된 배열 크기
    uint8_t* code;          // 바이트코드 배열
    int* lines;             // 각 바이트코드에 대응하는 소스 줄 번호
    ValueArray constants;   // 상수 풀
} Chunk;

// 빈 청크 초기화
void initChunk(Chunk* chunk);

// 청크에 바이트코드 1바이트 추가
void writeChunk(Chunk* chunk, uint8_t byte, int line);

// 청크 메모리 해제
void freeChunk(Chunk* chunk);

// 상수 풀에 값 추가, 추가된 인덱스 반환
int addConstant(Chunk* chunk, Value  value);

#endif //CLOX_CHUNK_H
