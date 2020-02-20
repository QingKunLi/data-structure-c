
#ifndef __BINTREE_H__
#define __BINTREE_H__

/* 
  二叉搜索树及二叉树的遍历
  二叉搜索树: 
    左子树所有值小于根节点的值, 右子树所有值大于根节点值
 */

typedef int TreeElement;
typedef struct TNode* BinTree;
typedef BinTree Position;

struct TNode {
  TreeElement value;
  BinTree left;
  BinTree right;
};

// 二叉搜索树API
Position Find(BinTree BT, TreeElement item);
Position FindMax(BinTree BT);
Position FindMin(BinTree BT);
BinTree Insert(BinTree BT, TreeElement item);
BinTree Delete(BinTree BT, TreeElement item);


// 二叉树的遍历 (非递归实现)
void PreorderTraversal(BinTree BT);  // 先序遍历
void InorderTraversal(BinTree BT);   // 中序遍历
void PostorderTraversal(BinTree BT); // 后序遍历
void LevelorderTraversal(BinTree BT); // 层序遍历


#endif