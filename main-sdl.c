// cc *.c $(sdl2-config --cflags --libs)
//sudo apt install libsdl2-dev
// cd ~/src/sdl2-in-c/ && rm a.out && cc *.c $(sdl2-config --cflags --libs) && ./a.out && echo STOP
//sudo apt install libsdl2-2.0-0 libsdl2-dev libsdl2-image-2.0-0 libsdl2-image-dev
// cd ~/src/sdl-tutorial/ && cc *.c $(pkg-config --cflags --libs sdl2 SDL2_image) && ./a.out && echo STOP
//https://www.geeksforgeeks.org/sdl-library-in-c-c-with-examples/

#include <SDL2/SDL.h>
#include <stdio.h>

void ensure(int return_code){
  if(return_code != 0)
    printf("error initializing SDL: %s\n", SDL_GetError());
}

int events(){
  SDL_Event event;
  while (SDL_PollEvent(&event)) {
    switch (event.type) {
      case SDL_QUIT: return 0;
    }
  }
  return 1;
}

int in_rect(int x, int y, struct SDL_Rect *r) {
  return (x >= r->x) && (y >= r->y) &&
          (x < r->x + r->w) && (y < r->y + r->h);
}

  int rgb[][3] = {
  {203, 203, 203}, // Gray
  {254, 254,  31}, // Yellow
  {0,   255, 255}, // Cyan
  {0,     0,   0}, // Black
  {0,   254,  30}, // Green
  {255,  16, 253}, // Magenta
  {253,   3,   2}, // Red
  {18,   14, 252}  // Blue
  };
  int rgb_size = sizeof rgb / sizeof rgb[0];

void draw_colors(SDL_Renderer * renderer, int i_current, int view_width, int view_height){

  SDL_Rect colorBar;
  colorBar.x = 0; colorBar.y = 0; colorBar.w = view_width/rgb_size; colorBar.h = view_height;

  int* color;
  SDL_Rect rectangle;

  int background_color[] = { 50, 50, 50 };
  for(int i = -1 ; i <= i_current ; i++ ){
    if(i==-1){
      color = background_color;
      SDL_Rect view={.x=0,.y=0,.w=view_width,.h=view_height};
      rectangle = view;
    }else{
      color = rgb[i];
      colorBar.x = i*colorBar.w;
      rectangle = colorBar;
    }
    SDL_SetRenderDrawColor( renderer, color[0], color[1], color[2], 255 );
    SDL_RenderFillRect( renderer, &rectangle );
  }
}

#define main3 main

// images (third app)
int main3(int argc, char* argv[]){
    ensure( SDL_Init( SDL_INIT_VIDEO ) );
    int view_width=400, view_height=300;
    SDL_Window * window;
    SDL_Renderer * renderer;
    ensure( SDL_CreateWindowAndRenderer( view_width, view_height, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE, &window, &renderer ) );

    SDL_Surface * image = SDL_LoadBMP("assets/P.bmp");
    SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer, image);

    while(events()){
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderClear(renderer);

        SDL_Rect dst_rect = { 5, 15, 100, 100 };
        SDL_RenderCopy(renderer, texture, NULL, &dst_rect);

        //SDL_RenderCopy(renderer, texture, NULL, NULL);

        SDL_RenderPresent( renderer );
    }

    SDL_DestroyTexture(texture);
    SDL_FreeSurface(image);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();
    return 0;
}

// simpler (second app)
int main2(int argc, char* argv[]){
    ensure( SDL_Init( SDL_INIT_VIDEO | SDL_INIT_TIMER ) );
    int view_width=400, view_height=300;
    SDL_Window * window;
    SDL_Renderer * renderer;
    ensure( SDL_CreateWindowAndRenderer( view_width, view_height, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE, &window, &renderer ) );

    double x1=0;
    double x2=0;

    int lastTime = SDL_GetTicks(), currentTime;
    while(events()){
        currentTime = SDL_GetTicks();
        int dt = currentTime - lastTime;
        lastTime = currentTime;

        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderClear(renderer);

        x1+=dt*0.02;
        if(x1>150) x1=0;
        SDL_Rect button1={.x=x1,.y=10,.w=50,.h=50};
        int button_color[] = { 0, 50, 50 };
        SDL_SetRenderDrawColor( renderer, button_color[0], button_color[1], button_color[2], 255 );
        SDL_RenderFillRect( renderer, &button1 );

        x2+=dt*0.08;
        if(x2>150) x2=0;
        SDL_Rect button2={.x=x2,.y=10+50+10,.w=50,.h=50};
        //int button_color[] = { 0, 50, 50 };
        SDL_SetRenderDrawColor( renderer, button_color[0], button_color[1], button_color[2], 255 );
        SDL_RenderFillRect( renderer, &button2 );

        SDL_RenderPresent( renderer );
    }

    SDL_DestroyWindow( window );
    SDL_DestroyRenderer( renderer );
    SDL_Quit();
    return 0;
}

// more advanced (first app)
int main1(int argc, char* argv[])
{
  ensure( SDL_Init( SDL_INIT_VIDEO | SDL_INIT_TIMER ) );
  int view_width=400, view_height=300;
  SDL_Window * window;
  SDL_Renderer * renderer;
  ensure( SDL_CreateWindowAndRenderer( view_width, view_height, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE, &window, &renderer ) );

  int i = -1;
  int lastTime = SDL_GetTicks(), currentTime;
  while(events()){

    SDL_GetWindowSize(window, &view_width, &view_height);

    draw_colors(renderer, i, view_width, view_height);

    int button_color[] = { 0, 50, 50 };
    SDL_Rect button={.x=10,.y=10,.w=50,.h=50};
    SDL_SetRenderDrawColor( renderer, button_color[0], button_color[1], button_color[2], 255 );
    SDL_RenderFillRect( renderer, &button );

    int x, y; Uint32 buttons;
    SDL_PumpEvents(); buttons = SDL_GetMouseState(&x, &y);
    if ((buttons & SDL_BUTTON_LMASK) != 0 && in_rect(x,y, &button) ) {
      SDL_Event quit_event;
      quit_event.type = SDL_QUIT;
      SDL_PushEvent(&quit_event);
    }

    SDL_RenderPresent( renderer );

    currentTime = SDL_GetTicks();
    if (currentTime >= lastTime + 500) {
      i += 1;
      lastTime = currentTime;
    }
    if( i >= rgb_size ) i = -1;
  }
  SDL_DestroyWindow( window );
  SDL_DestroyRenderer( renderer );
  SDL_Quit();
  return 0;
}


//==========================================

// . sdl-cross-compile.sh
// wine sdl-app.exe

#if defined(_WIN64)

#include <windows.h>

int WINAPI WinMain( HINSTANCE hInstance,    // HANDLE TO AN INSTANCE.  This is the "handle" to YOUR PROGRAM ITSELF.
                    HINSTANCE hPrevInstance,// USELESS on modern windows (totally ignore hPrevInstance)
                    LPSTR szCmdLine,        // Command line arguments.  similar to argv in standard C programs
                    int iCmdShow )          // Start window maximized, minimized, etc.
{
  char* argv[]={"main-sdl"};
  return main(1,argv);
}

#endif
