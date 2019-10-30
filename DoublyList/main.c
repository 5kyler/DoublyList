#include <stdio.h>
#include <stdlib.h>
#include "doublylist.h"

int main(int argc, char *argv[]) {
	int i = 0;
	int arrayCount = 0;
	DoublyList *pList = NULL;
	DoublyListNode *pValue = NULL;
	DoublyListNode node = { 0, };

	pList = createDoublyList(6);
	if (pList != NULL) {
		node.data = 1;
		addDoublyListElement(pList, 0, node);
		node.data = 3;
		addDoublyListElement(pList, 1, node);
		

		removeDoublyListNode(pList, 0);
		displayDoublyList(pList);
	}
	return 0;
}