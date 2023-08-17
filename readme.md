
<!-- PROJECT LOGO -->
<br />
<div align="center">
  <a href="https://github.com/cekcreator/Ray_Tracing_Proj">
    <img src="img/logo.jpg" alt="img/img_from_book.jpg" width="100" height="100">
  </a>

<h3 align="center">Ray Tracing algorithm following Peter Shirleys books</h3>

  <p align="center">
    Following Peter Shirley's "Ray Tracing the in One Weekend", and "Ray TRaving the Next Week", I created a ray traced 
    image adding my own twist of the two coding languages I use the most.
  </p>
</div>


<!-- ABOUT THE PROJECT -->
## About The Project

I added in both the Perlin blurring and different coding logos for the generated spheres. I was able to add the jpg logos for the coding by utilizing a library called stb. STB is a C++ library commonly used for images and 3d images in C++. I then went on into ray tracings' second book to figure out how to create the Perlin blurring. The Perlin blurring takes in a 3d point and then returns a similar randomized number. I then smoothed out the blurring using one of the recommended techniques from the book. The technique I used was called “Hermitian smoothing”. For the texture mapping, I had to add functionality to store all the RGB values and scale them, I then calculated the mapping from the 2d image to the 3d object by mapping the surface point and the hit point from the 2d texture info. After that, I changed the view coordinates to get a better view of what I had changed. I finally then randomized the number of spheres. The code may take a bit to run but the executable is there incase of any compiler issues.

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- GETTING STARTED -->
## Checking it out

### Prerequisites
You'll need a c++ compiler on your system, I recommend g++ as it's what I use.

### Installation

1. Clone the repo
   ```sh
   git clone https://github.com/cekcreator/Ray_Tracing_Proj.git
   ```
2. cd into src
   ```sh
   cd src
   ```
3. Run the cli command to create the picture
   ```c++
   g++ -std=c++11 test.cpp -o test 
   ```
4. Excute the generated executable and feed it into a ppm file
   ```c++
   ./image > image.ppm 
   ```

<p align="right">(<a href="#readme-top">back to top</a>)</p>


<!-- CONTACT -->
## Contact

Caleb Kumar - https://www.linkedin.com/in/caleb-k-0232b719b/

Project Link: [https://github.com/cekcreator/Ray_Tracing_Proj](https://github.com/cekcreator/Ray_Tracing_Proj)

<p align="right">(<a href="#readme-top">back to top</a>)</p>


<!-- ACKNOWLEDGMENTS -->
## Acknowledgments

* [Peter Shirley](https://github.com/RayTracing)

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->

[linkedin-shield]: https://img.shields.io/badge/-LinkedIn-black.svg?style=for-the-badge&logo=linkedin&colorB=555
[linkedin-url]: https://linkedin.com/in/linkedin_username
