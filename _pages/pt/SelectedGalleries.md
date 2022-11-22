---
permalink: /pt/SelectedGalleries/
title: "Galerias"
---

{% capture fig_img %}
![](https://upload.wikimedia.org/wikipedia/commons/c/c4/Paul_Peel_-_The_Little_Shepherdess_-_Google_Art_Project.jpg)
{% endcapture %}

{% capture fig_caption %}
The Little Shepherdess - Paul Peel (1860 -- 1892), oil on canvas
{% endcapture %}

<figure>
  {{ fig_img | markdownify | remove: "<p>" | remove: "</p>" }}
  <figcaption>{{ fig_caption | markdownify | remove: "<p>" | remove: "</p>" }}</figcaption>
</figure>
