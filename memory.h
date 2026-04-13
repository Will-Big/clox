#ifndef CLOX_MEMORY_H
#define CLOX_MEMORY_H

#include "common.h"

// 용량 증가: 8 미만이면 8로, 이후 2배씩 확장
#define GROW_CAPACITY(capacity) \
    ((capacity) < 8 ? 8 : (capacity) * 2)

// 동적 배열 확장 (realloc 래퍼)
#define GROW_ARRAY(type, pointer, oldCount, newCount) \
    (type*)reallocate(pointer, sizeof(type) * (oldCount), \
        sizeof(type) * (newCount))

// 새 메모리 할당 (malloc 래퍼)
#define ALLOCATE(type, count) \
    (type*)reallocate(NULL, 0, sizeof(type) * (count))

// 단일 객체 메모리 해제
#define FREE(type, pointer) reallocate(pointer, sizeof(type), 0)

// 배열 메모리 해제
#define FREE_ARRAY(type, pointer, oldCount) \
    reallocate(pointer, sizeof(type) * (oldCount), 0)

// 메모리 관리 핵심 함수: oldSize→newSize로 재할당. newSize가 0이면 해제
void* reallocate(void* pointer, size_t oldSize, size_t newSize);

// VM에 등록된 모든 힙 객체를 순회하며 해제
void freeObjects();

#endif //CLOX_MEMORY_H
