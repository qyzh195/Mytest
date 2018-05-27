%%% Base file for AMME5520 Assignment 2
% Navigation and control through an obstacle field.

%{
Questions:
    1.sometime lqrK may result in too large output, which would make theta 
        become too big to be simulated by linearized model.
        how to solve this problem?
%}


clear all
close all

global Width Height sampleNumber neighber
Width = 300;Height = 150;
neighber=20;sampleNumber=200;

% Randomly generate some obstacles (number, average size as parameters)
numObst = 10; % Control the number of obstacles, e.g. 10, 20, 30, 40.
Adim = 15; % Control the "average" size of the obstacles.


As = cell(numObst,1);
cs = cell(numObst,1);

figure(1);

dimensions = [0 Width 0 Height];

% Create obstacles only in the middle 60%
leftlim = 0.2*(dimensions(2)-dimensions(1));
rightlim = 0.8*(dimensions(2)-dimensions(1));

for k = 1:numObst
    % Generate ellipse in the form (x-c)'A(x-c)=1
    
     L = randn(2,2);
     As{k} = (0.4*eye(2)+ L'*L)/Adim^2;
     tmp = rand(2,1);
     cs{k} = [leftlim+(rightlim-leftlim)*tmp(1);dimensions(3)+(dimensions(4)-dimensions(3))*tmp(2)];
     Ellipse_plot(As{k},cs{k});
     
end
plot([dimensions(1) dimensions(2)],[dimensions(3) dimensions(3)],'r');
plot([dimensions(1) dimensions(2)],[dimensions(4) dimensions(4)],'r');
hold off

%% Students add code here for planning
% - Students to modify ComputePath, to include collision checker, PRM, and
% path planner.

bufferCofficient = 0.1;
bufferM=eye(2)*(1-bufferCofficient);
for ias = 1:length(As)
    As{ias}=As{ias}*bufferM;
end
ComputePath(As,cs);





%% Simulate Closed-loop system
% students to modify functions

h = 0.01; % 100Hz sample time. Modify as desired.



global errorT lqrK stateNum pathP; %threshold of position error
errorT = 0.3;lqrK=ComputeLQR();

stateNum=10;
x0 = zeros(stateNum,1);  %Initial condition.

stop = 0;
ts = 0;
xs = x0;

% Assuming xs = [ x, thetaX, xdot, thetaXdot, y, thetaY, ydot, thetaYdot ]

% This variable can be used to collect any parameters for simulation
dynparams = [];
params = [];

k = 1;
while (stop ~= 1)
    % Current state.
    xt = xs(:,k);
    
    % Get current measurement, compute control.
    yt = meas(xt);
    [ut, params] = ComputeControl(yt,params);
    if isempty(pathP) 
        break;
    end
    % ut = [ u for x axis , u for y axis ]
   
    % Use Runge Kutta to approximate the nonlinear dynamics over one time
    % step of length h.
    xs(:,k+1) = RungeKutta4(@RobotDynamics, xt, ut, 0, h, dynparams);
    
    ts(k+1) = ts(k)+h;
    us(:,k) = ut;
   
    if (k>100000)
        stop = 1;  % Stop after 100 time steps. You will need to change this.
                   % Should stop after goal reached or collision.
    end
    k = k+1;
end

figure(2)
plot(xs(1,:),xs(6,:))
hold on;
for k = 1:numObst
     Ellipse_plot(As{k},cs{k});
end


