all:
	gcc -Iinclude/ src/ball.c src/game.c src/main.c src/pad.c src/pong.c src/score.c -lmingw32 -lSDL2main -lSDL2 -lopengl32 -lm -o main.exe -Wall -Wextra -Wpedantic

linux:
	gcc -Iinclude/ src/ball.c src/game.c src/main.c src/pad.c src/pong.c src/score.c -lSDL2 -lGL -lm -o pong -Wall -Wextra -Wpedantic
