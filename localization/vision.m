cc;

degH = 60;
degV = 40;

degH0 = -degH/2;
degV0 = 30-degV/2;

pixH = 1296;
pixV = 967;

pixSize = 1.9e-6;
h = pixH*pixSize;
v = pixV*pixSize;

d1 = (0.5*h)/tand(degH/2);
d2 = (0.5*v)/tand(degV/2);

d = mean([d1 d2]);

numCols = 315;
numRows = 207;


height = 10.75*2.54;


R = 79;
% R = 0;
C = 50;


pH = (C-numCols/2)/numCols;
pV = (r-numRows/2)/numRows;

hDeg = atand(pH*h/d);
vDeg = atand(pV*v/d);

y = height*tand(vDeg)
x = d*tand(hDeg)/2.54