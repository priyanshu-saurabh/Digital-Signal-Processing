clc;
clear;
close all;

% basic setup
Fs = 8000;
N = 16;
t = (0:N-1)/Fs;

% freqs to use
f = [1000 500 250];
x = 0;
for i = 1:length(f)
    x = x + sin(2*pi*f(i)*t); % stack them
end

% do DFT manually
X1 = zeros(1,N);
for k = 1:N
    for n = 1:N
        X1(k) = X1(k) + x(n)*exp(-1j*2*pi*(k-1)*(n-1)/N);
    end
end

% just use fft for comparison
X2 = fft(x);

faxis = (0:N-1)*(Fs/N);

% plot DFT
figure
stem(faxis, abs(X1), 'r')
title('DFT plot')
xlabel('Freq Hz')
ylabel('Mag')
grid on

% plot FFT
figure
stem(faxis, abs(X2), 'b')
title('FFT quick view')
xlabel('Hz'); ylabel('abs');
