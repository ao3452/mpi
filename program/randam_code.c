#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


#define RANDAM_WEIGHT_MAX 1000
#define RANDAM_VALUE_MAX 1000
#define RANDAM_NUMBER 1000

#define RAND(a, b) ((a) + ((b) - (a) + 1) * (rand() / (RAND_MAX + 1.0)))

void passwrd(char *s, int n, int m){
  int i,a;
  const char c[] = "abcdefghijklmnopqrstuvwxyz";
  a=(int)RAND(m,n);
  for(i = 0; i < a; i ++) {
    s[i] = c[(int)RAND(0, strlen(c) - 1)];
  }
    s[i]='\0';
}

int main(void){
  int i;
  //  char s[20][11];
  FILE *outfile;
  if(( outfile = fopen("KNAP.txt","w")) == NULL){
    fprintf(stderr,"Object file creation failed.\n");
    exit(1);
  }
  fprintf(outfile,"%d\n",RANDAM_WEIGHT_MAX); 
  fprintf(outfile,"%d\n",RANDAM_NUMBER); 
  srand((unsigned)time(NULL));
  for(i = 0; i < RANDAM_NUMBER; i ++){
    /* passwrd(s[i], 10, 4); */
    /* fprintf(outfile,"%s %d %d\n", s[i], (int)RAND(1,RANDAM_WEIGHT_MAX),(int)RAND(0,RANDAM_VALUE_MAX)); */
    fprintf(outfile,"%d %d\n",(int)RAND(100,RANDAM_WEIGHT_MAX),(int)RAND(300,RANDAM_VALUE_MAX)); 
  }
  fclose(outfile);
  return 0;
}
