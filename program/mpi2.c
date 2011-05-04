#define GLOBAL_INSTANCE 	/* メインプログラム */
#include "../include/GV.h"	/* ヘッダファイル　GVのインクルード */

/* メイン関数 */
int main(int argc, char *argv[]){
  /* ファイル読み込み時に使用 */
  char weight_char[10];
  char value_char[10];

  /* グローバル変数の初期化 */
  //  first_init();

  if(argc != 2){
    fprintf(stderr,"USAGE: comp source-file-name\n");
    exit(1);
  }
  if(( infile = fopen(argv[1],"r")) == NULL){
    fprintf(stderr,"Source gile %s can't open.\n",argv[1]);
    exit(1);
  }
  fscanf(infile,"%s",weight_char);
  fscanf(infile,"%s",value_char);
  G_knap_weight_MAX=atoi(weight_char);
  G_knap_number_MAX=atoi(value_char);
  /* ファイルからの読み込み */

  knapsack_program();

  fclose(infile);
  return(0);
}

/* void load(void){
 *   char weight_char[10];
 *   char value_char[10];
 *   while(fscanf(infile,"%s %s",weight_char,value_char)!=EOF){
 *     G_goods_table[G_number].weight=atoi(weight_char);
 *     G_goods_table[G_number].value=atoi(value_char);
 *       printf("%d %d\n",G_goods_table[G_number].weight,G_goods_table[G_number].value);
 *     G_number++;
 *   }
 * } */

/* ナップザック問題を解くプログラム　主にknap_check関数を実行して表示する */
void knapsack_program(void){
  int i,w,maxValue=0;
  //ret=0,weight=0,flag=0,maxValue=0;
  //  double tmp=0,value_max=0;
  Goods_Table G_goods_table[G_knap_number_MAX+1];
  char weight_char[10];
  char value_char[10];
  int C[G_knap_number_MAX+1][G_knap_weight_MAX+1];
  int G[G_knap_number_MAX+1][G_knap_weight_MAX+1];

  for(i=0;i<G_knap_number_MAX;i++){
    G_goods_table[i].weight=0;
    G_goods_table[i].value=0;
    G_goods_table[i].flag=OFF;
  }
  for ( i = 0; i <= G_knap_weight_MAX; i++ ) {
    C[0][i] = 0;
    G[0][i] = 1;
  }
  for (i = 1; i <= G_knap_number_MAX; i++ ) C[i][0] = 0;

  G_knap.weight=0;
  G_knap.value=0;
  G_knap_number=0;
  G_number=0;
  while(fscanf(infile,"%s %s",weight_char,value_char)!=EOF){
    G_goods_table[G_number+1].weight=atoi(weight_char);
    G_goods_table[G_number+1].value=atoi(value_char);
    //   printf("%d %d\n",G_goods_table[G_number+1].weight,G_goods_table[G_number+1].value);
    G_number++;
  }
  G_number=0;
  //  printf("\n");
  printf("%d %d\n",G_knap_weight_MAX,G_knap_number_MAX);

  for (i = 1; i <= G_knap_number_MAX; i++ ){
    for (w = 1; w <= G_knap_weight_MAX; w++ ){
      if ( G_goods_table[i].weight <= w ){
	if ( G_goods_table[i].value + C[i-1][w - G_goods_table[i].weight] > C[i-1][w] ){
	  C[i][w] = G_goods_table[i].value + C[i-1][w - G_goods_table[i].weight];
	  G[i][w] = 1;
	  G_number++;
	}else{
	  C[i][w] = C[i-1][w];
	  G[i][w] = 0;
	}
      }else {
	C[i][w] = C[i-1][w];
	G[i][w] = 0;
      }
    }
  }

  maxValue = C[G_knap_number_MAX][G_knap_weight_MAX];

  w = G_knap_weight_MAX;
  /* int path[G_number];
   * for(i=0;i<G_number;i++) path[i]=0;
   * 
   * j=0;
   * for ( i = G_knap_number_MAX; i >=1; i-- ){
   *     if ( G[i][w] == 1 ){
   * 	path[j++]=i;
   * 	w -= G_goods_table[i].weight;
   *     }
   * }
   * printf("%d\n",w);
   * for ( i = 0; i < j; i++ ) printf("%d ",path[i]); */
  
  printf("\n");
  printf("MAX = %d\n",maxValue);


  /* for(j=0;j<G_knap_number_MAX;j++){
   *   for(i=0;i<G_knap_number_MAX;i++){
   *     while(G_goods_table[i].flag==ON)
   * 	i++;
   *     if(G_goods_table[i].weight==0)
   * 	break;
   *     if(value_max<=(tmp=G_goods_table[i].value/G_goods_table[i].weight)){
   * 	if(value_max==tmp){
   * 	  if(G_goods_table[i].weight<G_goods_table[ret].weight){
   * 	    value_max=tmp;
   * 	    ret=i;
   * 	    flag=1;
   * 	  }
   * 	}
   * 	else{
   * 	  value_max=tmp;
   * 	  ret=i;
   * 	  flag=1;
   * 	}
   *     }
   *   }
   * 
   *   if((weight=G_knap.weight+G_goods_table[ret].weight)<=G_knap_weight_MAX&&flag==1){
   *     printf("%d %d\n",G_goods_table[ret].value,G_goods_table[ret].weight);
   *     G_knap.weight=weight;
   *     G_knap.value+=G_goods_table[ret].value;
   *     G_goods_table[ret].flag=ON;
   *   }
   *   ret=0;
   *   flag=0;
   *   tmp=0;
   *   value_max=0;
   * }
   * printf("value = %d\n",G_knap.value);
   * printf("weight = %d\n",G_knap.weight); */
}

/* /\* グローバル変数初期化関数 *\/
 * void first_init(void){
 *   int i;
 *   for(i=0;i<TABLE_MAX;i++){
 *     G_goods_table[i].weight=0;
 *     G_goods_table[i].value=0;
 *     G_goods_table[i].flag=OFF;
 *   }
 *   G_knap.weight=KNAP_WEIGHT_MAX;
 *   G_knap.value=0;
 *   G_knap_number=0;
 *   G_number=0;
 * } */

/* /\*  ナップザック問題の肝となる部分　価値/重さの高い順から入れ、
 *  * 全てを評価しないのが特徴だが、うまく動かない部分あり  *\/
 * void knap_check(){
 *   int i,ret=0,weight=0,flag=0;
 *   double tmp=0,value_max=0;
 *   for(i=0;i<G_number;i++){
 *     while(G_goods_table[i].flag==ON)
 *       i++;
 *     if(G_goods_table[i].weight==0)
 *       break;
 *     if(value_max<=(tmp=G_goods_table[i].value/G_goods_table[i].weight)){
 *       if(value_max==tmp){
 * 	if(G_goods_table[i].weight<G_goods_table[ret].weight){
 * 	  value_max=tmp;
 * 	  ret=i;
 * 	  flag=1;
 * 	}
 *       }
 *       else{
 * 	  value_max=tmp;
 * 	  ret=i;
 * 	  flag=1;
 *       }
 *     }
 *   }
 * 
 *   if((weight=G_knap.weight-G_goods_table[ret].weight)>=0&&flag==1){
 *     G_knap.weight=weight;
 *     G_knap.value+=G_goods_table[ret].value;
 *     printf("%d %d\n",G_goods_table[ret].value,G_goods_table[ret].weight);
 *     G_goods_table[ret].flag=ON;
 *   }
 * 
 * } */

/* エラー出力用 */
void error(char *s){
  fprintf(stderr,"%s\n", s);
  exit(1);
}

  /* デバッグ用 */
void debug(char *dg){
#ifdef DEBUG
  printf("%s\n",dg);
#endif
}


/* void debug2(){
 * #ifdef DEBUG
 *   printf("%d  %d\n",tok.attr,tok.value);
 * #endif
 * 
 * } */
