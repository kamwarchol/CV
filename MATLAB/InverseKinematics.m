clc, clear all, close all
%% Kąty rotacji
%teta1 = 0;
%teta2 = -pi/2;
%teta3 = -pi/2;
%teta4 = pi;
%% Dlugości członów/wielkości translacji
%d1 = 2;
%d2 = 1; 
d3 = 105;
d4 = 90;

syms teta1 teta4 d1 d2 
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
d3 = 105
d4 = 90
T40 = a1 * a2 * a3 * a4;

%% Wartości z macierzy T40
x=89.1;
y=-34.399;
z=5;
a=0.8572;
b=-0.8572;
%% Obliczenia

eqn1= T40(1,4)==x;
eqn2= T40(2,4)==y;
eqn3= T40(3,4)==z;
eqn4= T40(1,1)==a;
eqn5= T40(2,2)==b;
eqns = [eqn1,eqn2,eqn3, eqn5];


wynik = solve(eqns,[d1 d2 teta1,teta4])

ResultD1 = wynik.d1
ResultD2 = wynik.d2
ResultTeta1 = wynik.teta1
ResultTeta4 = wynik.teta4
