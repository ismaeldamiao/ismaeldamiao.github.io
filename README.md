# yuzhangbit.github.io

My website based on the minimal mistakes theme.

Since github pages do not support all the jekyll plugins due to security reasons, I have to put all my source codes of the website with needed plugins in `source` branch and set it as the primary branch in github, then use the Rakefile script to publish a production website to the `master` branch. The github pages will host it automatically. If the repository is a project repo, the `gh-pages` branch will be used to deploy the website instead of the `master` branch.   
The default branch is the `source` where I enable the jekyll-scholar plugin. The master branch is for publishing gh-pages. The other jekyll plugins that are not supported by github pages can be installed to the `source` branch as well.



## Several interesting changes I have made.  

* Create a bibliography template ([bibtemplate.html](https://github.com/yuzhangbit/yuzhangbit.github.io/blob/source/_layouts/bibtemplate.html)). It display the bibentries, the publishing status and doi.  The corresponding buttons can be customized
using scss style file ([_buttons.scss](https://github.com/yuzhangbit/yuzhangbit.github.io/blob/source/_sass/minimal-mistakes/_buttons.scss#L101))
* The ieee citation style is modified.
    * The index is removed.
    * The title of the paper is bold.
    * The initialization of authors' name is disabled.

## Host the website locally
```
bash host_locally.bash
```
Then the website is available at [http://localhost:4000](http://localhost:4000).


## Publish the website

All the developments go to the `source` branch. When everything is ready, use commands below to publish the website to the `master` branch and push to the remote.
```
rake publish
```


## Usage Cases Cheat Sheet
* embeded pdf viewer
    ```
    <embed src="{{ site.url }}{{ site.baseurl }}/assets/pdfs/Yu_Zhang_CV.pdf" type="application/pdf" height="100%" width="100%"/>
    ```
    You have to include height and width both to have a full view of pdf. Only enabling one, let's say height, the actual height will not change. The default height is too low. Please refer to `_page/about.md` as an example.

* enable google analytics using gtag.js mode
    * create a new google analytics account for your website by the [instruction](https://support.google.com/analytics/answer/1009694?hl=en) and the get the gtag ID

    * In `_config.yml` file, enable the google analytics globally
    ```
    analytics:
        provider: "google-gtag"
        google:
            tracking_id: "UA-118867307-1"
            anonymize_ip: false # default
    ```
    * enable the `production` ENV variable to track the website by adding
    ```ruby
    ENV["JEKYLL_ENV"] = "production"
    ```
    to the [Rakefile](https://github.com/yuzhangbit/yuzhangbit.github.io/blob/source/Rakefile) before the website is built by the jekyll.
* notice syntax  
* feature_row and alignment
* gallery
* image alignment
* citations
* insert images with captions
* video embedded
* header overlay
