/* 構造体の宣言 */

/* 荷物表 */
typedef struct _goods_table {
  int  weight;   		/* 重さ */
  int  value;			/* 価値 */
  int  flag;
}Goods_Table;

 
typedef struct __bnode{
  Goods_Table tree_table;
  double value_max;
  struct __bnode *left;
  struct __bnode *right;
}BinNode;


