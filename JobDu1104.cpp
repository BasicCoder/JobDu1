#include <stdio.h>
#include <math.h>

int gdc(int a, int b) {
        int r = b;
        while (b != 0) {
                r = a % b;
                a = b;
                b = r;
        }
        return a;
}

int main() {
        int n,a;
        while (scanf("%d%d", &n, &a) != EOF) {
                int k = 0;
                int m = a;
                int pos = 2;
                int acc = pos;
                int t = 2; //m �� pos�����Լ��
                while (pos <= n) {
                        t = gdc(m, acc);
                        if (t == m) {
                                ++k;
                                m = a;
                                acc /= t;
                        } else if (t == acc) {
                                m /= t;
                                acc = ++pos;
                        } else if(t == 1) { //����
                                acc = ++pos;
                        } else {
                                m /= t;
                                acc = ++pos;
                        }
                }
                printf("%d\n", k);
        }
                
        return 0;
}