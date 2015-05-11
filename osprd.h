#ifndef OSPRD_H
#define OSPRD_H

// ioctl constants
#define OSPRDIOCACQUIRE		42
#define OSPRDIOCTRYACQUIRE	43
#define OSPRDIOCRELEASE		44


struct listnode{
	pid_t pid;
	struct listnode* next;
};
struct list{
	struct listnode* head;
	struct listnode* tail;
	int num;
};
#endif


void pushq(struct list* l, pid_t pid)
{
	struct listnode* node = (struct listnode*)kmalloc(sizeof(struct listnode),GFP_ATOMIC);
	node->next = NULL;
	node->pid = pid;
	if(num == 0)
	{
		l->head = l->tail = node;
	}
	else
	{
		l->tail->next = node;
		l->tail = l->tail->next;
	}
	l->num++;
}

int find(struct list* l, pid_t pid, char remove)
{
	struct listnode* curnode = l->head;
	if(l->num == 0)
		return 0;
	if(l->head->pid == pid)
	{
		if(remove == 'r')
		{		
		struct listnode* temp = l->head;
		l->head = l->head->next;
		kfree(l->temp);
		l->num--;
		}
		return 1;
	}
	while(curnode->next != NULL)
	{
		if(curnode->next->pid == pid)
		{
			if(remove == 'r')
			{
				curnode->next = curnode->next->next;
				l->num--;
			}
			return 1;
		}
	}
	return 0;
}