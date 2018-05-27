%% Model parameters

% Motor
% Resistance
Rm = 8.4;
% Current-torque (N-m/A)
kt = 0.042;
% Back-emf constant (V-s/rad)
km = 0.042;
%
% Rotary Arm
% Mass (kg)
Mr = 0.095;
% Total length (m)
Lr = 0.085;
% Moment of inertia about pivot (kg-m^2)
Jr = Mr*Lr^2/12;
% Equivalent Viscous Damping Coefficient (N-m-s/rad)
Dr = 0.0015;
%
% Pendulum Link
% Mass (kg)
Mp = 0.024;
% Total length (m)
Lp = 0.129;
% Moment of inertia about pivot (kg-m^2)
Jp = Mp*Lp^2/12;
% Equivalent Viscous Damping Coefficient (N-m-s/rad)
Dp = 0.0005;
% Gravity Constant
g = 9.81;
%

%% Linearized dynamics

% Write code the generates linearized system matrices A,B,C and D as a
% function of the above model parameters and the linearization point x0.

x_0 = [0;pi;0;0]; %theta,alpha,thetaDot,alphaDot

theta=x_0(1);alpha=x_0(2);
thetaD=x_0(3);alphaD=x_0(4);
thetaDD=0;alphaDD=0;

M=zeros(2);
M(1,1)= Mp*Lr^2+Mp*Lp^2/4 -0.25*Mp*Lp^2*cos(alpha)^2+Jr;
M(1,2)= 0.5*Mp*Lp*Lr*cos(alpha);
M(2,1)= 0.5*Mp*Lp*Lr*cos(alpha);
M(2,2)= Jp+0.25*Mp*Lp^2;

V=zeros(2);
V(1,1)= Dr+ 0.5*Mp*Lp^2*sin(alpha)*cos(alpha)*alphaD;
V(1,2)= 0.5*Mp*Lp^2*sin(alpha)*cos(alpha)*thetaD-Mp*Lp*Lr*sin(alpha)*alphaD;
V(2,1)= 0.5*Mp*Lp^2*cos(alpha)*sin(alpha)*thetaD;
V(2,2)= Dp;

G=zeros(2);
G(1,1)= 0;
G(1,2)= 0.5*Mp*Lp^2*cos(alpha)*sin(alpha)*thetaDD-0.5*Mp*Lp*Lr*sin(alpha)*alphaDD+0.5*Mp*Lp^2*cos(2*alpha)*thetaD*alphaD-0.5*Mp*Lp*Lr*cos(alpha)*alphaD^2;
G(2,1)= 0; 
G(2,2)= 0.5*Mp*Lp*g*cos(alpha)-0.5*Mp*Lp*Lr*sin(alpha)*thetaDD+0.25*Mp*Lp^2*cos(2*alpha)*thetaD^2;
Rsys=[1;0];
% Linear system
A = [zeros(2,2), eye(2); -M\G, -M\V];
B = [zeros(2,1); M\Rsys];
C = [eye(2),zeros(2)];
D = zeros(2,1);

% Add actuator dynamics
B = kt * B / Rm;
A(3,3) = A(3,3) - kt*kt/Rm*B(3);
A(4,3) = A(4,3) - kt*kt/Rm*B(4);

%% LQR Control

% Design as LQR to stabilize the upright equilibrium position.
Q = diag([5 1 1 1]);
R=1;
[K,S,e] = lqr(A,B,Q,R);


