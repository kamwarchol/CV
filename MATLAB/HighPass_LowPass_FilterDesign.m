N      = 25e3;              % number of samples
x      = rand(1,N)*10;      % generate and "upscale" noise (for clear% visualization)
x      = x -mean(x);       % remove DC (for clear visualization)
cutoff = 4000;              % frequencies below this value [Hz] are removed 
fs     = 25e3;              % sampling frequencyd
df     = fs/N;              % frequency resolution (equal to 1/duration)
f      = 0:df:fs/2;         % frequency axis
y = lowpass(x,cutoff,fs);  % FILTERS signal x and stores as y
%y = highpass(x,cutoff,fs);  % FILTERS signal x and stores as y


% Original signal
X = abs(fft(x));            % Full-resolution spectrum calculation -step 1
X = X(1:N/2+1)/(N/2);       % Full-resolution spectrum calculation -step 2
plot(f,X); hold on;% Filtered signal
Y = abs(fft(y));            % Full-resolution spectrum calculation -step 1
Y = Y(1:N/2+1)/(N/2);       % Full-resolution spectrum calculation -step 2
plot(f,Y,'--');% Axis description and settings
axis tight;
title('Full-resolution spectrum');
xlabel('Frequency [Hz]');
ylabel('Amplitude');
legend('Original signal','Filtered signal')
set(gca,'fontsize',8);
