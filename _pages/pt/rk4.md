---
permalink: /pt/ComputationalPhysics/rk4/
title: "Método de Runge-Kutta de 4ª ordem"
toc: true
toc_label: "Sumário"
toc_icon: "file-alt"
---

**Aviso**: A notação usada nesta página não é complicada, entretanto você pode não compreender se não entender a notação, portanto recomento que vejas antes [Equações Diferenciais Ordinárias](https://ismaeldamiao.blogspot.com/p/texto-aqui.html) onde explico a notação.


## O método de Runge-Kutta de 4ª ordem

O Método de Runge-Kutta de 4ª ordem, ou simplesmente RK4, é um método de cálculo numérico que permite colher resultados com maior precisão do que se usássemos o método de Euler ou, se quisermos a mesma precisão, com menos tempo do que usando Euler.

Para o PVI:
<div>
$$
\left \{ \begin{matrix}
\frac{d}{dx}f(x) &=& F(x, \; f(x) ) \\
f(x_0) &=& C
\end{matrix}\right .
$$
</div>

o método de Euler de primeira ordem pode ser expresso por:

$$
f(x + dx) = f(x) + I dx
$$

Onde $I$ é uma inclinação. No método de Euler essa inclinação é a derivada $\frac{d}{dx}f(x)$ no ponto de abscissa $x$, no RK4 essa inclinação é mais "detalhada", expressa por:

$$
I=\frac{1}{6} \left ( k_1 + 2k_2 + 2k_3 + k_4 \right )
$$

onde:
<div>
$$
\left \{ \begin{matrix}
   k_1 &=& F\left ( x, \;  \; f(x) \right )\\
   k_2 &=& F\left ( x + \frac{dx}{2}, \;  \; f(x) +  k_1 \, \frac{dx}{2} \right ) \\
   k_3 &=& F\left ( x + \frac{dx}{2}, \;  \; f(x) +  k_2 \, \frac{dx}{2} \right ) \\
   k_4 &=& F\left ( x + dx, \;  \; f(x) +  k_3 \, dx \right )
\end{matrix} \right .
$$
</div>

ou seja:
* $k_1$ é a inclinação de $f$ no início do intervalo $[x, x + dx]$, exatamente a mesma de Euler;
* $k_2$ é a inclinação de $f$ na metade do intervalo $[x, x + dx]$ estimada através do método de Euler usando $k_1$;
* $k_3$ é a inclinação de $f$ na metade do intervalo $[x, x + dx]$ estimada através do método de Euler usando $k_2$;
* $k_4$ é a inclinação de $f$ no fim do intervalo $[x, x + dx]$ estimada através do método de Euler usando $k_3$.

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
Para estimar o valor de $f(x_0 + dx)$ basta aplicar RK4:

$$
f(x_0 + dx) = f(x_0) + \frac{1}{6} \left ( k_1 + 2k_2 + 2k_3 + k_4 \right ) dx 
$$

com:
<div>
$$
\left \{ \begin{matrix}
   k_1 &=& F(x_0, f(x_0)) = x_0 \; C \\
   k_2 &=& (x_0 + \frac{dx}{2}) \; (C + k_1 \frac{dx}{2}) \\
   k_3 &=&  (x_0 + \frac{dx}{2}) \; (C + k_2 \frac{dx}{2}) \\
   k_4 &=& (x_0 + dx) \; (C + k_3 dx)
\end{matrix}\right .
$$
</div>

Finalmente, as equações do método RK4 para o problema, que seriam colocadas dentro de um loop em um programa, serão:
<div>
$$
\left \{ \begin{align*}
   k_1 &= x \; f(x) \\
   k_2 &= (x + \frac{dx}{2}) \; (f(x) + k_1 \frac{dx}{2}) \\
   k_3 &=  (x + \frac{dx}{2}) \; (f(x) + k_2 \frac{dx}{2}) \\
   k_4 &= (x + dx) \; (f(x) + k_3 dx) \\
   f(x + dx) &= f(x) + \frac{1}{6} \left ( k_1 + 2k_2 + 2k_3 + k_4 \right ) \; dx \\
   x &= x + dx
\end{align*}\right .
$$
</div>

lembrando de fazer $f(x) = C$, $x = x_0$ e $dx = 1.0 \cdot 10^{-3}$ antes do loop.


## Exemplo (2ª ordem):

Para ficar mais claro, vamos voltar ao problema do oscilador harmônico simples. A EDO era da forma:

$$
\ddot x(t) = - \omega_0^2 \, x(t)
$$

Além disso, fazendo $q_1(t) = x(t)$ e $q_2(t) = \dot x(t)$ o sistema de equações de 1ª ordem era:
<div>
$$
\begin{align}
\dot q_1(t) &= q_2(t) \\
\dot q_2(t) &= -\omega_0^2 \;\; q_1(t)
\end{align}
$$
</div>

Agora basta aplicar o RK4 para as duas equações:
<div>
$$
\left \{ \begin{matrix}
   q_1(t + dt) = q_1(t) + \frac{1}{6} \left ( kx_1 + 2kx_2 + 2kx_3 + kx_4 \right ) dt \\
   q_2(t + dt) = q_2(t) + \frac{1}{6} \left ( kv_1 + 2kv_2 + 2kv_3 + kv_4 \right ) dt
\end{matrix}\right .
$$
</div>

onde:

<div style="text-align: center;">
$$
\left \{ \begin{align*}
   kx_1 &= q_2(t) \\
   kx_2 &= q_2(t + \frac{dt}{2}) \\
   kx_3 &= q_2(t + \frac{dt}{2}) \\
   kx_4 &= q_2(t + dt)
\end{align*}\right .
$$ 
$$
\left \{ \begin{align*}
   kv_1 &= -\omega_0^2 \;\; q_1(t) \\
   kv_2 &= -\omega_0^2 \;\; q_1(t + \frac{dt}{2}) \\
   kv_3 &= -\omega_0^2 \;\; q_1(t + \frac{dt}{2}) \\
   kv_4 &= -\omega_0^2 \;\; q_1(t + dt)
\end{align*}\right .
$$
</div>


Note que, para o PVI são conhecidos os valores de $q_2(t)$ , $q_1(t)$, mas o valor de $q_2(t + \frac{dt}{2})$, por exemplo, não é conhecido. Contudo, lembre-se da definição, $kx_2$ deve ser a velocidade na metade do intervalo, estimada usando algum $k_1$ pelo método de Euler, note que, pela eq. (10), $kv_1$ pode ser utilizado como a inclinação de Euler. <br /><br />

De forma similar, pela eq. (9) $kx_1$ pode ser usado para estimar $q_1(t + \frac{dt}{2})$ em $kv_2$ por Euler.<br /><br />

Dessa forma, devemos aplicar o método de Euler em $kx_2$, $kx_3$, $kx_4$, $kv_2$, $kv_3$ e $kv_4$, daí:

<div style="text-align: center;">
$$
\left \{ \begin{align*}
   kx_1 &= q_2(t) \\
   kx_2 &= q_2(t) + kv_1 \; \; \frac{dt}{2} \\
   kx_3 &= q_2(t) + kv_2 \; \; \frac{dt}{2} \\
   kx_4 &= q_2(t) + kv_3 \; \; dt \\
\end{align*}\right .
$$
$$
\left \{ \begin{align*}
   kv_1 &= -\omega_0^2 \;\; q_1(t) \\
   kv_2 &= -\omega_0^2 \;\; ( q_1(t) + kx_1 \;\; \frac{dt}{2} ) \\
   kv_3 &= -\omega_0^2 \;\; ( q_1(t) + kx_2 \;\; \frac{dt}{2} ) \\
   kv_4 &= -\omega_0^2 \;\; ( q_1(t) + kx_3 \;\; dt )
\end{align*}\right .
$$
</div><br />

Finalmente, retornando à nossa notação em termos de posição e velocidade, as equações de RK4 para o problema, que seriam colocadas dentro de um loop em um programa, serão:

<div>
$$
\left \{ \begin{align*}
   kx_1 &= \dot x(t) \\
   kv_1 &= -\omega_0^2 \;\; x(t) \\
   kx_2 &= \dot x(t) + kv_1 \; \; \frac{dt}{2} \\
   kv_2 &= -\omega_0^2 \;\; ( x(t) + kx_1 \;\; \frac{dt}{2} ) \\
   kx_3 &= \dot x(t) + kv_2 \; \; \frac{dt}{2} \\
   kv_3 &= -\omega_0^2 \;\; ( x(t) + kx_2 \;\; \frac{dt}{2} ) \\
   kx_4 &= \dot x(t) + kv_3 \; \; dt \\
   kv_4 &= -\omega_0^2 \;\; ( x(t) + kx_3 \;\; dt ) \\
   x(t + dt) &= x(t) + \frac{1}{6} \left ( kx_1 + 2kx_2 + 2kx_3 + kx_4 \right ) dt \\
   \dot x(t + dt) &= \dot x(t) + \frac{1}{6} \left ( kv_1 + 2kv_2 + 2kv_3 + kv_4 \right ) dt \\
   t &= t + dt
\end{align*}\right .
$$
</div>

lembrando de fazer $x(t) = x_0$, $\dot x(t) = v_0$, $t = t_0$ e $dt = 1.0 \cdot 10^{-3}$ antes do loop.<br /><br />

Veja um exemplo de programa em c no <a href="https://github.com/ismaeldamiao/ismael-damiao-repo/tree/master/c/Oscilador%20simples" target="_blank">GitHub</a>.


Veja um exemplo de programa em fontran no <a href="https://github.com/ismaeldamiao/ismael-damiao-repo/tree/master/fortran/Oscilador%20simples" target="_blank">GitHub</a>.
