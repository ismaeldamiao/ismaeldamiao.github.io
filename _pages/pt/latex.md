---
permalink: /pt/pkg/latex/
title: "$\\LaTeX$"
toc: true
toc_label: "Sumário"
toc_icon: "file-alt"
---

O $\LaTeX$ é o programa que uso para fazer documentos segundo as normas na ABNT. Através dele é possível usar notação matemática, inserir tabelas, gráficos, fórmulas químicas, numerar automaticamente equações, leis, teoremas, imagens e etc dentre uma infinidade de outras funções.

Tudo isso é feito através de codigos inseridos no arquivo `.tex`, dessa forma a formatação é feita automaticamente quando o arquivo é compilado. O resultado é um documento PDF muito bonito.

## instalando

O primeiro componente que iremos instalar é o *texlive*, ele contém os pacotes necessários para usar $\LaTeX$.
Para instalar use os comandos abaixo conforme sua distribuição ou clique [aqui](http://tug.org/texlive/acquire-netinstall.html).

```bash
# No debian, ubuntu, linux-mint ou similar
sudo apt install -y texlive-full
# No opensuse
sudo zypper install texlive
# No android (termux)
apt install -y texlive-full
```

Depois, você deve baixar um [script](github.com/ismaeldamiao/modelo-latex/raw/master/tex2pdf) para compilar os documento $\LaTeX$ mais facilmente, em um terminal digite:

```bash
wget -qO tex2pdf github.com/ismaeldamiao/modelo-latex/raw/master/tex2pdf
```

E por fim, mova o script para um diretório `bin` e dê permissões de execussão, conforme os comandos abaixo.

```bash
# No android (termux)
mv tex2pdf $PREFIX/bin/tex2pdf
chmod 700 $PREFIX/bin/tex2pdf
# Em qualquer outra distribuicao
[ -d ~/bin ] || mkdir ~/bin
mv tex2pdf ~/bin/tex2pdf
chmod 700 ~/bin/tex2pdf
```

## Testando

Eu tenho um modelo com todas as configurações feitas, as principais biblioteca importadas e um exemplo para as principais funções. Tive que aprender tudo isso mas não se preocupe, você só vai precisar editar o principal, meio que a parte mais difícil eu já resolvi!

Veja <a href="https://github.com/ismaeldamiao/modelo-latex/blob/master/relatorio/main.tex">neste repositório</a> o meu modelo.

Baixe ele usando o seguinte comando em um terminal:
```bash
wget -q https://github.com/ismaeldamiao/modelo-latex/archive/master.zip
```

Agora descompacte o arquivo com o seguinte comando:
```bash
unzip master.zip
```

Agora vá ao diretório que você acabou de descompactar:
```bash
cd modelo-latex-master/relatorio/
```

E use meu script para compilar:
```bash
tex2pdf main.tex
```

Se tudo deu certo, deve aparecer no diretório um arquivo chamado *main.pdf* resultado de compilar o conteúdo do arquivo *main.tex*, use seu editor de texto preferido para editar o *main.tex*.

## Saiba mais
* [O que vou aprendendo em Latex](https://aprendolatex.wordpress.com/)
* [LaTex BR](https://latexbr.blogspot.com/2010/04/introducao-ao-latex.html)
* [Modelos de documentos em LaTex](http://dl.bintray.com/laurocesar/generic/abntex2-modelos-1.9.7.zip)
* [Manuiais de uso do AbnTex2](http://dl.bintray.com/laurocesar/generic/abntex2-doc-1.9.7.zip)(Devem ser os primeiros a ser consultados em caso de dúvidas, consulte os manuais antes mesmo de consultar a internet!)


* [Create LaTeX tables online](https://tablesgenerator.com/) - Para fazer tabelas mais facilmente
* [Guia de edição/Fórmulas TeX](https://pt.wikipedia.org/wiki/Ajuda:Guia_de_edi%C3%A7%C3%A3o/F%C3%B3rmulas_TeX) - Para fazer equações



