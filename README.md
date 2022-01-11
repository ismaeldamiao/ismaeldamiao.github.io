# Ismael Damião

[![Tip Me via PayPal](https://img.shields.io/badge/PayPal-tip%20me-green.svg?logo=paypal)](https://www.paypal.com/cgi-bin/webscr?cmd=_s-xclick&hosted_button_id=D66EM3DGU35EE&source=url)


Este é o repositório do site [https://ismaeldamiao.github.io/](https://ismaeldamiao.github.io/) (última alteração em 10/01/2022).

## Repositorios base e tutoriais

* GitHub
  * [Minimal Mistakes](https://github.com/mmistakes/minimal-mistakes)
  * [academicpages](https://github.com/academicpages/academicpages.github.io)
  * [Yu Zhang](https://github.com/tesschin/yuzhangbit.github.io)
* Pages
  * [Minimal Mistakes](https://mmistakes.github.io/minimal-mistakes/collection-archive/)
  * [academicpages](https://academicpages.github.io/markdown/)
  * [Ismael Damião](https://ismaeldamiao.github.io/pt/markdown)

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
(see as `ls`!) and you can edit `main.c` file.
* Vá até as configurações do seu repositório e em `GitHub Pages` selecione como `source` o branch correto (no meu caso `main`) e o diretório root e salve.
* Navegue até seu site, o endereço deve ser o mesmo que o nome do seu repositório.
