---
permalink: /pt/epidemiology/covid19al/
title: "COVID-19 em Alagoas"
toc: true
toc_label: "Sumário"
toc_icon: "file-alt"
---

**Última atualização em 27/12/2020.**

**Avisos**:
* Esta página trata de um evento epidêmico em acontecimento e seus dados estão sujeitos a revisão;
* Recomendo que leia sobre o [modelo SIR](/pt/epidemiology/sir/);
* Estou a considerar a população total de Alagoas $N = 3.3*10^{6}$.

## Dados oficiais

Os [boletins epidemiológicos](http://www.alagoascontraocoronavirus.al.gov.br/) informam sobre os casos letais (mortos - M), recuperados (curados - C) e portanto os removidos são $R = C + M$.

Já as informações sobre os casos ativos (infectados - I) apesar de terem a mesma fonte, estão melhor organizadas na [wikipedia](https://pt.wikipedia.org/wiki/Pandemia_de_COVID-19_em_Alagoas).

{% include figure image_path="./images/epidemiology/dados_oficiais_R.png" caption="Fonte..." %}
{% include figure image_path="./images/epidemiology/dados_oficiais_I.png" caption="Fonte..." %}

## Fase exponencial

Considerando a fase exponencial até o dia 44, podemos utilizar um fit exponencial para estigar a taxa de crescimento exponencial da curva de infectados e a partir daí calcular o número básico de reprodução $R_0$, note que para isso pode ser necessário chutar o valor de $\gamma$. Neste caso estou usando $\gamma = 0.04$.

## Reproduzindo o grágico
