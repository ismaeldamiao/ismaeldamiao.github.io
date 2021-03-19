---
permalink: /pt/wiki/clmc/intro/
title: "wiki - CLMC"
toc: true
toc_label: "Sumário"
toc_icon: "file-alt"
---

## O programa

Este programa estuda como a energia se propaga em uma
cadeia linear (unidimencional) através da dinâmica dos modos de vibração da energia
e de medidas de localização.

É possível resolver o **problema de valor inicial** (PVI) com diversos metodos iterativos,
tais como:
* Runge-Kutta de 4a, 8a e 14a ordem;
* Adams-Bashforth-Moulton de 8a e 10a ordem.

Disponibilizei este programa como material de aprendizagem para quem tem interesse
nos diversos métodos de resolução numérica de equações diferenciais ordinárias
(EDO) associadas a um PVI. Estes métodos podem ser aplicados em equações mais "simples",
entretanto eu resolvi mostrar como aplica-los em um problema mais extenso para
resolver um sistema de `N` equações.

## O Hamiltoniano

Considere um sistema físico com grau de liberdade 1 formado por $N$
partículas. Considere também que o acoplamento entre partículas
vizinhas pode ser descrito por um potencial harmônico e por
generalizações anarmônicas desse potencial, todos dependendo da
distância entre as partículas vizinhas.

Seja $x_n$ a distância em relação à própria posição de equilíbrio
da partícula $n$ de massa $M_n$ e momento linear $P_n$.
A energia $E_n$ dessa partícula é dada por:

$$
E_n = \frac{P_n^2}{2M_n}
   + \sum_{i = 2}^{4}
   \frac{1}{2i}\left[\eta_{i,n}(x_n - x_{n-1})^i + \eta_{i,n+1}(x_{n+1} - x_n)^i\right]
$$

Dessa forma o hamiltoniano que descreve o sistema é $H=\sum_{n=1}^NE_n$.
Onde os fatores $\eta_{i,n}$ são termos de acoplamento. O expoente $i=2$
dá os termos de potencial harmônico.

## O PVI

Dado o hamiltoniano, a principal tarefa do CLMC é resolver as equações
de Hamilton, que são:

$$
   \frac{d}{dt} x_n = \frac{P_n}{M_n}
$$

$$
   \frac{d}{dt} P_n = \sum_{i=2}^{4}
   \eta_{i,n+1}(x_{n+1} - x_n)^{i-1} - \eta_{i,n}(x_n - Q_{n-1})^{i-1}
$$
