#include <cstdio>

int main() {
   int vt, v1, v2;
   scanf("%d %d %d", &vt, &v1, &v2);
   
   bool possible = false;
   int minTotal = 10000000;
   int minA = 0;
   int minB = 0;
   int a = 0;
   int b = 0;
   int vb = 0;
   
   while (vb >= 0) {
       vb = (vt - (a * v1));
       if ((vb == 0 || vb >= v2) && vb % v2 == 0) {
           b = vb / v2;
           if (a >= 0 && b >= 0 && a + b < minTotal) {
               possible = true;
               minTotal = a + b;
               minA = a;
               minB = b;
           }
       }
       a++;
   }
   
  if (!possible) {
      printf("Impossible\n");
  } else {
       printf("%d %d\n", minA, minB);
  }
    
    return 0;
}