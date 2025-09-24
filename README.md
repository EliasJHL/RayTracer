# Raytracer Project

## Project Overview

This project is a raytracer implementation designed to render 3D scenes based on configuration files. It uses a modular architecture to separate concerns such as mathematical operations, scene parsing, and rendering primitives. The project is written in C++ and follows object-oriented principles.

<img width="1405" height="757" alt="image" src="https://github.com/user-attachments/assets/8f04747b-c7dc-47f3-a153-054834a8d4ef" />

---

## Requirements

C++17 for filesystem

## Project Structure

Here is the directory tree of the project:

```plaintext
raytracer/
├── include/
│   ├── Math/
│   │   ├── Color.hpp
│   │   ├── Ray.hpp
│   │   ├── Transform.hpp
│   │   └── Vector3D.hpp
│   ├── Raytracer/
│   │   ├── Lights/
│   │   │   ├── AmbientLight.hpp
│   │   │   ├── DirectionalLight.hpp
│   │   │   └── ILight.hpp
│   │   ├── Materials/
│   │   │   ├── FlatMaterial.hpp
│   │   │   └── IMaterial.hpp
│   │   ├── Primitives/
│   │   │   ├── Cone.hpp
│   │   │   ├── Cylinder.hpp
│   │   │   ├── IPrimitive.hpp
│   │   │   ├── Plane.hpp
│   │   │   └── Sphere.hpp
│   │   └── Scene/
│   │       ├── Camera.hpp
│   │       ├── Image.hpp
│   │       ├── Renderer.hpp
│   │       ├── Scene.hpp
│   │       └── SceneLoader.hpp
│   │   
│   └── Utils/
│       ├── ConfigParser.hpp
│       ├── Error.hpp
│       ├── Logger.hpp
│       ├── Parser.hpp
│       ├── PPMWriter.hpp
│       └── Timer.hpp
├── src/
│   ├── main.cpp
│   ├── Math/
│   │   ├── Color.cpp
│   │   ├── Ray.cpp
│   │   ├── Transform.cpp
│   │   └── Vector3D.cpp
│   ├── Raytracer/
│   │   ├── Lights/
│   │   │   ├── AmbientLight.cpp
│   │   │   ├── DirectionalLight.cpp
│   │   │   └── ILight.cpp
│   │   ├── Materials/
│   │   │   ├── FlatMaterial.cpp
│   │   │   └── IMaterial.cpp
│   │   ├── Primitives/
│   │   │   ├── Cone.cpp
│   │   │   ├── Cylinder.cpp
│   │   │   ├── IPrimitive.cpp
│   │   │   ├── Plane.cpp
│   │   │   └── Sphere.cpp
│   │   └── Scene/
│   │       ├── Camera.cpp
│   │       ├── Image.cpp
│   │       ├── Renderer.cpp
│   │       ├── Scene.cpp
│   │       └── SceneLoader.cpp
│   └── Utils/
│       ├── ConfigParser.cpp
│       ├── Error.cpp
│       ├── Logger.cpp
│       ├── Parser.cpp
│       ├── PPMWriter.cpp
│       └── Timer.cpp
├── scenes/
│   ├── scene1.json
│   ├── scene2.json
│   └── scene3.json
├── screenshots/
│   └── scene1.ppm
├── Makefile
└── README.md
```
