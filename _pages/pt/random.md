---
permalink: /pt/ComputationalPhysics/random/
title: "Gerador de números aleatórios"
toc: true
toc_label: "Sumário"
toc_icon: "file-alt"
---

Um gerador de números aleatórios é um rotina que gera números pseudo-aleatórios a partir de uma parâmetro de entrada chamado de _semente_. Em geral o número gerado é um número real no intervalo $[0,1)$. O papél da semente é fazer com que o gerador retorne sempre os mesmos números se for iniciado com a mesma semente. Por exemplo, se você executa o gerador duas vezes sendo que na primeira você usou a semente igual a $-1$ e em cada vez obteve, respectivamente, os números $a_1$ e $a_2$ então se você reiniciar a gerador com a mesma semente e executar-lo duas vezes então irá obter novamente os mesmos valores $a_1$ e $a_2$.

Dizemos que os números são pseudo-aleatórios pois na prática é impossível gerar números verdadeiramente aleatórios sem uso de alguma "moeda quântica", entretanto a correlação entre os números gerados por uma bom gerador não é forte o suficiente para interferir em cálculos físicos, o que já nos basta. Apresentarei aqui a rotina _ran1_ retirada do livro _numerical recipes_ com pequenas alterações.

## A rotina ran1:

Usaremos uma variável inteira chamada `semente` para, adivinhem, guardar a semente. Ao chamar a `ran1` pela primeira vez em um programa, `semente` deverá ser um valor negativo. `ran1` irá alterar o valor de `semente` para um número positivo assim da próxima vez que você chamar `ran1` ela entenderá que não está sendo inicializada e irá gerar um número aleatório sem correlação com o anterior. Por causa disso acho interessante usar uma variável `semente0` para a semente propriamente dita e `semente1` para usar como argumento para `ran1` onde, no começo, `semente1=semente0` dessa forma não perdemos a informação da semente que utilizamos para inicializar o gerador.

O número aleatório `p` gerado tem precisão dupla então não tente guardalo em uma variável inteira sem converter.

Suponha que queremos guardar na variável de precisão dupla `p` um número aleatório no intervalo $[x_0, x_1)$, para isso faça:

* 
```
p = ran1(semente1)
```
* Como $p\in[0, 1)$ multiplicamos ele pelo comprimento do intervalo:
```
p = p*(x1-x0)
```
* Dessa forma temos $p\in[0, x_1-x_0)$. Agora some $x_0$ a $p$:
```
p = p+x0
```
Temos, finalmente, $p\in[x_0, x_1)$ como queríamos.
* De forma mais reduzida, pode-se fazer tudo em um cálculo só quando se chama o gerador, da forma:
```
p = ran1(semente1) * (x1-x0) + x0
```

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
</div>

Usar a `ran1` em `c` é fácil. Simplesmente faça:

* No diretório do seu programa em `c` baixe o arquivo [ran1.c](https://github.com/ismaeldamiao/avulsos/raw/master/c/rotinas/ran1.c) digitando no terminal
```bash
wget -O ran1.c https://github.com/ismaeldamiao/avulsos/raw/master/c/rotinas/ran1.c
```
* Utilize a seguinte macro, ela irá incluir a funcão `double ran1(long int *)` no seu programa:
```c
#include "ran1.c"
```
* Declare uma variável `long int` para guardar a semente, que inicialmente deve ser negativa, por exemplo:
```c
long int semente = -1L;
```
* Chame a função `ran1` quantas vezes quiser, lembrando de indicar a região da memória da semente, por exemplo:
```c
double aleatorio = ran1(&semente);
```
* Compile seu programa normalmente.

## ran1 em FORTRAN 90

<button class="btn btn--primary" onclick="Show(sourceF)">ran1.f90</button>

<div id="sourceF" style="display: none">
{% highlight fortran %}
! Gerador de numeros aleatorios.
! Adaptado ao Fortran 90 por SANTOS. I.F.F. (Ismael Damião)
! https://ismaeldamiao.github.io/
! "Numerical Recipes in Fortran 77" (Cambridge Univ. Press)
! The Art of Scientific Computing, 2nd Edition, 1992 p 271
! by W.H. Press, S.A. Teukolsky, W.T. Vetterling, and B.P. Flannery

! Nao usar para gerar mais de 100000000 de numeros, use ran2 ou ran3
! double var = ran1(&semente); // Guarda em var um numero aleatorio em [0, 1)

! “Minimal” random number generator of Park and Miller with Bays-Durham shuffle
! and added safeguards. Returns a uniform random deviate between 0.0 and 1.0
! (exclusive of the endpoint values). Call with idum a negative integer to
! initialize; thereafter, do not alter idum between successive deviates in a
! sequence. RNMX should approximate the largest floating value that is less
! than 1.
REAL(8) FUNCTION ran1(idum)
   INTEGER(8), PARAMETER :: IA = 16807, IM = 2147483647, IQ = 127773,&
   NTAB = 32, NDIV = 1+(IM-1)/NTAB, IR = 2836
   REAL(8), PARAMETER :: AM = 1.0d0/IM, EPS = 1.2d-7, RNMX = 1.0d0-EPS
   INTEGER(8), intent(inout) :: idum
   INTEGER(8) :: j, k
   INTEGER(8), SAVE :: iy = 0, iv(NTAB)

   IF((idum.le.0) .or. (iy.eq.0)) THEN
      idum = MAX(-idum, 1)
      DO j = NTAB+8, 1, -1
         k = idum / IQ
         idum = IA*(idum-k*IQ)-IR*k
         IF(idum .lt. 0) idum = idum + IM
         IF(j .le. NTAB) iv(j) = idum
      ENDDO
      iy=iv(1)
   ENDIF
   k = idum/IQ
   idum = IA*(idum-k*IQ)-IR*k
   IF(idum.lt.0) idum = idum+IM
   j = 1 + iy/NDIV
   iy = iv(j)
   iv(j) = idum
   ran1 = MIN(AM*iy, RNMX)
   return
END FUNCTION ran1
{% endhighlight %}
</div>

Use o comando abaixo para descarregar o arquivo [ran1.f90](https://github.com/ismaeldamiao/avulsos/raw/master/fortran/rotinas/ran1.f90)

```
wget -O ran1.f90 https://github.com/ismaeldamiao/avulsos/raw/master/fortran/rotinas/ran1.f90
```

Para usar lembre-se de "usar" o módulo _ran_ do seguinte jeito:
{% highlight fortran %}
USE ran
{% endhighlight %}

Para compilar use o comando abaixo:
```
gfortran ran1.f90 SeuPrograma.f90 -o a.out
```

De maneira alternativa você pode copiar toda a função ran1 do arquivo [ran1.f90](https://github.com/ismaeldamiao/avulsos/raw/master/fortran/rotinas/ran1.f90) e colar no final do seu programa, mais ou menos assim:
{% highlight fortran %}
PROGRAM SeuPrograma
! Seu codigo
CONTAINS
   REAL(8) FUNCTION ran1(idum)
   ! ...
   END FUNCTION ran1
END PROGRAM SeuPrograma
{% endhighlight %}

Dessa forma você só precisa compilar o seu programa:
```
gfortran SeuPrograma.f90 -o a.out
```
