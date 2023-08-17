#include "rtweekend.h"
#include "camera.h"
#include "color.h"
#include "hittable_list.h"
#include "material.h"
#include "sphere.h"


using namespace std;



color ray_color(const ray& r, const color& background, const hittable& world, int depth) {
    hit_record rec;

    // If we've exceeded the ray bounce limit, no more light is gathered.
    if (depth <= 0)
        return color(0,0,0);

    // If the ray hits nothing, return the background color.
    if (!world.hit(r, 0.001, infinity, rec))
        return background;

    ray scattered;
    color attenuation;
    color emitted = rec.mat_ptr->emitted(rec.u, rec.v, rec.p);

    if (!rec.mat_ptr->scatter(r, rec, attenuation, scattered))
        return emitted;

    return emitted + attenuation * ray_color(scattered, background, world, depth-1);
}


hittable_list random_scene() {

    hittable_list world;

    auto ground_material = make_shared<lambertian>(color(.5,
                                                         .5,
                                                         .5));
    world.add(make_shared<sphere>(point3(0,-1000,0), 1000, ground_material));
    auto pertext = make_shared<noise_texture>(4);

    double r1 = random_double(0,.5);
    double r2 = random_double(0,.5);
    double r3 = random_double(0,.5);

    int r = random_int(-15, -5);
    int c = random_int(5, 15);

    for (int a = r; a < c; a++) {
        for (int b = r; b < c; b++) {
            auto choose_mat = random_double();
            point3 center(a + 4*random_double(), 1.8*random_double(), b + 1.5*random_double());

            if ((center - point3(4, 0.2, 0)).length() > 0.9) {
                shared_ptr<material> sphere_material;

                if (choose_mat < 0.8) {
                    // diffuse
                    auto earth_texture = make_shared<image_texture>("py_logo.jpg");
                    auto earth_surface = make_shared<lambertian>(earth_texture);
                    world.add(make_shared<sphere>(center, r1, earth_surface));
                    world.add(make_shared<sphere>(center, r2, make_shared<lambertian>(pertext)));
                } else if (choose_mat < 0.95) {

                    auto earth_texture = make_shared<image_texture>("c++_logo.jpg");
                    auto earth_surface = make_shared<lambertian>(earth_texture);
                    world.add(make_shared<sphere>(center, r3, earth_surface));
                    world.add(make_shared<sphere>(center, r1, make_shared<lambertian>(pertext)));
                } else  {
                    // glass
                    auto earth_texture = make_shared<image_texture>("py_logo.jpg");
                    auto earth_surface = make_shared<lambertian>(earth_texture);
                    world.add(make_shared<sphere>(center, r3, earth_surface));
                    world.add(make_shared<sphere>(center, r2, make_shared<lambertian>(pertext)));
                }
            }
        }
    }

    return world;
}


int main() {

    // Image

    const auto aspect_ratio = 16.0 / 9.0;
    const int image_width = 1200;
//    const int image_height = static_cast<int>(image_width / aspect_ratio);
    const int samples_per_pixel = 10;
    const int max_depth = 50;
    color background(0,0,0);

    // World

    hittable_list world;

    point3 lookfrom;
    point3 lookat;
    auto vfov = 40.0;
    auto aperture = 0.0;


    background = color(0.70, 0.80, 1.00);
    world = random_scene();
    lookfrom = point3(13,6,4);
    lookat = point3(0,0,0);
    vfov = 20.0;
    aperture = 0.1;


// Camera

    vec3 vup(0,1,0);
    auto dist_to_focus = 10.0;
    int image_height = static_cast<int>(image_width / aspect_ratio);

    camera cam(lookfrom, lookat, vup, vfov, aspect_ratio, aperture, dist_to_focus, 0.0, 1.0);

    // Render

    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int j = image_height-1; j >= 0; --j) {
        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
        for (int i = 0; i < image_width; ++i) {
            color pixel_color(0,0,0);
            for (int s = 0; s < samples_per_pixel; ++s) {
                auto u = (i + random_double()) / (image_width-1);
                auto v = (j + random_double()) / (image_height-1);
                ray r = cam.get_ray(u, v);
                pixel_color += ray_color(r, background, world, max_depth);
            }
            write_color(std::cout, pixel_color, samples_per_pixel);
        }
    }

    std::cerr << "\nDone.\n";
}