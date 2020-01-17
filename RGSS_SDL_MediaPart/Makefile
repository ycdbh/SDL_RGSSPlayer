CC=g++
INCLUDE_PATH=../include
DEP_LIB=../lib/x64/SDL2.dll ../lib/x64/SDL2_ttf.dll ../lib/x64/SDL2_image.dll 
DEP_RSM=RGSS_SDL_MediaPart.cpp pch.cpp rsm_Font.cpp rsm_Graphics.cpp rsm_Sprite.cpp rsm_Viewport.cpp rsm_bitmap.cpp rsm_main.cpp

rsm.dll: $(DEP_RSM)
	$(CC) -shared -std=c++11 $(DEP_RSM) $(DEP_LIB) -I $(INCLUDE_PATH) -o rsm.dll
