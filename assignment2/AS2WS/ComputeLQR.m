function K = ComputeLQR()
%  clear all
Ih=0.0256;Mh=3;Rh=0.33;Ib=0.25;Mb=6;Rb=0.25;g=9.8;

sx0=[0,0,0,0,0];
thetax_=sx0(4);
dthetax_=sx0(2);

Mx=zeros(2);
Mx(1,1)=Mb+Ib/Rb^2+Mh;
Mx(1,2)=-Mh*Rh*cos(thetax_);
Mx(2,1)=-Mh*Rh*cos(thetax_);
Mx(2,2)=Mh*Rh^2+Ih;

Cx=zeros(2);
Cx(1,2)=2*Mh*Rh*sin(thetax_)*dthetax_^2;

Gx=[0,0;0,-Mh*Rh*g*cos(thetax_)];
Bx=[1;Rb];


% M * ddot_q + C * dot_q + G * q = B*t
% dot t = -2 r - 2 t
%s tate: q,dot_q, t

Ax=[zeros(2), eye(2), zeros(2,1);
    -Mx\Gx, -Mx\Cx, Mx\Bx;
    0, 0, 0, 0, -2];
Bx=[0;0;0;0;2];

Qx=diag([1,1,1,1,1]);
Rx=1;
[Kx,Sx,ex] = lqr(Ax,Bx,Qx,Rx);
K = Kx;
end