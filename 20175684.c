#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

struct Birthday {
	char year[5];
	char month[3];
	char day[3];
};

typedef struct Birthday Birthday;

struct Person {
	char name[30];
	Birthday birthday;
	char gender[10];
	char phone[11];
};

typedef struct Person Person;

void getPerson(Person ** people, int size);
void printPeople(Person ** people, int size);
void sortByName(Person ** people, int size);
void sortByBirthday(Person ** people, int size);

int main() {
	int n;
	printf("입력할 명세서 개수 입력 >> ");
	scanf("%d", &n);

	Person ** people = (Person **)malloc(sizeof(Person *) * n);
	getPerson(people, n);

	printPeople(people, n);
	printf("\n");
	
	sortByName(people, n);
	printPeople(people, n);
	printf("\n");

	sortByBirthday(people, n);
	printPeople(people, n);
	printf("\n");

	return 0;
}

void getPerson(Person ** people, int size) {
	for (int i = 0; i < size; i++) {
		Person * person = (Person *)malloc(sizeof(Person));
		if (person == NULL) {
			printf("동적할당을 받는데 오류가 있습니다.\n");
			exit(1);
		}

		char * delimiter = "/";
		char nameInput[30] = "옥재현";
		char birthInput[15] = "1999/01/12";
		char genderInput[10] = "남자";
		char phoneInput[20] = "01029873581";


		printf("개별명세서 입력%d: ", i + 1);
		scanf("%s %s %s %s", nameInput, birthInput, genderInput, phoneInput);

		char * ptok = strtok(birthInput, delimiter);

		strcpy(person->name, nameInput);
		strcpy(person->birthday.year, ptok);
		ptok = strtok(NULL, delimiter);
		strcpy(person->birthday.month, ptok);
		ptok = strtok(NULL, delimiter);
		strcpy(person->birthday.day, ptok);
		strcpy(person->gender, genderInput);
		strcpy(person->phone, phoneInput);

		*(people + i) = person;
	}
}

void printPeople(Person ** people, int size) {
	printf("%s%16s%15s%18s\n", "이름", "생년월일", "성별", "전화번호");
	for (int i = 0; i < size; i++) {
		printf("%s%10s년%s월%s일%9s%21s\n", (*(people + i))->name, (*(people + i))->birthday.year, (*(people + i))->birthday.month, (*(people + i))->birthday.day, (*(people + i))->gender, (*(people + i))->phone);
	}
}

void sortByName(Person ** people, int size) {
	for (int i = 0; i < size - 1; i++) {
		if (strcmp((*(people + i))->name, (*(people + i + 1))->name) > 0) {
			Person * temp;
			temp = (*(people + i));
			*(people + i) = *(people + i + 1);
			*(people + i + 1) = temp;
			i = 0;
		}
	}
}

void sortByBirthday(Person ** people, int size) {
	for (int i = 0; i < size - 1; i++) {
		if (strcmp((*(people + i))->birthday.year, (*(people + i + 1))->birthday.year) > 0) {
			Person * temp;
			temp = (*(people + i));
			*(people + i) = *(people + i + 1);
			*(people + i + 1) = temp;
			i = 0;
		}
		else if (strcmp((*(people + i))->birthday.year, (*(people + i + 1))->birthday.year) == 0) {
			if (strcmp((*(people + i))->birthday.month, (*(people + i + 1))->birthday.month) > 0) {
				Person * temp;
				temp = (*(people + i));
				*(people + i) = *(people + i + 1);
				*(people + i + 1) = temp;
				i = 0;
			}
			else if (strcmp((*(people + i))->birthday.month, (*(people + i + 1))->birthday.month) == 0) {
				if (strcmp((*(people + i))->birthday.day, (*(people + i + 1))->birthday.day) > 0) {
					Person * temp;
					temp = (*(people + i));
					*(people + i) = *(people + i + 1);
					*(people + i + 1) = temp;
					i = 0;
				}
			}
		}
	}
}