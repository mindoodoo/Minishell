# Minishell

This project is a **minimalistic** basic **shell implentation** written in C suring my first year at epitech.

**Important Note:** At this point of the Epitech curriculum, we were not allowed to use most of the standard libary, which is why you will see a lot of **```my_...```** functions which correspond to our own basic standard libary implementations.
The definition of all these functions can be found in the ```lib/my/``` directory.

## Building

In order to build this project you need to have ```gcc``` and ```make``` installed. You can then build the project by running :

```
make
```

The binary built can be run by doing :

```
./mysh
```

## Features

- Basic **UNIX command interpreter**
- Based off of the [Tcsh](https://en.wikipedia.org/wiki/Tcsh) shell.
- Temporary environment **(original environment restored on exit)**
- Custom implementation of **some** commands :
    - cd
    - exit
    - setenv
    - env
    - unsetenv
- **Redirection Support**
    - \>>
    - <<
    - \>
    - <
- **Pipe Implementation**
- ';' Support