function [V]=OptPath(adjMap,startP)
%{
% Test data
adjMap=[0 5 5 0 0 0 0;
    0 0 2 0 0 0 0;
    8 2 0 1 5 0 0;
    0 0 0 0 0 0 4;
    0 0 0 0 0 6 3;
    0 4 0 0 0 0 0;
    0 0 0 0 0 10 0];
startP=3;
%}
%verify adjmap firstly
Size=size(adjMap);
if (~diff(Size)&&ismatrix(adjMap))
    Q=1:Size(1);
    sol=[];
    cost=Inf(1,Size(1));
    cost(startP)=0;
    cost=[cost;zeros(1,Size(1))];
    %cost(1) stores cost of every point from startpoint,
    %whose sequence represent index.
    %cost(2) stores path from the last point
    while ~isempty(Q)
        
        costQ=[;];
        for iQ=1:numel(Q)
            costQ=[costQ,[Q(iQ);cost(1,Q(iQ))]];
        end
        
        [x,ind]=min(costQ(2,:));
        if x==Inf
            break;
        end
        x=costQ(1,ind);
        Q(ind)=[];
        ind=costQ(1,ind);%update the index to cost
        sol=[sol,ind];%ind for current node.
        for indAdj = 1:Size(1) %indAdj for nodes in current node's adjacency.
            dist=adjMap(ind,indAdj);
            %row in adjacency matrix are nodes can be reach from current node.
            if (dist~=0)&&(indAdj~=ind)
                if cost(1,ind)+dist<cost(1,indAdj)
                    cost(1,indAdj)=cost(1,ind)+dist;
                    cost(2,indAdj)=ind;
                end
            end
        end
    end
    V=cost;
end
end