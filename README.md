# Ismael Damião

[![LICENSE](https://img.shields.io/badge/license-MIT-lightgrey.svg)](/LICENSE)
[![Tip Me via PayPal](https://img.shields.io/badge/PayPal-tip%20me-green.svg?logo=paypal)](https://www.paypal.com/cgi-bin/webscr?cmd=_s-xclick&hosted_button_id=D66EM3DGU35EE&source=url)

Este é o repositório do site [https://ismaeldamiao.github.io/](https://ismaeldamiao.github.io/) (última alteração em 01/10/2020).

Desde © 2020 os códigos desta página estão protegidos pela licença MIT. Veja LICENSE.

Repositórios que serviram de modelo:

* [minimal-mistakes](https://github.com/mmistakes/minimal-mistakes)
* [academicpages](https://github.com/academicpages/academicpages.github.io)
* [Yu Zhang](https://github.com/tesschin/yuzhangbit.github.io)

Tutoriais sobre páginas usando `MarkDown`:

* [academicpages](https://academicpages.github.io/markdown/)
* [Ismael Damião](https://ismaeldamiao.github.io/pt/markdown)

Considere fazer-me uma [doação](https://www.paypal.com/cgi-bin/webscr?cmd=_s-xclick&hosted_button_id=D66EM3DGU35EE&source=url).

## Criando seu site

### Baixando jekyll

Comandos(no ubuntu):
```
sudo apt install bundle
sudo gem install minimal-mistakes-jekyll unicode jekyll-scholar jekyll-seo-tag jekyll bundler json jekyll-paginate github-pages wdm liquid
```

### Site de testes

#### Opção 1: Usando template

Primeiro baixe um dos repositórios que usei como modelo ou baixe este repositório.

Por exemplo, para baixar esse repositório usando o `git` faça

```
git clone https://github.com/ismaeldamiao/ismaeldamiao.github.io.git
cd ismaeldamiao.github.io
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

```
jekyll new www
cd www
jekyll server
```

Vá ao navegador e acesse
```
http://localhost:4000/
```

### Enviando seu site para o GuiHub

* Crie um repositório com o seu nome de usuário seguido de .github.io. Por exemplo, meu nome de usuário é `ismaeldamiao` e o nome do meu repositório é `ismaeldamiao.github.io`.
* Usando o botão de enviar arquivos arraste para o navegador todos os arquivos e diretórios do seu site.
* Vá até as configurações do seu repositório e em `GitHub Pages` selecione como `source` o branch correto (no meu caso `main`) e o diretório root e salve.
* Navegue até seu site, o endereço deve ser o mesmo que o nome do seu repositório.
