%% Parametry
Fs=1000;
N= 1000;
%% Wzory 
t=[0:N-1]/Fs;
T=N/Fs; %N = Fs*T
f=[0:N-1]/N*Fs;
dt=1/Fs;
df=1/T;
k=0:1:N-1
%% Sygnał
x=chirp(t,20,1,220);


%% FFT implementacja
for p=0:1:N-1
    x1=  x .* exp((-i*2*pi*k*p)./N);
    y1(p+1)=sum(x1);
    x2=  x .* (cos((-2*pi*k*p)/N) + i*sin((-2*pi*k*p)/N)); %Wzor Eulera 
    y2(p+1)=sum(x2); 
end
%% Plot FFT z funkcji
y=fft(x);

m=abs(y); % magnitude of X(jw)
p=rad2deg(unwrap(angle(y)));% unwraped phase

figure(1);
subplot(1,2,1)
plot(f,m,'green');
xlabel('Częstotliwość [Hz]');
ylabel('|H(f)|')  
xlim([0 220])
title('Widmo amplitudowo-czestotliwosciowe');
subplot(1,2,2),plot(f,p,'black');
xlabel('Częstotliwość [Hz]');
ylabel('Kąt [deg]');
title('Widmo fazowo-czestotliwosciowe')
%% Plot FFT implementacja 
p1=rad2deg(unwrap(angle(y1)));% unwraped phase
m1=abs(y1);
figure(2)
title('Implementacja')
subplot(1,2,1), plot(f,m1,'green');
xlabel('Częstotliwość [Hz]');
ylabel('|H(f)|')  
xlim([0 220])
title('Widmo amplitudowo-czestotliwosciowe');

subplot(1,2,2), plot(f,p1,'black');
xlabel('Częstotliwość [Hz]');
ylabel('Kąt [deg]')
title('Widmo fazowo-czestotliwosciowe')

%% Plot FFT implementacja EULER
p2=rad2deg(unwrap(angle(y2)));% unwraped phase
m2=abs(y2);
figure(3)
title('Implementacja ze wzorem Eulera')
subplot(1,2,1), plot(f,m2,'green');
xlabel('Częstotliwość [Hz]');
ylabel('|H(f)|')  
xlim([0 220])
title('Widmo amplitudowo-czestotliwosciowe');
subplot(1,2,2), plot(f,p2,'black');
xlabel('Częstotliwość [Hz]');
ylabel('Kąt [deg]')
title('Widmo fazowo-czestotliwosciowe')

