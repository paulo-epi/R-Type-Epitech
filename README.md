<p>
    <a href="https://cplusplus.com/">
    <img src="https://img.shields.io/badge/C%2B%2B-17-brightgreen"
         alt="Badge C++">
    <a href="https://www.sfml-dev.org/index.php">
    <img src="https://img.shields.io/badge/SFML-2.5.1-brightgreen"
         alt="Badge SFML">
    <a href="https://www.boost.org/">
    <img src="https://img.shields.io/badge/boost-1.70.0-brightgreen"
         alt="Badge boost">
    </a>
</p>

### Table of Contents
**[R-Type](#r-type)**<br>
**[Prequisites](#prerequisites)**<br>
**[How To Build](#how-to-build)**<br>
**[How To Run](#how-to-run)**<br>
**[How To Play](#how-to-play)**<br>
**[Supported Platform](#supported-platform)**<br>
**[Documentation](#documentation)**<br>
**[Authors](#authors)**<br>

## R-Type

The mid ‘80s was a renaissance for shooters. In 1985, Konami released Gradius. Not long later, in 1987, Irem released R-Type. These are two of the most important games in the genre. It’s completely stunning that, in its relative infancy, Irem could shape a game as ingenious as R-Type.

One of the premiere side-scrolling shooters, R-Type moved a bit slower than your typical twitch games, with a meticulous pace and almost leisurely scrolling. The idea wasn’t to simply blast everything on the screen, although you could certainly try.

The idea was, quite simply, to stay alive. Naturally, given the claustrophobic nature of the levels, swarming with enemies from every angle, this was never an easy task.

## Prerequisites

- Prérequis.

> Conan

- To install conan:
```bash
$ pip install conan
```

## How to build

- How to compile on Linux:
```bash
$ mkdir build && cd build && conan install .. --build=missing -c tools.system.package_manager:mode=install -c tools.system package_manager:sudo=True && cmake .. -G "Unix Makefiles" && cmake --build .
```
or execute:
```
$ ./run.sh
```

- How to compile on Windows (non-functional):
```bash
$ mkdir build
$ cd build
$ conan install .. --build=missing -c tools.system.package_manager:mode=install -c tools.system.package_manager:sudo=True
$ cmake .. -G "Visual Studio 17 2022" -A x64
$ cmake --build .
```

## How to run

- How to run on Linux:
```bash
$ ./r-type_server [port]
$ ./r-type_client
```

- How to run on Windows (non-functional):
```bash
$ ./r-type_server.exe [port]
$ ./r-type_client.exe
```

## How to play

| Arrows | Movement |
|:------:|:--------:|
|    ↑   |   UP     |
|    ↓   |   DOWN   |
|    ←   |   LEFT   |
|    →   |   RIGHT  |
|  SPACE |   SHOOT  |

## Supported Platform

✔️[![Badge Linux](https://img.shields.io/badge/Linux-ubuntu%2020.04%20LTS-brightgreen)](https://ubuntu.com/)<br>
❌[![Badge Windows](https://img.shields.io/badge/Windows-11-brightgreen)](https://www.microsoft.com/en-us/windows)<br>
✔️[![Badge MacOS](https://img.shields.io/badge/MacOS-13-brightgreen)](https://www.apple.com/macos/mojave/)<br>

## Documentation

If you wanna look a documentation for developpers, you just need to go on folder DOC then HTML and open index.html in your browser.

We also have an RFC.
```bash
open doc/rfc4040.txt
```
Or you can also follow this link to open the RFC in your browser.
https://github.com/EpitechPromo2025/B-CPP-500-NCY-5-1-rtype-kelian.this/blob/master/doc/rfc4040.txt


## Authors

* **Paul Petit, Kelian This, Tiago Martins-Sousa, Maxime Eleonore**
