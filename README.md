<h1 align="center">snd.h</h1>
  
<p align="center">
  <em>An opinionated header-only "standard library".</em>
</p>

<p align="center">
    <img src="https://img.shields.io/badge/license-MIT-green?style=flat-square" alt="MIT License" />
  <img src="https://img.shields.io/github/last-commit/simon-danielsson/snd.h/main?style=flat-square&color=blue" alt="Last commit" />
      <img src="https://img.shields.io/badge/C_version-99-cyan?style=flat-square" alt="C" />
</p>
  
<p align="center">
  <a href="#info">Info</a> •
  <a href="#usage">Usage</a> •
  <a href="#license">License</a>
</p>  
  
---
<div id="info"></div>

## Info
  
'snd.h' is a small stb-style header-only library for C. This library can be used either
as a library you include in the standard manner, or as a file of useful
functions to copy-paste directly into your codebase.  
  
While this library is useful to me, it may not be useful to you - please take
the time to skim the library's contents before cloning.
  
---
<div id="usage"></div>
  
## Usage
   
### Setup
     
Download (or copy) [snd.h](./snd.h) into your codebase and include it like this:
  
``` c
#include ...
#include ...
#include ...
#define SND_IMPLEMENTATION
#include "snd.h"
```
      
---
<div id="license"></div>
  
## License
  
This project is licensed under the [MIT License](https://github.com/simon-danielsson/snd.h/blob/main/LICENSE).  
