function [ sdot ] = RobotDynamics(st,ut,t, dynparams)
% Dynamics stub for AMME5520 Assignment 2. Students to fill in.
Ih=0.0256;Mh=3;Rh=0.33;Ib=0.25;Mb=6;Rb=0.25;g=9.8;

thetaX=st(2);dthetaX=st(4);tx=st(5);
thetaY=st(7);dthetaY=st(9);ty=st(10);
qx=st(1:2);dqx=st(3:4);
qy=st(6:7);dqy=st(8:9);
rx=ut(1);ry=ut(2);

Mx=[ Mb+Ib/Rb^2+Mh, -Mh*Rh*cos(thetaX);
    -Mh*Rh*cos(thetaX), Mh*Rh^2+Ih];
Cx=[0, Mh*Rh*dthetaX*sin(thetaX); 0, 0];
Gx=[0;-Mh*Rh*g*sin(thetaX)];
Bx=[tx;Rb*tx];
dtx=2*rx-2*tx;

My=[ Mb+Ib/Rb^2+Mh, -Mh*Rh*cos(thetaY);
    -Mh*Rh*cos(thetaY), Mh*Rh^2+Ih];
Cy=[0, Mh*Rh*dthetaY*sin(thetaY); 0, 0];
Gy=[0;-Mh*Rh*g*sin(thetaY)];
By=[ty;Rb*ty];
dty=2*ry-2*ty;

dxs=[zeros(2), eye(2);zeros(2),-Mx\Cx]*[qx;dqx]+[0;0;Mx\(Bx-Gx)];
dxs=[dxs;dtx];
dys=[zeros(2), eye(2);zeros(2),-My\Cy]*[qy;dqy]+[0;0;My\(By-Gy)];
dys=[dys;dty];
sdot=[dxs;dys];
end

