#ifndef clox_object_h
#define clox_object_h

#include "common.h"
#include "value.h"

// 힙 할당 객체의 종류
typedef enum {
    OBJ_STRING,
} ObjType;

// 모든 힙 객체의 베이스 구조체 (구조체 상속의 기반)
struct Obj {
    ObjType type;       // 객체 타입 태그
    struct Obj* next;   // VM의 객체 링크드 리스트 (GC용)
};

// 문자열 객체 (Obj를 첫 필드로 두어 구조체 상속)
struct ObjString {
    Obj obj;            // 베이스 객체 (반드시 첫 번째 필드)
    int length;         // 문자열 길이
    char* chars;        // null-terminated 문자 배열
    uint32_t hash;      // 캐싱된 해시값 (FNV-1a)
};

// Value에서 Obj 타입 태그 추출
#define OBJ_TYPE(value)     (AS_OBJ(value)->type)

// 타입 검사
#define IS_STRING(value)    isObjType(value, OBJ_STRING)

// Value에서 ObjString*/char* 추출
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
