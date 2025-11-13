#include <stdio.h>

//typedef struct {
//	char plan_name[20];
//	int  plan_year;
//	int  plan_month;
//	int  plan_day;
//	int  plan_time;
//	char plan_task[100];
//};

void mainmenu(void);

int main(int argv, char* argc[])
{
	mainmenu();
	return 0;
}

void mainmenu(void)
{
	printf("--------------------------------------------------------\n");
	printf("|");
	printf("1. Create a new plan\n");
	printf("2. View existing plans\n");
	printf("3. Edit a plan\n");
	printf("4. Delete a plan\n");
	printf("5. Exit\n");
	printf("Please select an option (1-5): ");
	// Further implementation would go here
}