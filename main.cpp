#include "color.hpp"
#include "vec3.hpp"

#include <iostream>

using namespace std;

int main() {

    // Image parameters

    const int image_width = 256;
    const int image_height = 256;
    const int max_color = 256;

    // Printing the image in ASCII

    cout << "P3\n" << image_width << ' ' << image_height << "\n" << max_color << "\n";

    for (int j = image_height - 1; j >= 0; j--) {
        cerr << "\rScanlines remaining: " << j << ' ' << flush;
        for (int i = 0; i < image_width; i++) {
            color pixel_color(double(i) / (image_width - 1), double(j) / (image_height - 1), 0.25);
            write_color(cout, pixel_color);
        }
    }

    cerr << "\nDone.\n";
}