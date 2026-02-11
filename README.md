*This project has been created as part of the 42 curriculum by tkhamis.*

# fract-ol

<p align="center">
  <img src="https://img.shields.io/badge/42-Project-blue" />
  <img src="https://img.shields.io/badge/Language-C-green" />
  <img src="https://img.shields.io/badge/Status-Completed-success" />
</p>

## Description

**fract-ol** is a 42 curriculum project focused on computer graphics and complex numbers.

The goal is to create a small, graphically smooth fractal explorer using the MiniLibX library.

The project explores:

- The Mandelbrot set and Julia sets.
- Mathematical mapping from screen pixels to the complex plane.
- Interactive zooming at the mouse position.
- Efficient pixel manipulation using a single-image buffer.
- This project reinforces a solid understanding of event handling (hooks), floating-point arithmetic, and rendering optimization.

---

## Instructions

### Compilation

Compile the project using:
```bash
make
./fractol mandelbrot
./fractol julia [real] [imaginary]
./fractol leaf
```

Controls
Mouse Wheel: Zoom in/out at the cursor position.

Arrows: Move the view.

ESC: Exit the program.


## Resources

42 Subject PDF: fract-ol

MiniLibX Documentation: Introduction to MLX

Complex Numbers: Understanding the Complex Plane

The Mandelbrot Set: Numberphile Explanation
