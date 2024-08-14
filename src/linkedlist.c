#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

NODE *g_pHead = NULL;

int print_list(void) {
  printf("===[ print_list ]===\n");

  NODE *pTmp = g_pHead;

  while (pTmp != NULL) {
    printf("NODE[%p], %s\n", pTmp, pTmp->szData);
    pTmp = pTmp->pNext;
  }

  return 0;
}

int release_list(void) {
  printf("===[ release ]===\n");

  NODE *pTmp = g_pHead;
  NODE *pDelete;

  while (pTmp != NULL) {
    printf("NODE[%p], %s\n", pTmp, pTmp->szData);
    pDelete = pTmp;
    pTmp = pTmp->pNext;
    free(pDelete);
  }

  return 0;
}

int insert_new_node(const char *szData) {
  NODE *pNew = (NODE *)malloc(sizeof(NODE));
  memset(pNew->szData, 0, sizeof(pNew->szData));
  strlcpy(pNew->szData, szData, sizeof(pNew->szData));

  // insert to the head.
  if (g_pHead != NULL)
    pNew->pNext = g_pHead;

  g_pHead = pNew;

  return 0;
}

int linkedlist(void) {
  NODE *blue = (NODE *)malloc(sizeof(NODE));
  strlcpy(blue->szData, "blue", sizeof(blue->szData));
  g_pHead = blue;

  NODE *yellow = (NODE *)malloc(sizeof(NODE));
  strlcpy(yellow->szData, "yellow", sizeof(yellow->szData));
  blue->pNext = yellow;

  NODE *red = (NODE *)malloc(sizeof(NODE));
  strlcpy(red->szData, "red", sizeof(red->szData));
  yellow->pNext = red;

  print_list();
  release_list();

  return 0;
}

// 순환,원형 리스트
int circular_list(void) {
  NODE *blue = (NODE *)malloc(sizeof(NODE));
  strlcpy(blue->szData, "blue", sizeof(blue->szData));
  g_pHead = blue;

  NODE *yellow = (NODE *)malloc(sizeof(NODE));
  strlcpy(yellow->szData, "yellow", sizeof(yellow->szData));
  blue->pNext = yellow;

  NODE *red = (NODE *)malloc(sizeof(NODE));
  strlcpy(red->szData, "red", sizeof(red->szData));
  yellow->pNext = red;
  // NOTE: only
  red->pNext = blue;

  return 0;
}
