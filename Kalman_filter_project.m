%% Kalman filter script
%syms deltaT
data = readmatrix("C:\Users\kasper\Downloads\data\Run1");
deltaT = 0.1
accmeasure(1,length(data)) = [zeros];
accmeasure(1) = sqrt(data(1,8)^2+data(1,2)^2)*9.82
for i = 2:length(data)
    accmeasure(i) = sqrt((data(i,8)+0.01)^2+(data(i,2)+0.02)^2)*9.82 
end
A = [1, deltaT, 2*deltaT^2;
     0, 1,      deltaT    ;
     0, 0,      0         ];
g = 9.82;
theta = asin(65/164);

largefriction = [1.99, 1.97, 1.98, 1.92];
smallfriction = [1.64, 1.67, 1.66, 1.66, 1.71];

largefric = mean(largefriction);
smallfric = mean(smallfriction);
angle = asin(65/164);
frictionlargecoefficient = ((2*1.405)/(9.82*largefric^2)-sin(theta))/(-cos(theta));
%frictionsmallcoefficient = (1.405-1.5*9.82*smallfric^3*sin(theta))/(-1.5*9.82*smallfric^3*cos(theta));
frictionsmallcoefficient = ((2*1.405)/(9.82*smallfric^2)-sin(theta))/(-cos(theta));
w =  g *(sin(theta)-cos(theta)*frictionsmallcoefficient)
B = [0; 0; w]
U = 1
Cacc = [0, 0, 0
        0, 0, 0
        0, 0, 1];
Covar(3, 3) = [zeros];
Systemnoise =  [ 0.2,0,0;
                 0,0.2,0;
                 0,0,0.2]
X = [0; 0; 0];
X2 = [0; 0; 0];
savex(3, 20) = [zeros];
savex2(3, 20) = [zeros];

%Kalman filter equations
Sacc = [1, 0, 0;
        0, 1, 0;
        0, 0, 0.19]






for i=1:42
    X = A*X + B*U;
    X2 = A*X2 + B*U;
    Covar = A*Covar*A' + Systemnoise
    savex(:,i) = X;
    R = Covar * Cacc * Sacc^-1
    v = [0;0;accmeasure(i)] - Cacc*X2
    X2 = X2+R*v
    savex2(:,i) = X2;

end
figure()
hold on
plot(savex(1,:) )
plot(savex2(1,:) )

