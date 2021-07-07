#!/bin/bash

# Avoid using the poorly optimized (for Wine) DirectX Renderer
export SDL_RENDER_DRIVER=opengl

# Enable threaded OpenGL for Mesa
# export mesa_glthread=true

# Enable threaded OpenGL for Nvidia
# export __GL_THREADED_OPTIMIZATIONS=1

# Prefer native dinput and ddraw
export WINEDLLOVERRIDES="dinput,ddraw=n,b"

wine Open1560.exe $@
