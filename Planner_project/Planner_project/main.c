#include <stdio.h>

typedef struct date{
	int year, month, day;
}DATE;

typedef struct plan {
	char name[100];
	DATE sdate;
	DATE edate;
	int done;
} PLAN;

int mainmenu(void);
PLAN newPlan(void);
void checkPlan(PLAN plans[], int num);
void modifyPlan(PLAN plans[], int num);
void deletePlan(PLAN plans[], int* num);

int main(void)
{
	PLAN plans[10] = { 0 };
	int count = 0;
	int menu;

	while (1) {
		menu = mainmenu();
		switch (menu) {
		case 1:
			if (count >= 10) printf("더 이상 계획을 저장할 수 없습니다.\n");
			else 
			{
				plans[count] = newPlan();
				count++;
			}
			break;
		case 2:
			checkPlan(plans, count);
			break;
		case 3:
			modifyPlan(plans, count);
			break;
		case 4:
			deletePlan(plans, &count);
			break;
		case 5:
			printf("프로그램을 종료합니다.\n");
			return 0;
		default:
			printf("메뉴를 잘못 선택하셨습니다. 다시 선택해주세요.\n");
			break;
		}
	}
	return 0;
}

int mainmenu(void)
{
	int menu = 0;
	printf("==================플래너 프로그램 1.5v==================\n");
	printf("|                                                      |\n");
	printf("------------------------메뉴----------------------------\n");
	printf("|                                                      |\n");
	printf("| 1. 새 계획 작성                                      |\n");
	printf("| 2. 계획 확인                                         |\n");
	printf("| 3. 계획 수정                                         |\n");
	printf("| 4. 계획 삭제                                         |\n");
	printf("| 5. 종료                                              |\n");
	printf("|                                                      |\n");
	printf("--------------------------------------------------------\n");
	printf("메뉴를 선택하세요(1-5): ");
	scanf_s("%d", &menu);
	getchar();
	return menu;
}

PLAN newPlan(void)
{
	PLAN temp = { 0 };

	printf("\n[새 계획 작성]\n");
	printf("계획 이름: ");
	gets_s(temp.name, sizeof(temp.name));
	
	printf("시작날짜(년 월 일): ");
	scanf_s("%d %d %d", &temp.sdate.year, &temp.sdate.month, &temp.sdate.day);
	getchar();

	printf("종료날짜(년 월 일): ");
	scanf_s("%d %d %d", &temp.edate.year, &temp.edate.month, &temp.edate.day);
	getchar();

	temp.done = 0;

	printf("\n저장이 완료되었습니다.\n\n");
	return temp;
}

void checkPlan(PLAN plans[], int num)
{
	printf("\n[계획 확인]\n");

	if (num == 0) {
		printf("저장된 계획이 없습니다.\n\n");
	}
	else {
		printf("-------저장된 계획 목록-------\n");

		for (int i = 0; i < num; i++) {
			char status = (plans[i].done == 1) ? 'O' : 'X';
			
			printf("[%c] %s\n", status, plans[i].name);
			printf("기간: %d.%d.%d ~ %d.%d.%d\n",
				plans[i].sdate.year, plans[i].sdate.month, plans[i].sdate.day,
				plans[i].edate.year, plans[i].edate.month, plans[i].edate.day);
			
			printf("------------------------------\n");
		}
		printf("\n");
	}
}

void modifyPlan(PLAN plans[], int num)
{
	int n1 = 0;
	int n2 = 0;
	int index = 0;

	printf("\n[계획 수정]\n");
	if (num == 0) printf("수정할 계획이 없습니다.\n\n");
	else {
		for (int i = 0; i < num; i++) printf("[%d] %s\n", i + 1, plans[i].name);

		printf("수정할 계획 번호를 입력하세요(취소:0): ");
		scanf_s("%d", &n1);
		getchar();

		if (n1 > 0 && n1 <= num)
		{
			index = n1 - 1;

			printf("\n[%d]번 계획을 수정합니다.\n\n", n1);
			printf("------------------------수정항목------------------------\n");
			printf("|   1. 제목   2. 시작날짜   3. 종료날짜   4.완료여부   |\n");
			printf("--------------------------------------------------------\n");

			while (1) {
				printf("수정할 항목을 선택하세요(종료:0): ");
				scanf_s("%d", &n2);
				getchar();

				if (n2 == 0) {
					printf("\n수정이 완료되었습니다.\n\n");
					break;
				}

				switch (n2)
				{
				case 1:
					printf("제목: ");
					gets_s(plans[index].name, sizeof(plans[index].name));
					break;
				case 2:
					printf("시작날짜: ");
					scanf_s("%d %d %d", &plans[index].sdate.year, &plans[index].sdate.month, &plans[index].sdate.day);
					getchar();
					break;
				case 3:
					printf("종료날짜: ");
					scanf_s("%d %d %d", &plans[index].edate.year, &plans[index].edate.month, &plans[index].edate.day);
					getchar();
					break;
				case 4:
					if (plans[index].done == 0) {
						plans[index].done = 1;
						printf(">> 상태가 완료(O)로 변경되었습니다.\n");
					} else {
						plans[index].done = 0;
						printf(">> 상태가 미완료(X)로 변경되었습니다.\n");
					}
					break;
				default:
					printf("없는 항목입니다.\n");
					break;
				}
			}
		}
		else if (n1 == 0) printf("\n수정을 취소했습니다.\n\n");
		else printf("잘못된 번호입니다.\n\n");
	}
}

void deletePlan(PLAN plans[], int* num)
{
	int n = 0;
	int count = *num;

	printf("\n[계획 삭제]\n");
	if (count == 0) printf("삭제할 계획이 없습니다.\n\n");
	else {
		for (int i = 0; i < count; i++) printf("[%d] %s\n", i + 1, plans[i].name);
		printf("삭제할 계획 번호를 입력하세요(취소:0): ");
		scanf_s("%d", &n);
		getchar();

		if (n > 0 && n <= count)
		{
			for (int i = n - 1; i < count - 1; i++) plans[i] = plans[i + 1];
			(*num)--;
			printf("\n[%d]번 계획이 삭제되었습니다.\n\n", n);
		}
		else if (n == 0) printf("\n삭제를 취소했습니다.\n\n");
		else printf("잘못된 번호입니다.\n\n");
	}
}