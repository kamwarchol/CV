clc; clear; close all;

obraz = imread('Database/Lena.jpg');
obraz = rgb2gray(obraz);

poziome = edge(obraz,'sobel',0.1, 'horizontal');
pionowe = edge(obraz,'sobel',0.1, 'vertical');
roberts = edge(obraz,'roberts');
canny = edge(obraz,'canny');

figure(1)
subplot(1,2,1)
imshow(obraz)
title('Obraz orginalny')
subplot(1,2,2)
imshow(poziome)
title('Sobel poziomy')

figure(2)
subplot(1,2,1)
imshow(obraz)
title('Obraz orginalny')
subplot(1,2,2)
imshow(poziome)
title('Sobel pionowy')

figure(3)
subplot(1,2,1)
imshow(obraz)
title('Obraz orginalny')
subplot(1,2,2)
imshow(roberts)
title('Roberts')

figure(4)
subplot(1,2,1)
imshow(obraz)
title('Obraz orginalny')
subplot(1,2,2)
imshow(canny)
title('Canny')
