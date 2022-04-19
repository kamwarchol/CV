clc; clear; close all;

obraz = imread('Database/Lena.jpg');
obraz = rgb2gray(obraz);
%% dolnoprzepustowe
mask1 = (1/16)*[1 1 1 1; 1 1 1 1; 1 1 1 1; 1 1 1 1 ]; %filtr usredniajacy
mask2 = (1/20)*[1 1 1; 1 12 1; 1 1 1]; %usredniajacy, ale mniej rozmazuje
mask3 = (1/16)*[1 2 1; 2 4 2; 1 2 1]; %gauss
%% gornoprzestowe
mask4 =(1)*[-1 -1 -1; -1 9 -1; -1 -1 -1];
mask5 =(1/16)*[0 -1 0; -1 20 -1; 0 -1 0];
%% uwypuklajacy 
mask6 =(1)*[-1 -1 -1; 0 1 0; 1 1 1];
%% laplace - wykrywanie krawedzi
mask7 =(1)*[0 -1 0; -1 4 -1;0 -1 0];
%% filtr sobela - krawedzie poziome
mask8 = (1)*[1 2 1; 0 0 0;-1 -2 -1];
%% ustawienia filtrow
im_filt1 = conv2(double(obraz), double(mask1));
im_filt2 = conv2(double(obraz), double(mask2));
im_filt3 = conv2(double(obraz), double(mask3));
im_filt4 = conv2(double(obraz), double(mask4));
im_filt5 = conv2(double(obraz), double(mask5));
im_filt6 = conv2(double(obraz), double(mask6));
im_filt7 = conv2(double(obraz), double(mask7));
im_filt8 = conv2(double(obraz), double(mask8));



%% wyswietlanie
figure(1)
subplot(1,2,1)
imshow(obraz)
title('Bez filtra')
subplot(1,2,2)
imshow(uint8(im_filt1));
title('Filtr usredniajacy')

figure(2)
subplot(1,2,1)
imshow(obraz)
title('Bez filtra')
subplot(1,2,2)
imshow(uint8(im_filt2));
title('Filtr usredniajacy z mniejszym rozmazaniem')

figure(3)
subplot(1,2,1)
imshow(obraz)
title('Bez filtra')
subplot(1,2,2)
imshow(uint8(im_filt3));
title('Filtr z wykorzsystaniem funkcji Gaussa')

figure(4)
subplot(1,2,1)
imshow(obraz)
title('Bez filtra')
subplot(1,2,2)
imshow(uint8(im_filt4));
title('Filtr usun srednia')

figure(5)
subplot(1,2,1)
imshow(obraz)
title('Bez filtra')
subplot(1,2,2)
imshow(uint8(im_filt5));
title('Filtr usun srednia z najmniejszym wzmocneiniem szumów')

figure(6)
subplot(1,2,1)
imshow(obraz)
title('Bez filtra')
subplot(1,2,2)
imshow(uint8(im_filt6));
title('Filtr uwypuklajacy południe')

figure(7)
subplot(1,2,1)
imshow(obraz)
title('Bez filtra')
subplot(1,2,2)
imshow(uint8(im_filt7));
title('Filtr Laplace')

figure(8)
subplot(1,2,1)
imshow(obraz)
title('Bez filtra')
subplot(1,2,2)
imshow(uint8(im_filt8));
title('Filtr Sobela - krawedzie poziome')

