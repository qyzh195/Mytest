function hit = CheckCollision(x1,x2,A,c)

%x1=[0;0];x2=[10;0];A=eye(2);c=[11;0.2];

%Students to add code that returns:
% hit = 1 if the line from x1 to x2 hits the ellipse (x-c)'A(x-c)<=1.
% hit = 0 otherwise (i.e. path is safe)
x=x2-x1;
xi=x/sqrt(sum(x.^2));

qa=x'*A*x;
qb=2*(x1-c)'*A*x;
qc=(x1-c)'*A*(x1-c)-1;

delta=qb^2-4*qa*qc;
if delta>0
    d1=(-qb-sqrt(delta))/2/qa;
    d2=(-qb+sqrt(delta))/2/qa;
    if ((0<=d1)&&(d1<=1))||((0<=d2)&&(d2<=1))
        hit=1;
    else
        hit=0;
    end
else
    hit = 0;
end