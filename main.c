// main.py
#include <stdio.h>

int width = 80;
int height = 40;
int max_iterations = 1000;

double center_x = -0.75;
double center_y = 0;
double zoom = 1;

char characters[] = "17235698";

int mandelbrot(double cx, double cy, int max_iterations) {
    double zx = 0.0;
    double zy = 0.0;
    int iterations = 0;

    while (zx * zx  + zy * zy <= 4 && iterations < max_iterations) {
        double n_zx = zx * zx - zy * zy + cx;
        double n_zy = 2 * zx * zy + cy;
        
        zy = n_zy;
        zx = n_zx;

        iterations = iterations + 1;
    }
    return iterations;
}

int main(void) {
    for (int y = 0; y < height; y++){
        for (int x = 0; x < width; x++) {
            double visible_width = 3.5 / zoom;
            double visible_height = 2.0 / zoom;
            double cx = center_x + (x - width / 2) * visible_width / width;
            double cy = center_y + (y - height / 2) * visible_height / height;

            int iterations = mandelbrot(cx, cy, max_iterations);
        
            if (iterations == max_iterations) {
                printf(" ");
            } else {
                int index = iterations * 8 / max_iterations;
                printf("%c", characters[index]);
            }
        }
        printf("\n");
    }
    return 0;
}