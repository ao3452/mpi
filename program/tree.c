#include "../include/GV.h"	/* ヘッダファイル　GVのインクルード */

/* ノードの確保 */
BinNode *AllocNode(void){
  return((BinNode *)calloc(1,sizeof(BinNode)));
}

/* ノードの挿入 */
BinNode *ApndNode(BinNode *p, BinNode *w){
  int cond;

  if(p==NULL){
    p=AllocNode();
    p->tree_table=w->tree_table;
    p->left=p->right=NULL;
  }
  else if((cond=strcmp(w->tree_table.name,p->tree_table.name))==0)
    error("登録済み名前の使用");

  else if (cond < 0) p->left = ApndNode(p->left,w);
  else p->right = ApndNode(p->right,w);
  return p;
}

void SrchNode(BinNode *p, BinNode *w)
{
  int cond;
  if (p == NULL) 
    printf("%s is not registered\n",w->tree_table.name);
  else if((cond = strcmp(w->tree_table.name,p->tree_table.name))==0) 
    printf("%s is registered\n",w->tree_table.name);
  else if (cond < 0)
    SrchNode(p->left,w);
  else
    SrchNode(p->right,w);
}
/* 降順にデータを表示するように変更 */
void PrintTree(BinNode *p)
{
  if (p != NULL) {
//
      PrintTree(p->right);

    printf("%s\n",p->tree_table.name);
//
    PrintTree(p->left);

  }
}

void FreeTree(BinNode *p) 
{
  if (p != NULL) {
    FreeTree(p->left);
    FreeTree(p->right);
    free(p);
  }
}

BinNode Read(char *message)
{
  BinNode temp;
  printf("Please Input name for %s:",message);
  scanf("%s",temp.tree_table.name);
  return (temp);
}
