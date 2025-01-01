debug:
	gcc src/main.c -o bin/debug/union.exe -I include -I C:/sdks/luajit/src -I C:/sdks/raylib/src -L C:/sdks/raylib/src -L C:/sdks/luajit/src -Wall -lraylib -lgdi32 -lwinmm -lluajit-5.1 -lopengl32 -g

debug-linux:
		gcc src/main.c -o bin/debug/union -Wall -lraylib -g
