# Seven Keys
O seguinte tutorial está deprecated pois um dos comandos não está bem descrito.

# Instalação
Usando o terminal, acesse a pasta /Game/lib:

```sh
$ cd Game/lib
```

Após isso, extraia a engine necessária para rodar o jogo:

```sh
$ tar -vzxf ijengine-0.0.5.tar.gz
```

Certifique-se que as seguintes bibliotecas estejam instaladas no seu computador:

*libsdl2-image-dev*,
*libsdl2-mixer-dev* e
*libsdl2-ttf-dev*

Para instalar essas bibliotecas, execute os seguintes comandos:

*libsdl2-image-dev*
```sh
$ sudo apt install libsdl2-image-dev
```

*libsdl2-mixer-dev*
```sh
$ sudo apt install libsdl2-mixer-dev
```

*libsdl2-ttf-dev*
```sh
$ sudo apt install libsdl2-ttf-dev
```

Agora verifique se o compilador *g++* está instalado no seu computador.
Se não estiver, execute o seguinte comando:

```sh
sudo apt-get install g++
```

Realize a instalação da engine e do jogo através do script:

```sh
$ ./fullMake
```

Para rodar o jogo execute o arquivo binário com o seguinte comando:

```sh
$ ./bin/7keys
```
