---
permalink: /pt/ComputationalPhysics/euler/
title: "Método de Euler"
---

**Aviso**: A notação usada nesta página não é complicada, entretanto você pode não compreender se não entender a notação, portanto recomento que vejas antes [Equações Diferenciais Ordinárias](https://ismaeldamiao.blogspot.com/p/texto-aqui.html) onde explico a notação.


# O método de Euler:

O método de Euler é um método simples de primeira ordem usado para resolução numérica de equações diferenciais. Euler se utilizou a definição de função diferenciável, que relaciona uma transformação linear com uma função diferenciável, para estimar o valor da função em um ponto posterior sabendo o valor da função no ponto atual e o valor de sua inclinação no ponto atual.

Seja o problema de valor inicial:

<div>
$$
\left \{ \begin{matrix}
\frac{d}{dx}f(x) &=& F(x, \; f(x) ) \\
f(x_0) &=& C
\end{matrix} \right .
$$
</div>
