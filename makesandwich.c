//makesandwich.c
#define _CRT_SECURE_NO_WARNINGS//소스 속성에서 전처리기에다가 추가해야함.
#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "Stage.h"
#include "Sandwich.h"

void showlocal(LocalNode* p) {
    gotoxy(55, 39);
    printf("            [[%d]]", p->localname);
}

const char* numberToStringmake(int num) {
    switch (num) {
    case 1:
        return "뭔지 모를 피가 묻은 빵";
    case 2:
        return "악몽의 죽음빵";
    case 3:
        return "유령의 고귀한 빵";
    case 4:
        return "악마의 화염 당근";
    case 5:
        return "마녀의 마법 버섯";
    case 6:
        return "좀비의 신선한 파프리카";
    case 7:
        return "인간으로 만든 신선한 햄";
    case 8:
        return "뱀파이어의 혈액 소시지";
    case 9:
        return "마녀의 마법 미트볼";
    case 10:
        return "인간의 신선한 혈액 케첩";
    case 11:
        return "요정의 이른 아침 갈릭 버터";
    case 12:
        return "신선한 유령 샹솔레";
    case 13:
        return "신비로운 달빛 에이드";
    case 14:
        return "황홀한 샘물 스프라이트";
    case 15:
        return "인간의 신선한 이슬 콜라";
    default:
        return "Invalid number";
    }
}

const char* numberToStringmakep(int num) {
    switch (num) {
    case 1:
        return "빵";
    case 2:
        return "야채";
    case 3:
        return "재료";
    case 4:
        return "소스";
    case 5:
        return "음료";
    default:
        return "Invalid number";
    }
}

void makesandwich(Owner* sand_owner, int* stagecheck, OwnerStock* stock) {

    Customer* cus = (Customer*)malloc(sizeof(Customer));
    memset(cus, 0, sizeof(Customer));
    cus->sandwich = (Sandwich*)malloc(sizeof(Sandwich));
    init_product(cus->sandwich);
    int guessnum = 0;
    int guess = 0;
    srand(time(NULL));// 필요 없는지 확인
    gotoxy(20, 28);
    printf("<<재고>>");
    for (int i = 0; i < 5; i++) {
        gotoxy(20, 28 + ((i + 1) * 3));
        printf("[%d] :: %2d", i + 1, stock->stock[i]);
    }

    for (int i = 0; i < 5; i++) {
        gotoxy(55, 31);
        printf("                                       ");
        gotoxy(55, 31);
        printf("[%s]어떤 재료를 넣을까요?", numberToStringmakep(i + 1));
        gotoxy(55, 33);
        printf("                                                             ");
        gotoxy(17, 46);
        printf("총 수익 : %d  ", sand_owner->total_income);
        gotoxy(17, 48);
        printf("남은 체력 : %d  ", sand_owner->blood);
        gotoxy(55, 33);
        printf("<%s> = %d\n", numberToStringmake(3 * i + 1), 3 * i + 1);
        gotoxy(55, 35);
        printf("<%s> = %d\n", numberToStringmake(3 * i + 2), 3 * i + 2);
        gotoxy(55, 37);
        printf("<%s> = %d\n ", numberToStringmake(3 * i + 3), 3 * i + 3);
        gotoxy(55, 38);
        scanf("%d", &guess);
        if (stock->stock[i] == 0) {
            gotoxy(55, 40);
            printf("재고가 없습니다 총 수익 50 감소");
            sand_owner->total_income -= 50;
            Sleep(1000);
            gotoxy(55, 40);
            printf("                                                ");
        }
        else {
            stock->stock[i] -= 1;
        }
        gotoxy(20, 28);
        printf("<<재고>>");
        for (int i = 0; i < 5; i++) {
            gotoxy(20, 28 + ((i + 1) * 3));
            printf("[%d] :: %2d", i + 1, stock->stock[i]);
        }
        push_stack(guess, cus->sandwich);
        gotoxy(55, 33);
        printf("                                                              ");
        gotoxy(55, 35);
        printf("                                                              ");
        gotoxy(55, 37);
        printf("                                                              ");
        gotoxy(55, 38);
        printf("                    ");
    }

    //insertnode(sand_owner->localNode, 2);
    gotoxy(55, 31);
    printf("                                             ");
    gotoxy(55, 33);
    printf("                                                                     ");
    LocalNode* p;
    p = sand_owner->localNode;
    int local = 1; // 배달 지역은 다시 선택 가능하게!!
    while (1) {
        showlocal(p);
        gotoxy(45, 41);
        printf("배달 지역을 선택하세요( 선택 : 1 / 다른 지역으로 : 2) : ");
        scanf("%d", &guess);
        if (guess == 1) {

            if (p->localname == (*stagecheck)) {

                cus->local = p->localname;
                gotoxy(45, 43);
                printf("                                                                                     ");
                gotoxy(55, 43);
                printf("VIP 손님인가요?(O : 1 / X : 0) : ");
                scanf("%d", &guess);
                cus->vip = guess;
                if (cus->vip == 1) {
                    p->cuscount += 1;
                    p->cusQ->vipnum += 1;
                    add_front(p->cusQ, cus);
                    //gotoxy(55, 41);
                    //printf("%d", sand_owner->cusNode->cusQ->cus[0]->sandwich->sandwich_num[0]);
                    break;
                }
                else {
                    p->cuscount += 1;
                    add_rear(p->cusQ, cus);
                    //gotoxy(55, 41);
                    //printf("%d", sand_owner->cusNode->cusQ->cus[1]->sandwich->sandwich_num[0]);
                    break;
                }
            }
            else {
                gotoxy(45, 43);
                printf("지역을 잘 못 선택하셨어요. 주의하세요 (체력이 감소했습니다! <%d> -> <%d>) ", sand_owner->blood, (sand_owner->blood) - 1);
                sand_owner->blood--;
            }


        }
        else if (guess == 2) {
            p = p->link;
        }

    }

}