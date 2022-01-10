# Ismael Damião

[![Tip Me via PayPal](https://img.shields.io/badge/PayPal-tip%20me-green.svg?logo=paypal)](https://www.paypal.com/cgi-bin/webscr?cmd=_s-xclick&hosted_button_id=D66EM3DGU35EE&source=url)


Este é o repositório do site [https://ismaeldamiao.github.io/](https://ismaeldamiao.github.io/) (última alteração em 10/01/2022).

## Repositorios base e tutoriais

* [academicpages](https://github.com/academicpages/academicpages.github.io)
* [Yu Zhang](https://github.com/tesschin/yuzhangbit.github.io)
* [academicpages](https://academicpages.github.io/markdown/)
* [Ismael Damião](https://ismaeldamiao.github.io/pt/markdown)

## Criando seu site

### Baixando jekyll

No ubuntu
```bash
sudo gem install minimal-mistakes-jekyll unicode jekyll-scholar jekyll-seo-tag jekyll bundler json jekyll-paginate github-pages wdm liquid
```

#### Opção 1: Usando template

Ainda estou preparanto o template.

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
