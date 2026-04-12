#ifndef clox_table_h
#define clox_table_h

#include "common.h"
#include "value.h"

typedef struct {
    ObjString* key;
    Value value;
} Entry;

typedef struct {
    int count;
    int capacity;
    Entry* entries;
} Table;

// 해시 테이블 초기화 (빈 테이블)
void initTable(Table* table);

// 해시 테이블 메모리 해제
void freeTable(Table* table);

// key-value 삽입 (이미 있으면 값 덮어쓰기). 새 key면 true 반환
bool tableSet(Table* table, ObjString* key, Value value);

// key로 값 조회. 찾으면 value에 저장하고 true 반환
bool tableGet(Table* table, ObjString* key, Value* value);

// key 삭제 (tombstone으로 대체). 삭제 성공 시 true 반환
bool tableDelete(Table* table, ObjString* key);

// from 테이블의 모든 엔트리를 to 테이블에 복사
void tableAddAll(Table* from, Table* to);

// 문자열 내용(chars, length, hash)으로 테이블에서 동일한 문자열 검색. string interning 용
ObjString* tableFindString(Table* table, const char* chars, int length, uint32_t hash);

#endif
