# Dracarys :dragon:
> A personal game development library in C99 

## What is it?

Dracarys aims to provide a simple and easy to use library for game development. It is my personal project to make my "perfect tool" for making games, and is therefore not meant to be the universal perfect library for everyone's use. Dracarys is a learning project, an attempt to make custom tools. But it will rely on third parties where it might need to, and it should never be too reliant on itself. This means that if my custom implementation isn't good enough, it can easily be swapped. Dracarys needs to be low level enough for my needs of learning, and it should serve as a base for creating higher level components. It should include higher level components like model loading, and physics, but it will be minimal since these kinds of things might work better if implemented in the actual game. Dracarys is the game library I want to use for all my projects, the same way I might use raylib, monogame, or miniquad.

> My learning project to grow with. It should be powerful enough to make the games I want to make. Because my interest is mainly in 3D games, 2D will have little to no focus. But because lower level functions are exposed, a customized 2D renderer could be written at any time. 

## Why use it?

Raylib is my favorite library because of its simplicity, and strengths. It is very easy to make projects of all kinds, and serves as an amazing tool for game development. Dracarys aspires to be the same, at least for me. Dracarys to me should be like excalibur to Arthur, it is a tool that will grow with me, and it is a tool that should be powerful. So why use Dracarys? Dracarys aims to provide the low level control I want to use when I need to for games. For example, I should be able to use a very thin abstraction layer over a graphics API like OpenGL to write custom graphics code. It should be easy to change when I need to, something that's trivial for me because I made this project so I know the ins and outs hehe; but I shouldn't have to change the source code much, if ever. Furthermore, it should have high level constructs ready when I desire. An easy to customize 3D renderer that abstracts the lower level graphics abstraction so I can focus on the real work without worrying about cross platform graphics. Or an easy to use physics library to just drop in to any game? That sounds sweet! Dracarys aims to expose a lot of lower level functions to give maximum power for me to reuse across special projects, and it also aims to provide high level features that I might end up writing over and over again. 

> Dracarys is for those who want to start with empty acres of land, or for those who want to start with a neat farm. Low level stuff for programming, and high level stuff for making games.

## Platforms

At the moment, I do not want to focus on supporting literally every platform and device out there, nor every language. My current development machine is Windows, and that is the platform I will focus on when making games. However, I knew before the project that I would want to use Dracarys for game jams. So I added web support by using emscripten, and now I can finally target the web with Dracarys and my precious C code! It'll be a huge flex for game jams. :grinning:

> Dracarys supports the platforms I have access to at the moment which is Windows and the Web. This doesn't mean I'll ditch other platforms, because I might be interested in Mac and Linux in the future. 

## ROADMAP
- [ ] Loading textures. Probably integrate stb libraries.
- [ ] Using shader uniforms.
- [ ] Custom math library 
- [ ] Camera system
- [ ] Shader materials and lighting 
- [ ] Model loading. Maybe not assimp this time? (OBJ, STL, and maybe FBX) 
- [ ] GUI - Nuklear, or maybe a custom implementation?
- [ ] Study some more graphics programming!
- [X] Logging library. Gotta be better than a `printf` right?
- [ ] 3D Flappy bird with actual 3D models, sound effects, UI, etc. Should be playable on the web too. This is when my work comes to fruition.

## Planned for the future

- [ ] Vulkan support
- [ ] Asset pipeline
- [ ] Asset packer
- [ ] Level Editor

...And more!
