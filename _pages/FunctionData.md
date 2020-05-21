---
permalink: /ComputationalPhysics/FunctionData/
title: "Usando c e Fortran para calcular o valor de uma função"
---
El testeo 9.0

Entender o que vou ensinar nesta página pode ser difícil se você não não sabe o que é umarquivo de dados e como plotar um gráfico com base nesse arquivo. Nesse caso, recomendo que antes vejas [essa página](/ComputationalPhysics/gnuplot/).

# Pontos no plano

Plotar gráficos é uma tarefa bastante simples!

Tudo o que você precisa fazer é encontrar o valor de uma determinada função em diferentes pontos.

Trabalharemos com o plano cartesiano, nesse plano todos os ponto podem ser descritos em termos de $x$ e $y$ da forma:

$$
(x, y)
$$

Uma curva colocada em um plano cartesiano pode, em geral, ser regida por leis. Sejam $f_1$ e $f_2$ duas leis então qualquer ponto do plano que pertença a curva pode ser descrito por:

$$
(x, \, y) = (f_1, f_2)
$$

Um exemplo comum é $f_1(x)=x$ e $f_2(x)=x^2$, essa curva é conhecida com parábola e é uma das primeiras que aprendemos, nela todos os pontos da parábola no plano são da forma:

$$
(x, y) = (f_1(x), f_2(x)) = (x, x^2)
$$

Quando a curva é do tipo $(x, y) = (x, f(x))$ ela é chamada de função.

Em geral, plotar uma curva, ou uma função, consiste em <b>escrever em um arquivo os valores dos pontos $(x, y)$ que pertencem à curva</b>. Ou seja, simplesmente temos que resolver $f_1$ e $f_2$ mutas vezes, até que tenhamos bastante pontos $(x, y)$ para plotar.

# Script

Um programa plotar uma curva no plano, em geral, deve segir essa rotina:
1. Calcule o valor da curva em um dado ponto;
1. Escreva este valor em um arquivo de dados;
1. Volte ao passo 1.

Obviamente não é possível seguir essa rotina indefinidamente, dessa forma, é comum estabelecer aguma regra para parar de executar a rotina quando achamos que já temos informação suficiente.

# Exemplo

Farei um exemplo um pouco mais robusto, sejam:

<div>
$$
\left \{\begin{align*}
f_1(r, \theta) &= r \cos(\theta) \\
f_2(r, \theta) &= r \sin(\theta)
\end{align*}\right .
$$
</div>

A fómula acima é conhecida como mudança de coordenadas polares para coordenadas cartezianas, note portanto que o método aqui apresentado é universal e serve para quaisquer tipos de coordenadas, desde que se faça uma mudança de coordenadas adequada.

Uma curva comum em coordenadas polares é a rosácea, nela o raio $r$ de qualquer ponto está relacionado com o ângulo $\theta$ por:

$$
r = 2 \cos(2\theta)
$$

e portanto, os pontos no plano carteziano que pertencem à rosácea são da forma:

<div>
\begin{align*}
(x, y) &= (f_1(r, \theta), f_2(r, \theta) ) \\
       &= (r \cos(\theta), r \sin(\theta) ) \\
       &= (2 \cos(2\theta)\cos(\theta), 2 \cos(2\theta) \sin(\theta) )
\end{align*}
</div>

Como na prática $f_1$ e $f_2$ só dependem de $\theta$, iremos adcionar a variável theta ao programa principal, vamos adcionar também a variável dt, isso porque obviamente não é possível calcular o valor da função em todos os pontos, assim, sempre que calcularmos o valor para um dado $\theta$, iremos calcular para um $\theta$ um pouquinho maior, isto é em $\theta = \theta + dt$.

Além disso vamos adcionar theta como parâmetro das funções, e as funções serão preenchidas conforme a equação acima.

<div style="text-align: center;">
   Clique em um dos botões abaixo para ver o programa.<br />
       
   <button onclick="Show(source, sourceC)">C</button> 
   <button onclick="Show(source, sourceF)">Fortran</button>
</div>

<div id="source"></div>

<div hidden="" id="sourceC">
       <script src="https://gist.github.com/ismaeldamiao/553c08676881dc919a70193de561dc67.js"></script>
</div>
<div hidden="" id="sourceF">
       <script src="https://gist.github.com/ismaeldamiao/890367569c152c890e1fcf59ab92ab0e.js"></script>
</div>
