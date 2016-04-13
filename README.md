# Seven Keys
  

# Instalação
Usando o terminal, acesse a pasta /Seven-Keys/Game/lib:

```sh
$ cd /Seven-Keys/Game/lib
```

Após isso, extraia a engine necessária para rodar o jogo:

```sh
$ tar -vzxf ijengine-0.0.5.tar.gz
```

Certifique-se que as seguintes bibliotecas estejam instaladas no seu computador:

*libsdl2-image-dev*,
*libsdl2-mixer-dev* e
*libsdl2-ttf-dev*

Se não estiverem, execute os seguintes comandos:

```sh
$ sudo apt install libsdl2-image-dev
```
```sh
$ sudo apt install libsdl2-mixer-dev
```
```sh
$ sudo apt install libsdl2-ttf-dev
```

Realize a instalação da engine através do MakeFile:

```sh
$ sudo make install
```
Após realizada a instalação da engine, volte a pasta Manteam/Game e realize a instalação do jogo, também utilizando seu MakeFile:

```sh
$ cd ../..
$ make -j8
```

Para rodar o jogo, acesse a pasta /ManaTeam/Game/bin e execute o arquivo binário:

```sh
$ cd ijengine-0.0.5
$ ./7keys
```
