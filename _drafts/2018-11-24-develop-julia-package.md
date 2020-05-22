---
published: false
title: Develop a julia package
classes: wide
categories:
- Tools
tags:
-	Julia
---

Working Environments
--------------------

-	Julia 0.7
-	Julia 1.0

Create a develop package
------------------------

-	start julia

```
julia
```

-	active the `Pkg` julia package

```
]
```

-	clone the repo to `~/.julia/dev`

```
(v0.7) pkg> develop git@github.com:yuzhangbit/SpeedOpt.jl.git
```

Run Julia even in the background
--------------------------------

```julia
using IJulia; notebook(detached=true) # run IJulia kernel in the background
```
