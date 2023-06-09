# 3D-Renderer-and-Raytracer

This repository contains a simple raytracing engine written in C++. The engine can render a variety of scenes, including spheres, cubes, and triangles. This project demonstrated my skills in C++, object-oriented programming, and software design. It also allowed me to learn about modern C++ features, such as lambdas, move semantics, and constexpr.

The main focus of this project was to understand the fundamentals of raytracing and gain practical experience in implementing a raytracer from scratch. By going through this project, I developed a deep understanding of concepts such as ray-object intersection, shading, anti-aliasing, and more.

# Features

Ray Tracing: Implements the core ray tracing algorithm, tracing rays into the scene to compute colors for each pixel.
Sphere and Material Support: Supports rendering of spheres with different materials, including diffuse, metallic, and dielectric materials.
Shading: Implements shading models for realistic lighting effects, including diffuse reflection, specular highlights, and soft shadows.
Anti-aliasing: Applies anti-aliasing techniques to reduce pixelation and produce smoother images.
Multi-threading: Utilizes multi-threading to speed up rendering by distributing work across multiple processor cores.

# Usage

1. Clone the repository:

`git clone https://github.com/zkabyken/3D-Renderer-and-Raytracer.git`

2. Build the project using the Makefile I wrote:

`make`

3. Run the raytracer executable and render the image into a ppm file:

`./raytracer > image.ppm`

# Resources 

[Ray Tracing in One Weekend](https://raytracing.github.io/books/RayTracingInOneWeekend.html#thevec3class): The tutorial series that inspired this project and served as a guide.
[C++ Documentation](https://en.cppreference.com/w/): Comprehensive documentation for the C++ programming language.


# Contributing

Contributions are welcome! If you find any issues or have suggestions for improvements, please feel free to open an issue or submit a pull request.

