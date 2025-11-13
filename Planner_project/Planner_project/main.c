#include <stdio.h>

int mainmenu(void);
void newplan(void);
void checkplan(void);

int main(void)
{
	char menu;

	while (1) {
		
		menu = mainmenu();
		switch (menu) {
		case 0:
			printf("프로그램을 종료합니다.\n");
			return 0;
			break;
		case 1:
			newplan();
			break;
		case 2:
			//checkplan();
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
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
	printf("==================플래너 프로그램 1.1v==================\n");
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

void newplan(void)
{
	char pname[100];
	int pyear, pmonth, pday, ptime;
	char ptask[100];

	printf("계획 이름: ");
	scanf_s("%s", pname, (int)sizeof(pname));
	printf("날짜(xx(년도) x(월) x(일)): ");
	scanf_s("%d %d %d", &pyear, &pmonth, &pday);
	printf("시간(xx(24h)): ");
	scanf_s("%d", &ptime);
	printf("계획 내용: ");
	scanf_s("%s", ptask, (int)sizeof(ptask));

	printf("\n저장 완료!\n");

	printf("계획 이름: %s\n", pname);
	printf("날짜: %d년 %d월 %d일\n", pyear, pmonth, pday);
	printf("시간: %d시\n", ptime);
	printf("계획 내용: %s\n\n", ptask);
}

//void checkplan(void)
//{
//	printf("기존 계획을 확인합니다.\n\n");
//	for (/*계획의 갯수만큼*/) {
//		printf("%d번. %s");
//		
//	}
//	
//}