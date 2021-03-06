function [ H ] = terrainHeight( terrain, X, Y )
%GETHEIGHT Returns the height at each point in (X,Y)
%               terrain is a terrain structure generated by the
%               generateTerrain() function.
% 
%               If X and Y are matrices
%                   H(i,j) is the height at X(i,j), Y(i,j)
%                   This consides with the convention used for meshgrid.


Hy = zeros(size(X));
Hx = zeros(size(X));

for i = 1:size(X,1)
    for j = 1:size(X,2)
        Hx(i,j) = sum(terrain.xCoeffs.*cos(terrain.xFreqs*X(i,j) + terrain.xPhase));
        Hy(i,j) = sum(terrain.yCoeffs.*cos(terrain.yFreqs*Y(i,j) + terrain.yPhase));
    end
end

H = (Hx).*(Hy);

end

