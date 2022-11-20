---
permalink: /pt/tutoriais/pkg/latex/
title: "$\\LaTeX$"
layout: single
sidebar: true
toc: true
toc_label: "Sumário"
toc_icon: "file-alt"
---

Nesta página apresentarei um pouco sobre o $\LaTeX$ e mostrarei algumas ligações
que podem ser úteis para quem está começando ou quer aprofundar seus conhecimentos
sobre $\LaTeX$.

## O que é e para quê serve o $\LaTeX$

Imagine que você precisa escrever um relatório para a universidade,
ou um TCC, uma dissertação ou tese, ou qualquer coisa do estilo.
Você pode usar o
[Microsoft Word](https://www.microsoft.com/pt-br/microsoft-365/word) ou o
[LibreOffice Writter](https://pt.libreoffice.org/descobrir/writer/)
para gerar esse documento, mas também é possível usar $\LaTeX$ para o mesmo
objetivo.

A diferença entre o $\LaTeX$ e o Word ou o Writter é que enquanto nestes
últimos você edita enquanto vê como está ficando o documento,
no $\LaTeX$ você escreve códigos em um arquivo de texto,
compila os códigos e só então vê como ficou o documento.
Por exemplo, veja o código abaixo:

```latex
% Encoding: UTF-8
% TeX Live 2022
\documentclass{abntex2}

\usepackage[T1]{fontenc}    % Selecao de codigos de fonte.
\usepackage[utf8]{inputenc} % Codificacao do documento (conversão automática dos acentos).
\usepackage{ucs}            % Complemento do anterior.

\begin{document}

Olá Mundo!

\end{document}
```

Após compilado este código gera o seguinte `pdf`:

<iframe
   src="{{ site.url }}{{ site.baseurl }}/assets/documents/ola_mundo.pdf"
   width="100%"
   heigh="15em"
   type="application/pdf"
></iframe>

## Vantagens de usar o $\LaTeX$

A grande vantagem do $\LaTeX$ é a alta qualidade dos documentos gerados,
desde que você use modelos bem preparados é possível com simples comandos
obter documentos que obedecem estritamente às normas da universidade ou
regras da ABNT.

Modelos bem preparados também permitem que o processo de escrita dos documentos
seja deveras mais simples e rápido de que se utilizássemos os concorrentes
World ou Writter.

Ainda sobre a qualidade dos documentos, o $\LaTeX$ facilmente trabalha
junto de outras tecnologias permitindo a integração do seu
documentos com outros, desde outros documentos em `pdf` até documentos
em `PostScript`, formato exigido pelas revistas para os gráficos.

## Por onde começar

### Usando o $\LaTeX$ online

A meneira mais simples de usar o $\LaTeX$ é usando o site
[Overleaf](https://pt.overleaf.com/),
ele é basicamente um editor de códigos gratuito com compiladores de códigos
$\LaTeX$, este site também é muito útil para trabalhar em equipe já
que várias pessoas podem editar um único projeto ao mesmo tempo.

- Crie uma conta no Overleaf: <https://pt.overleaf.com/register>.

### Instalando no Linux

Para instalar o $\LaTeX$ em qualquer distribuição linux
(Linux Mint, Ubuntu, Open SUSE e até mesmo no Termux, etc)
o primeiro que precisamos é baixar o `TeX Live` (pacote com todos os arquivos e
programas necessários).

- Pré-requisitos: Você vai precisar de um mínimo de conhecimento em
terminal linux e precisará ter o `perl` instalado.
- Download do [TeX Live](https://mirror.ctan.org/systems/texlive/tlnet/install-tl-unx.tar.gz).

Uma vez baixado o arquivo basta copiar seu conteúdo para algum lugar e abrir
no terminal (se você quiser descomprimir usando linha de comando use
`tar -xf install-tl-unx.tar.gz`). Com o terminal aberto no diretório correto
basta digitar o seguinte comando para concluir a instalação.

```bash
sudo su
perl ./install-tl --no-interaction
# Ou, se você está instalando no Termux (Android)
perl ./install-tl --no-interaction  \
   --custom-bin $PREFIX/bin/texlive \
   --texdir $PREFIX/local
```

**Aviso:** Faça um café, o comando acima pode demorar horas
para terminar de executar.
{: .notice--danger}

Se todo o processor acima funcionou então você já possui o $\LaTeX$
instalado.

## Onde encontrar modelos

Para que sua experiência com o $\LaTeX$ seja a melhor possível recomendo
o uso de modelos.

No link abaixo tu podes encontrar vários modelos e exemplos preparados por mim.

[![A name](https://github-readme-stats.vercel.app/api/pin/?username=ismaeldamiao&locale=pt-pt&theme=onedark&repo=modelo-latex)](https://github.com/ismaeldamiao/modelo-latex)

## E o que é MarkDown

Como o $\LaTeX$, o `MarkDown` é uma linguagem de marcação,
isto é, serve para escrever e formatar textos.
O `MarkDown` é muito mais simples e fácil de usar que o $\LaTeX$.
A nível de exemplo, compare os dois códigos abaixo.

```latex
% Código em LaTeX

\begin{itemize}
\item Texto normal em uma lista.
\item \textbf{Assim se escreve em negrito}.
\item \textit{Assim se escreve em itálico}.
\end{itemize}
```


```markdown
<!-- Código em MarkDown -->

- Texto normal em uma lista.
- **Assim se escreve em negrito**.
- *Assim se escreve em itálico*.
```

Por essa razão se você utilizar o modelo `relatorio_ufal` você irá escrever
os códigos mais simples em `MarkDown`,
como usar negrito, itálico, listas, inserir imagens, etc.
Já os códigos mais complexos serão escritos em $\LaTeX$,
como formatação da capa e corpo do documento, fontes, etc.

## Saiba mais

* [O que vou aprendendo em Latex](https://aprendolatex.wordpress.com/)
* [LaTex BR](https://latexbr.blogspot.com/2010/04/introducao-ao-latex.html)
* [Modelos de documentos em LaTex](http://dl.bintray.com/laurocesar/generic/abntex2-modelos-1.9.7.zip)
* [Manuiais de uso do AbnTex2](http://dl.bintray.com/laurocesar/generic/abntex2-doc-1.9.7.zip)(Devem ser os primeiros a ser consultados em caso de dúvidas, consulte os manuais antes mesmo de consultar a internet!)


* [Create LaTeX tables online](https://tablesgenerator.com/) - Para fazer tabelas mais facilmente
* [Guia de edição/Fórmulas TeX](https://pt.wikipedia.org/wiki/Ajuda:Guia_de_edi%C3%A7%C3%A3o/F%C3%B3rmulas_TeX) - Para fazer equações



