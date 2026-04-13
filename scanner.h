#ifndef CLOX_SCANNER_H
#define CLOX_SCANNER_H

// 토큰 종류
typedef enum {
    // 단일 문자 토큰
    TOKEN_LEFT_PAREN, TOKEN_RIGHT_PAREN,
    TOKEN_LEFT_BRACE, TOKEN_RIGHT_BRACE,
    TOKEN_COMMA, TOKEN_DOT, TOKEN_MINUS, TOKEN_PLUS,
    TOKEN_SEMICOLON, TOKEN_SLASH, TOKEN_STAR,
    // 1~2 문자 토큰
    TOKEN_BANG, TOKEN_BANG_EQUAL,
    TOKEN_EQUAL, TOKEN_EQUAL_EQUAL,
    TOKEN_GREATER, TOKEN_GREATER_EQUAL,
    TOKEN_LESS, TOKEN_LESS_EQUAL,
    // 리터럴
    TOKEN_IDENTIFIER, TOKEN_STRING, TOKEN_NUMBER,
    // 예약어
    TOKEN_AND, TOKEN_CLASS, TOKEN_ELSE, TOKEN_FALSE,
    TOKEN_FOR, TOKEN_FUN, TOKEN_IF, TOKEN_NIL, TOKEN_OR,
    TOKEN_PRINT, TOKEN_RETURN, TOKEN_SUPER, TOKEN_THIS,
    TOKEN_TRUE, TOKEN_VAR, TOKEN_WHILE,

    TOKEN_ERROR, TOKEN_EOF
} TokenType;

// 토큰: 타입 + 소스 내 위치(start, length) + 줄 번호
typedef struct
{
    TokenType type;
    const char* start;  // 소스 문자열 내 토큰 시작 위치
    int length;         // 토큰 길이
    int line;           // 소스 줄 번호
} Token;

// 스캐너 초기화 (소스 문자열 설정)
void initScanner(const char* source);

// 다음 토큰 하나를 읽어서 반환
Token scanToken();

#endif //CLOX_SCANNER_H
