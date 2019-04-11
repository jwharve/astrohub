cc;

degH = 60;
degV = 40;

degH0 = -degH/2;
degV0 = 50-degV/2;

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


height = 26.5;%(10.375-2)*2.54;
height = 24.5;


C = 199; % 20
R = 163;
R = 111;
R = 75;
R = 47;
R = 11; % 70

C = 190;
R = 20;

pH = (C-numCols/2)/numCols;
pV = ((numRows - R)-numRows/2)/numRows;

hDeg = degH0 + degH/2 + atand(pH*h/d);
vDeg = degV0 + degV/2 + atand(pV*v/d);

y = height*tand(vDeg);
x = sqrt(y^2+height^2)*tand(hDeg);

x
y