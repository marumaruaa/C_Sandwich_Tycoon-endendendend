//main.c
#define _CRT_SECURE_NO_WARNINGS//소스 속성에서 전처리기에다가 추가해야함.
#include <stdio.h>
#include <windows.h>
#define Max_Sand_Size 5;

int guess = 0;

int main() {
    // 변경할 창 크기 설정
    SMALL_RECT windowSize = { 0, 0, 1200, 900 };
    // 창 핸들 가져오기
    HWND hwnd = GetConsoleWindow();
    // 창 크기 변경
    MoveWindow(hwnd, windowSize.Left, windowSize.Top, windowSize.Right - windowSize.Left + 1, windowSize.Bottom - windowSize.Top + 1, TRUE);
    cls();
    displayPrologue();

     do{
        guess = StartMenu(guess);
     } while (guess != 1);
     cls();
     start_stage(); // 게임 시작

    return 0;
}