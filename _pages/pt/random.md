---
permalink: /pt/ComputationalPhysics/random/
title: "Gerador de números aleatórios"
toc: true
toc_label: "Sumário"
toc_icon: "file-alt"
---

**Aviso**: A notação usada nesta página não é complicada, entretanto você pode não compreender se não entender a notação, portanto recomento que vejas antes [Equações Diferenciais Ordinárias](https://ismaeldamiao.blogspot.com/p/texto-aqui.html) onde explico a notação.


## O gerador de números aleatórios:

Um gerador de números aleatórios é um rotina que gera números pseudo-aleatórios a partir de uma parâmetro de entrada chamado de _semente_. Em geral o número gerado é um número real no intervalo $[0,1)$. O papél da semente é fazer com que o gerador retorne sempre os mesmos números se for iniciado com a mesma semente. Por exemplo, se você executa o gerador duas vezes sendo que na primeira você usou a $-1$ e em cada vez obteve, respectivamente, os números $a_1$ e $a_2$ então se você reiniciar a gerador com a mesma semente e executar-lo duas vezes então irá obter novamente os mesmos valores $a_1$ e $a_2$.

Dizemos que os números são pseudo-aleatórios por na prática é impossível gerar números verdadeiramente aleatórios sem uso de alguma "moeda quântica", entretanto a correlação entre os números gerados por uma bom gerador não é forte o suficiente para interferir em cálculos físicos, o que já nos basta. Apresentarei aqui a rotina _ran1_ retirada do livro _numerical recipes_ com pequenas alterações.

## ran1 em C

<button class="btn btn--primary" onclick="Show(sourceC)">C</button>

a

<div style="text-align: center;"><button class="btn btn--primary" onclick="Show(sourceC)">C</button></div>

## ran1 em FORTRAN 90

<div style="text-align: center;">
   Clique em um dos botões abaixo para ver o programa.<br />
       
   <button class="btn btn--primary" onclick="Show(sourceC)">C</button> 
   <button class="btn btn--primary" onclick="Show(sourceF)">Fortran</button>
</div>

<div id="sourceC" style="display: none">
{% highlight c %}
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
{% endhighlight %}
</div>
<div id="sourceF" style="display: none">
{% highlight fortran %}
PROGRAM plotar

   IMPLICIT none
   REAL(8) :: x, y, theta = 0.0d0, dt = 0.01d0
   INTEGER, PARAMETER :: arquivo = 10

   OPEN(arquivo, FILE="pontos.dat")

   DO; IF(theta > 2.0d0 * 3.1415d0) EXIT

      x = 2.0d0 * cos(2.0d0 * theta) * cos(theta)
      y = 2.0d0 * cos(2.0d0 * theta) * sin(theta)
      WRITE(arquivo, FMT=*) x, y
      theta = theta + dt

   END DO

   CLOSE(arquivo)

END PROGRAM plotar
{% endhighlight %}
</div>
