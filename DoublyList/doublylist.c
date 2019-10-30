#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "doublylist.h"

//������Ʈ �����ϱ� 
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
		printf("����, �޸� �Ҵ� ����");
		return NULL;
	}

	return pReturn;
}

//������Ʈ ��� �߰��ϱ�
int addDoublyListElement(DoublyList* pList, int position, DoublyListNode element) {

	//return �� i ���� ���� �� ������� ����� ����
	int ret = FALSE, i = 0;
	DoublyListNode *pPreNode = NULL, *pNewNode = NULL;

	//pList �ȳ��Ͻ��� Ȯ���ϰ� position�� 0���� ũ�� currentcount ������ ������ ��ȿ�˻�
	if (pList != NULL) {
		if (position >= 0 && position <= pList->currentCount) {
			
			//����� �޸� �Ҵ� �� �ʱ�ȭ (��������� ��)
			pNewNode = (DoublyListNode*)malloc(sizeof(DoublyListNode));
			//����� �޸� �Ҵ� �ߵǾ��� �˻�
			if (pNewNode == NULL) {
				printf("���� �޸� �Ҵ����");
				return ret;
			}

			*pNewNode = element;
			pNewNode->pLLink = NULL;
			pNewNode->pRLink = NULL;
			
			//������� �� ã��������~ �ǹ����� position �� ������! 
			pPreNode = &(pList->headerNode);
			for (i = 0; i < position; i++) {
				pPreNode = pPreNode->pRLink;
			}

			//������� �� ��ũ�� �˸°� ���� ����
			pNewNode->pRLink = pPreNode->pRLink;
			pNewNode->pLLink = pPreNode;

			//��������� �������� ���� ���ο� ���, ������� ��������� ������ ������
			pPreNode->pRLink = pNewNode;
			pNewNode->pRLink->pLLink = pNewNode;

			//���� ���� �ϳ� ������Ű�� true ��ȯ
			pList->currentCount++;

			ret = TRUE;

		}
		else
		{
			printf("position���� �߸� �Է��߽��ϴ�");
		}
	}
	return ret;
}

//��������Ʈ ��� ���� �ϱ�
int removeDoublyListNode(DoublyList* pList, int position) {

	//���������ϱ�(ret, i, pPrenNode, pDelNode)
	int ret = FALSE, i = 0; 
	DoublyListNode *pPreNode = NULL, *pDelNode = NULL;

	//pList �������� Ȯ���ϰ� position��ġ���� Ȯ���ϱ�
	if (pList != NULL) {
		if (position >= 0 && position < pList->currentCount) {
			//������尪 ã���� ����
			pPreNode = &(pList->headerNode);
			for (i = 0; i < position; i++) {
				pPreNode = pPreNode->pRLink;
			}
			//delnode
			pDelNode = pPreNode->pRLink;
			
			//�������� ������� �����ϱ�
			pPreNode->pRLink = pDelNode->pRLink;
			pDelNode->pRLink->pLLink = pDelNode;

			//free���ֱ� currentcount -- �ϰ� return true
			free(pDelNode);
			pList->currentCount--;
			ret = TRUE;
		}
		else
		{
			printf("position ���� ��ȿ���� �ʽ��ϴ�");
		}
	}
	return ret;
}

//����Ʈ ��� �� ��������
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
			printf("��ġ �߸� �Է� �ϼŝ����ϴ�");
		}
	}
	return pNode;
}

void displayDoublyList(DoublyList* pList) {
	int i = 0;
	if (pList != NULL) {
		printf("���� ����� ���� : %d\n", pList->currentCount);
		for (i = 0; i < pList->currentCount; i++) {
			printf("[%d],%d\n", i, getDLElement(pList, i)->data);
		}
	}
	else
	{
		printf("���� �����ϴ�");
	}
}