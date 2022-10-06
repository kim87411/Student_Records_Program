#include<stdio.h>
#include<string.h>
#include<malloc.h>

#define NameString 30
#define SubjectNum 5.0f

typedef struct studentinform {

	char Name[NameString];
	int kor;
	int math;
	int eng;
	int history;
	int social;
	int sum;
	float avg;

}Studentinform;


typedef struct node {

	struct node* next;
	struct node* prev;
	Studentinform student;

}NODE;

void LoadFunction(FILE** p_Load, NODE** p_head, NODE** p_tail, NODE* p_p, Studentinform p_temp, int* p_Count) {
	fopen_s(p_Load, "C:\\Users\\kms41\\Desktop\\save_file\\save_file.bin", "rb");
	if (*p_Load != NULL) {
		while (fread(&p_temp, sizeof(Studentinform), 1, *p_Load) == 1) {
			if (*p_head != NULL) {
				p_p = *p_tail;
				p_p->next = (NODE*)malloc(sizeof(NODE));
				if (p_p->next != NULL) {
					*p_tail = p_p->next;
					memcpy_s(&(*p_tail)->student, sizeof(Studentinform), &p_temp, sizeof(Studentinform));
					(*p_tail)->next = NULL;
					(*p_tail)->prev = p_p;
					*p_Count = (*p_Count) + 1;
					memset(&p_temp, 0, sizeof(p_temp));
				}
				else {
					printf_s("*p_tail->next is NULL!!\n");
				}
			}
			else {
				*p_head = (NODE*)malloc(sizeof(NODE));
				*p_tail = *p_head;

				if (*p_tail != NULL) {
					memcpy_s(&(*p_tail)->student, sizeof(Studentinform), &p_temp, sizeof(Studentinform));
					(*p_tail)->next = NULL;
					(*p_tail)->prev = NULL;
					*p_Count = (*p_Count) + 1;
					memset(&p_temp, 0, sizeof(p_temp));
				}
				else {
					printf_s("*p_tail is NULL!!\n");
				}
			}
		}
		fclose(*p_Load);
		printf_s("\n");
	}
	else {
		printf_s("\n");
	}
}


void InsertStudent(Studentinform* p_temp, int* p_Count) {
	printf_s("\n");
	*p_Count = (*p_Count) + 1;
	printf_s("%d번째 학생 이름 : ", *p_Count);
	if (scanf_s("%s", p_temp->Name, NameString) == 0) {
		rewind(stdin);
	}
	printf_s("국어 성적: ");
	if (scanf_s("%d", &(p_temp->kor)) == 0) {
		rewind(stdin);
	}
	printf_s("수학 성적: ");
	if (scanf_s("%d", &(p_temp->math)) == 0) {
		rewind(stdin);
	}
	printf_s("영어 성적: ");
	if (scanf_s("%d", &(p_temp->eng)) == 0) {
		rewind(stdin);
	}
	printf_s("역사 성적: ");
	if (scanf_s("%d", &(p_temp->history)) == 0) {
		rewind(stdin);
	}
	printf_s("사회 성적: ");
	if (scanf_s("%d", &(p_temp->social)) == 0) {
		rewind(stdin);
	}
	p_temp->sum = p_temp->kor + p_temp->math + p_temp->eng + p_temp->history + p_temp->social;
	p_temp->avg = (float)(p_temp->sum) / SubjectNum;
	printf_s("\n");
}

int NameCheck(Studentinform* p_temp, NODE** p_head, NODE* p_p, int* p_Count) {
	p_p = *p_head;
	if (p_p != NULL) {
		while (p_p != NULL) {
			if (strcmp(p_temp->Name, p_p->student.Name) == 0) {
				*p_Count = (*p_Count) - 1;
				return(0);
			}
			p_p = p_p->next;
		}
	}
	return(1);
}

void StudentAllView(NODE** p_head, NODE* p_p) {

	int i = 1;
	p_p = *p_head;

	if (p_p != NULL) {

		printf_s("\n\n");
		printf_s("=============================================================\n");
		printf_s("  연번  이름  국어  수학  영어  역사  사회  합계     평균\n");
		printf_s("=============================================================\n");
		while (p_p != NULL) {
			printf_s("%4d %8s %3d %5d %5d %5d %5d %6d %11f\n", i++, p_p->student.Name, p_p->student.kor, p_p->student.math,
				p_p->student.eng, p_p->student.history, p_p->student.social, p_p->student.sum, p_p->student.avg);

			p_p = p_p->next;
		}
		printf_s("=============================================================\n");
		printf_s("\n\n");
	}
	else {
		printf_s("\n\n");
		printf_s("입력된 학생이 없습니다.");
		printf_s("\n\n");
	}
}

void StudentView(Studentinform* p_temp, NODE** p_head, NODE* p_p) {
	p_p = *p_head;
	if (p_p != NULL) {
		while (p_p != NULL) {
			if (strcmp(p_temp->Name, p_p->student.Name) == 0) {
				printf_s("=============================================================\n");
				printf_s("  이름  국어  수학  영어  역사  사회  합계     평균\n");
				printf_s("=============================================================\n");
				printf_s("%8s %3d %5d %5d %5d %5d %6d %11f\n", p_p->student.Name, p_p->student.kor, p_p->student.math,
					p_p->student.eng, p_p->student.history, p_p->student.social, p_p->student.sum, p_p->student.avg);
				printf_s("=====================================================\n");
				memset(p_temp, 0, sizeof(Studentinform));
				break;
			}
			else {
				p_p = p_p->next;
			}
		}
		memset(p_temp, 0, sizeof(Studentinform));
	}
	else {
		printf_s("*p_head is NULL!!");
	}
}

void NodePlusFunction(NODE** p_head, NODE** p_tail, NODE* p_p, Studentinform p_temp, int* p_Count) {

	if (*p_head != NULL) {
		p_p = *p_tail;
		p_p->next = (NODE*)malloc(sizeof(NODE));
		if (p_p->next != NULL) {
			*p_tail = p_p->next;
			memcpy_s(&(*p_tail)->student, sizeof(Studentinform), &p_temp, sizeof(Studentinform));
			(*p_tail)->next = NULL;
			(*p_tail)->prev = p_p;
			memset(&p_temp, 0, sizeof(p_temp));
		}
		else {
			printf_s("*p_tail->next is NULL!!\n");
		}
	}
	else {
		*p_head = (NODE*)malloc(sizeof(NODE));
		*p_tail = *p_head;

		if (*p_tail != NULL) {
			memcpy_s(&(*p_tail)->student, sizeof(Studentinform), &p_temp, sizeof(Studentinform));
			(*p_tail)->next = NULL;
			(*p_tail)->prev = NULL;
			memset(&p_temp, 0, sizeof(p_temp));
		}
		else {
			printf_s("*p_tail is NULL!!\n");
		}
	}
}

void SaveFunction(FILE** p_Save, NODE** p_head, NODE* p_p) {
	fopen_s(p_Save, "C:\\Users\\kms41\\Desktop\\save_file\\save_file.bin", "wb");
	if (remove("C:\\Users\\kms41\\Desktop\\save_file\\save_file.bin") == 0) {
		if (*p_Save != NULL) {
			p_p = *p_head;
			while (p_p != NULL) {
				fwrite(&(p_p->student), sizeof(Studentinform), 1, *p_Save);
				p_p = p_p->next;
			}
			fclose(*p_Save);
		}
		else {
			printf_s("\n");
		}
	}
	else {
		if (*p_Save != NULL) {
			p_p = *p_head;
			while (p_p != NULL) {
				fwrite(&(p_p->student), sizeof(Studentinform), 1, *p_Save);
				p_p = p_p->next;
			}
			fclose(*p_Save);
		}
		else {
			printf_s("\n");
		}
	}
}

void RemoveFunction(Studentinform* p_temp, NODE** p_head, NODE** p_tail, NODE* p_p, int* p_Count) {
	p_p = *p_head;
	int n = *p_Count;

	if ((*p_head != NULL) && (*p_tail != NULL) && (p_p != NULL)) {
		while (p_p != NULL) {
			if (strcmp(p_temp->Name, p_p->student.Name) == 0) {
				if (p_p == *p_head) {
					if ((*p_head)->next != NULL) {
						*p_head = p_p->next;
						free(p_p);
						(*p_head)->prev = NULL;
						p_p = NULL;
					}
					else {
						free(p_p);
						p_p = *p_head = NULL;
					}
				}
				else if (p_p == *p_tail) {
					*p_tail = p_p->prev;
					free(p_p);
					(*p_tail)->next = NULL;
				}
				else {
					(p_p->next)->prev = p_p->prev;
					(p_p->prev)->next = p_p->next;
					free(p_p);
					p_p = NULL;
				}
				*p_Count = (*p_Count) - 1;
				break;
			}
			else {
				p_p = p_p->next;
			}
		}

		if (n == *p_Count) {
			printf_s("\n\n찾는 학생이 없습니다.\n\n");
			memset(p_temp, 0, sizeof(Studentinform));
		}
		else {
			printf_s("\n\n찾는 학생을 삭제했습니다.\n\n");
			memset(p_temp, 0, sizeof(Studentinform));
		}


	}
	else {
		printf_s("p_p, *p_head, *p_tail is NULL!!");
	}
}

void NodeDeleteFunction(NODE** p_head, NODE** p_tail, NODE* p_p) {
	if ((*p_head != NULL) && (*p_tail != NULL)) {
		while (*p_head != NULL) {
			p_p = *p_head;
			*p_head = p_p->next;
			free(p_p);
		}
	}
	else {
		*p_head = *p_tail = p_p = NULL;
	}
}


int main(void) {

	FILE* Load = NULL;
	FILE* Save = NULL;

	NODE* head = NULL;
	NODE* tail = NULL;
	NODE* p = NULL;

	int Count = 0;
	int SelectNum = 0;

	Studentinform temp;

	memset(&temp, 0, sizeof(temp));
	LoadFunction(&Load, &head, &tail, p, temp, &Count);

	while (1) {
		printf_s("================\n");
		printf_s("      선  택    \n");
		printf_s("================\n");
		printf_s(" 1. 학생성적입력\n");
		printf_s(" 2. 입력사항확인\n");
		printf_s(" 3. 학생성적찾기\n");
		printf_s(" 4. 특정학생삭제\n");
		printf_s(" 5. 학생성적저장\n");
		printf_s(" 6. 프로그램종료\n");
		printf_s("================\n");
		printf_s(" 번호선택: ");
		if (scanf_s("%d", &SelectNum) == 0) {
			rewind(stdin);
		}
		switch (SelectNum) {
		case 1://학생성적입력
			InsertStudent(&temp, &Count);
			if (NameCheck(&temp, &head, p, &Count) == 1) {
				NodePlusFunction(&head, &tail, p, temp, &Count);
			}
			else {
				printf_s("\n입력된 학생이 존재합니다.\n");
				memset(&temp, 0, sizeof(temp));
			}
			break;

		case 2://입력사항확인
			if (head != NULL) {
				StudentAllView(&head, p);
			}
			else {
				printf_s("\n\n");
				printf_s("입력된 학생이 없습니다.");
				printf_s("\n\n");
			}
			break;

		case 3://학생성적찾기

			if (head != NULL) {
				printf_s("\n찾을 학생이름 입력 :");
				scanf_s("%s", temp.Name, NameString);
				if (NameCheck(&temp, &head, p, &Count) == 0) {
					StudentView(&temp, &head, p);
				}
				else {
					printf_s("\n찾는 학생은 존재하지 않습니다.\n");
				}
			}
			else {
				printf_s("\n\n");
				printf_s("입력된 학생이 없습니다.");
				printf_s("\n\n");
			}

			break;

		case 4://특정학생삭제
			if (head != NULL) {
				printf_s("\n삭제할 학생의 이름: ");
				scanf_s("%s", temp.Name, NameString);
				RemoveFunction(&temp, &head, &tail, p, &Count);
			}
			else {
				printf_s("\n\n");
				printf_s("입력된 학생이 없습니다.");
				printf_s("\n\n");
			}

			break;

		case 5://학생성적저장
			if (head != NULL) {
				SaveFunction(&Save, &head, p);
			}
			else {
				printf_s("\n\n");
				printf_s("입력된 학생이 없습니다.");
				printf_s("\n\n");
			}
			break;

		case 6://프로그램종료
			SaveFunction(&Save, &head, p);
			NodeDeleteFunction(&head, &tail, p);
			break;

		default:
			printf_s("\n\n");
			printf_s("잘못 누르셨습니다.");
			printf_s("\n\n");
		}
		if (SelectNum == 6) {
			break;
		}
	}
	return(0);
}