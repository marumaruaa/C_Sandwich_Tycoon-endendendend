//makesandwich.c
#define _CRT_SECURE_NO_WARNINGS//�ҽ� �Ӽ����� ��ó���⿡�ٰ� �߰��ؾ���.
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
        return "���� �� �ǰ� ���� ��";
    case 2:
        return "�Ǹ��� ������";
    case 3:
        return "������ ������ ��";
    case 4:
        return "�Ǹ��� ȭ�� ���";
    case 5:
        return "������ ���� ����";
    case 6:
        return "������ �ż��� ������ī";
    case 7:
        return "�ΰ����� ���� �ż��� ��";
    case 8:
        return "�����̾��� ���� �ҽ���";
    case 9:
        return "������ ���� ��Ʈ��";
    case 10:
        return "�ΰ��� �ż��� ���� ��ø";
    case 11:
        return "������ �̸� ��ħ ���� ����";
    case 12:
        return "�ż��� ���� ���ַ�";
    case 13:
        return "�ź�ο� �޺� ���̵�";
    case 14:
        return "ȲȦ�� ���� ��������Ʈ";
    case 15:
        return "�ΰ��� �ż��� �̽� �ݶ�";
    default:
        return "Invalid number";
    }
}

const char* numberToStringmakep(int num) {
    switch (num) {
    case 1:
        return "��";
    case 2:
        return "��ä";
    case 3:
        return "���";
    case 4:
        return "�ҽ�";
    case 5:
        return "����";
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
    srand(time(NULL));// �ʿ� ������ Ȯ��
    gotoxy(20, 28);
    printf("<<���>>");
    for (int i = 0; i < 5; i++) {
        gotoxy(20, 28 + ((i + 1) * 3));
        printf("[%d] :: %2d", i + 1, stock->stock[i]);
    }

    for (int i = 0; i < 5; i++) {
        gotoxy(55, 31);
        printf("                                       ");
        gotoxy(55, 31);
        printf("[%s]� ��Ḧ �������?", numberToStringmakep(i + 1));
        gotoxy(55, 33);
        printf("                                                             ");
        gotoxy(17, 46);
        printf("�� ���� : %d  ", sand_owner->total_income);
        gotoxy(17, 48);
        printf("���� ü�� : %d  ", sand_owner->blood);
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
            printf("����� �����ϴ� �� ���� 50 ����");
            sand_owner->total_income -= 50;
            Sleep(1000);
            gotoxy(55, 40);
            printf("                                                ");
        }
        else {
            stock->stock[i] -= 1;
        }
        gotoxy(20, 28);
        printf("<<���>>");
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
    int local = 1; // ��� ������ �ٽ� ���� �����ϰ�!!
    while (1) {
        showlocal(p);
        gotoxy(45, 41);
        printf("��� ������ �����ϼ���( ���� : 1 / �ٸ� �������� : 2) : ");
        scanf("%d", &guess);
        if (guess == 1) {

            if (p->localname == (*stagecheck)) {

                cus->local = p->localname;
                gotoxy(45, 43);
                printf("                                                                                     ");
                gotoxy(55, 43);
                printf("VIP �մ��ΰ���?(O : 1 / X : 0) : ");
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
                printf("������ �� �� �����ϼ̾��. �����ϼ��� (ü���� �����߽��ϴ�! <%d> -> <%d>) ", sand_owner->blood, (sand_owner->blood) - 1);
                sand_owner->blood--;
            }


        }
        else if (guess == 2) {
            p = p->link;
        }

    }

}