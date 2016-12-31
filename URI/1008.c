#include <stdio.h>

int main() {
	int emp_num, worked_hours;
	float amount_hour;
	scanf("%d %d %f", &emp_num, &worked_hours, &amount_hour);
	printf("NUMBER = %d\nSALARY = U$ %.2f\n", emp_num, 
			worked_hours * amount_hour);
	return 0;
}
