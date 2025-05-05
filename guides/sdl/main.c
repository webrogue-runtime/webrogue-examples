#include <stdio.h>
#include <stdlib.h>

#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>

/*
- x, y: upper left corner.
- texture, rect: outputs.
*/
void get_text_and_rect(SDL_Renderer *renderer, int x, int y, char *text,
                       TTF_Font *font, SDL_Texture **texture, SDL_FRect *rect) {
  int text_width;
  int text_height;
  SDL_Surface *surface;
  SDL_Color textColor = {255, 255, 255, 0};

  surface = TTF_RenderText_Solid(font, text, strlen(text), textColor);
  *texture = SDL_CreateTextureFromSurface(renderer, surface);
  text_width = surface->w;
  text_height = surface->h;
  SDL_DestroySurface(surface);
  rect->x = x;
  rect->y = y;
  rect->w = text_width;
  rect->h = text_height;
}

int main(int argc, char **argv) {
  SDL_Event event;
  SDL_FRect text_rect1, text_rect2;
  SDL_FRect red_rect;
  SDL_Renderer *renderer;
  SDL_Texture *texture1, *texture2;
  SDL_Window *window;
  char *font_path;
  int quit;

  font_path = "/app/FreeSans.otf";

  /* Inint TTF. */
  SDL_Init(SDL_INIT_VIDEO);

  SDL_CreateWindowAndRenderer("AAA?", 300, 300, 0, &window, &renderer);
  TTF_Init();
  TTF_Font *font = TTF_OpenFont(font_path, 24);
  if (font == NULL) {
    fprintf(stderr, "error: font not found\n");
    exit(EXIT_FAILURE);
  }
  get_text_and_rect(renderer, 0, 0, "hello", font, &texture1, &text_rect1);
  get_text_and_rect(renderer, 0, text_rect1.y + text_rect1.h, "world", font,
                    &texture2, &text_rect2);

  red_rect.x = 100;
  red_rect.y = 100;
  red_rect.w = 100;
  red_rect.h = 100;

  quit = 0;
  while (!quit) {
    while (SDL_PollEvent(&event) == 1) {
      if (event.type == SDL_EVENT_QUIT) {
        quit = 1;
      }
      if (event.type == SDL_EVENT_KEY_DOWN) {
        printf("Key pressed: %d %d\n", event.key.scancode, event.key.key);
      }
    }
    // SDL_GL_GetAttribute SDL_GL_CONTEXT_DEBUG_FLAG
    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0xFF, 0xFF);
    SDL_RenderClear(renderer);

    // Set renderer color red to draw the square
    SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);

    // Draw filled square
    SDL_RenderFillRect(renderer, &red_rect);

    /* Use TTF textures. */
    SDL_RenderTexture(renderer, texture1, NULL, &text_rect1);
    SDL_RenderTexture(renderer, texture2, NULL, &text_rect2);

    SDL_RenderPresent(renderer);
  }

  /* Deinit TTF. */
  SDL_DestroyTexture(texture1);
  SDL_DestroyTexture(texture2);
  TTF_Quit();

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
  return EXIT_SUCCESS;
}
