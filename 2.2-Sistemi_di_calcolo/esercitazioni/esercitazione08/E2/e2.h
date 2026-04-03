#ifndef __E2__
#define __E2__

struct booking {
	char * surname;  
	int places;		 
	char * time;     
	struct booking * next;
};

void getBookingsAfterTime(struct booking ** list, const char * data, int size, const char * time);

#endif