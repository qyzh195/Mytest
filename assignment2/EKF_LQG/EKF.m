function derivs = EKF(t,states)

% reshape and relabel states
x = states(1:2);
xh = states(3:4);
X = reshape(states(5:end),2,2);

% variances
measvar = 1e-2;
R=measvar;
Q=0;

y = atan2(x(2),x(1))+sqrt(measvar)*randn;

A = 0;
B = eye(2);

u = [-1;1-0.15*t];

rs = (xh(1)^2+xh(2)^2);
C = [-xh(2)/rs xh(1)/rs];

yh = atan2(xh(2),xh(1));


L = X*C'/R;

% True dynamics
xdot = u;

% State estimator
xhdot = u + L*(y-yh);

% Riccati Eqn. In this case A = B = 0, so only the last term matters
Xdot = A*X+X*A'+B*Q*B'-X*C'/R*C*X;


derivs = [xdot;xhdot;Xdot(:)];