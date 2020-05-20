---
permalink: /linux/android/
title: "Android"
excerpt: "Física computacional desde Android"
---

É possível criar programas de física, documentos $LaTeX$ e gráficos pelo GNUPlot usando o bom e velho Android e nessa página eu mostro como fazer isso

# Termux

O terminal é nosso melhor ambiente de trabalho, mesmo no android. Gosto muito do Termux e acho que ele é o melhor que tem para Android, baixe ele em uma das opções abaixo:

  * [Fdroid](https://f-droid.org/repository/browse/?fdid=com.termux)
  * [PlayStore](https://f-droid.org/repository/browse/?fdid=com.termux)

Logo ao abrir ele pela primeira vez você verá uma tela preta onde você digita comandos coisas acontecem conforme o comando digitado.

Digite os seguintes comandos, um a um, para instalar o pacote de download <kbd>wget</kbd> e baixar um script, explicarei sobre o script mais adiante:

<pre>
apt update
apt install -y wget
wget -q [](https://github.com/ismaeldamiao/scripts/raw/master/termux_config.bash)
</pre>
