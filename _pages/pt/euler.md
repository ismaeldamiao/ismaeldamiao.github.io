---
permalink: /pt/ComputationalPhysics/euler/
title: "Método de Euler"
---

*Aviso*: A notação usada nesta página não é complicada, entretanto você pode não compreender se não entender a notação, portanto recomento que vejas antes <a href="https://ismaeldamiao.blogspot.com/p/texto-aqui.html" target="_blank">Equações Diferenciais Ordinárias</a> onde explico a notação.<br /><br /> 


# O método de Euler:

O método de Euler é um método simples de primeira ordem usado para resolução numérica de equações diferenciais. Euler se utilizou a definição de função diferenciável, que relaciona uma transformação linear com uma função diferenciável, para estimar o valor da função em um ponto posterior sabendo o valor da função no ponto atual e o valor de sua inclinação no ponto atual.<br /><br />

Seja o problema de valor inicial:
$$
\left \{ \begin{align*}
\frac{d}{dx}f(x) &amp;= F(x, \; f(x) ) \\
f(x_0) &amp;= C
\end{align*}\right . \; \; \; \; (1)
$$

O método de Euler consiste em estimar $f(x)$ por uma soma discreta de aproximações lineares da EDO, ou seja:<br />
\[
\begin{align*}
f(x_0 + dx) &amp;= f(x_0) \; + \; \left . \frac{d}{dx}f(x) \right |_{x_0} \; dx \\
            &amp;= C      \; + \; F(x_0, \; f(x_0) )                      \; dx
\end{align*}\; \; \; \; (2)
\]
Onde $f(x_0 + dx)$ é o valor de $f$ que queremos estimar, isto é, num ponto futuro, e $f(x_0)$ é o valor de $f$ que já possuímos no ponto "presente", de abscissa $x_0$.<br /><br />

Em geral, queremos estimar o valor de $f$ em mais do que um ponto, daí, como já temos uma estimativa o valor de $f$ para um ponto então usamos esta estimativa para estimar em outro ponto, e outro, e outro e assim por diante, isto é repetido de forma recursiva várias vezes até termos estimado $f$ em todo o domínio desejado.

Devido esse carater recursivo da aplicação do método de Euler, é conveniente usar a notação:
\[
f(x + dx) = f(x) \; + \; f'(x) \; dx \; \; \; \; (3)
\]

----------------------------------------<br />
<b>2.0 - Exemplo (1ª ordem):</b><br />
----------------------------------------<br /><br />

Seja o PVI:
\[
\left \{ \begin{align*}
\frac{d}{dx}f(x) &amp;= x \; f(x) \\
f(x_0) &amp;= C
\end{align*}\right .
\]

Para estimar o valor de $f(x_0 + dx)$ basta aplicar o método de Euler:
\[
\begin{align*}
f(x_0 + dx) &amp;= f(x_0) + F(x_0, f(x_0)) \; dx \\
            &amp;= C + x_0 \; C \; dx
\end{align*}
\]

Finalmente, as equações do método de Euler para o problema, que seriam colocadas dentro de um loop em um programa, serão:

\[
\left \{ \begin{align*}
f(x + dx) &amp;= f(x) + x \; f(x) \; dx \\
x &amp;= x + dx
\end{align*}\right .
\]

lembrando de fazer $f(x) = C$, $x = x_0$ e $dx = 1.0 \cdot 10^{-6}$ antes do loop.<br /><br />

----------------------------------------<br />
<b>3.0 - Exemplo (2ª ordem):</b><br />
----------------------------------------<br /><br />

Façamos um exemplo, considere um corpo de massa $m$ que está presa a uma mola de constante de mola $k$ e pode se deslocar sobre uma superfíce horizontal sem atrito com deslocamento paralelo ao eixo $x$. Considere também que conhecemos a velocidade $\dot x(t_0)$ inicial no tempo $t_0$ e a posição inicial $x(t_0)$ no tempo $t_0$. Se $P(t)$ for o momento linear do corpo, pela <i>Lei de Hooke</i> temos:<br />
\[
\dot P(t) = m \ddot x(t) = -k x(t) \\
\Rightarrow \\
\ddot x(t) = - \frac{k}{m} x(t) = - \omega_0^2 x(t)
\]

Fazendo $q_1(t) = x(t)$ e $q_2(t) = \dot x(t)$ o sistema de equações de 1ª ordem será:
\[
\left \{ \begin{align*}
\dot q_1(t) &amp;= q_2(t) \\
\dot q_2(t) &amp;= -\omega_0^2 q_1(t)
\end{align*}\right .
\]

Agora basta aplicar o método de Euler para as duas equações:
\[
\left \{ \begin{align*}
q_1(t + dt) &amp;= q_1(t) + q_2(t) \; dt \\
q_2(t + dt) &amp;= q_2(t) - \omega_0^2 \; q_1(t) \; dt
\end{align*}\right .
\]

Finalmente, retornando à nossa notação em termos de posição e velocidade, as equações do método de Euler para o problema, que seriam colocadas dentro de um loop em um programa, serão:
\[
\left \{ \begin{align*}
x(t + dt) &amp;= x(t) + \dot x(t) \; dt \\
\dot x(t + dt) &amp;= \dot x(t) - \omega_0^2 x(t) \; dt \\
t &amp;= t + dt
\end{align*}\right .
\]

lembrando de fazer $x(t) = x_0$, $\dot x(t) = v_0$, $t = t_0$ e $dt = 1.0 \cdot 10^{-6}$ antes do loop.<br /><br />

Dessa forma, o problema consiste simplesmente em aplicar esse método recursivamente até um tempo desejado. Digamos que queremos obter a posição do corpo após 30 segundos, para as condições iniciais $x(0) = 10$ e $\dot x(0) = 0$, então o principal do programa sera:<br /><br />

<!--HTML generated using hilite.me--><div style="background: rgb(248, 248, 248) none repeat scroll 0% 0%; border: medium solid gray; overflow: auto; padding: 0.2em 0.6em; width: auto;"><pre style="line-height: 125%; margin: 0px;"><span style="color: #408080; font-style: italic;">/* C ------------------------------------------------------------------------ */</span>
dt <span style="color: #666666;">=</span> <span style="color: #666666;">1.0e-6</span>;
posicao <span style="color: #666666;">=</span> <span style="color: #666666;">10.0</span>;
velocidade <span style="color: #666666;">=</span> <span style="color: #666666;">0.0</span>;

<span style="color: green; font-weight: bold;">for</span>(tempo <span style="color: #666666;">=</span> <span style="color: #666666;">0.0</span>; tempo <span style="color: #666666;">&lt;=</span> <span style="color: #666666;">30.0</span>; tempo <span style="color: #666666;">+=</span> dt){
   aux[<span style="color: #666666;">0</span>] <span style="color: #666666;">=</span> <span style="color: #666666;">-</span> omega2 <span style="color: #666666;">*</span> posicao;
   aux[<span style="color: #666666;">1</span>] <span style="color: #666666;">=</span> velocidade;
   <span style="color: #408080; font-style: italic;">/* Calculo para a velocidade em funcao do tempo */</span>
   velocidade <span style="color: #666666;">+=</span> aux[<span style="color: #666666;">0</span>] <span style="color: #666666;">*</span> dt;
   <span style="color: #408080; font-style: italic;">/* Calculo para  a posicao em funcao do tempo */</span>
   posicao <span style="color: #666666;">+=</span> aux[<span style="color: #666666;">1</span>] <span style="color: #666666;">*</span> dt;

   fprintf(fPosicao, <span style="color: #ba2121;">"%g %g</span><span style="color: #bb6622; font-weight: bold;">\n</span><span style="color: #ba2121;">"</span>, tempo, posicao);
}
</pre></div><br />

Veja o programa em c completo no <a href="https://github.com/ismaeldamiao/ismael-damiao-repo/tree/master/c/Oscilador%20simples" target="_blank">GitHub</a>.<br /><br />


<!--HTML generated using hilite.me--><div style="background: rgb(248, 248, 248) none repeat scroll 0% 0%; border: medium solid gray; overflow: auto; padding: 0.2em 0.6em; width: auto;"><pre style="line-height: 125%; margin: 0px;"><span style="color: #408080; font-style: italic;">! FORTRAN 90 -------------------------------------------------------------------</span>
<span style="color: #19177c;">dt</span> <span style="color: #666666;">=</span> <span style="color: #666666;">1.0</span><span style="color: #19177c;">d</span><span style="color: #666666;">-6</span>
<span style="color: #19177c;">posicao</span> <span style="color: #666666;">=</span> <span style="color: #666666;">10.0</span><span style="color: #19177c;">d0</span>
<span style="color: #19177c;">velocidade</span> <span style="color: #666666;">=</span> <span style="color: #666666;">0.0</span><span style="color: #19177c;">d0</span>

<span style="color: #19177c;">tempo</span> <span style="color: #666666;">=</span> <span style="color: #666666;">0.0</span><span style="color: #19177c;">d0</span>
<span style="color: green; font-weight: bold;">DO</span>
<span style="color: green; font-weight: bold;">   </span><span style="color: #19177c;">aux</span>(<span style="color: #666666;">1</span>) <span style="color: #666666;">=</span> <span style="color: #666666;">-</span> <span style="color: #19177c;">omega2</span> <span style="color: #666666;">*</span> <span style="color: #19177c;">posicao</span>;
   <span style="color: #19177c;">aux</span>(<span style="color: #666666;">2</span>) <span style="color: #666666;">=</span> <span style="color: #19177c;">velocidade</span>;
   <span style="color: #408080; font-style: italic;">! Calculo para a velocidade em funcao do tempo</span>
   <span style="color: #19177c;">velocidade</span> <span style="color: #666666;">=</span> <span style="color: #19177c;">velocidade</span> <span style="color: #666666;">+</span> <span style="color: #19177c;">aux</span>(<span style="color: #666666;">1</span>) <span style="color: #666666;">*</span> <span style="color: #19177c;">dt</span>
   <span style="color: #408080; font-style: italic;">! Calculo para  a posicao em funcao do tempo</span>
   <span style="color: #19177c;">posicao</span> <span style="color: #666666;">=</span> <span style="color: #19177c;">posicao</span> <span style="color: #666666;">+</span> <span style="color: #19177c;">aux</span>(<span style="color: #666666;">2</span>) <span style="color: #666666;">*</span> <span style="color: #19177c;">dt</span>

   <span style="color: green; font-weight: bold;">WRITE</span>(<span style="color: #19177c;">fPosicao</span>, <span style="color: #19177c;">FMT</span><span style="color: #666666;">=*</span>) <span style="color: #19177c;">tempo</span>, <span style="color: #19177c;">posicao</span>
   <span style="color: #19177c;">tempo</span> <span style="color: #666666;">=</span> <span style="color: #19177c;">tempo</span> <span style="color: #666666;">+</span> <span style="color: #19177c;">dt</span>
   <span style="color: green; font-weight: bold;">IF</span>(<span style="color: #19177c;">tempo</span> <span style="color: #666666;">&gt;</span> <span style="color: #666666;">30.0</span>) <span style="color: green; font-weight: bold;">EXIT</span>
<span style="color: green; font-weight: bold;">END DO</span>
</pre></div><br />

Veja o programa em fortran completo no <a href="https://github.com/ismaeldamiao/ismael-damiao-repo/tree/master/fortran/Oscilador%20simples" target="_blank">GitHub</a>.<br /><br />

</div>
