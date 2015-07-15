/* DriveMain.cpp -- 测试LoopQueue接口的驱动程序 */
#include <stdio.h>
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include "LoopQueue.h"

int main(int argc, char ** argv)
{
	char ch;
	Data temp;
	Data * deleteElem;
	LoopQueue * queue;
	queue = createLoopQueue(0);	//创建默认大小的队列

	fputs("Testing the Queue interface.Type a to add a value, \n", stdout);
	fputs("type d to delete a value, and type q to quit.\n", stdout);
	while ((ch = getchar()) != 'q'){
		if (ch != 'a' && ch != 'd')
			continue;
		if ('a' == ch){
			printf("integer to add: ");
			scanf_s("%d", &temp.TestNum);
			printf("Putting %d into queue\n", temp.TestNum);
			EnLoopQueue(queue, temp);
		}
		else{
			if (LoopQueueIsEmpty(queue))
				fputs("Nothing to delete!\n", stdout);
			else{
				deleteElem = DeLoopQueue(queue);
				printf("Removing %d from queue\n", deleteElem->TestNum);
			}
		}
		toStringLoopQueue(queue);
		printf("%d items in queue\n", countLoopQueue(queue));
		fputs("Type a to add, d to delete, q to quit: \n", stdout);
	}

	//销毁创建的队列
	destroyLoopQueue(queue);
	fputs("Bye!~\n", stdout);

	_CrtDumpMemoryLeaks();
	return EXIT_SUCCESS;
}
