figure(1);
subplot(1,2,1)
plot(rotArm.time, rotArm.signals.values(:,1),rotArm.time, rotArm.signals.values(:,2));
title(strcat('Rotate arm angle'));%'Q=',mat2str(Q)));%[Q(1,1),Q(2,2),Q(3,3),Q(4,4)])));
xlabel('Time(s)');
ylabel('Angle(deg)');
legend('Arm reference','Arm angle');
subplot(1,2,2)
plot(penout.time,penout.signals.values)
title('Pendulum angle');
xlabel('Time(s)');
ylabel('Angle(deg)');
%legend('Pendulum angle');