#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_lines_in_file(FILE *fp) {
	int result = 0;
	int c = fgetc(fp);

	while (c != EOF) {
		if (c == '\n')
			result++;
		
		c = fgetc(fp);
	}
		
	return result;
}

int main(int argc, char **argv) {
	SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_VSYNC_HINT);
	InitWindow(1280, 720, "Union Text Editor - Version 0.0.1(alpha)");
	SetTargetFPS(60);

	FILE *fp = fopen("test.txt", "r");
	int file_lines = get_lines_in_file(fp);
	char **lines = malloc(sizeof(char*) * file_lines);
	
	rewind(fp);
	
	for (int i = 0; i < file_lines; i++) {
		char line[500];
		memset(line, '\0', 500);

		fgets(line, 500, fp);
		
		lines[i] = malloc(strlen(line) + 1);
		strcpy(lines[i], line);
		lines[i][strlen(line)-1] = '\0';
	}
	fclose(fp);

	Font font = LoadFontEx("courier_new.ttf", 40, NULL, 0);
	SetTextureFilter(font.texture, TEXTURE_FILTER_BILINEAR);
	
	while(!WindowShouldClose()) {
			BeginDrawing();
			ClearBackground(BLACK);

			Vector2 cursor_pos = (Vector2){10, 10};
			for (int i = 0; i < file_lines; i++) {
				char line_no[10];
				itoa(i, line_no, 10);
				
				DrawTextEx(font, line_no, cursor_pos, 30, 1, GRAY);
				cursor_pos.x += strlen(line_no) * 30;
				
					DrawTextEx(font, lines[i], cursor_pos, 30, 1, WHITE);
				cursor_pos.y += 30;
				cursor_pos.x = 30;
			}
			
			EndDrawing();
	}
	CloseWindow();
	
	for (int i = 0; i < file_lines; i++) {
		printf("%s\n", lines[i]);
		free(lines[i]);
	}
	free(lines);
	
	return 0;
}
