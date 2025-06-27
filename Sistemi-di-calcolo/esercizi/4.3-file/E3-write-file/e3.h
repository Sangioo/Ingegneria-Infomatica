#ifndef __E3__
#define __E3__

typedef struct student {
	char surname[20]; 
	char name[20];
	int mark;
	struct student * next;
} student;

int getStudents(const char * filename, student * in_list, int min_mark);

#endif