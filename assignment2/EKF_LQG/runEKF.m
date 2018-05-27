%% Extended Kalman Filter example for a simple problem of monocular localisation.


x0 = [4;-1];
xh0 = [5;-1];
X0 = 10*eye(2);

states0 = [x0;xh0;X0(:)];

tspan = 0:0.05:8;
[tout, xout] = ode45(@EKF,tspan,states0);




% Plot results

hFig = figure(1);
set(hFig,'DoubleBuffer', 'on');
for k = 1:length(tout);
    x = xout(k,1:2);
    xh = xout(k,3:4);
    X = reshape(xout(k,5:end),2,2);
        
    Ellipse_plot(inv(X),-xh);
    plot(-x(1),-x(2),'ok');
    plot(0,0,'xr');
    hold off
    axis([-8 5 -5 3])
    drawnow
    pause
    
end
    
figure(2);plot(tout,xout(:,1)-xout(:,3));
figure(3);plot(tout,xout(:,2)-xout(:,4));

figure(4);plot(-xout(:,1),-xout(:,2));
hold on;
plot(-xout(:,3),-xout(:,4),'r');
hold off