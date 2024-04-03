# COMP3015 CW1
# Thomas O'Toole
This application was written using Microsoft Visual Studio 2022, Version 17.7.6, on the Windows 10 Operating System.

This application has been designed to load 3D models, applying shading, lighting and rendering to them in real time. It was written using the C++, OpenGL and GLSL languages, and is meant to depict a work in progress model for a Final Year Project. The creative intent was to portray a work in progress game asset, with a showroom vibe to it, perhaps intended as a bonus feature for the game. 

The application works via the entry point - that being main.cpp -, initializing an instance of the SceneBasic_Uniform class. This instance of SceneBasic_Uniform is then responsible for several tasks such as window creation, rendering the scene, performing dynamic animation and so on. 

This application utilizes the Blinn-Phong lighting model - it offers more detail than lighting models such as the Diffuse model, without being excessively computationally expensive compared to its predecessor, the Blinn model. The work on this can primarily be found under the basic_uniform.frag file, under the shaders folder. The lighting model can be found to be used on the moving spotlight effect in the scene - refer to the scenebasic_uniform.cpp file for its implementation, with particular attention on the initScene (parameter implementation) update (implementation to make the spotlight move around the scene dynamically) and render (further parameter implementation) methods.

The foundations for texturing the character model have been laid but, unfortunately, do not work as intended. The entire scene has grey textures to it, which is not ideal. The code does exist for textures to be applied - refer to basic_uniform.vert -> main() and SceneBasic_Uniform.cpp -> initScene() - but whether due to the texture file itself (found under the media folder) or an error in programming, this could not be fixed in time.

To sum up each file's purpose:
- main.cpp: Entry point into the program, creates an instance of scenebasic_uniform.
- scenebasic_uniform.h: Method and variable initialization for the cpp file.
- scenebasic_uniform.cpp: Scene/window setup, model/light rendering.
- basic_uniform.vert: Transform model vertices model space to clip space, normals/texture coordinate calculation.
- basic_uniform.frag: Handles Blinn-Phong lighting model, texture mapping, computing colours for each fragment/pixel and spotlight effect.

 YouTube video:
 Part 1: https://www.youtube.com/watch?v=HBjWZTsQ25k
 Part 2: https://youtu.be/VRnSYSCGba4
