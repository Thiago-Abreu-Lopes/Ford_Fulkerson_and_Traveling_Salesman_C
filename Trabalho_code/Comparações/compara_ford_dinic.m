%estração de dados
ford = fopen('time_ford_fulkerson.txt');
vford = fscanf(ford,'%f');
dinic = fopen('time_dinic.txt');
vdinic = fscanf(dinic,'%f');
% plotagem
p = plot(1:length(vford),vford,1:length(vdinic),vdinic);
xlabel('Grafo','fontweight','bold','fontsize',12);
ylabel('Tempo de Execução [ms]','fontweight','bold','fontsize',12);
legend('ford-fulkerson','dinic','Location','northwest');
p(1).LineWidth = 2;
p(2).LineWidth = 2; 
