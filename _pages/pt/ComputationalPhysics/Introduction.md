---
permalink: /pt/ComputationalPhysics/Introduction
title: "Introdução à Computação"
---
<head>
<style>
.button {
  border: none;
  border-radius: 4px;
  border-color: none;
  color: white;
  padding: 2px 6px;
  text-align: center;
  text-decoration: none;
  display: inline-block;
  font-size: 90%;
  /* margin: 4px 2px; */
  cursor: pointer;
}

.button:hover {
  opacity: 0.5;
} 
 
.bnt_blue {background-color: #0092ca;} /* BibTeX, Blue */
.bnt_red {background-color: #850000;} /* Code, Red */
.bnt_green {background-color: #009200;} /* Article, Green */
.bnt_purple {background-color: #b366ff;} /* Preprint, Purple */
</style>
</head>

## Resumo

A computação tem se tornado cada vez mais importante,
independente da área do conhecimento. Nessa linha

Estes são os conhecimentos computacionais básicos que todo físico deve saber:
* Escrever programas para fazer cálculo numérico.
* Plotar gráficos.
* Escrever documentos conforme as normas da ABNT.

Esta página irá citar vários programas, veja as instruções para instalar eles:
* [/pt/ComputationalPhysics/Introduction/win](Windows).
* [/pt/ComputationalPhysics/Introduction/ubuntu](Ubuntu) e derivados.
* [/pt/ComputationalPhysics/Introduction/android](Android) (Termux).

## Cálculo numérico

O cálculo numérico é feito usando linguagens de programação.

Algumas linguagens, desde a de mais baixo nível até a de mais alto nível.

* **C**
* **Java**
  * Uma vez que o código Java é compilado ele pode ser executado em qualquer dispositivo com uma JVM,
sem necessidade de compilar novamente.
  * Ideal para aplicativos de divulgação ou cálculos que não exigem muita dedicação
de memória e processador.
* **Fortran**
  * Linguagem líder no meio físico.
  * Feita especialmente para o cálculo numérico e científico.
  * Fácil de aprender.
  * Versões: Recomendo que estudes <a href="https://wg5-fortran.org/N001-N1100/N692.pdf">Fortran 90</a>
ou <a href="https://wg5-fortran.org/N1151-N1200/N1191.pdf">Fortran 95</a>.
  * Compilador: `gfortran`
   <a href="https://cygwin.com/install.html"><button class="button bnt_red">Windows</button></a>
* **Python**
  * Intérprete: 

Para instalar o compilador/intérprete de cada liguagem no Windows basta 

## Plotar gráficos

* **gnuplot**
  * Grátis e de código aberto (gnuplot License).
  * OS: Linux, Android, Windows
  * Baixe:
   <a href="http://www.gnuplot.info/download.html"><button class="button bnt_green">Oficial</button></a>
   <a href="http://www.gnuplot.info/download.html"><button class="button bnt_blue">Ubuntu</button></a>
   <a href="https://cygwin.com/install.html"><button class="button bnt_red">Windows</button></a>
* **Grace**
  * Grátis e de código aberto (GPL).
  * OS: Linux, Android, Windows
  * Baixe:
   <a href="https://plasma-gate.weizmann.ac.il/pub/grace/src/grace-latest.tar.gz"><button class="button bnt_green">Oficial</button></a>
   <a href="https://cygwin.com/install.html"><button class="button bnt_red">Windows</button></a>
* **QtiPlot**
  * Demo grátis.
  * OS: Linux, Android, Windows
  * Baixe:
   <a href="https://www.qtiplot.com/demo.html"><button class="button bnt_green">Oficial</button></a>
* **GeoGebra**
  * Grátis.
  * OS: Linux, Android, Windows
  * Baixe:
   <a href="https://www.geogebra.org/download"><button class="button bnt_green">Oficial</button></a>

## Documentos

Ferramentas gratuitas para escrever documentos.

* **LaTeX**
  * Você escreve códigos em um arquivo e, ao compilar os códigos, um documento em PDF é produzido.
  * Alta qualidade e precisão.
  * <a href="https://www.overleaf.com/"><button class="button bnt_red">Editor online</button></a>
* **LibreOffice**
  * Editor gráfico de documentos.
  * Grátis e de código aberto (MPLv2.0).
  * Baixe:
   <a href="https://www.libreoffice.org/download/download/"><button class="button bnt_green">Oficial</button></a>
