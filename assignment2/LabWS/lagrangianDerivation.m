%% Inverted Pendulum Dynamics

% Complete the following symbolic math derivation of the inverted pendulum.

% Refer to Section 2 of the Rotary Pendulum Workbook for details of the
% inverted pendulum (Furuta pendulum) setup, as well as sign conventions
% and notation.

%% Parameters

% g     Gravitational constant                                      (m/s^2)
% Mp    Pendulum Mass                                               (kg)
% Lp    Full Length of the pendulum  (centre of mass at Lp/2)       (m)
% Lr    Full Length of the rotary arm                               (m)
% Jr    Rotary arm moment of inertia (about axis of rotation)       (kg.m^2)
% Jp    Pendulum moment of inertia (about centre of mass)           (kg.m^2)
% Dr    Viscous damping (rotary arm) 
% Dr    Viscous damping (rotary arm) 

syms g Mp Lp Lr Jr Jp Dr Dp real

%% Generalized coordinates

syms alpha theta dAlpha dTheta ddAlpha ddTheta real

q = [theta;alpha];          % Generalized coordinates
dq = [dTheta;dAlpha];       % Time derivative of generalized coordinates
ddq = [ddTheta;ddAlpha];    % Second time derivative (i.e. generalized acceleration)

x = [q;dq];                 % State variable
dx = [dq;ddq];              % Time derivative of state variable.

%% Rotation matrices

% Rotation matrix from rotary frame (frame 1) to pendulum frame (frame 2).
% Let's say that:
% x coordinate is directed along the rod (rotary arm or pendulum)
% z coordinate define the axis of rotation (for each of the two rotating rods)
% y is mutually orthogonal to x,z.

R_12 = ???

%% Energy of Rotary arm

% Potential energy 
Vr = ???

% Kinetic energy
Kr = ???

%% Energy of Pendulum

% Potential energy
Vp = ???

% Kinetic Energy

% Angular velocity of pendulum:
% Transform angular velocity of rotary arm into pendulum frame, and add
% angular velocity of pendulum.
w_p = R_12*[0;0;dTheta] + [0;0;dAlpha];

% Linear velocity of pendulum:
% Transform velocity of rotary arm 'tip' into pendulum frame and add
% velocity of pednulum centre of mass.
v_p = R_12*cross([0;0;dTheta],[Lr;0;0]) + cross(w_p,[Lp/2;0;0]);

% Pendulm inertia matrix:
% Assume Jp_xx is negligible.
Ip = [0,0,0;
      0,Jp,0;
      0,0,Jp];
  
% Total kinetic energy of pendulum: 
Kp = 0.5*(v_p.'*Mp*v_p + w_p.'*Ip*w_p);  


%% Lagrangian and Euler-Lagrange Equation

L = ???                             % Lagrangian

dL_q = jacobian(L,q);               % dL/d(q) - derivitive of Lagrangian with respect to generalized coordinates
dL_dq = jacobian(L,dq);             % dL/d(dq) - derivitive of Lagrangian with respect to generalized velocity
    
dL_dq_t = jacobian(dL_dq,x)*dx;     % d(dL/d(dq))/dt - time derivitive of above (using chain rule)

dyn = dL_dq_t - dL_q.';             % LHS of Euler-Lagrange equation


% DON'T FORGET to include the friction effects in the generalized forces on 
% the right hand side of the Euler-Lagrange equation.



