#ifndef clox_object_h
#define clox_object_h

#include "common.h"
#include "value.h"

typedef enum {
    OBJ_STRING,
} ObjType;

struct Obj {
    ObjType type;
    struct Obj* next;
};

struct ObjString {
    Obj obj;
    int length;
    char* chars;
    uint32_t hash;
};

#define OBJ_TYPE(value)     (AS_OBJ(value)->type)

#define IS_STRING(value)    isObjType(value, OBJ_STRING)

#define AS_STRING(value)    ((ObjString*)AS_OBJ(value))
#define AS_CSTRING(value)   (((ObjString*)AS_OBJ(value))->chars)

static inline bool isObjType(Value value, ObjType type) {
    return IS_OBJ(value) && AS_OBJ(value)->type == type;
}

// 소스 문자열을 복사하여 새 ObjString 생성 (리터럴용)
ObjString* copyString(const char* chars, int length);

// 이미 할당된 문자열의 소유권을 넘겨받아 ObjString 생성 (연결 연산 결과용)
ObjString* takeString(char* chars, int length);

// Obj 타입에 맞는 값을 출력
void printObject(Value value);

#endif
