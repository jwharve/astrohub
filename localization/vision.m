cc;
degH = 60;
degV = 40;

degH0 = -degH/2;
degV0 = 72.125;%atand(13.5/(10.75*2.54));

numCols = 315;
numRows = 207;

hPer = degH/numCols;
vPer = degV/numRows;

height = 10.75*2.54;



R = 79;
% R = 0;
C = 50;

hDeg = degH0+C*hPer;
vDeg = degV0+(numRows-R)*vPer;
vDeg = degV0-R*vPer;

d = height*tand(vDeg)
over = d*tand(hDeg)/2.54