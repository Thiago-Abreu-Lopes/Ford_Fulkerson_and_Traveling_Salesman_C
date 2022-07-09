%estração de dados
greedy = fopen('greedy_total.txt');
vgreedy = fscanf(greedy,'%f');
brute = fopen('brute_total.txt');
vbrute = fscanf(brute,'%f');
v = 0;
x = 1:1:100;
y = zeros(100,1);

for i=1:length(vgreedy)
    if vgreedy(i) == vbrute(i)
        v = v+1;
        y(i) = 1;
    end
end
stem(x,y ,'LineWidth',2);
xlabel('grafos','fontweight','bold','fontsize',12);
ylabel('igualdades','fontweight','bold','fontsize',12);

disp(v); % retorna o numero de soluções ótimas


