clc, clear all, close all
%% Kąty rotacji
teta1 = 1.09955743;
teta2 = -pi/2;
teta3 = -pi/2;
teta4 = 0.558505361;
%% Dlugości członów/wielkości translacji
d1 = 200;
d2 = 100; 
d3 = 105;
d4 = 90;

%% Macierze przekształceń jednorodnych
a1rotz = [cos(teta1) -sin(teta1) 0 0;
          sin(teta1) cos(teta1) 0 0;
          0 0 1 0;
          0 0 0 1];

a1transz = [1 0 0 0;
            0 1 0 0;
            0 0 1 d1;
            0 0 0 1];
 
a1rotx = [1 0 0 0;
          0 0 -1 0;
          0 1 0 0;
          0 0 0 1];


a2transz = [1 0 0 0;
            0 1 0 0;
            0 0 1 d2;
            0 0 0 1];

a2rotx = [1 0 0 0;
          0 0 -1 0;
          0 1 0 0;
          0 0 0 1];

a3transz = [1 0 0 0;
           0 1 0 0;
           0 0 1 d3;
           0 0 0 1];

a4rotz = [cos(teta4) -sin(teta4) 0 0;
          sin(teta4) cos(teta4) 0 0;
          0 0 1 0;
          0 0 0 1];

a4transz = [1 0 0 0;
            0 1 0 0;
            0 0 1 d4;
            0 0 0 1];
        
%% Obliczenia macierzy Ai
a1 = a1rotz * a1transz * a1rotx;
a2 = a2transz * a2rotx;
a3 = a3transz;
a4 = a4rotz * a4transz;

%% Macierz transformacji T40
T40 = a1 * a2 * a3 * a4;
