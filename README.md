## Scene Generator
Для создания OpenGL контекста и отрисовки использовал библотеку `raylib`. 

Входные параметры сцены находятся в файле `resources/scene.txt`.

Приложение парсит этот файл и отображает сцену в окне.

## Сборка

### Docker
У меня не получилось настроить докер-образ так, чтобы в нём запускался OpenGL контекст :(.
Пытался использовать `mesa` как реализацию OpenGL API.
Похоже, такая проблема возникала [возникала](https://github.com/tashrifbillah/glxgears-containers#build-container) не только у меня.

```shell
docker build -t scene-gen-image .

./run-container.sh
cd SceneGen
./buildAndRun.sh docker


exit # Выход из контейнера
```

Приложение соберётся, но не сможет запуститься.

### Linux
```shell
./buildAndRun.sh linux
```


## Формат файла `resources/scene.txt`:

Файл может состоять из нескольких описаний фигур.

Фигура описывается так:

Сначало идёт название фигуры (cube/pyramid).
Затем может идти указание позиции (position *x* *y* *z*),
указание поворота по каждой оси в градусах (orientation *x* *y* *z*)
и указание размера фигуры (scale *factor*).
