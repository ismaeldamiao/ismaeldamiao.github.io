---
permalink: /ComputationalPhysics/gnuplot/
title: "Usando o GNUplot para plotar grágicos"
---

O GNUplot é um software muito bom para plotar grágicos 2D e 3D, ele possui diversas funções, muito mais do que consigo usar.

Usar o GNUplot consiste em escrever um script, uma série de comandos de terminal, para obter um gráfico dos dados dispostos em um arquivo de dados. Me explico.

# O arquivo de dados

Você deve se lembrar em um plano cartesiano o ponto são representados por duas coordenadas x e y. Em geral, um arquivo de dados é um arquivo de texto com os valores de x e y de um ponto em cada linha, como no seguinte exemplo:

<pre>
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
</pre>

Este será o conteúdo do nosso primeiro exemplo, que estará em um arquivo chamado <kbd>dados.dat</kbd>, o nome poderia ser qualquer outro.

Note que se for um gráfico 3D então cada linha deverá conter os valores das três coordenadas de cada ponto.

# Pra começar

Usando seu editor de texto favorito crie um arquivo com um nome qualquer, eu costumo colocar um <kbd>.gr</kbd> depois do nome pra indicar que se trata de um script para gráfico.

O primeiro comando do script trata do interpretador e somente é necessário de você quiser torná-lo executável, se você não sabe o que é isso sugiro que pesquise ou ignore esse comando.

<pre>
#!/usr/bin/env gnuplot
</pre>

O seguinte comando indica o formato que queremos salvar nosso gráfico, o tamanho da fonte e da imagem

* png
<pre>
set terminal png size 720, 720 fsize 18
set output "output.png"
</pre>

* svg
<pre>
set terminal svg size 720, 720 fsize 18
set output "output.svg"
</pre>

* eps
<pre>
set terminal postscript eps size 720, 720 fsize 18
set output "output.svg"
</pre>

Neste caso o tamanho da fonte é 18 e o gráfico terá o formato 720px, quadrado.

# Plotando
