![FDF Chronicles: 2D Projections](https://pedromelodev.com/wp-content/uploads/2024/01/42-fdf-thumb-2-1024x1019.png)
*Understanding 2D projections by parsing and converting matrices at Ecole 42.*

---

### FDF Chronicles: 2D Projections

[**It's been a while since my last article! Last time, I wrote about Virtual Machines. Check my article by clicking.**](https://pedromelodev.com/index.php/2023/11/14/born2beroot-virtual-machines-debian-secure-server-mastery/)

To be honest, this project FDF was a huge challenge in my journey. Creating an abstract perspective from matrix conversions was my biggest and toughest goal. To give you a better knowledge about the FDF project, I will give a short and pragmatic introduction to how it works.

The journey of the FDF Chronicles: 2D Projections is to create a program that will receive a simple map in a file format .fdf. We presume this file contains the coordinates of a landscape which will be displayed in our output. So, in this image, you will understand a little bit of what kind of files we are expecting:

![FDF Chronicles: 2D Projections](https://pedromelodev.com/wp-content/uploads/2024/01/file-exemple-1-1024x292.png)
*This is what we are expecting in our .fdf files.*

**Each number from the file has 3 representations:**
- The **horizontal position** corresponds to its **axis**;
- The **vertical position** corresponds to its **ordinate**;
- The **value itself** corresponds to the **altitude**.

It could look a little bit nonsense and confusing right now. So, I will show the expected output from this same file and you will try to get it:

![Expected output from the program.](https://pedromelodev.com/wp-content/uploads/2024/01/42-fdf.png)

[If you are looking for some code to help your development you can check my GitHub by clicking.](https://github.com/pedromelocf/42_fdf)

**Disclaimer:**
This article "FDF Chronicles: 2D Projections" represents my perspective about my understanding of the scope of this project, and it might contain incorrect information. If you found any mistakes, I would be grateful if you sent them to me to make corrections.

**Summary:**
1. What is an isometric projection?
2. Think about your data structure very well!
3. How drawing lines between coordinates?

---

### Isometric projections and videogames

![Age of Empires](https://pedromelodev.com/wp-content/uploads/2024/01/ageofempires.png)
*Age of Empires: Example of isometric projections games.*

As I am a game lover, this is the best way to visualize the power of isometric views. Somehow, we created the idea that this is a 3D representation. But it is not! Each object works in the same abstract way as our maps from the FDF project.

At the time of development, 3D graphical representations demanded a lot of GPU resources, which were not too much available at that time (we are talking about 2000s).

To create a short description, isometric projections use angles between the x-axis, y-axis, and z-axis equal to 120 degrees. To do this, we need to convert our matrix using formulas that will apply this perspective.

![This is an image with isometric projections.](https://pikuma.com/images/blog/isometric-projection-in-games/isometric-angles.png)
[This article is very good to show more information about isometric projections in games.](https://pikuma.com/blog/isometric-projection-in-games)
[Also, check this one from Wikipedia.](https://en.wikipedia.org/wiki/Isometric_video_game_graphics)

---

#### Dedicate good time to create your data structures

Right now, as I finished the project, I can create the best data structure from my perspective. But, at the beginning of this project, I didn´t have to understand and used structures and lists.

So, my tools were a little bit scarce and this is good because I spent a long time thinking about how I could manage my data in the best approach. And right now I can see it very clearly. So, if you also don´t have a deep comprehension of this topic, this is a great opportunity to create this idea. It will demand more time, but it is a good investment.

In my case, I first collected all information in a linked list with a structure containing x, y, and z values. To collect all coordinates from the file, use split and get next-line functions. Then, used two conversion functions to convert the matrix using my linked list and applying isometric conversions, and scales, using width and height dimensions from the map.

[If you are looking for some code to help your development you can check my GitHub by clicking.](https://github.com/pedromelocf/42_fdf)

---

#### Line drawing algorithms: how to use it?

Drawing lines is a good challenge in the FDF project. After we had all the positions in our matrix, we had to "connect" all points from our map. In my case, I used Bresenham's line algorithm.

![Line drawing algorithm.](https://media.geeksforgeeks.org/wp-content/uploads/BresenhamLine.png)

To draw lines, we need to draw all pixels between the initial coordinate to the final coordinate, using a while loop that increments and prints each pixel between these points. In FDF, our logic needs to do this from position x -> x+ 1, and x -> width for almost all map coordinates from our matrices.

![Draw_map function.](https://pedromelodev.com/wp-content/uploads/2024/01/Captura-de-tela-de-2024-01-14-15-28-03.png)

I was only concerned with this step when I had all my data correctly stored. It is also good to validate if the pixels are within the window height and width to avoid segmentation faults in your program.

---

#### Maps Examples

**Elem.fdf:**

![Input elem.fdf](https://pedromelodev.com/wp-content/uploads/2024/01/image.png)
![Output elem.fdf](https://pedromelodev.com/wp-content/uploads/2024/01/Captura-de-tela-de-2024-01-14-14-44-10-1024x711.png)

**Pyra.fdf:**

![Input pyra.fdf](https://pedromelodev.com/wp-content/uploads/2024/01/Captura-de-tela-de-2024-01-14-15-33-14.png)
![Output pyra.fdf](https://pedromelodev.com/wp-content/uploads/2024/01/Captura-de-tela-de-2024-01-14-14-43-40-1024x711.png)

**Pyramid.fdf:**

![Input pyramid.fdf](https://pedromelodev.com/wp-content/uploads/2024

/01/image-1.png)
![Output pyramid.fdf](https://pedromelodev.com/wp-content/uploads/2024/01/Captura-de-tela-de-2024-01-14-14-42-42-1024x711.png)

---

#### Documentation

If you want a deeper understanding of this project's topics, I recommend these links that can help you in your journey. Thank you for reading FDF Chronicles: 2D Projections

- [My GitHub repository.](https://github.com/pedromelocf/42_fdf)
- [42 São Paulo Student repository](https://github.com/alissonmarcs/fdf)
- [Line drawing algorithm](https://github.com/hanrell/bresenham-rasterization)
- [Another line-drawing algorithm](https://www.geeksforgeeks.org/bresenhams-line-generation-algorithm)
- [MLX 42 Codam graphics library](https://github.com/codam-coding-college/MLX42)

**Hope you enjoy it! I would love to talk about this project or other subjects. Feel free to reach me! Happy 2024!**

---

> "If you wish to improve, be content to appear clueless or stupid in extraneous matters—don't wish to seem knowledgeable. And if some regard you as important, distrust yourself."
> - Enchiridion - Epictetus
```
