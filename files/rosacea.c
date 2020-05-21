#include<stdio.h>
#include<math.h>

int main(void){
   double x, y, theta, dt = 0.01;
   FILE *arquivo = fopen("pontos.dat", "w");

   for(theta = 0.0; theta <= 2.0 * M_PI; theta += dt){

      x = 2.0 * cos(2.0 * theta) * cos(theta);
      y = 2.0 * cos(2.0 * theta) * sin(theta);
      fprintf(arquivo, "%g %g\n", x, y);
   }
   fclose(arquivo);
   return 0;
}
