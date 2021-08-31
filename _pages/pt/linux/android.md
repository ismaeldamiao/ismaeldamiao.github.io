---
permalink: /pt/linux/android/
title: "Android"
toc: true
toc_label: "Sumário"
toc_icon: "file-alt"
---

[![DISCORD](https://img.shields.io/discord/765774817910980618?label=discord)](https://discord.gg/Hf9E33N)

Na física, em geral, queremos usar o computador para criar programas de física, documentos $\LaTeX$ e gráficos pelo GNUPlot. É possível fazer tudo isso pelo android quase do mesmo jeito que em outros sistemas linux e aqui você aprenderá como.

A principal ferramenta android que iremos utilizar em física computacional é o termux, entretanto algumas outras também serão úteis. Baixe elas nos links abaixo.

* [Termux](https://f-droid.org/repository/browse/?fdid=com.termux) - Para emular um terminal UNIX.
* [AnySoftKeyboard](http://anysoftkeyboard.github.io/download/) - teclado virtual melhorado.
* [Material Files](https://github.com/zhanghai/MaterialFiles) - Gestor de arquivos que consegue ler e modificar a $HOME do termux.
* [DroidEdit](https://play.google.com/store/apps/details?id=com.aor.droidedit.pro) - Editor de códigos.

Para informações mais detalhadas, embora, talvez, menos didáticas consulte o o repositório [termux](https://github.com/ismaeldamiao/termux).

## Termux

{% include video id="HFPpYZVaP7E" provider="youtube" %}

O terminal é nosso melhor ambiente de trabalho, mesmo no android. Gosto muito do Termux e acho que ele é o melhor que tem para Android.
Após instalar e configurar o termux você poderá seguir outros tutoriais que trabalham em terminais linux, de fato, para aprender termux é preciso primeiro aprender terminal linux pois a grande maioria dos comandos serão iguais e funcionaram do mesmo jeito.

### Configurando

{% include video id="CIvA4KnTZZg" provider="youtube" %}

Seguem abaixo os comandos mostrados no vídeo:

```bash
# Atualizar e baixar pacotes
apt update
apt upgrade
apt install nano wget ncurses-utils coreutils gnupg
# Atalhos
mkdir .termux
cat > $HOME/.termux/termux.properties <<EOF
extra-keys = [\
   ['$','{','}','(',')','<','>','#',';'],\
   ['ALT','HOME','END','BACKSLASH','-','+','APOSTROPHE','&','BKSP'],\
   ['CTRL','TAB','|','/','LEFT','UP','DOWN','RIGHT','ESC']\
]
# Open a new terminal with ctrl + t (volume down + t)
shortcut.create-session = ctrl + t
# Go one session down with (for example) ctrl + 2
shortcut.next-session = ctrl + 2
# Go one session up with (for example) ctrl + 1
shortcut.previous-session = ctrl + 1
# Rename a session with (for example) ctrl + n
shortcut.rename-session = ctrl + n
# Ignore bell character (vibrate,beep,ignore)
bell-character=ignore
# Send the Escape key.
back-key=back
EOF
termux-reload-settings
# bashrc
wget github.com/ismaeldamiao/How-to/raw/main/files/.bashrc
```

### Programando

{% include video id="g7PwcSnp0SI" provider="youtube" %}

Agradeço a equipe do [CCTools](https://cctools.info/) por disponibilizar os compiladores para o Termux, em especial ao programador Sasha Chukov.

Seguem abaixo os comandos mostrados no vídeo:

```bash
# Instalando clang
apt install clang
# Instalando gcc e gfortran
wget "https://raw.githubusercontent.com/ismaeldamiao/termux/main/install-termux-cctools.sh"
bash install-termux-cctools.sh
```

Note que se ouver algo em seu código exclusivo para quando for executado no android então você deve indicar isso ao compilador usando a macro:

{% highlight c %}
#if __ANDROID_API__ >= 18
   /* Seu codigo */
#endif
{% endhighlight %}

Onde \_\_ANDROID_API\_\_ é a versão do android. 18 refere-se à última versão do Jellybean, a versão mais atual (em junho de 2020) é o Android Q (API 29). Veja [api-level.h](https://android.googlesource.com/platform/bionic/+/refs/heads/master/libc/include/android/api-level.h) para mais detalhes.
