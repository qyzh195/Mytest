
M=zeros(4);
M(1,1)= mp*Lr^2+mp*Lp^2/4 -0.25*mp*Lp^2*cos(alpha)^2+Jr;
M(1,2)= 0.5*mp*Lp*Lr*cos(alpha);
M(2,1)= 0.5*mp*Lp*Lr*cos(alpha);
M(2,2)= Jp+0.25*mp*Lp^2;

V=zeros(4);
V(1,1)= 0; %Dr+ 0.5*mp*Lp^2*sin(alpha)*cos(alpha)*alphaD;
V(1,2)= 0; %0.5*mp*Lp^2*sin(alpha)*cos(alpha)*thetaD-mp*Lp*Lr*sin(alpha)*alphaD;
V(2,1)= 0; %0.5*mp*Lp^2*cos(alpha)*sin(alpha)*thetaD;
V(2,2)= Dp;

G=zeros(4);
G(1,1)= 0;
G(1,2)= 0;
G(2,1)= 0;
G(2,2)= 0.5*mp*Lp*g*cos(alpha); %thetaDD,alphaDD,thetaD,alphaD=0

A=[zeros(2,2), eye(2); -M\G, -M\V];
B=[zeros(2,1); M\R];
%state = [q,qDot];
% stateD=[ zeros(2,2), eye(2); -M\G, -M\V]*state + [zeros(2,1); M\R]*tao;
