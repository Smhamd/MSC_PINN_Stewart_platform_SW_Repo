function deltaL = UPU_IK_Sim(u)
%#codegen
% u = [X; Y; Z; Roll; Pitch; Yaw]
% X,Y,Z in mm, angles in rad
% output deltaL in mm

u = reshape(u, [6,1]);

X     = u(1);
Y     = u(2);
Z     = u(3);
Roll  = u(4);
Pitch = u(5);
Yaw   = u(6);

Rb = 185;   % mm
Rp = 150;   % mm
l0 = 290;   % mm

angleB = deg2rad([25 49 145 169 265 289]);
angleP = deg2rad([0 74 120 194 240 314]);

b = zeros(3,6);
p = zeros(3,6);

for i = 1:6
    b(:,i) = [Rb*cos(angleB(i)); Rb*sin(angleB(i)); 0];
    p(:,i) = [Rp*cos(angleP(i)); Rp*sin(angleP(i)); 0];
end

r = [X; Y; Z];

cy = cos(Yaw);   sy = sin(Yaw);
cp = cos(Pitch); sp = sin(Pitch);
cr = cos(Roll);  sr = sin(Roll);

R = [cy*cp, cy*sp*sr - sy*cr, cy*sp*cr + sy*sr;
     sy*cp, sy*sp*sr + cy*cr, sy*sp*cr - cy*sr;
     -sp,   cp*sr,            cp*cr];

l = zeros(6,1);

for i = 1:6
    L = r + R*p(:,i) - b(:,i);
    l(i) = sqrt(L(1)^2 + L(2)^2 + L(3)^2);
end

deltaL = l - l0;

end