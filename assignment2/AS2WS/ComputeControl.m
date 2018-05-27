function [u,params] = ComputeControl(y,params)
% Students to add code here. You can use the "params" variable to store
% internal controller states, if necessary.

%params should be the route points set.

global errorT lqrK pathP; %threshold of position error

if ~isempty(pathP)
    pc = [y(1);y(6)];
    if sum(abs(pathP(:,1)-pc))<errorT
        pathP(:,1)=[];
    end
    if ~isempty(pathP)
        xc=y-[pathP(1,1) 0 0 0 0 pathP(2,1) 0 0 0 0]';
        u = [-lqrK * xc(1:5), -lqrK * xc(6:10)];
    else
        u=0;
    end
else
    u=0;
end
