---
permalink: /pt/ComputationalPhysics/Introduction/ubuntu
title: "Pacotes básicos no Ubuntu"
---

Esta página contém instruções para instalação dos pacotes mostrados
em [/pt/ComputationalPhysics/Introduction](/pt/ComputationalPhysics/Introduction)
no Ubuntu e em sistema baseados nele.

Para instalar, basta seguir o script abaixo em um terminal com permissões de super usuário (root).

```bash
#!/bin/bash

apt update
apt install software-properties-common

add-apt-repository -y -n ppa:ubuntu-toolchain-r/test
add-apt-repository -y -n ppa:openjdk-r/ppa
add-apt-repository -y -n ppa:deadsnakes/ppa
add-apt-repository -y -n ppa:libreoffice/libreoffice-prereleases

apt update
apt install -y gcc-11 gfortran openjdk-17-jdk-headless python3.9 gnuplot grace libreoffice

# A partir daqui a instalação ja esta concluida
# O que segue, serve para facilitar o uso dos executaveis no terminal

[ -x /usr/bin/gcc ] && rm /usr/bin/gcc
[ -x /usr/bin/python ] && rm /usr/bin/python

ln -s /usr/bin/gcc-11 /usr/bin/gcc
ln -s /usr/bin/python3.9 /usr/bin/python
```

Com isso todos os programas foram instalados, exetuando `QtiPlot`, `GeoGebra` e `TexLive`.

Para usar o LaTeX é possivel recorrer ao editor online [https://www.overleaf.com/](Overleaf). Caso queiras instalar
um compilador LaTeX no seu Ubuntu sigua as instruções.
* Baixe uma imagem do texlive [https://mirrors.rit.edu/CTAN/systems/texlive/Images/](aqui).
* Descomprima a imagem ISO em algum diretório e execute o arquivo `install-tl` digitando (como root)
```bash
cd /diretorio/onde/vc/descomprimiu/a/ISO
chmod 700 install-tl
./install-tl
```
* Depois de terminada a instalação, os executáveis estarão no diretório `/usr/local/texlive/2021/bin/x86_64-linux`

Uma versão mais antiga, porém funcional, pode ser obtida simplesmente digitando como root o seguinte comando.
```bash
apt install texlive-full
```
