#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
  FILE *fo;
  char *fname;
  int i;
  float star[500][4];//[i][0]=x0,[i][1]=y0,[i][2]=vx,[i][3]=vy;
  static float H = 3.5;
  static int org = 50;
  static float dt = 0.1;
  static int nk = 40;
  fname="data.csv";
  srand(991);
  if( (fo=fopen(fname,"w")) == NULL ){
    printf("File[%s] dose not open!! ¥n",fname);
    exit(0);
  }
  for(i  = 0; i < 500; i++){
    star[i][0] = -5.0+(10.0*rand()/RAND_MAX);
    star[i][1] = -5.0+(10.0*rand()/RAND_MAX);
    if(star[i][0]*star[i][0]+star[i][1]*star[i][1]>=25.0){
      i--;
    }
  }
  for(i = 0; i < 500; i++){
    star[i][2]=star[i][0]*H;
    star[i][0]+=(float)org;
    star[i][3]=star[i][1]*H;
    star[i][1]+=(float)org;
    fprintf(fo,"%f,%f\n", star[i][0],star[i][1]);
  }
  fprintf(fo,"\n");
  for(i = 0; i < nk; i++){
    for(int j = 0; j < 500; j++){
      star[j][0]+=star[j][2]*dt;
      star[j][1]+=star[j][3]*dt;
    }
  }
  for(i = 0; i < 500; i++)fprintf(fo,"%f,%f\n", star[i][0],star[i][1]);
}
