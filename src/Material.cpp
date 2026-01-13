#include "../include/Material.h"
#include "../include/Sphere.h"
#include "../include/Utils.h"
#include <cmath>

bool Lambertian::scatter(const Ray& ray_in, const HitRecord& rec, 
                         Color& attenuation, Ray& scattered) const {
    Vec3 scatter_direction = rec.normal + random_unit_vector();
    
    // Catch degenerate scatter direction
    if (scatter_direction.length_squared() < 1e-8) {
        scatter_direction = rec.normal;
    }
    
    scattered = Ray(rec.p, scatter_direction);
    attenuation = albedo;
    return true;
}

bool Metal::scatter(const Ray& ray_in, const HitRecord& rec, 
                    Color& attenuation, Ray& scattered) const {
    Vec3 reflected = reflect(ray_in.dir.normalized(), rec.normal);
    scattered = Ray(rec.p, reflected + fuzz * random_in_unit_sphere());
    attenuation = albedo;
    return (dot(scattered.dir, rec.normal) > 0);
}
