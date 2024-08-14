#ifndef UTILS_H
#define UTILS_H
#define TRUE 1
#define FALSE 0

typedef struct NODE {
  char szData[64];
  struct NODE *pNext;
} NODE;

typedef struct DNODE {
  char szData[64];
  struct DNODE *pPrev;
  struct DNODE *pNext;
} DNODE;
#endif // !UTILS_H
