---
permalink: /pt/ComputationalPhysics/FunctionData/
title: "Usando c e Fortran para calcular o valor de uma função"
toc: true
toc_label: "Sumário"
toc_icon: "file-alt"
---

Entender o que vou ensinar nesta página pode ser difícil se você não não sabe o que é umarquivo de dados e como plotar um gráfico com base nesse arquivo. Nesse caso, recomendo que antes vejas [essa página](/ComputationalPhysics/gnuplot/).

## Pontos no plano

Plotar gráficos é uma tarefa bastante simples!

Tudo o que você precisa fazer é encontrar o valor de uma determinada função em diferentes pontos.

Trabalharemos com o plano cartesiano, nesse plano todos os ponto podem ser descritos em termos de $x$ e $y$ da forma:

$$
\begin{bmatrix}
x \\ y
\end{bmatrix}
$$

Em geral, as coordenadas $x$ e $y$ podem ser descritas por leis escritas em termos de um ou mais parâmetros. No caso de 1 parâmetro temos:

$$
\begin{bmatrix}
x \\ y
\end{bmatrix} =
\begin{bmatrix}
x(t) \\ y(t)
\end{bmatrix}
$$

Um exemplo comum é $x(t)=t$ e $y(t)=t^2$, essa curva é conhecida com parábola e é uma das primeiras que aprendemos, nela todos os pontos da parábola no plano são da forma:

$$
\begin{bmatrix}
x \\ y
\end{bmatrix} = 
\begin{bmatrix}
x(t) \\ y(t)
\end{bmatrix} =
\begin{bmatrix}
t \\ t^2
\end{bmatrix}
$$

Quando a curva é do tipo
$
\begin{bmatrix}
x \\\\ y
\end{bmatrix} =
\begin{bmatrix}
x \\\\ f(x)
\end{bmatrix}
$, como a apresentada acima, ela é chamada de função.

Em geral, plotar uma curva, ou uma função, consiste em <b>escrever em um arquivo os valores dos pontos
$\begin{bmatrix}
x \\\\ y
\end{bmatrix}$
que pertencem à curva</b>. Ou seja, simplesmente temos que resolver $x(t_1, ..., t_n)$ e $y(t_1, ..., t_n)$ muitas vezes, até que tenhamos bastante pontos $\begin{bmatrix}
x \\\\ y
\end{bmatrix}$ para plotar.

## Script

Um programa plotar uma curva no plano, em geral, deve segir essa rotina:
1. Calcule o valor da curva em um dado ponto;
1. Escreva este valor em um arquivo de dados;
1. Volte ao passo 1.

Obviamente não é possível seguir essa rotina indefinidamente, dessa forma, é comum estabelecer aguma regra para parar de executar a rotina quando achamos que já temos informação suficiente.

## Exemplo

Farei um exemplo um pouco mais robusto, sejam:

$$
\begin{bmatrix}
x(r, \theta) \\ y(r, \theta)
\end{bmatrix}
=
\begin{bmatrix}
r \cos(\theta) \\ r \sen(\theta)
\end{bmatrix}
$$

A fómula acima é conhecida como mudança de coordenadas polares para coordenadas cartesianas, note portanto que o método aqui apresentado é universal e serve para quaisquer tipos de coordenadas, desde que se faça uma mudança de coordenadas adequada.

Uma curva comum em coordenadas polares é a rosácea, nela o raio $r$ de qualquer ponto está relacionado com o ângulo $\theta$ por:

$$
r = r(\theta) = 2 \cos(2\theta)
$$

e portanto, os pontos no plano cartesiano que pertencem à rosácea são da forma:

$$
\begin{bmatrix}
x \\ y
\end{bmatrix}
=
\begin{bmatrix}
x(r, \theta) \\ y(r, \theta)
\end{bmatrix}
=
\begin{bmatrix}
r\,\cos(\theta) \\ r\,\sen(\theta)
\end{bmatrix}
=
\begin{bmatrix}
2\,\cos(2\theta)\cos(\theta) \\ 2\,\cos(2\theta) \sen(\theta)
\end{bmatrix}
$$

Como na prática $x$ e $y$ só dependem de $\theta$, iremos adicionar a variável theta ao programa principal, vamos adicionar também a variável $dt$, isso porque obviamente não é possível calcular o valor da função em todos os pontos, assim, sempre que calcularmos o valor para um dado $\theta$, iremos calcular para um $\theta$ um pouquinho maior, isto é em $\theta = \theta + dt$.

Além disso vamos adicionar theta como parâmetro das funções, e as funções serão preenchidas conforme a equação acima.

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
