function ComputePath(As,Cs)

% start point and end point still not defined yet

global Width Height sampleNumber neighber pathP

P = [ Width*rand(1,sampleNumber-2); Height*rand(1,sampleNumber-2)];
P = [P [0;0] [300;150]];

axis equal
hold on;
px=P(1,:);py=P(2,:);
scatter(px,py)


idx=knnsearch(P',P','K',neighber+1);
adjM=zeros(sampleNumber);
for inp=1:sampleNumber
    for inei=2:(neighber+1)
        hit = 0;
        for iobs=1:length(As)
            hit = hit + CheckCollision(P(:,inp),P(:,idx(inp,inei)),As{iobs},Cs{iobs});
        end
        if hit==0
            adjM(inp,idx(inp,inei))=sqrt(sum((P(:,inp)-P(:,idx(inp,inei))).^2));
        end
    end
end

begin = sampleNumber-1;
V=OptPath(adjM,begin);

sp=sampleNumber;
path=sp;

while sp~=begin
    path=[V(2,sp) path];
    sp = V(2,sp);
end
pathP = P(:,path);
 plot(pathP(1,:),pathP(2,:));

