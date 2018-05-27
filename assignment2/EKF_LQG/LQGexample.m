%% LQG control for yaw damper, 
% from Anderson and Moore, Optimal Control: Linear Quadratic Methods

A = zeros(6,6);
A(1,1) = -2.82e-8;
A(2,2) = -6.76e-3;
A(3:4,3:4) = [-0.122 1.57
            -1.57 -0.122];
A(5:6,5:6) = [-0.71 21.3
            -21.3 -0.71];

B = [-4.06e-4
    -2.2e-1
    8.84e-2
    -3.08e-1
    6.39e-2
    -1.08];

Bw = [-1.65e-7
    7.61e-5
    3.05e-2
    -1.05e-2
    4.46e-3
    -1.02e-2];

C = [-3.5e-4 -1.57e-1 -1.56e-1 4.61e-3 -3.37e-1 -2.4e-2
    -2.05e-4 -1.54e-1 2.81e-1 -9.85e-2 -1.02 -7.68e-2];

sys = ss(A,Bw,C,0);

sys2 = ss(A,[Bw B],C,0);



Q = C'*C+1*diag([0 0 1 1 0 0]);
%Q = eye(6);
R = 1e-3;

K = lqr(A,B,Q,R);

Qn = 1;
Rn = 1e-6*eye(2);

[E, L] = kalman(sys, Qn, Rn);

kalmanfilt = ss(A-B*K-L*C,L,eye(6),0);

sim LQGsim

figure(1);plot(y(:,2));
hold on;plot(y2(:,2),'r');
hold off

[Py f] = pwelch(y(:,2),[],[],[],200);
[Py2 f] = pwelch(y2(:,2),[],[],[],200);

figure(2);loglog(2*pi*f,Py)
grid on
hold on;loglog(2*pi*f,Py2,'r')
hold off


[Py f] = pwelch(y(:,1),[],[],[],200);
[Py2 f] = pwelch(y2(:,1),[],[],[],200);

figure(3);loglog(2*pi*f,Py)
grid on
hold on;loglog(2*pi*f,Py2,'r')
hold off



