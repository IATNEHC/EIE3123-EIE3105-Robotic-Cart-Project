clc;
clear;

pkg load control;

s = tf('s');

gcl = 3981*((s+1)/s);

gsysl = (7/3000)*(1/(s+1));

Tl = feedback(gcl*gsysl, 1);

gcr = 10000*((s+1)/s);

gsysr = (7/6000)*(1/(s+1));

Tr = feedback(gcr*gsysr, 1);

gcout = 0.5*((s+1)/s)

bode(gsysl*gcl);
margin(gsysl*gcl);

bode((Tl+Tr), (Tl+Tr)*gcout);
margin((Tl+Tr)*gcout);

step(feedback(gcl*gsysl, 1));
step(feedback((Tr+Tl)*gcout, 1));






