#ifndef _DOUBLYLIST_
#define _DOUBLYLIST_

typedef struct DoublyListNodeType
{
	int data;
	struct DoublyListNodeType* pLLink;
	struct DoublyListNodeType* pRLink;
}DoublyListNode;

typedef struct DoublyListType {
	int currentCount;
	DoublyListNode headerNode;
}DoublyList;

//함수리스트
DoublyListNode* createDoublyList();
int addDoublyListElement(DoublyList* pList, int position, DoublyListNode element);
int removeDoublyListNode(DoublyList* pList, int position);
DoublyListNode* getDLElement(DoublyList* pList, int position);
void displayDoublyList(DoublyList* pList);

#endif // !_DOUBLYLIST_

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE		1
#define FALSE		0

#endif // !_COMMON_LIST_DEF_
