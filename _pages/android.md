---
permalink: /linux/android/
title: "Android"
excerpt: "Física computacional desde Android"
---

É possível criar programas de física, documentos $LaTeX$ e gráficos pelo GNUPlot usando o bom e velho Android e nessa página eu mostro como fazer isso.

Antes de começar, recomendo que baixe um teclado como [AnySoftKey-board](https://f-droid.org/en/packages/com.menny.android.anysoftkeyboard/) ou [Go Keyboard](https://play.google.com/store/apps/details?id=com.jb.emoji.gokeyboard), esses teclados facilitam a escrita no terminal.

Também recomendo o uso de algum editor de texto, como o [DroidEdit](https://play.google.com/store/apps/details?id=com.aor.droidedit), para escrever os programas.

# Termux

O terminal é nosso melhor ambiente de trabalho, mesmo no android. Gosto muito do Termux e acho que ele é o melhor que tem para Android, baixe ele em uma das opções abaixo:

  * [Fdroid](https://f-droid.org/repository/browse/?fdid=com.termux)
  * [PlayStore](https://play.google.com/store/apps/details?id=com.termux)

Logo ao abrir ele pela primeira vez você verá uma tela preta onde você digita comandos e coisas acontecem conforme o comando digitado.

Digite os seguintes comandos, um a um, para instalar o pacote de download <kbd>wget</kbd> e baixar um script, explicarei sobre o script mais adiante:

<pre>
apt update
apt install -y wget
wget -q https://github.com/ismaeldamiao/scripts/raw/master/termux_config.bash

</pre>

Este script irá executar vários comando para configurar automáticamente o seu Termux, caso queira saber o que ele faz acesse [termux_config.bash](https://github.com/ismaeldamiao/scripts/blob/master/termux_config.bash).

Digite o seguinte comando para executar o script:

<pre>
bash termux_config.bash

</pre>

Pronto, seu Termux está configurado e, quase, pronto para uso!

# Ubuntu no Termux

Ainda estou tentando descobrir um geito de programar no Android sem esse passo, mas por enquanto ele é necessário...

Execute o seguinte comando para baixar e untalar o Ubuntu-chroot no Termux:

<pre>
wget -O ubuntu.sh 'https://drive.google.com/uc?export=download&id=1XGqchzzzz3bc9JuO8eKvHyHRrqRdOlFy' && bash ubuntu.sh

</pre>

Pronto! Se tudo seu certo certo, sempre que quiser entrar no seu ubuntu digite:

<pre>
start-ubuntu
</pre>

Assim você estará executando uma distribuição Ubuntu no seu Termux!
