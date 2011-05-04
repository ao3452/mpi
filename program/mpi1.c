#define GLOBAL_INSTANCE 	/* メインプログラム */
#include "../include/GV.h"	/* ヘッダファイル　GVのインクルード */

/* メイン関数 */
int main(int argc, char *argv[]){
  /* ファイル読み込み時に使用 */
  char weight_char[10];
  char value_char[10];

  /* グローバル変数の初期化 */
  first_init();

  fprintf(stderr,"Simple compiler: compile start.\n");
  if(argc != 2){
    fprintf(stderr,"USAGE: comp source-file-name\n");
    exit(1);
  }
  if(( infile = fopen(argv[1],"r")) == NULL){
    fprintf(stderr,"Source gile %s can't open.\n",argv[1]);
    exit(1);
  }

  /* ファイルからの読み込み */
  while(fscanf(infile,"%s %s %s",G_goods_table[G_number].name,weight_char,value_char)!=EOF){
    G_goods_table[G_number].weight=atoi(weight_char);
    G_goods_table[G_number].value=atoi(value_char);
      printf("%s %d %d\n",G_goods_table[G_number].name,G_goods_table[G_number].weight,G_goods_table[G_number].value);
    G_number++;
  }
  printf("\n");

  knapsack_program();

  fclose(infile);
  return(0);
}

/* ナップザック問題を解くプログラム　主にknap_check関数を実行して表示する */
void knapsack_program(void){
  int i;
  for(i=0;i<G_number;i++)
    knap_check();
  for(i=0;i<G_knap_number;i++)
    printf("%s\n",G_knap_in_name[i]);
  printf("value = %d\n",G_knap.value);
  printf("weight = %d\n",G_knap.weight);
}

/* グローバル変数初期化関数 */
void first_init(void){
  int i;
  for(i=0;i<TABLE_MAX;i++){
    G_goods_table[i].weight=0;
    G_goods_table[i].value=0;
    G_goods_table[i].flag=OFF;
  }
  G_knap.weight=KNAP_WEIGHT_MAX;
  G_knap.value=0;
  G_knap_number=0;
  G_number=0;
}

/*  ナップザック問題の肝となる部分　価値/重さの高い順から入れ、
 * 全てを評価しないのが特徴だが、うまく動かない部分あり  */
void knap_check(){
  int i,ret=0,weight=0,flag=0;
  double tmp=0,value_max=0;
  for(i=0;i<G_number;i++){
    while(G_goods_table[i].flag==ON)
      i++;
    if(G_goods_table[i].weight==0)
      break;
    if(value_max<=(tmp=G_goods_table[i].value/G_goods_table[i].weight)){
      if(value_max==tmp){
	if(G_goods_table[i].weight<G_goods_table[ret].weight){
	  value_max=tmp;
	  ret=i;
	  flag=1;
	}
      }
      else{
	  value_max=tmp;
	  ret=i;
	  flag=1;
      }
    }
  }

  if((weight=G_knap.weight-G_goods_table[ret].weight)>=0&&flag==1){
    G_knap.weight=weight;
    G_knap.value+=G_goods_table[ret].value;
    strcpy(G_knap_in_name[G_knap_number++],G_goods_table[ret].name);
    G_goods_table[ret].flag=ON;
  }


}
