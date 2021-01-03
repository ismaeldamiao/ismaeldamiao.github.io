---
permalink: /pt/linux/android/
title: "Android"
toc: true
toc_label: "Sumário"
toc_icon: "file-alt"
---

[![DISCORD](https://img.shields.io/discord/765774817910980618?label=discord)](https://discord.gg/Hf9E33N)

É possível criar programas de física, documentos $\LaTeX$ e gráficos pelo GNUPlot usando o bom e velho Android e nessa página eu mostro como fazer isso.

Antes de começar, recomendo que baixe um teclado como [AnySoftKey-board](https://f-droid.org/en/packages/com.menny.android.anysoftkeyboard/) ou [Go Keyboard](https://play.google.com/store/apps/details?id=com.jb.emoji.gokeyboard), esses teclados facilitam a escrita no terminal.

Também recomendo o uso de algum editor de texto, como o [DroidEdit](https://play.google.com/store/apps/details?id=com.aor.droidedit), para escrever os programas.

## Termux

{% include video id="HFPpYZVaP7E" provider="youtube" %}

O terminal é nosso melhor ambiente de trabalho, mesmo no android. Gosto muito do Termux e acho que ele é o melhor que tem para Android, baixe ele em uma das opções abaixo:

  * [Fdroid](https://f-droid.org/repository/browse/?fdid=com.termux)
  * [PlayStore](https://play.google.com/store/apps/details?id=com.termux)

## Configurando

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
wget https://raw.githubusercontent.com/ismaeldamiao/scripts/master/.bashrc
```

## Programando

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

## Modo gráfico

Caso você queira usar programas gráficos então você pode instalar o x no termux. Comece com o comando:

```bash
apt install x11-repo
```

Agora podemos instalar o gestor de janelas:

```bash
apt install fluxbox tigervnc
```

Agora execute o seguinte comando para configurar sua senha:

```bash
vncserver -localhost
```

No terminal deve aparecer o seguinte:

```bash
You will require a password to access your desktops.

Password:
Verify:
Would you like to enter a view-only password (y/n)? n
```

Note que se o termux for reiniciado então o comando acima deverá ser executado novamente.

Antes de seguir, diga ao vnc para usar o gestor de janelas fluxbox:

```bash
echo "fluxbox & " >> ~/.vnc/xstartup
```

Agora para ver seu modo gráfico baixe o [VNC Viewer](https://play.google.com/store/apps/details?id=com.realvnc.viewer.android) e:
* toque no ícone para adcionar nova conecção
* Em Address: localhost:1
* Coloque sua senha

{% include figure image_path="./images/Screenshot_20200629-175500_VNC_Viewer.png" caption="Login no VNC Viewer." %}

Pronto, seu modo gráfico deve esta a funcionar!

Se quiser fazer um teste, tente usar o terminal via modo gráfico.

{% include figure image_path="./images/Screenshot_20200629-175317_VNC_Viewer.png" caption="Modo gráfico usando termux." %}

## Ubuntu no Termux

Apesar de ser um ótimo terminal, o termux pode não ser útil para uma ou outra função que necessite de um terminal linux e pode ser conveniente instalar uma distro linux. Veja como instalar o ubuntu no termux.

Execute o seguinte comando para baixar e intalar o Ubuntu-chroot no Termux:

```bash
wget -qO ubuntu.sh 'https://drive.google.com/uc?export=download&id=1XGqchzzzz3bc9JuO8eKvHyHRrqRdOlFy' && bash ubuntu.sh

```

Pronto! Se tudo seu certo certo, você tem uma distribuição ubuntu no seu termux.

Para entrar no ubuntu digite:

```bash
start-ubuntu
```

Já para sair dele, e voltar ao termux, digite:

```bash
exit
```
