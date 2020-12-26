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

Dessa forma o modelo SIR fica
$$
\frac{d}{dt} S = -\beta I \frac{S}{N}
$$

$$
\frac{d}{dt} I = beta I \frac{S}{N} - \gamma I
$$

$$
\frac{d}{dt} R = \gamma I
$$

Sendo $N$ a população total.
