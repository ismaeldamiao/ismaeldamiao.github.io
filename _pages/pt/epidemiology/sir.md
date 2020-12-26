---
permalink: /pt/epidemiology/sir/
title: "O Modelo SIR"
toc: true
toc_label: "Sumário"
toc_icon: "file-alt"
---

## Introdução

Para estudar o que acontece no começo de uma epidemia, consideremos o que se segue:

* Quando **infectados** ($I$) e **suscetíveis** ($S$) interagem, uma parcela da população é removida da categoria suscetíveis e colocada na categoria infectados;
* Parte dos infectados se curam em um dado intervalo de tempo. Estes são removidos da categoria infectados e colocados na categoria **curados** ($C$);
* Outra parte dos infectados morrem devido à doença. Estes são removidos da categoria infectados e colocados na categoria **mortos** ($M$).

Para simplicar, consideremos uma única categoria que abrange os curados e os mostos, a dos **removidos** ($R$), onde $R = C + M$.

## As equações

A parte central de trabalhar as equações do modelo SIR aqui apresentado é entender o papel das seguintes **taxas**:

* $\beta$ - taxa de infecção: Taxa com que o número de sucetíveis dacai ao interagirem com os infectados;
* $\gamma$ - taxa de recuperação: Taxa com que cresce o número de removidos;
* $\mu$ - taxa de mortalidade: Percentual dos removidos que morreram.

Dessa forma o modelo SIR fica:

$$
\frac{d}{dt} S = -\beta I \frac{S}{N}
$$

$$
\frac{d}{dt} I = \beta I \frac{S}{N} - \gamma I
$$

$$
\frac{d}{dt} R = \gamma I
$$

Sendo $N$ a população total. Além dessas equações temos a equação para o número de mostos em função do número de removidos:

$$
M = \mu R
$$

ainda que para determinar $\mu$ acho interessante notar que de $R = C + M$ vem:

$$
C = (1 - \mu) R
$$

## Pontos fixos

Em qualquer sistema de equações diferenciais os pontos fixos, se existirem, serão um conjunto de valores que o sistema não muda com o tempo. Neste caso, são solução do sistema:

$$
\left\{
\begin{matrix}
0 = -\beta I \frac{S}{N} \\
0 = \beta I \frac{S}{N} + \gamma I \\
0 = \gamma I
\end{matrix}
\right.
$$

Daí vem que o sistema somente é estável quando $I=0$, ou seja, para controlar a epidemia é necessário que não haja ninguém infectado.

## O número básico de reprodução

Este número mede, em média, quantas pessoas alguém infectado é capaz de infectar. Se o **número básico de reprodução** ($R_0$) é maior que 1 a doença se propaga de forma epidêmica, já se ele for menor que 1 a doença termina por ser controlada e erradicada (note que se for uma doença como a dengue que pode ser transmitida por um vetor animal não humano então a doença pode estar somente temporariamente controlada).

Neste modelo $R_0$ é definido por $R_0 \equiv \frac{\beta}{\gamma}$ e a equação 2 fica:

$$
\frac{d}{dt} I = \left(R_0\frac{S}{N} - 1\right)\gamma I
$$

## A fase exponencial

Note que bem no começo da epidemia quando o número de sucetíveis é praticamente igual à população total podemos simplificar a equação 2 tomando $\frac{S}{N}\approxeq 1$:

$$
\begin{matrix}
\frac{d}{dt} I \approxeq \left(R_0 - 1\right)\gamma I &\Rightarrow \\
\int_{I(0)}^{I(t)} \frac{1}{I} dI \approxeq \int_{0}^{t} (R_0-1) \gamma dt &\Rightarrow \\
I(t) \approxeq I(0) e^{\gamma (R_0 -1) t} &
\end{matrix}
$$

Como essa solução exponencial é valida somente no começo da epidemia se diz que esta é a fase exponencial da epidemia.
