# Ismael Damião

[![LICENSE](https://img.shields.io/badge/license-MIT-lightgrey.svg)](/LICENSE)
[![Tip Me via PayPal](https://img.shields.io/badge/PayPal-tip%20me-green.svg?logo=paypal)](https://www.paypal.com/cgi-bin/webscr?cmd=_s-xclick&hosted_button_id=D66EM3DGU35EE&source=url)


Este é o repositório do site [https://ismaeldamiao.github.io/](https://ismaeldamiao.github.io/) (última alteração em 01/10/2020).
# LibDamiao


Desde © 2020 os códigos desta página estão protegidos pela licença MIT. Veja LICENSE.
This repository contains the header file were I use in my programs

and implementations for functions declared in the header.
Repositórios que serviram de modelo:


## Good pratices
* [minimal-mistakes](https://github.com/mmistakes/minimal-mistakes)

* [academicpages](https://github.com/academicpages/academicpages.github.io)
* Use pure and only C99 features.
* [Yu Zhang](https://github.com/tesschin/yuzhangbit.github.io)
  * If any extension is good, implement this.

* Do not use `tgmath.h` library.
Tutoriais sobre páginas usando `MarkDown`:
* Set `I` as `const` to imaginary unit.

* Prefers operators as functions.
* [academicpages](https://academicpages.github.io/markdown/)
* If the compiler is `gcc` then hability `-Wall`, `-Wextra` and `-Wpedantic` flags.
* [Ismael Damião](https://ismaeldamiao.github.io/pt/markdown)
* Define the mathematical constants from `POSIX` extension.

* Define physical constants in [SI base unit](https://en.wikipedia.org/wiki/SI_base_unit).
Considere fazer-me uma [doação](https://www.paypal.com/cgi-bin/webscr?cmd=_s-xclick&hosted_button_id=D66EM3DGU35EE&source=url).


Moreover, the following functions be declared:
## Criando seu site
* `double random(unsigned int *idum);`

  * **Description:**
### Baixando jekyll
The `random` function computes a sequence of pseudo-random integers in the range 0 to

`UINT_MAX` and convert it in pseudo-random reals in the interval [0, 1].
Comandos(no ubuntu):
Successive calls must generate the same sequence of numbers if the first
```
call have the same value. The argument `idum` is a pointer to a
sudo apt install bundle
initialized integer, the integer are initialized with
sudo gem install minimal-mistakes-jekyll unicode jekyll-scholar jekyll-seo-tag jekyll bundler json jekyll-paginate github-pages wdm liquid
the seed of pseudo-random gererator and after call is changed to a
```
pseudo-random integer.

  * **Returns:**
### Site de testes
The `random` function return the pseudo-random real.

* `double _Complex atoc(const char *str);`
#### Opção 1: Usando template
  * **Description:**

The `atoc` function convert the initial portion of the string pointed
Primeiro baixe um dos repositórios que usei como modelo ou baixe este repositório.
to by `str` to `double _Complex` representation.

  * **Returns:**
Por exemplo, para baixar esse repositório usando o `git` faça
The `atoc` function return the converted value.


```
it's OK use `#define` to a implementation.
git clone https://github.com/ismaeldamiao/ismaeldamiao.github.io.git

cd ismaeldamiao.github.io
Repository with many `c` function and utilities in computational physics,
```
mathematics and engineering.


Depois use os seguintes comandos para executar o site no seu computador
To learn about c see [...](...).


```
To learn about macros see [macros.md](/MarkDown/macros.md).
sudo bundle update

sudo bundle clean --force
## Install
sudo bundle install

sudo bundle exec jekyll serve
You can download this repository using a terminal as:
```
```bash

wget https://github.com/ismaeldamiao/my_c_header/archive/refs/heads/main.zip
Vá ao navegador e acesse

```
http://localhost:4000/
```
```


#### Opção 2: Manualmente
And install the scrit `newc` as:

```bash
```
unzip main.c && cd my_c_header-main/ && bash install.sh
jekyll new www
cd www
jekyll server
```
```


Vá ao navegador e acesse
Allways if you want to start a new c project use:
```bash
newc
```
```
http://localhost:4000/
```

### Enviando seu site para o GuiHub


* Crie um repositório com o seu nome de usuário seguido de .github.io. Por exemplo, meu nome de usuário é `ismaeldamiao` e o nome do meu repositório é `ismaeldamiao.github.io`.
and all contents of this directoty are copied to a current directory
* Usando o botão de enviar arquivos arraste para o navegador todos os arquivos e diretórios do seu site.
(see as `ls`!) and you can edit `main.c` file.
* Vá até as configurações do seu repositório e em `GitHub Pages` selecione como `source` o branch correto (no meu caso `main`) e o diretório root e salve.
* Navegue até seu site, o endereço deve ser o mesmo que o nome do seu repositório.
