
#include <stdio.h>
#include "bintree.h"

int main() {
  BinTree BT = NULL;
  int number[] = {3, 4, 1, 2, 5};
  for (int i = 0; i < 5; i++) {
    BT = Insert(BT, number[i]);
  }
  PreorderTraversal(BT);
  InorderTraversal(BT);
  PostorderTraversal(BT);
  LevelorderTraversal(BT);
  return 0;
}