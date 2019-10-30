#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "doublylist.h"

//더블리스트 생성하기 
DoublyListNode* createDoublyList() {
	DoublyList *pReturn = NULL;
	int i = 0;
	pReturn = (DoublyList *)malloc(sizeof(DoublyList));
	if (pReturn != NULL) {
		memset(pReturn, 0, sizeof(DoublyList));

		pReturn->headerNode.pLLink = &(pReturn->headerNode);
		pReturn->headerNode.pRLink = &(pReturn->headerNode);
	}
	else
	{
		printf("오류, 메모리 할당 오류");
		return NULL;
	}

	return pReturn;
}

//더블리스트 노드 추가하기
int addDoublyListElement(DoublyList* pList, int position, DoublyListNode element) {

	//return 과 i 변수 선언 및 이전노드 새노드 선언
	int ret = FALSE, i = 0;
	DoublyListNode *pPreNode = NULL, *pNewNode = NULL;

	//pList 안녕하신지 확인하고 position이 0보다 크고 currentcount 값보다 작은지 유효검사
	if (pList != NULL) {
		if (position >= 0 && position <= pList->currentCount) {
			
			//새노드 메모리 할당 및 초기화 (멤버변수도 다)
			pNewNode = (DoublyListNode*)malloc(sizeof(DoublyListNode));
			//새노드 메모리 할당 잘되었나 검사
			if (pNewNode == NULL) {
				printf("오류 메모리 할당오류");
				return ret;
			}

			*pNewNode = element;
			pNewNode->pLLink = NULL;
			pNewNode->pRLink = NULL;
			
			//이전노드 값 찾으러가자~ 뽀문으로 position 전 값까지! 
			pPreNode = &(pList->headerNode);
			for (i = 0; i < position; i++) {
				pPreNode = pPreNode->pRLink;
			}

			//새노드의 양 링크에 알맞게 값을 대입
			pNewNode->pRLink = pPreNode->pRLink;
			pNewNode->pLLink = pPreNode;

			//이전노드의 오른쪽은 이제 새로운 노드, 새노드의 다음노드의 왼쪽은 새노드로
			pPreNode->pRLink = pNewNode;
			pNewNode->pRLink->pLLink = pNewNode;

			//현재 개수 하나 증가시키고 true 반환
			pList->currentCount++;

			ret = TRUE;

		}
		else
		{
			printf("position값을 잘못 입력했습니다");
		}
	}
	return ret;
}

//더블리리스트 노드 삭제 하기
int removeDoublyListNode(DoublyList* pList, int position) {

	//변수선언하기(ret, i, pPrenNode, pDelNode)
	int ret = FALSE, i = 0; 
	DoublyListNode *pPreNode = NULL, *pDelNode = NULL;

	//pList 멀쩡한지 확인하고 position위치값도 확인하기
	if (pList != NULL) {
		if (position >= 0 && position < pList->currentCount) {
			//이전노드값 찾으러 가기
			pPreNode = &(pList->headerNode);
			for (i = 0; i < position; i++) {
				pPreNode = pPreNode->pRLink;
			}
			//delnode
			pDelNode = pPreNode->pRLink;
			
			//이전노드와 다음노드 설정하기
			pPreNode->pRLink = pDelNode->pRLink;
			pDelNode->pRLink->pLLink = pDelNode;

			//free해주기 currentcount -- 하고 return true
			free(pDelNode);
			pList->currentCount--;
			ret = TRUE;
		}
		else
		{
			printf("position 값이 유효하지 않습니다");
		}
	}
	return ret;
}

//리스트 노드 값 가져오기
DoublyListNode* getDLElement(DoublyList* pList, int position) {
	DoublyListNode* pNode = NULL;
	int i = 0;

	if (pList != NULL) {
		if (position >= 0 && position < pList->currentCount) {
			pNode = pList->headerNode.pRLink;
			for (i = 0; i < position; i++) {
				pNode = pNode->pRLink;
			}
		}
		else
		{
			printf("위치 잘못 입력 하셔씃ㅂ니다");
		}
	}
	return pNode;
}

void displayDoublyList(DoublyList* pList) {
	int i = 0;
	if (pList != NULL) {
		printf("현재 노드의 개수 : %d\n", pList->currentCount);
		for (i = 0; i < pList->currentCount; i++) {
			printf("[%d],%d\n", i, getDLElement(pList, i)->data);
		}
	}
	else
	{
		printf("원소 없습니다");
	}
}