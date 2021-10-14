---
permalink: /pt/ComputationalPhysics/Introduction/win
title: "Pacotes básicos no Windows"
---

Esta página contém instruções para instalação dos pacotes mostrados
em [/pt/ComputationalPhysics/Introduction](/pt/ComputationalPhysics/Introduction)
no Windows.

## GCC, gnuplot, Grace, Python

Iremos instalar o `Cygwin`, ele emula um terminal com várias funções do linux.

Primeiramente, vá ao site [https://cygwin.com/install.html](https://cygwin.com/install.html),
baixe o instalador e execute ele. Você deve seguir com o processo normal de instalação
até aparecer a tela *Choose A Download Site*, nela você irá escolher o servidor de sua preferência
(pode ser qualquer um), se a lista estiver vazia escolha um [desta lista](https://cygwin.com/mirrors.html)
(eu usei https://mirrors.sonic.net/cygwin/).

Continue com a instalação até a aparecer tela
*Select Packages*. Na opção *View* deixe *full* e use a opção *Search* para pesquisar, agora
pesquise e selecione (toque duas vezes sobre a palavra *Skip*) os seguintes pacotes:
* `gcc-core`
* `gcc-fortran`
* Todos que começam com `gnuplot`
* `python3`
* `grace`
* `xinit`
* `xorg-server`
* `nano`

Agora basta continuar a instalação até o fim. Uma vez instalado pesquise
no mení iniciar (ou cortana) por *XWin Server*, se quiser adcione um atalho para a área
de trabalho. Executar o *XWin Server* deve criar barra de tarefas um ícone,
use esse ícone para iniciar os programas do *Cygwin* ou o *Cygwin Terminal*.
