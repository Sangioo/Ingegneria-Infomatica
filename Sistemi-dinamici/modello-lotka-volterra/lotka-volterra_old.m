function LotkaVolterra

% tempo massimo della simulazione
tempo_max = 30;

% parametri
a = 8;
b = 9;
c = 4;
d = 3;

% condizioni iniziali
x0 = 1;
y0 = 1;

% modello Volterra-Lotka
eq=@(t,x) [a*x(1) - c*x(1)*x(2); -b*x(2) + d*x(1)*x(2)];
[t,sol] = ode45(eq,[0 tempo_max],[x0 y0]);

% grafico di Volterra-Lotka
subplot(3,1,1)
plot(sol(:,1),sol(:,2),'-','color',[0; 1; 0],'markersize',14,'MarkerFaceColor','b');                               
hold on
title('Grafico di Lotka-Volterra:','fontsize',12)
xlabel('x')
ylabel('y')
axis([0 max(sol(:,1))+.5 0 max(sol(:,2))+.5])

% grafico di x nel tempo
subplot(3,1,2)
plot(t(:,1),sol(:,1),'-','color',[1; 0; 0],'markersize',10,'MarkerFaceColor','b')
title('Andamento nel tempo di x:','fontsize',12)
xlabel('t')
ylabel('x')
axis([0 tempo_max 0 max(sol(:,1))+.5])

% grafico di y nel tempo
subplot(3,1,3)
plot(t(:,1),sol(:,2),'-','color',[0; 0; 1],'markersize',10,'MarkerFaceColor','b')
title('Andamento nel tempo di y:','fontsize',12)
xlabel('t')
ylabel('y')
axis([0 tempo_max 0 max(sol(:,2))+.5])
