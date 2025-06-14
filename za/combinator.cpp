const int p = 1e9+7;
int c[1005][1005];
void init(){
    for (int i = 0;i <= 1000;i++){
        for(int j = 0;j <= i;j++){
            c[i][j] = (j == 0 || j == i ?1:c[i-1][j]+c[i-1][j-1]);
            c[i][j]%=p;
        }
    }
}