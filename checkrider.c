//checkrider.c
#define _CRT_SECURE_NO_WARNINGS//�ҽ� �Ӽ����� ��ó���⿡�ٰ� �߰��ؾ���.
#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "Stage.h"
#include "Sandwich.h"

void showrider(Heap* rider_heap) {
	for (int i = 1 ; i <= 10; i++) {
		Sleep(100);
		gotoxy(55, 31+i);
		printf("[%d] ������ ���ð� : %d", rider_heap->heap[i].id, rider_heap->heap[i].avail_time);
	}
	int guess;
	while (1) {
		gotoxy(47, 44);
		printf("������ ȣ���Ͻ÷��� 1�� �Է��ϼ���: ");
		scanf("%d", &guess);
		if (guess == 1) {
			break;
		}
	}
}


void checkrider(Owner* sand_owner,Heap* rider_heap, OwnerStock* stock) {
	int guess;
	gotoxy(17, 46);
	printf("�� ���� : %d  ", sand_owner->total_income);
	gotoxy(17, 48);
	printf("���� ü�� : %d  ", sand_owner->blood);
	gotoxy(20, 28);
	printf("<<���>>");
	for (int i = 0; i < 5; i++) {
		gotoxy(20, 28 + ((i + 1) * 3));
		printf("[%d] :: %2d", i + 1, stock->stock[i]);
	}
	while (1) {
		gotoxy(41, 25);
		printf("��� ������ ������ Heap���� ���� �˻��Ͻ÷��� 1�� �Է��ϼ���: ");
		scanf("%d", &guess);
		if (guess == 1) {
			gotoxy(52, 27);
			printf("�˻���........(��� ��ٷ��ּ���) ");// ������ ���� �ð�!
			break;
		}
	}
	Sleep(1000);
	showrider(rider_heap);

}