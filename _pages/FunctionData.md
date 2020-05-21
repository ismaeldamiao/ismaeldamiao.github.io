---
permalink: /ComputationalPhysics/gnuplot/
title: "Usando c e Fortran para calcular o valor de uma função"
---

Plotar gráficos é uma tarefa bastante simples!

Tudo o que você precisa fazer é encontrar o valor de uma determinada função em diferentes pontos.

Trabalharemos com o plano cartesiano, nesse plano todos os ponto podem ser descritos em termos de $x$ e $y$ da forma:
\\(
(x, y)
\\)

Uma curva colocada em um plano cartesiano pode, em geral, ser regida por leis. Sejam $f_1$ e $f_2$ duas leis então qualquer ponto do plano que pertença a curva pode ser descrito por:
\\(
(x, \, y) = (f_1, f_2)
\\)

Um exemplo comum é $f_1(x)=x$ e $f_2(x)=x^2$, essa curva é conhecida com parábola e é uma das primeiras que aprendemos, nela todos os pontos da parábola no plano são da forma:
\\(
(x, y) = (f_1(x), f_2(x)) = (x, x^2)
\\)

Quando a curva é do tipo $(x, y) = (x, f(x))$ ela é chamada de função.

Em geral, plotar uma curva, ou uma função, consiste em <b>escrever em um arquivo os valores dos pontos $(x, y)$ que pertencem à curva</b>. Ou seja, simplesmente temos que resolver $f_1$ e $f_2$ mutas vezes, até que tenhamos bastante pontos $(x, y)$ para plotar.
