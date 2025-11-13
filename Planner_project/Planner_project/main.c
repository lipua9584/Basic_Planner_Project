#include <stdio.h>

//typedef struct {
//	char plan_name[20];
//	int  plan_year;
//	int  plan_month;
//	int  plan_day;
//	int  plan_time;
//	char plan_task[100];
//};

int mainmenu(void);

int main(int argv, char* argc[])
{
	while (1) {
		char menu;
		mainmenu();
	}
	return 0;
}

int mainmenu(void)
{
	int menu = 0;
	printf("=====================플래너 프로그램====================\n");
	printf("|                                                      |\n");
	printf("------------------------메뉴----------------------------\n");
	printf("|                                                      |\n");
	printf("| 1. 새 계획 작성                                      |\n");
	printf("| 2. 기존 계획 확인                                    |\n");
	printf("| 3. 계획 수정                                         |\n");
	printf("| 4. 계획 삭제                                         |\n");
	printf("| 5. 종료                                              |\n");
	printf("|                                                      |\n");
	printf("--------------------------------------------------------\n");
	printf("메뉴를 선택하세요(1-5): ");
	scanf_s("%d", &menu);
	return menu;
}