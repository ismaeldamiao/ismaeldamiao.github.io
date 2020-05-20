---
permalink: /ComputationalPhysics/gnuplot/
title: "Usando o GNUplot para plotar grágicos"
---

$\frac{y}{x}$

\[
\frac{y}{x}
\]

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

{"source": [
    "!cat publications.tsv"
]
}

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

# Plotando

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

Para gerar o gráfico basta abrir o terminal no mesmo diretório que o script e executar-lo com o gnuplot:
```bash
gnuplot test.gr
```

# Pontos

Para mudar o tipo dos pontos para 7 e o tamanho dos pontos para 1, faça:
```bash
plot "dados.dat" w p pt 7 ps 1
```

Há 13 tipos de pontos.

Para mudar a cor dos pontos para azul, faça:
```bash
plot "dados.dat" w p lt rgb "blue" pt 6 ps 1
```

# Linhas

Para mudar a cor das linhas para azul, faça:
```bash
plot "dados.dat" w l lt rgb "blue"
```

# Caixa

Para mudar a posição da caixa coloque, antes do 
