---
permalink: /pt/linux/android/
title: "Android"
toc: true
toc_label: "Sumário"
toc_icon: "file-alt"
---

É possível criar programas de física, documentos $\LaTeX$ e gráficos pelo GNUPlot usando o bom e velho Android e nessa página eu mostro como fazer isso.

Antes de começar, recomendo que baixe um teclado como [AnySoftKey-board](https://f-droid.org/en/packages/com.menny.android.anysoftkeyboard/) ou [Go Keyboard](https://play.google.com/store/apps/details?id=com.jb.emoji.gokeyboard), esses teclados facilitam a escrita no terminal.

Também recomendo o uso de algum editor de texto, como o [DroidEdit](https://play.google.com/store/apps/details?id=com.aor.droidedit), para escrever os programas.

## Termux

O terminal é nosso melhor ambiente de trabalho, mesmo no android. Gosto muito do Termux e acho que ele é o melhor que tem para Android, baixe ele em uma das opções abaixo:

  * [Fdroid](https://f-droid.org/repository/browse/?fdid=com.termux)
  * [PlayStore](https://play.google.com/store/apps/details?id=com.termux)

Logo ao abrir ele pela primeira vez você verá uma tela preta onde você digita comandos e coisas acontecem conforme o comando digitado.

Digite os seguintes comandos, um a um, para instalar o pacote de download <kbd>wget</kbd> e baixar um script, explicarei sobre o script mais adiante:

```bash
apt update
apt install -y wget
wget -q https://github.com/ismaeldamiao/scripts/raw/master/termux_config.bash

```

Este script irá executar vários comando para configurar automáticamente o seu Termux, caso queira saber o que ele faz acesse [termux_config.bash](https://github.com/ismaeldamiao/scripts/blob/master/termux_config.bash).

Digite o seguinte comando para executar o script:

```bash
bash termux_config.bash
```

Pronto, seu Termux está configurado e, quase, pronto para uso!

## Programando em c

Clang é compilador para C disponível nos repositórios oficiais do Termux.

Para compilar um programa podemos seguir a mesma lógica que utilizamos o comando:

```bash
clang programa.c -lm
```

Entretando, ao ser instalado o Clang cria um script para você também conseguir compilar usando o comando:

```bash
gcc programa.c -lm
```

Exatamente como faria para compilar usando o gcc em uma distro linux.

Note que se ouver algo em seu código exclusivo para quando for executado no android então você deve indicar isso ao compilador usando a macro:

```C
#if __ANDROID_API__ >= 18
   /* Seu codigo */
#endif
```

Onde __ANDROID_API__ é a versão do android. 18 refere-se à última versão do Jellybean, a versão mais atual (em junho de 2020) é o Android Q (API 29). Veja [api-level.h](https://android.googlesource.com/platform/bionic/+/refs/heads/master/libc/include/android/api-level.h) para mais detalhes.

## Programando em Fortran

Ainda não há compiladores para Fortran nos repositórios oficiais do Termux então a maneira mais simples de compilar em fortran é instalar uma distro linux no seu Termux. Mais adiante eu explico como instalar o ubuntu no Termux.

Uma vez dentro da sua distro linux você poderá usar o gfortran normalmente para compilar programa em fortran.

## Modo gráfico

Caso você queira usar programas gráficos então você pode instalar o x no termux. Comece com o comando:

```bash
apt install x11-repo
```

Agora podemos instalar o gestor de janelas:

```bash
apt install fluxbox tigervnc
```

Agora execute o seguinte comando para configurar sua senha:

```bash
vncserver -localhost
```

No terminal deve aparecer o seguinte:

```bash
You will require a password to access your desktops.

Password:
Verify:
Would you like to enter a view-only password (y/n)? n
```

Note que se o termux for reiniciado então o comando acima deverá ser executado novamente.

Agora para ver seu modo gráfico baixe o [VNC Viewer](https://play.google.com/store/apps/details?id=com.realvnc.viewer.android) e:
* toque no ícone para adcionar nova conecção
* Em Address: localhost:1
* Coloque sua senha

Pronto, seu modo gráfico deve estar funcionando!

Se quiser fazer um teste, tente usar o terminal via modo gráfico.

## Ubuntu no Termux

Apesar de ser um ótimo terminal, o termux pode não ser útil para uma ou outra função que necessite de um terminal linux e pode ser conveniente instalar uma disto. Veja como instalar o ubuntu no termux.

Execute o seguinte comando para baixar e intalar o Ubuntu-chroot no Termux:

```bash
wget -qO ubuntu.sh 'https://drive.google.com/uc?export=download&id=1XGqchzzzz3bc9JuO8eKvHyHRrqRdOlFy' && bash ubuntu.sh

```

Pronto! Se tudo seu certo certo, você tem uma distribuição ubuntu no seu termux.

Para entrar no ubuntu digite:

```bash
start-ubuntu
```

Já para sair dele, e voltar ao termux, digite:

```bash
exit
```
