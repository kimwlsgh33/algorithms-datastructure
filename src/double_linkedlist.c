#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

DNODE *g_pHead;
DNODE *g_pTail;

int init_dlist(void) {
  g_pHead = (DNODE *)malloc(sizeof(DNODE));
  g_pTail = (DNODE *)malloc(sizeof(DNODE));

  memset(g_pHead, 0, sizeof(DNODE));
  memset(g_pTail, 0, sizeof(DNODE));

  strlcpy(g_pHead->szData, "DUMMY HEAD", sizeof(g_pHead->szData));
  strlcpy(g_pTail->szData, "DUMMY TAIL", sizeof(g_pTail->szData));

  g_pHead->pNext = g_pTail;
  g_pTail->pPrev = g_pHead;

  return 0;
}

int release_dlist(void) {
  printf("===[ release_dlist ]===\n");
  DNODE *pTmp = g_pHead;
  DNODE *pDelete;

  while (pTmp != NULL) {
    pDelete = pTmp;
    printf("Delete [%p], '%s'\n", pDelete, pDelete->szData);
    pTmp = pTmp->pNext;
    free(pDelete);
  }

  return 0;
}

DNODE *insert_at_head(const char *szData) {
  printf("===[ insert_at_head ]===\n");
  DNODE *pNew = (DNODE *)malloc(sizeof(DNODE));
  memset(pNew, 0, sizeof(DNODE));
  strlcpy(pNew->szData, szData, sizeof(pNew->szData));

  pNew->pPrev = g_pHead;
  pNew->pNext = g_pHead->pNext;

  g_pHead->pNext->pPrev = pNew;
  g_pHead->pNext = pNew;

  printf("'%s' inserted.\n", pNew->szData);
  return pNew;
}

DNODE *insert_at_tail(const char *szData) {
  printf("===[ insert_at_tail ]===\n");
  DNODE *pNew = (DNODE *)malloc(sizeof(DNODE));
  memset(pNew, 0, sizeof(DNODE));
  strlcpy(pNew->szData, szData, sizeof(pNew->szData));

  pNew->pNext = g_pTail;
  pNew->pPrev = g_pTail->pPrev;
  g_pTail->pPrev->pNext = pNew;
  g_pTail->pPrev = pNew;
  printf("'%s' inserted.\n", pNew->szData);

  return pNew;
}

int delete_node(const char *szData) {
  printf("===[ delete_node ]===\n");
  DNODE *pTmp = g_pHead->pNext;
  while (pTmp != g_pTail) {
    if (strcmp(pTmp->szData, szData) == 0) {
      DNODE *pDelete = pTmp;
      pDelete->pPrev->pNext = pDelete->pNext;
      pDelete->pNext->pPrev = pDelete->pPrev;
      printf("Delete [%p], '%s'\n", pDelete, pDelete->szData);
      free(pDelete);

      return 1;
    }
    pTmp = pTmp->pNext;
  }
  return 0;
}

int print_dlist_from_head(void) {
  printf("===[ print_dlist_from_head ]===\n");

  DNODE *pTmp = g_pHead;

  while (pTmp != NULL) {
    printf("DNODE[%p], %s\n", pTmp, pTmp->szData);
    pTmp = pTmp->pNext;
  }

  return 0;
}

int print_dlist_from_tail(void) {
  printf("===[ print_dlist_from_tail ]===\n");

  DNODE *pTmp = g_pTail;

  while (pTmp != NULL) {
    printf("DNODE[%p], %s\n", pTmp, pTmp->szData);
    pTmp = pTmp->pPrev;
  }

  return 0;
}

int double_linkedlist(void) {
  init_dlist();

  DNODE *blue = insert_at_head("blue");
  /* printf("The blue node: [%p], '%s'\n", blue, blue->szData); */

  DNODE *yellow = insert_at_head("yellow");
  DNODE *red = insert_at_head("red");

  /* DNODE *blue = insert_at_tail("blue"); */
  /* DNODE *yellow = insert_at_tail("yellow"); */
  /* DNODE *red = insert_at_tail("red"); */

  print_dlist_from_head();
  delete_node("yellow");
  print_dlist_from_tail();

  release_dlist();

  return 0;
}
