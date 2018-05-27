close all;
global Width Height sampleNumber neighber

Width = 300;Height = 150;neighber=20;sampleNumber=1000;

 P = [ Width*rand(1,sampleNumber-2); Height*rand(1,sampleNumber-2)];
P = [P [0;0] [300;150]];
% P=[];
% for i=1:10:Height
%     for j=1:10:Width
%         P=[P [j;i]];
%     end
% end

px=P(1,:);py=P(2,:);
scatter(px,py,'*')
axis equal
hold on;

idx=knnsearch(P',P','K',neighber+1);
adjM=zeros(sampleNumber);
for inp=1:sampleNumber
    for inei=2:(neighber+1)
        hit = 0;
        
%         try
%             xp=[P(1,inp),P(1,idx(inp,inei))];yp=[P(2,inp),P(2,idx(inp,inei))];
%         catch
%          ans=[];
%         end
%         plot(xp,yp);

%         for iobs=1:length(As)
%             hit = hit + CheckCollision(P(:,inp),P(:,idx(inp,inei),As(iobs),Cs(iobs))
%         end
        if hit==0
            adjM(inp,idx(inp,inei))=sqrt(sum((P(:,inp)-P(:,idx(inp,inei))).^2));
        end
    end
end

begin = sampleNumber-1;
V=OptPath(adjM,begin);


sp=sampleNumber;
path=[sp];
while sp~=begin
    path=[path V(2,sp)];
    sp = V(2,sp);
end
pathP=P(:,path);
plot(pathP(1,:),pathP(2,:));
