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
