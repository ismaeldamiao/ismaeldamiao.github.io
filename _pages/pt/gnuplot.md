---
permalink: /pt/ComputationalPhysics/gnuplot/
title: "Usando o GNUplot para plotar grágicos"
toc: true
toc_label: "Sumário"
toc_icon: "file-alt"
---

O GNUplot é um software muito bom para plotar grágicos 2D e 3D, ele possui diversas funções, muito mais do que consigo usar.

Usar o GNUplot consiste em escrever um script, uma série de comandos de terminal, para obter um gráfico dos dados dispostos em um arquivo de dados. Me explico.

## O arquivo de dados

Você deve se lembrar em um plano cartesiano o ponto são representados por duas coordenadas x e y. Em geral, um arquivo de dados é um arquivo de texto com os valores de x e y de um ponto em cada linha, como no seguinte exemplo:

```
  -5.00000000       25.0000000    
  -4.00000000       16.0000000    
  -3.00000000       9.00000000    
  -2.00000000       4.00000000    
  -1.00000000       1.00000000    
   0.00000000       0.00000000    
   1.00000000       1.00000000    
   2.00000000       4.00000000    
   3.00000000       9.00000000    
   4.00000000       16.0000000 
```

Este será o conteúdo do nosso primeiro exemplo, que estará em um arquivo chamado <kbd>dados.dat</kbd>, o nome poderia ser qualquer outro.

Note que se for um gráfico 3D então cada linha deverá conter os valores das três coordenadas de cada ponto.

## Pra começar

Usando seu editor de texto favorito crie um arquivo com um nome qualquer, eu costumo colocar um <kbd>.gr</kbd> depois do nome pra indicar que se trata de um script para gráfico.

O primeiro comando do script trata do interpretador e somente é necessário de você quiser torná-lo executável, se você não sabe o que é isso sugiro que pesquise ou ignore esse comando.

```bash
#!/usr/bin/env gnuplot
```

O seguinte comando indica o formato que queremos salvar nosso gráfico, o tamanho da fonte e da imagem

* png
```bash
set term png size 720, 720 font ",18"
set output "output.png"
```

* svg
```bash
set term svg size 720, 720 font ",18"
set output "output.svg"
```

Neste caso o tamanho da fonte é 18 e o gráfico terá o formato 720px, quadrado.

## Plotando

O comando para plotar é simples:

* Somente pontos
```bash
plot "dados.dat" w p
```

* Somente linhas
```bash
plot "dados.dat" w l
```

* Linhas e pontos
```bash
plot "dados.dat" w lp
```

Para gerar o gráfico basta abrir o terminal no mesmo diretório que o script e executar-lo com o gnuplot usando o seguinte comando, no terminal:
```bash
gnuplot test.gr
```

## Pontos

Para mudar o tipo dos pontos para 7 e o tamanho dos pontos para 1, faça:
```bash
plot "dados.dat" w p pt 7 ps 1
```

Há 13 tipos de pontos.

Para mudar a cor dos pontos para azul, faça:
```bash
plot "dados.dat" w p lt rgb "blue" pt 6 ps 1
```

## Linhas

Para mudar a cor das linhas para azul, faça:
```bash
plot "dados.dat" w l lt rgb "blue"
```

## Caixa

Para mudar a posição da caixa coloque, antes do *plot*:

* Esquerda
```bash
set key left
```

* Centro
```bash
set key center
```

* Direita
```bash
set key right
```

* Encima
```bash
set key top
```

* Embaixo
```bash
set key bottom
```

* Fora
```bash
set key outside
```

Podemos colocar-lo em uma caixa:
```bash
set key box
```

Ou sumir com ele:
```bash
set key off
```

Os comandos acima podem ser mesclados, por exemplo:
```bash
set key box top right
```
Também é possível mudar o título de um gráfico:
```bash
plot "dados.dat" w p lt rgb "blue" pt 6 ps 3 title "Massa 1"
```

## Eixos e Título

Já os eixos e o título da figura podem ser auterados assim:
```bash
set xlabel "Eixo x"
set ylabel "Eixo y"
set zlabel "Eixo z"
set title "Tutorial"
```

## Curva de ajuste

Primeiro crie uma função dependente de quantos parâmetros quiser, na física use não mais que dois sempre que possível:
```bash
f(x) = a * x ** 2 + b
```

Depois crie uma variável para o seu arquivo de dados:
```bash
data = "dados.dat"
```

Agora passe um ajuste nos seus dados e guarde a informação na função:
```bash
fit f(x) data via a, b
```

Plote as duas curvas juntas:
```bash
plot data w p lt rgb "blue" pt 6 ps 3 title "Massa 1", \
     f(x) w l lt rgb "red"
```

Nosso primeiro exemplo termina aqui, ficando assim:
```bash
#!/usr/bin/env gnuplot

set term png size 720, 720 font ",18"
set output "output.png"

set key box top right

data = "dados.dat"

set xlabel "Eixo x"
set ylabel "Eixo y"
set title "Tutorial"

f(x) = a * x ** 2 + b
fit f(x) data via a, b

plot data w p lt rgb "blue" pt 6 ps 3 title "Massa 1", \
     f(x) w l lt rgb "red"
```

## Escala logarítmica

Para usar a escala logarítmica faça:
```bash
set logscale xyz
```
Note que não necessáriamente a escala logarítimica deve ser aplicada em todos os eixos.

## Strings

É possível usar strings como no c:
```bash
a=2
plot "dados.dat" title sprintf("%02d", a)
```
## Barra de erro

Támbem é possível que, no arquivo de dados, além das coordenadas x e y de um ponto, uma linha contenha os valores da incerteza em uma medida.

Por exemplo, em um arquivo, os dados de cada linha podem estar organizados da forma:

x y xErro yErro

Para plotar as barras de erro basta usar:
```bash
plot "dados.dat" with xyerrorbars
```

## Superfícies

Para plotar curvas e superfúcies 3D basicamente basta trocar o *plot* por *splot* e todo o resto é igual.
