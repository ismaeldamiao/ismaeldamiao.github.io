---
permalink: /pt/tutoriais/markdown
title: "Tutorial de MarkDown"
toc: true
toc_label: "Sumário"
toc_icon: "file-alt"
gallery-07.09.2020:
  - url: /images/Screenshot_20200629-175317_VNC_Viewer.png
    image_path: /images/Screenshot_20200629-175317_VNC_Viewer.png
    title: "Imagem 1"
  - url: /images/Screenshot_20200629-175500_VNC_Viewer.png
    image_path: /images/Screenshot_20200629-175500_VNC_Viewer.png
    title: "Imagem 2"
---

## Vídeos

Para adcionar vídeos, do YouTube, por exemplo, use a tag liquid

```liquid
{% raw %}{% include video id="ndZl7L_ciAQ" provider="youtube" %}{% endraw %}
```

Resultado
{% include video id="ndZl7L_ciAQ" provider="youtube" %}

## Imagem

Para adcionar uma imagem use a tag liquid

```liquid
{% raw %}{% include figure image_path="./images/Screenshot_20200629-175317_VNC_Viewer.png" caption="Modo gráfico usando termux." %}{% endraw %}
```

Substitua em `image_path` o endereço da sua imagem e em `capition` a legenda.

Resultado
{% include figure image_path="./images/Screenshot_20200629-175317_VNC_Viewer.png" caption="Modo gráfico usando termux." %}

## Galeria

Para adcionar uma galeria use a tag liquid

```liquid
{% raw %}{% include gallery id="gallery-07.09.2020" %}{% endraw %}
```

Substitua em `id` o id de uma galeria adicionada na cabeçalho do MarkDown. Por exemplo, o cabeçalho deste MarkDown está assim

```markdown
permalink: /pt/markdown
title: "Tutorial de MarkDown"
toc: true
toc_label: "Sumário"
toc_icon: "file-alt"
gallery-07.09.2020:
  - url: /images/Screenshot_20200629-175317_VNC_Viewer.png
    image_path: /images/Screenshot_20200629-175317_VNC_Viewer.png
    title: "Imagem 1"
  - url: /images/Screenshot_20200629-175500_VNC_Viewer.png
    image_path: /images/Screenshot_20200629-175500_VNC_Viewer.png
    title: "Imagem 2"
```

Resultado
{% include gallery id="gallery-07.09.2020" %}

## Equações

Para colocar equações em $\LaTeX$ na linha use $\{\$}$ e $\{\$}$. Por exemplo, o texto
$\{\$}$\hat H\vec\Psi=\hat E\vec\Psi$\{\$}$ dá a equação $\hat H\vec\Psi=\hat E\vec\Psi$.

Para usar o modo equação use $\{\$\$}$ e $\{\$\$}$.

$$\hat H\vec\Psi=\hat E\vec\Psi$$

Isto é possível graças ao `MathJax` que pode ser configurado no arquivo
[custom.html](https://github.com/ismaeldamiao/ismaeldamiao.github.io/blob/main/_includes/head/custom.html).
