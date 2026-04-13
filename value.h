#ifndef CLOX_VALUE_H
#define CLOX_VALUE_H

#include "common.h"

// 전방 선언 (object.h와의 순환 참조 방지)
typedef struct Obj Obj;
typedef struct ObjString ObjString;

// 값의 타입 태그
typedef enum {
    VAL_BOOL,
    VAL_NIL,
    VAL_NUMBER,
    VAL_OBJ,       // 힙 할당 객체 (문자열 등)
} ValueType;

// 태그드 유니온: 타입 태그 + 실제 값
typedef struct {
    ValueType type;
    union {
        bool boolean;
        double number;
        Obj* obj;
    } as;
} Value;

// 타입 검사 매크로
#define IS_BOOL(value)    ((value).type == VAL_BOOL)
#define IS_NIL(value)     ((value).type == VAL_NIL)
#define IS_NUMBER(value)  ((value).type == VAL_NUMBER)
#define IS_OBJ(value)     ((value).type == VAL_OBJ)

// 값 추출 매크로 (Value → C 타입)
#define AS_BOOL(value)    ((value).as.boolean)
#define AS_NUMBER(value)  ((value).as.number)
#define AS_OBJ(value)     ((value).as.obj)

// 값 생성 매크로 (C 타입 → Value)
#define BOOL_VAL(value)   ((Value){VAL_BOOL, {.boolean = value}})
#define NIL_VAL           ((Value){VAL_NIL, {.number = 0}})
#define NUMBER_VAL(value) ((Value){VAL_NUMBER, {.number = value}})
#define OBJ_VAL(value)    ((Value){VAL_OBJ, {.obj = (Obj*)(value)}})

// 상수 풀용 동적 배열
typedef struct {
    int capacity;
    int count;
    Value* values;
} ValueArray;

// 두 값이 같은지 비교 (타입 + 값 모두 일치해야 true)
bool valuesEqual(Value a, Value b);

// 값 배열 초기화
void initValueArray(ValueArray* array);

// 값 배열에 값 추가
void writeValueArray(ValueArray* array, Value value);

// 값 배열 메모리 해제
void freeValueArray(ValueArray* array);

// 값을 사람이 읽을 수 있는 형태로 출력
void printValue(Value value);

#endif //CLOX_VALUE_H
