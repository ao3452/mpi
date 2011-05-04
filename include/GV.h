/* すべてのファイルで呼び出されるヘッダファイル
 * 主にグローバル変数の記述や、関数、定数宣言などのヘッダファイルのインクルードを記述 */


/* 共通ヘッダファイルのインクルード */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* externの簡略化 */
#ifdef GLOBAL_INSTANCE
#define GLOBAL
#else
#define GLOBAL extern 
#endif

/* 自作したヘッダファイルのインクルード */
#include "define.h"		/* 定数宣言 */
#include "function.h"           /* 関数宣言 */

GLOBAL int G_knap_weight_MAX;
GLOBAL int G_knap_number_MAX;
//GLOBAL Goods_Table G_goods_table[TABLE_MAX];
GLOBAL FILE *infile;
GLOBAL Goods_Table G_knap;
GLOBAL char G_knap_in_name[TABLE_MAX][CHAR_MAX];
GLOBAL int G_knap_number;
GLOBAL int G_number;

