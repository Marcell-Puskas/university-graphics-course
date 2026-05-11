all:
	gcc -Iinclude/ src/app.c src/camera.c src/main.c src/scene.c src/utils.c src/texture.c src/car.c src/track.c src/skybox.c src/cones.c src/read_cones.c -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lobj -lopengl32 -lm -o main.exe -Wall -Wextra -Wpedantic -g

linux:
	gcc -Iinclude/ src/app.c src/camera.c src/main.c src/scene.c src/utils.c src/texture.c src/car.c src/track.c src/skybox.c src/cones.c src/read_cones.c -lSDL2 -lSDL2_image -lobj -lGL -lm -o main -Wall -Wextra -Wpedantic

tests:
	gcc -Iinclude/ tests/main.c src/read_cones.c -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lobj -lopengl32 -lm -o tests.exe -Wall -Wextra -Wpedantic -g

.PHONY: all tests