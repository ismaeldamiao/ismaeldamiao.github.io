---
permalink: /pt/ComputationalPhysics/euler/
title: "Método de Euler"
toc: true
toc_label: "Sumário"
toc_icon: "file-alt"
---

**Aviso**: A notação usada nesta página não é complicada, entretanto você pode não compreender se não entender a notação, portanto recomento que vejas antes [Equações Diferenciais Ordinárias](https://ismaeldamiao.blogspot.com/p/texto-aqui.html) onde explico a notação.


## O método de Euler:

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

O método de Euler consiste em estimar $f(x)$ por uma soma discreta de aproximações lineares da EDO, ou seja:<br />

<div>
$$
\begin{matrix}
f(x_0 + dx) &=& f(x_0) \; + \; \left . \frac{d}{dx}f(x) \right |_{x_0} \; dx
            &=& C      \; + \; F(x_0, \; f(x_0) )                      \; dx
\end{matrix}
$$
</div>

Onde $f(x_0 + dx)$ é o valor de $f$ que queremos estimar, isto é, num ponto futuro, e $f(x_0)$ é o valor de $f$ que já possuímos no ponto "presente", de abscissa $x_0$.

Em geral, queremos estimar o valor de $f$ em mais do que um ponto, daí, como já temos uma estimativa o valor de $f$ para um ponto então usamos esta estimativa para estimar em outro ponto, e outro, e outro e assim por diante, isto é repetido de forma recursiva várias vezes até termos estimado $f$ em todo o domínio desejado.

Devido esse carater recursivo da aplicação do método de Euler, é conveniente usar a notação:

$$
f(x + dx) = f(x) \; + \; f'(x) \; dx
$$


## Exemplo (1ª ordem)

Seja o PVI:

<div>
$$
\left \{ \begin{matrix}
\frac{d}{dx}f(x) &=& x \; f(x) \\
f(x_0) &=& C
\end{matrix}\right .
$$
</div>

Para estimar o valor de $f(x_0 + dx)$ basta aplicar o método de Euler:

<div>
$$
\begin{matrix}
f(x_0 + dx) &=& f(x_0) + F(x_0, f(x_0)) \; dx \\
            &=& C + x_0 \; C \; dx
\end{matrix}
$$
</div>

Finalmente, as equações do método de Euler para o problema, que seriam colocadas dentro de um loop em um programa, serão:

<div>
$$
\left \{ \begin{matrix}
f(x + dx) &=& f(x) + x \; f(x) \; dx \\
x &=& x + dx
\end{matrix}\right .
$$
</div>

lembrando de fazer $f(x) = C$, $x = x_0$ e $dx = 1.0 \cdot 10^{-6}$ antes do loop.<br /><br />


## Exemplo (2ª ordem):

Façamos um exemplo, considere um corpo de massa $m$ que está presa a uma mola de constante de mola $k$ e pode se deslocar sobre uma superfíce horizontal sem atrito com deslocamento paralelo ao eixo $x$. Considere também que conhecemos a velocidade $\dot x(t_0)$ inicial no tempo $t_0$ e a posição inicial $x(t_0)$ no tempo $t_0$. Se $P(t)$ for o momento linear do corpo, pela <i>Lei de Hooke</i> temos:<br />

$$
\dot P(t) = m \ddot x(t) = -k x(t) \\
\Rightarrow \\
\ddot x(t) = - \frac{k}{m} x(t) = - \omega_0^2 x(t)
$$

Fazendo $q_1(t) = x(t)$ e $q_2(t) = \dot x(t)$ o sistema de equações de 1ª ordem será:

$$
\left \{ \begin{matrix}
\dot q_1(t) = q_2(t) \\
\dot q_2(t) = -\omega_0^2 q_1(t)
\end{matrix}\right .
$$

Agora basta aplicar o método de Euler para as duas equações:

<div>
$$
\left \{ \begin{matrix}
q_1(t + dt) &=& q_1(t) + q_2(t) \; dt \\
q_2(t + dt) &=& q_2(t) - \omega_0^2 \; q_1(t) \; dt
\end{matrix}\right .
$$
</div>

Finalmente, retornando à nossa notação em termos de posição e velocidade, as equações do método de Euler para o problema, que seriam colocadas dentro de um loop em um programa, serão:

<div>
$$
\left \{ \begin{matrix}
x(t + dt) &=& x(t) + \dot x(t) \; dt \\
\dot x(t + dt) &=& \dot x(t) - \omega_0^2 x(t) \; dt \\
t &=& t + dt
\end{matrix}\right .
$$
</div>

lembrando de fazer $x(t) = x_0$, $\dot x(t) = v_0$, $t = t_0$ e $dt = 1.0 \cdot 10^{-6}$ antes do loop.<br /><br />

Dessa forma, o problema consiste simplesmente em aplicar esse método recursivamente até um tempo desejado. Digamos que queremos obter a posição do corpo após 30 segundos, para as condições iniciais $x(0) = 10$ e $\dot x(0) = 0$, então o principal do programa sera:<br /><br />

Veja o programa em c completo no <a href="https://github.com/ismaeldamiao/ismael-damiao-repo/tree/master/c/Oscilador%20simples" target="_blank">GitHub</a>.<br /><br />

Veja o programa em fortran completo no <a href="https://github.com/ismaeldamiao/ismael-damiao-repo/tree/master/fortran/Oscilador%20simples" target="_blank">GitHub</a>.<br /><br />

