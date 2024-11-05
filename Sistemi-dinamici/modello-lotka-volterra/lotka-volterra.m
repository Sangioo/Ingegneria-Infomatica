% Equazioni
f1 = @(t, x) x.^3;
f2 = @(t, x) -x.^3;
f3 = @(t, x) x.^2;
f4 = @(t, x) -x.^2;
f5 = @(t, x) x;
f6 = @(t, x) -x;

% Condizioni iniziali f1-f6
x0_positive = 0.1;  
x0_negative = -0.1;

tspan = [0 8]; % intervallo di tempo

% Soluzioni equazioni differenziali positive 
[t1, x1] = ode15s(f1, tspan, x0_positive);
[t2, x2] = ode15s(f2, tspan, x0_positive);
[t3, x3] = ode15s(f3, tspan, x0_positive);
[t4, x4] = ode15s(f4, tspan, x0_positive);
[t5, x5] = ode15s(f5, tspan, x0_positive);
[t6, x6] = ode15s(f6, tspan, x0_positive);

% Soluzioni negative
[t1n, x1n] = ode15s(f1, tspan, x0_negative);
[t2n, x2n] = ode15s(f2, tspan, x0_negative);
[t3n, x3n] = ode15s(f3, tspan, x0_negative);
[t4n, x4n] = ode15s(f4, tspan, x0_negative);
[t5n, x5n] = ode15s(f5, tspan, x0_negative);
[t6n, x6n] = ode15s(f6, tspan, x0_negative);

% Grafici equazioni differenziali
figure('Position', [100, 100, 1200, 800]);

subplot(2, 3, 1);
plot(t1, x1, 'b', t1n, x1n, 'r');
title("x' = x^3");
xlabel('Tempo');
ylabel('x');
legend('x_0 > 0', 'x_0 < 0');

subplot(2, 3, 2);
plot(t3, x3, 'b', t3n, x3n, 'r');
title("x' = x^2");
xlabel('Tempo');
ylabel('x');
legend('x_0 > 0', 'x_0 < 0');

subplot(2, 3, 3);
plot(t5, x5, 'b', t5n, x5n, 'r');
title("x' = x");
xlabel('Tempo');
ylabel('x');
legend('x_0 > 0', 'x_0 < 0');

subplot(2, 3, 4);
plot(t2, x2, 'b', t2n, x2n, 'r');
title("x' = -x^3");
xlabel('Tempo');
ylabel('x');
legend('x_0 > 0', 'x_0 < 0');

subplot(2, 3, 5);
plot(t4, x4, 'b', t4n, x4n, 'r');
title("x' = -x^2");
xlabel('Tempo');
ylabel('x');
legend('x_0 > 0', 'x_0 < 0');

subplot(2, 3, 6);
plot(t6, x6, 'b', t6n, x6n, 'r');
title("x' = -x");
xlabel('Tempo');
ylabel('x');
legend('x_0 > 0', 'x_0 < 0');


% Modello Volterra-lotka

a = 1;          % Crescita preda
b = 1;          % Decrescita predatori
c = 1;          % Decrescita preda dovuta ai predatori
d = 1;          % Crescita predatori dovuta alle prede
t_max = 30;     % tempo massimo
xy0 = [2, 1];   % condizioni iniziali

% Equazioni del modello
f = @(t, X) [a*X(1) - c*X(1)*X(2); -b*X(2) + d*X(1)*X(2)];
[t, sol] = ode45(f, [0 t_max], xy0);

% Punti di equilibrio
eq1 = [0; 0];
eq2 = [b/d; a/c];

% Grafico
figure;
hold on;
xlabel('Prede (x)');
ylabel('Predatori (y)');
title('Modello Lotka-Volterra');
axis([0 max(sol(:,1))+.5 0 max(sol(:,2))+.5]);

plot(eq1(1), eq1(2), 'ro');
plot(eq2(1), eq2(2), 'ro');
plot(sol(:,1), sol(:,2), 'b');
legend('x=0 y=0', 'x=b/d y=a/c', 'x=2 y=1');

% Grafico prede e predatori nel tempo
figure;
subplot(2,1,1);
plot(t, sol(:,1), 'b', 'LineWidth', 2);
xlabel('Tempo');
ylabel('Prede');
title('Prede nel tempo');

subplot(2,1,2);
plot(t, sol(:,2), 'r', 'LineWidth', 2);
xlabel('Tempo');
ylabel('Predatori');
title('Predatori nel tempo');