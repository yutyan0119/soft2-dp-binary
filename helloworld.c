#include <stdio.h>

int main(void)
{
    float f[4];
    
    // 以下に適切な値を設定する
    f[0] = 1143139122437582505939828736.000000;
    f[1] = 176112701276160.000000;
    f[2] = 17446709643352771395584.000000;
    f[3] = 1.4013e-44;
    
    // "Hello,World\n" と出力してほしい
    printf("%s",(char*)f);
    return 0;
}
