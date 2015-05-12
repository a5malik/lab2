#ifndef OSPRD_H
#define OSPRD_H

// ioctl constants
#define OSPRDIOCACQUIRE		42
#define OSPRDIOCTRYACQUIRE	43
#define OSPRDIOCRELEASE		44


struct listnode{
	pid_t pid;
	unsigned int ticket;
	struct listnode* next;
};
struct list{
	struct listnode* head;
	struct listnode* tail;
	int num;
};
#endif


