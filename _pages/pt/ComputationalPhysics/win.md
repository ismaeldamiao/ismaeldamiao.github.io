---
permalink: /pt/ComputationalPhysics/Introduction/win
title: "Pacotes básicos no Windows"
---

Esta página contém instruções para instalação dos pacotes mostrados
em [/pt/ComputationalPhysics/Introduction](/pt/ComputationalPhysics/Introduction)
no Windows.

## GCC

https://docs.microsoft.com/pt-br/cpp
https://code.visualstudio.com/Download
MSVC
ext install krvajalm.linter-gfortran
```C
#include <stdio.h>

int main(void){
#if defined(__ANDROID_API__)
   fprintf(stdout, "Android\n");
#endif
#if defined(__linux__)
   fprintf(stdout, "Linux\n");
#endif
#if defined(_WIN32)
   fprintf(stdout, "Windows\n");
#endif
#if defined(__APPLE__)
   fprintf(stdout, "MAC OS\n");
#endif
   return 0;
}
```


Iremos instalar o `MinGW`, ele contém os compiladores GCC (compiladores de c e Fortran).

Primeiramente, vá ao site [https://sourceforge.net/projects/mingw/](https://sourceforge.net/projects/mingw/),
baixe o instalador e execute ele siga normalmente com a instalação até aparecer uma tela como a da figura abaixo.
Clique em *Basic Setup* e em todos os *Pakages* que aparecerem clique no quadradinho
ao lado e em *Mark for Instalation*. Depois vá em *Installation* na parte superior e em *Apply Changes*.

## Grace

Para instalar o *Grace* baixe o arquivo em
[https://sourceforge.net/projects/qtgrace/](https://sourceforge.net/projects/qtgrace/).
Ele deve estar compactado como `zip`, você deve descompactar ele ir à
pasta `bin` e executar o arquivo `qtfrace.exe`, se quiser crie um atalho para a área de trabalho.

## Java

Para instalar o *OpenJDK* (implementação gratuita do Java) visite o site
[https://docs.microsoft.com/pt-br/java/openjdk/download](https://docs.microsoft.com/pt-br/java/openjdk/download)
e baixe o arquivo para Windows de extensão `msi`. Após isso basta executar o arquivo baixado e seguir com a instalação.

## LibreOffice

Para instalar o LibreOffice basta visitar o site
[https://www.libreoffice.org/download/download/](https://www.libreoffice.org/download/download/),
baixar e instalar.
