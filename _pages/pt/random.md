---
permalink: /pt/ComputationalPhysics/random/
title: "Gerador de números aleatórios"
toc: true
toc_label: "Sumário"
toc_icon: "file-alt"
---

**Aviso**: A notação usada nesta página não é complicada, entretanto você pode não compreender se não entender a notação, portanto recomento que vejas antes [Equações Diferenciais Ordinárias](https://ismaeldamiao.blogspot.com/p/texto-aqui.html) onde explico a notação.


## O gerador de números aleatórios:

Um gerador de números aleatórios é um rotina que gera números pseudo-aleatórios a partir de uma parâmetro de entrada chamado de _semente_. Em geral o número gerado é um número real no intervalo $[0,1)$. O papél da semente é fazer com que o gerador retorne sempre os mesmos números se for iniciado com a mesma semente. Por exemplo, se você executa o gerador duas vezes sendo que na primeira você usou a semente igual a $-1$ e em cada vez obteve, respectivamente, os números $a_1$ e $a_2$ então se você reiniciar a gerador com a mesma semente e executar-lo duas vezes então irá obter novamente os mesmos valores $a_1$ e $a_2$.

Dizemos que os números são pseudo-aleatórios pois na prática é impossível gerar números verdadeiramente aleatórios sem uso de alguma "moeda quântica", entretanto a correlação entre os números gerados por uma bom gerador não é forte o suficiente para interferir em cálculos físicos, o que já nos basta. Apresentarei aqui a rotina _ran1_ retirada do livro _numerical recipes_ com pequenas alterações.

## A rotina ran1:

Usaremos uma variável inteira chamada _semente_ para, adivinhem, guardar a semente. Ao chamar a _ran1_ pela primeira vez em um programa _semente_ deverá ser um valor negativo. _ran1_ irá alterar o valor de _semente_ para um número positivo assim da próxima vez que você chamar _ran1_ ela entenderá que não está sendo inicializada e irá gerar um número aleatório sem correlação com o anterior. Por causa disso acho interessante usar uma variável _semente0_ para a semente propriamente dita e _semente1_ para usar como argumento para _ran1_ onde, no começo, _semente1=semente0_, dessa forma não perdemos a informação da semente que utilizamos para inicializar o gerador.

O número aleatório $p$ gerado tem precisão dupla então não tente guardalo em uma variável inteira sem converter.

Suponha que queremos um número aleatório no intervalo $[x_0, x_1)$ sendo $Dx = x_1-x_0$ o comprimento desse intervalo. O primeiro que fazemos é:

```
p = _ran1_(semente1)
```

Como $p\in[0, 1)$ multiplicamos ele por $Dx$:

```
p = p*Dx
```

Dessa forma temos $p\in[0, Dx)$ e ao subtrair $x_0$ de $p$:

```
p = p-x0
```

Temos, finalmente $p\in[x_0, x_1)$ como queríamos.

## ran1 em C

<button class="btn btn--primary" onclick="Show(sourceC)">ran1.c</button>

<div id="sourceC" style="display: none">
{% highlight c %}
/* *****************************************************************************
Gerador de numeros aleatorios.
"Numerical Recipes in C" (Cambridge Univ. Press)
The Art of Scientific Computing, 2nd Edition, 1992 p 280
by W.H. Press, S.A. Teukolsky, W.T. Vetterling, and B.P. Flannery
***************************************************************************** */

/* *****************************************************************************
Nao usar para gerar mais de 100000000 de numeros, use ran2 ou ran3
double var = ran1(&semente); // Guarda em var um numero aleatorio em [0, 1)
***************************************************************************** */
#define IA 16807
#define IM 2147483647
#define AM (1.0/IM)
#define IQ 127773
#define IR 2836
#define NTAB 32
#define NDIV (1+(IM-1)/NTAB)
#define EPS 1.2e-7
#define RNMX (1.0-EPS)
/* *****************************************************************************
“Minimal” random number generator of Park and Miller with Bays-Durham shuffle
and added safeguards. Returns a uniform random deviate between 0.0 and 1.0
(exclusive of the endpoint values). Call with idum a negative integer to
initialize; thereafter, do not alter idum between successive deviates in a
sequence. RNMX should approximate the largest floating value that is less
than 1.
***************************************************************************** */
double ran1(long int *idum){
   static long int iy=0, iv[NTAB];
   long int j, k;
   double temp;
   if(*idum <= 0 || !iy){ /* Inicialise */
      if (-(*idum) < 1) *idum = 1; /* Garantir que idum != 0 */
      else *idum = -(*idum);
      for(j = NTAB + 7; j >= 0; j--){
         k = (*idum) / IQ;
         *idum = IA * (*idum - k * IQ) - IR * k;
         if(*idum < 0) *idum += IM;
         if(j < NTAB) iv[j] = *idum;
      }
      iy = iv[0];
   }
   k = (*idum) / IQ; /* Comece aqui quando nao inicializado */
   *idum = IA * (*idum - k * IQ) - IR * k;
   if(*idum < 0) *idum += IM;
   j = iy / NDIV;
   iy = iv[j];
   iv[j] = *idum;
   if((temp=AM*iy) > RNMX) return RNMX;
   else return temp;
}
{% endhighlight %}

## ran1 em FORTRAN 90

<div style="text-align: center;">
   Clique em um dos botões abaixo para ver o programa.<br />
       
   <button class="btn btn--primary" onclick="Show(sourceC)">C</button> 
   <button class="btn btn--primary" onclick="Show(sourceF)">Fortran</button>
</div>


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
