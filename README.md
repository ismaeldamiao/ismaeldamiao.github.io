# Ismael Damião

[![Tip Me via PayPal](https://img.shields.io/badge/PayPal-tip%20me-green.svg?logo=paypal)](https://www.paypal.com/cgi-bin/webscr?cmd=_s-xclick&hosted_button_id=D66EM3DGU35EE&source=url)


Este é o repositório do site [ismaeldamiao.github.io](https://ismaeldamiao.github.io/) (última alteração em 14/01/2022).

## Repositorios base e tutoriais

Este site é feito usando [jekyll](https://jekyllrb.com/),
um software que permite usar Markdown como frontend para escrever as páginas
do site.
O tema usado como base para o site é o [Minimal Mistakes](https://github.com/mmistakes/minimal-mistakes)
e algumas funcionalidade do [academicpages](https://github.com/academicpages/academicpages.github.io)
foram utilizadas.

A maioria das funcionalidades que podem ser utilizadas em Markdown
estão extensivamente explicadas [aqui](https://mmistakes.github.io/minimal-mistakes/docs/quick-start-guide/).
Alguns tutoriais básicos de Markdown podem ser encontrados
[aqui](https://guides.github.com/features/mastering-markdown/) e
[aqui](https://academicpages.github.io/markdown/) (cf. [fonte](https://github.com/academicpages/academicpages.github.io/blob/master/_pages/markdown.md?plain=1)).

Principais modificações que fiz no código fonte (backend):
* Atualizei as fontes [Font Awesome](https://fontawesome.com)
e [Academicons](https://github.com/jpswalsh/academicons) para as versões
`6.0.0-beta3` e `1.9.1`, respectivamente
(cf. `assets/css`).
* Configurei o [MathJax](https://www.mathjax.org/)
(cf. `_includes/head/custom.html`) para inserir equações em LaTeX.
* Criei uma função em [liquid](https://github.com/Shopify/liquid/wiki)
para facilitar o uso de botões em bibliografias
(o GitHub não suporta a plugin jekyll-scholar;
cf. `_includes/cite_btn`, `_pages/pt/library.md`, `_includes/bib.html`).


Alguns links que podem ser úteis.
* GitHub
  * [Minimal Mistakes](https://github.com/mmistakes/minimal-mistakes)
  * [academicpages](https://github.com/academicpages/academicpages.github.io)
  * [Yu Zhang](https://github.com/tesschin/yuzhangbit.github.io)
* Pages
  * [Minimal Mistakes](https://mmistakes.github.io/minimal-mistakes/collection-archive/)
  * [academicpages](https://academicpages.github.io/markdown/)
  * [Ismael Damião](https://ismaeldamiao.github.io/pt/tutoriais/markdown)
  * [An Amateur Computational Mathematician](https://scaomath.github.io/research/)
  * [Rob Williams](https://jayrobwilliams.com/publications/)
  * [Sayorn Chin](https://schinlfc.github.io/posts/2020/07/customizing-website/)

Veja as funcionalidade utilizadas pelo GitHub Pages
[aqui](https://pages.github.com/versions/).
Se você for hospedar seu site localmente (abaixo mostro como)
então é possível usar o plugin
[jekyll-scholar](https://github.com/inukshuk/jekyll-scholar),
leia um pouco sobre esse plugin também
[aqui](https://www.amirasiaee.com/dailyreport/jekyll-scholar/).

## Criando seu site

### Baixando jekyll

No ubuntu
```bash
sudo apt install ruby-dev ruby-bundler nodejs
gem update --system
sudo gem install \
  minimal-mistakes-jekyll \
  github-pages \
  liquid \
  jekyll \
  jekyll-seo-tag \
  jekyll-paginate \
  jekyll-scholar \
  jekyll-sitemap \
  jekyll-gist \
  jekyll-feed \
  jekyll-seo-tag \
  jemoji unicode bundler json wdm hawkins mercenary
```

#### Opção 1: Usando template

Primeiro baixe um dos repositórios que usei como modelo ou baixe este repositório.

Por exemplo, para baixar esse repositório usando o `git` faça

```
git clone https://github.com/ismaeldamiao/ismaeldamiao.github.io.git
```

Depois use os seguintes comandos para executar o site no seu computador

```
sudo bundle update
sudo bundle clean --force
sudo bundle install
sudo bundle exec jekyll serve
```

Vá ao navegador e acesse

```
http://localhost:4000/
```

#### Opção 2: Manualmente


```bash
jekyll new www
cd www
jekyll server
```

Vá ao navegador e acesse
```bash
http://localhost:4000/
```

### Enviando seu site para o GuiHub


* Crie um repositório com o seu nome de usuário seguido de .github.io. Por exemplo, meu nome de usuário é `ismaeldamiao` e o nome do meu repositório é `ismaeldamiao.github.io`.
and all contents of this directoty are copied to a current directory
* Usando o botão de enviar arquivos arraste para o navegador todos os arquivos e diretórios do seu site.
* Vá até as configurações do seu repositório e em `GitHub Pages` selecione como `source` o branch correto (no meu caso `main`) e o diretório root e salve.
* Navegue até seu site, o endereço deve ser o mesmo que o nome do seu repositório.

## Licença

```
MIT License

Copyright (c) 2020 Ismael Damião

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
```