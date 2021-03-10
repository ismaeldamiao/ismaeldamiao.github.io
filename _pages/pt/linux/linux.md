---
permalink: /pt/linux/
title: "Linux"
toc: true
toc_label: "Sumário"
toc_icon: "file-alt"
---

Recomendo muito o uso de uma distribuição Linux na física, na verdade para qualquer atividade que não seja jogar eu recomendo o uso do Linux, entretanto sei que há pessoas que não gostam nem querem usar o Linux, temo que esta página não seja direcionada a essas pessoas.

## Distribuiçao

Existem vários sistemas operasionais (SO) baseados no kernel linux, estes SO são conhecidos como distribuições linux, ou distros, a nível de curiosidade [este arquivo](https://upload.wikimedia.org/wikipedia/commons/1/1b/Linux_Distribution_Timeline.svg) da wikimedia pretende, se é que isso é possível, mostrar todas as distribuições baseadas no kernel Linux.

A distribuição que utilizo é Ubuntu Minimal, que é o núcleo de qualquer sub-distribuição do Ubuntu, o próprio Ubuntu, por sua vez, foi feito baseado do Debian, dessa forma espero que pelo menos no Debian, Ubuntu, LinuxMint e derivados os tutoriais mostrados aqui funcionem.

Há distribuições para todos os gostos, se você está começando a usar o Linux agora, sugiro que use uma distribuição bem configurada, como [Ubuntu](https://pt.wikipedia.org/wiki/Ubuntu), [Linux Mint](https://pt.wikipedia.org/wiki/Linux_Mint), [Debian](https://pt.wikipedia.org/wiki/Debian), [openSUSE](https://pt.wikipedia.org/wiki/OpenSUSE) ou [Android-x86](https://pt.wikipedia.org/wiki/Android).

Já se você quer personalizar seu linux e entender melhor como ele funciona, use distribuições como [Arch Linux](https://pt.wikipedia.org/wiki/Arch_Linux), [Ubuntu Minimal](https://help.ubuntu.com/community/Installation/MinimalCD) ou [Sackware](https://pt.wikipedia.org/wiki/Slackware), o uso dessas distribuições também é recomendado em computadores com baixo poder de processamento ou pouca memória, nesses casos também reomendo o [Tiny Core](https://es.wikipedia.org/wiki/Tiny_Core_Linux). Estas distros precisam ter o gestor de janelas configurado com o X, eu uso o [FluxBox](https://pt.wikipedia.org/wiki/FluxBox) mas [Xfce](https://pt.wikipedia.org/wiki/Xfce), [MATE](https://pt.wikipedia.org/wiki/MATE), [KDE Plasma](https://pt.wikipedia.org/wiki/KDE_Plasma_4), [Cinnamoon](https://pt.wikipedia.org/wiki/Cinnamon_(interface_de_usu%C3%A1rio)) e [GNOME](https://pt.wikipedia.org/wiki/GNOME) também são boas opções.

Se o objetivo for fazer testes de segurança em redes e sistemas o [Kali Linux](https://pt.wikipedia.org/wiki/Kali_Linux) é uma boa opção.

## Comandos básicos

* Para copiar o arquivo *arq* para o diretório *dir*
```bash
cp arq dir
```
* Para mover o arquivo *arq* para o diretório *dir*
```bash
mv arq dir
```
* Para entrar no diretório *dir*
```bash
cd dir
```
* Para ver os arquivos que tem no diretório que você está dentro
```bash
ls
```
* Para remover o arquivo *arq*
```bash
rm arq
```
* Para ver os processos rodando na máquina
```bash
ps arxu
```
* Para compilar o programa, escrito em c, *programa.c* e criar o executável *programa.out*
```bash
gcc programa.c -o programa.out -lm
```
* Para compilar o programa, escrito em FORTRAN 90, *programa.f90* e criar o executável *programa.out*
```bash
gfortran programa.f90 -o programa.out
```
* Para executar o programa executável *programa.out*
```bash
./programa.out
```

## Pacotes de uso na física

* Para compilar programas
  * gcc
  * gfortran
* Para documentos acadêmicos
  * texlive-full
  * [tex2pdf](/pt/pkg/latex/)
* Para plotar gráficos, curvas, superfícies, etc
  * gnuplot
* Para editar texto
  * nano
  * xed
* Para edição de imagens
  * inkscape
  
Em geral instalar esses pacotes usando um gestor de pacotes é simples, eu uso o APT. Os pacotes que não estão nos respositórios oficiais do Ubuntu, estão enlaçados com maiores instruções para instalação.
* [APT](https://pt.wikipedia.org/wiki/APT_(software))
```bash
sudo apt install -y nome_do_pacote
```
* [yum](https://pt.wikipedia.org/wiki/Yum)
```bash
sudo yum install -y nome_do_pacote
```
* [zypper](https://pt.wikipedia.org/wiki/ZYpp)
```bash
sudo zypper install nome_do_pacote
```
